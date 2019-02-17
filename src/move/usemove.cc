//
// Created by neel on 2/6/19.
//

#include <cmath>
#include <random>
#include <cassert>
#include "usemove.h"
#include "../stringconverter/stringconverter.h"
#include "baseaccuracy.h"
#include "basepower.h"
#include "../clientelements/gui.h"
#include "../type/effectiveness.h"
#include "pp.h"

namespace artificialtrainer {
namespace {
double ChanceToHit(const std::shared_ptr<Pokemon> &attacker,
                   const std::shared_ptr<Pokemon> &defender) {
  std::shared_ptr<Move> move_used = attacker->MoveUsed();

  if (BaseAccuracy(move_used->MoveName()) == kNeverMiss) {
    return (move_used->MoveName() == MoveNames::kSwift ? 255.0 / 256.0 : 100.0);
  }

  ExclusiveInGameStatsContainer attacker_stats =
      attacker->GetExclusiveInGameStatsContainer();
  ExclusiveInGameStatsContainer defender_stats =
      defender->GetExclusiveInGameStatsContainer();
  double chance = static_cast<double>(BaseAccuracy(move_used->MoveName())) *
      (attacker_stats[StatNames::kAccuracy]->CalculatedStat() /
          defender_stats[StatNames::kEvasion]->CalculatedStat());

  return chance > 100.0 ? 100.0 : chance;
}

double TypeProduct(const std::shared_ptr<Move> &move_used,
                   const std::shared_ptr<Pokemon> &defender) {
  TypeNames move_type = Type(move_used->MoveName());
  TypeContainer defender_types = defender->GetTypeContainer();
  return Effectiveness(move_type, defender_types.FirstType()) *
      Effectiveness(move_type, defender_types.SecondType()) * 10;
}

bool MoveCrit(const double &crit_chance) {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_real_distribution<> distribution(0.0, 1.0);
  return distribution(generator) <= crit_chance;
}

bool MoveHit(const double &chance_to_hit) {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_real_distribution<> distribution(1.0, 100.0);
  return distribution(generator) <= chance_to_hit;
}

bool VariableEffectActivates(const MoveNames &move_name) {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<> distribution(1, 100);
  return distribution(generator) <= VariableEffectChance(move_name);
}

int DamageRandomFactor() {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<> distribution(217, 255);
  return distribution(generator);
}

double StabBonus(const std::shared_ptr<Pokemon> &attacker) {
  return ((attacker->GetTypeContainer().MoveMatchesType(
      attacker->MoveUsed()->MoveName())) ? 1.5 : 1.0);
}

double CriticalHitChance(const std::shared_ptr<Pokemon> &attacker) {
  MoveNames move_used_name = attacker->MoveUsed()->MoveName();
  double attacker_base_speed = static_cast<double>(
      attacker->GetNormalStatsContainer()[StatNames::kSpeed]->BaseStat());

  if (HasHighCriticalHitRatio(move_used_name) && attacker->UsedFocusEnergy()) {
    return attacker_base_speed / 256;
  }

  if (HasHighCriticalHitRatio(move_used_name)) {
    return attacker_base_speed / 64;
  }

  if (attacker->UsedFocusEnergy()) {
    return attacker_base_speed / 2048;
  }

  return attacker_base_speed / 512;
}

std::pair<int, int> AttackAndDefenseUsed(
    const std::shared_ptr<Pokemon> &attacker,
    const std::shared_ptr<Pokemon> &defender,
    const bool &move_crit) {
  MoveNames move_used_name = attacker->MoveUsed()->MoveName();
  NormalStatsContainer attacker_stats = attacker->GetNormalStatsContainer();
  NormalStatsContainer defender_stats = defender->GetNormalStatsContainer();
  std::shared_ptr<NormalStat> attack;
  std::shared_ptr<NormalStat> defense;

  if (IsPhysical(move_used_name)) {
    attack = attacker_stats[StatNames::kAttack];
    defense = defender_stats[StatNames::kDefense];
  } else {
    attack = attacker_stats[StatNames::kSpecial];
    defense = defender_stats[StatNames::kSpecial];
  }

  if (move_crit) {
    return std::make_pair(attack->InitialStat(), defense->InitialStat());
  }

  return std::make_pair(attack->InGameStat(), defense->InGameStat());
}

int DamageDone(const std::shared_ptr<Pokemon> &attacker,
               const std::shared_ptr<Pokemon> &defender,
               const bool &self_ko_move) {
  std::shared_ptr<Move> move_used = attacker->MoveUsed();

  if (!BasePower(move_used->MoveName())) {
    return 0;
  }

  double type_product = TypeProduct(move_used, defender);

  if (!static_cast<int>(type_product) ||
      (move_used->MoveName() == MoveNames::kLick &&
          defender->IsTyoe(TypeNames::kPsychic))) {
    Gui::DisplayMoveHadNoEffectMessage();
    return 0;
  }

  if (type_product < 10.0) {
    Gui::DisplayNotVeryEffectiveMessage();
  } else if (type_product > 10.0) {
    Gui::DisplaySuperEffectiveMessage();
  }

  bool move_crit = IsDamaging(move_used->MoveName())
                   ? MoveCrit(CriticalHitChance(attacker)) : false;
  std::pair<int, int> used_stats = AttackAndDefenseUsed(attacker, defender,
                                                        move_crit);

  if (move_crit) {
    Gui::DisplayMoveCritMessage();
  }

  return static_cast<int>(floor(((((((((2.0 * (move_crit ? 2 : 1) *
      attacker->Level() / 5 + 2) * used_stats.first * BasePower(
      move_used->MoveName()) * (self_ko_move ? 2 : 1) / used_stats.second) /
      50) + 2) * StabBonus(attacker)) * type_product / 10) *
      DamageRandomFactor()) / 255)));
}

void UseCounter(const std::shared_ptr<Pokemon> &attacker,
                const std::shared_ptr<Pokemon> &defender) {
  if (!static_cast<int>(TypeProduct(attacker->MoveUsed(), defender))) {
    Gui::DisplayMoveHadNoEffectMessage();
    return;
  }

  MoveNames defender_move_name = defender->MoveUsed()->MoveName();
  TypeNames defender_move_type = Type(defender_move_name);

  if (!IsPhysical(defender_move_name) || !IsDamaging(defender_move_name) ||
      (defender_move_type != TypeNames::kNormal &&
          defender_move_type != TypeNames::kFighting)) {
    Gui::DisplayMoveFailedMessage();
    return;
  }

  int damage_done = defender->MoveUsed()->DamageDone() << 1;
  defender->GetNormalStatsContainer().HpStat()->SubtractHp(damage_done);
  Gui::DisplayDamageDoneMessage(damage_done);
}

void UseOneHitKoMove(const std::shared_ptr<Pokemon> &attacker,
                     const std::shared_ptr<Pokemon> &defender,
                     const int &damage_done) {
  // in this case, damage done is damage that would have been done. if it's
  // 0, the move didn't affect the target
  int attacker_speed =
      attacker->GetNormalStatsContainer()[StatNames::kSpeed]->InGameStat();
  int defender_speed =
      defender->GetNormalStatsContainer()[StatNames::kSpeed]->InGameStat();

  if (attacker->Level() < defender->Level() ||
      attacker_speed < defender_speed || !damage_done) {
    Gui::DisplayMoveFailedMessage();
    return;
  }

  defender->AutoFaint();
  Gui::DisplayOneHitKoMoveLandedMessage();
}

void DoSideEffect(const std::shared_ptr<Pokemon> &attacker,
                  const std::shared_ptr<Pokemon> &defender,
                  const int &damage_done, const bool &move_hit) {
  MoveNames move_name = attacker->MoveUsed()->MoveName();

  if (!HasSideEffectIfMissed(move_name) && !move_hit) {
    return;
  }

  switch (move_name) {
    case MoveNames::kAbsorb:
    case MoveNames::kMegaDrain:
    case MoveNames::kLeechLife:
      attacker->AbsorbHp(damage_done);
      break;
    case MoveNames::kAcid:
    case MoveNames::kPsychic:
      if (VariableEffectActivates(move_name)) {
        defender->ChangeStat(StatNames::kSpecial, -1);
      }

      break;
    case MoveNames::kBarrier:
    case MoveNames::kAcidArmor:
      attacker->ChangeStat(StatNames::kDefense, 2);
      break;
    case MoveNames::kAgility:
      attacker->ChangeStat(StatNames::kSpeed, 2);
      break;
    case MoveNames::kBite:
    case MoveNames::kBoneClub:
    case MoveNames::kHeadbutt:
    case MoveNames::kHyperFang:
    case MoveNames::kLowKick:
    case MoveNames::kRollingKick:
    case MoveNames::kStomp:
      if (VariableEffectActivates(move_name)) {
        defender->SetFlinched(true);
      }

      break;
    case MoveNames::kAmnesia:
      attacker->ChangeStat(StatNames::kSpeed, 2);
      break;
    case MoveNames::kAuroraBeam:
      defender->ChangeStat(StatNames::kAttack, -1);
      break;
    case MoveNames::kBide:
      // use bide
      break;
    case MoveNames::kBind:
    case MoveNames::kClamp:
    case MoveNames::kFireSpin:
    case MoveNames::kWrap:
      // trap defender
      break;
    case MoveNames::kBlizzard:
    case MoveNames::kIcePunch:
    case MoveNames::kIceBeam:
      // variable freeze defender
      break;
    case MoveNames::kBodySlam:
    case MoveNames::kLick:
    case MoveNames::kThunder:
    case MoveNames::kThunderbolt:
    case MoveNames::kThunderShock:
      // variable paralyze defender
      break;
    case MoveNames::kBubble:
    case MoveNames::kBubbleBeam:
    case MoveNames::kConstrict:
      defender->ChangeStat(StatNames::kSpeed, -1);
      break;
    case MoveNames::kConfuseRay:
    case MoveNames::kSupersonic:
      if (!defender->IsConfused()) {
        defender->Confuse();
        Gui::DisplayConfusionStartedMessage(defender->SpeciesName());
      }

      break;
    case MoveNames::kConfusion:
    case MoveNames::kPsybeam:
      if (VariableEffectActivates(move_name)) {
        if (!defender->IsConfused()) {
          defender->Confuse();
          Gui::DisplayConfusionStartedMessage(defender->SpeciesName());
        }
      }

      break;
    case MoveNames::kConversion:
      attacker->UseConversion();
      break;
    case MoveNames::kCounter:
      UseCounter(attacker, defender);
      break;
    case MoveNames::kDefenseCurl:
    case MoveNames::kHarden:
    case MoveNames::kWithdraw:
      attacker->ChangeStat(StatNames::kDefense, 1);
      break;
    case MoveNames::kDig:
    case MoveNames::kFly:
      // use vanish move
      break;
    case MoveNames::kDisable:
      if (!defender->HasMoveDisabled()) {
        defender->DisableMove();
      }

      break;
    case MoveNames::kDoubleTeam:
    case MoveNames::kMinimize:
      attacker->ChangeStat(StatNames::kEvasion, -1);
      break;
    case MoveNames::kDoubleEdge:
    case MoveNames::kTakeDown:
    case MoveNames::kSubmission:
      attacker->TakeRecoilDamage(damage_done);
      break;
    case MoveNames::kDragonRage:
      defender->GetNormalStatsContainer().HpStat()->SubtractHp(40);
      break;
    case MoveNames::kDreamEater:
      // if defender is sleeping, absorb hp
      break;
    case MoveNames::kExplosion:
    case MoveNames::kSelfDestruct:
      // if defender is behind sub, attacker will not faint self
      attacker->AutoFaint();
      break;
    case MoveNames::kFissure:
    case MoveNames::kGuillotine:
    case MoveNames::kHornDrill:
      UseOneHitKoMove(attacker, defender, damage_done);
      break;
    case MoveNames::kFlash:
    case MoveNames::kKinesis:
    case MoveNames::kSmokescreen:
    case MoveNames::kSandAttack:
      defender->ChangeStat(StatNames::kAccuracy, -1);
      break;
    case MoveNames::kFocusEnergy:
      attacker->SetUsedFocusEnergy(true);
      break;
    case MoveNames::kGlare:
    case MoveNames::kStunSpore:
    case MoveNames::kThunderWave:
      // paralyze the target
      break;
    case MoveNames::kGrowl:
      defender->ChangeStat(StatNames::kAttack, -1);
      break;
    case MoveNames::kGrowth:
      attacker->ChangeStat(StatNames::kSpecial, 1);
      break;
    case MoveNames::kHaze:
      // haze the field
      break;
    case MoveNames::kHighJumpKick:
    case MoveNames::kJumpKick:
      if (!move_hit || !damage_done) {
        attacker->GetNormalStatsContainer().HpStat()->SubtractHp(1);
        Gui::DisplayRecoilDamageMessage(attacker->SpeciesName(), 1);
      }

      break;
    case MoveNames::kHyperBeam:
      // recharge
      break;
    case MoveNames::kHypnosis:
    case MoveNames::kLovelyKiss:
    case MoveNames::kSing:
    case MoveNames::kSleepPowder:
    case MoveNames::kSpore:
      // put target to sleep
      break;
    case MoveNames::kLeechSeed:
      // use leech seed
      break;
    case MoveNames::kLeer:
    case MoveNames::kTailWhip:
      defender->ChangeStat(StatNames::kDefense, -1);
      break;
    case MoveNames::kLightScreen:
      // set up light screen
      break;
    case MoveNames::kMeditate:
    case MoveNames::kSharpen:
      attacker->ChangeStat(StatNames::kAttack, 1);
      break;
    default:
      break;
  }
}

void DoDamage(const std::shared_ptr<Pokemon> &defender,
              const int &damage_done) {
  defender->GetNormalStatsContainer().HpStat()->SubtractHp(damage_done);
  Gui::DisplayDamageDoneMessage(damage_done);
}

bool IsGoodToMove(const std::shared_ptr<Pokemon> &attacker,
                  const std::shared_ptr<Pokemon> &defender) {
  if (!attacker->GetNormalStatsContainer().HpStat()->CurrentHp() ||
      !defender->GetNormalStatsContainer().HpStat()->CurrentHp()) {
    return false;
  }

  if (attacker->IsFlinched()) {
    Gui::DisplayFlinchedMessage(attacker->SpeciesName());
    return false;
  }

  if (!attacker->HandleConfusion()) {
    attacker->SetMoveUsed(std::make_shared<Move>(
        MoveNames::kHitSelf, Pp(MoveNames::kHitSelf)));
    DoDamage(attacker, DamageDone(attacker, attacker, false));
    return false;
  }

  if (attacker->MoveUsed()->IsDisabled()) {
    Gui::DisplayMoveDisabledMessage(attacker->MoveUsed()->MoveName());
    return false;
  }

  // SLEEP, FROZEN: RETURN FALSE
  // FLINCHED: RETURN FALSE
  // FULLY PARA: RETURN FALSE
  // HIT SELF: RETURN FALSE
  // IS LOCKED IN TO CLAMP, BIND, ETC
  // DISABLED

  return true;
}

void HardSwitch(Team &attacker) {
  std::shared_ptr<Pokemon> old_active_member = attacker.ActiveMember();
  attacker.HardSwitch();
  Gui::DisplaySwitchMessage(old_active_member->SpeciesName(),
                            attacker.ActiveMember()->SpeciesName());
}

void ExecuteMove(const std::shared_ptr<Pokemon> &attacker,
                 const std::shared_ptr<Pokemon> &defender,
                 const bool &move_hit) {
  std::shared_ptr<Move> move_used = attacker->MoveUsed();

  // have to call recursively for moves that hit multiple times in one turn
  // maybe ?

  int damage_done = IsSelfKo(move_used->MoveName()) ?
                    DamageDone(attacker,
                               defender,
                               true) :
                    DamageDone(attacker,
                               defender,
                               false);

  if (damage_done && move_hit) {
    move_used->SetDamageDone(damage_done);
    DoDamage(defender, damage_done);
  }

  DoSideEffect(attacker, defender, damage_done, move_hit);
}

} //namespace

void UseMove(Team &attacker, Team &defender) {
  std::shared_ptr<Pokemon> attacking_member = attacker.ActiveMember();
  std::shared_ptr<Pokemon> defending_member = defender.ActiveMember();

  if (IsSwitch(attacking_member->MoveUsed()->MoveName())) {
    HardSwitch(attacker);
    return;
  }

  if (!IsGoodToMove(attacking_member, defending_member)) {
    return;
  }

  attacking_member->HandleDisable();
  defending_member->HandleDisable();
  std::shared_ptr<Move> move_used = attacking_member->MoveUsed();
  attacking_member->MoveUsed()->DecrementPp(1);
  Gui::DisplayPokemonUsedMoveMessage(attacking_member->SpeciesName(),
                                     move_used->MoveName());
  bool move_hit = MoveHit(ChanceToHit(attacking_member, defending_member));

  if (!move_hit) {
    Gui::DisplayMoveMissedMessage();
  }

  // have to handle metronome separately as well
  if (move_used->MoveName() == MoveNames::kMetronome) {
    attacking_member->UseMetronome();
  }

  ExecuteMove(attacking_member, defending_member, move_hit);
}

} //namespace artificialtrainer