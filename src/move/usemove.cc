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

int DamageRandomFactor() {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<> distribution(217, 255);
  return distribution(generator);
}

double DamageBonus(const std::shared_ptr<Pokemon> &attacker) {
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
               const bool &move_crit) {
  std::pair<int, int> used_stats = AttackAndDefenseUsed(attacker, defender,
                                                        move_crit);
  std::shared_ptr<Move> move_used = attacker->MoveUsed();
  double type_product = TypeProduct(move_used, defender);

  if (!static_cast<int>(type_product)) {
    Gui::DisplayMoveHadNoEffectMessage();
  } else if (type_product < 10.0) {
    Gui::DisplayNotVeryEffectiveMessage();
  } else if (type_product > 10.0) {
    Gui::DisplaySuperEffectiveMessage();
  }

  return static_cast<int>(floor(((((((((2.0 * (move_crit ? 2 : 1) *
      attacker->Level() / 5 + 2) * used_stats.first * BasePower(
      move_used->MoveName()) / used_stats.second) / 50) + 2) *
      DamageBonus(attacker)) * type_product / 10) * DamageRandomFactor()) /
      255)));
}

bool DoDamage(const std::shared_ptr<Pokemon> &attacker,
              const std::shared_ptr<Pokemon> &defender) {
  NormalStatsContainer attacker_stats = attacker->GetNormalStatsContainer();
  NormalStatsContainer defender_stats = defender->GetNormalStatsContainer();
  std::shared_ptr<Move> move_used = attacker->MoveUsed();
  move_used->DecrementPp(1);

  if (IsUseless(move_used->MoveName())) {
    Gui::DisplayMoveHadNoEffectMessage();
    return false;
  }

  if (!MoveHit(ChanceToHit(attacker, defender))) {
    Gui::DisplayMoveMissedMessage();
    return false;
  }

  bool move_crit = false;
  double crit_chance = CriticalHitChance(attacker);

  if (MoveCrit(crit_chance > 255.0 / 256.0 ? 255.0 / 256.0 : crit_chance)) {
    move_crit = true;
    Gui::DisplayMoveCritMessage();
  }

  int damage_done = DamageDone(attacker, defender, move_crit);
  defender->GetNormalStatsContainer().HpStat()->SubtractHp(damage_done);
  Gui::DisplayDamageDoneMessage(damage_done);
  return true;
}

bool VariableEffectActivates(const MoveNames &move_name) {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<> distribution(1, 100);
  return distribution(generator) <= VariableEffectChance(move_name);
}

void HandleVariableEffect(const MoveNames &move_name,
                          const std::shared_ptr<Pokemon> &defender) {
  switch (move_name) {
    case MoveNames::kAcid:
      defender->ChangeStat(StatNames::kDefense, -1);
      break;
    case MoveNames::kAuroraBeam:
      defender->ChangeStat(StatNames::kAttack, -1);
      break;
    case MoveNames::kBite:
      // SET FLINCH FLAG
      break;
    case MoveNames::kBlizzard:
      // FREEZE
      break;
    case MoveNames::kBoneClub:
      // SET FLINCH FLAG
      break;
    case MoveNames::kBubbleBeam:
    case MoveNames::kBubble:
      defender->ChangeStat(StatNames::kSpeed, -1);
      break;
    case MoveNames::kConfusion:
      // CONFUSE
      break;
    case MoveNames::kConstrict:
      defender->ChangeStat(StatNames::kSpeed, -1);
      break;
    default:
      break;
  }
}

void UseDamagingMove(const std::shared_ptr<Pokemon> &attacker,
                     const std::shared_ptr<Pokemon> &defender) {
  if (DoDamage(attacker, defender)) {
    if (VariableEffectActivates(attacker->MoveUsed()->MoveName())) {
      HandleVariableEffect(attacker->MoveUsed()->MoveName(), defender);
    }
  }
}

void HardSwitch(Team &attacker) {
  std::shared_ptr<Pokemon> old_active_member = attacker.ActiveMember();
  attacker.HardSwitch();
  Gui::DisplaySwitchMessage(old_active_member->SpeciesName(),
                            attacker.ActiveMember()->SpeciesName());
}

void UseChangeStatMove(const std::shared_ptr<Pokemon> &attacker,
                       const std::shared_ptr<Pokemon> &defender) {
  std::shared_ptr<Move> move_used = attacker->MoveUsed();
  move_used->DecrementPp(1);

  if (!MoveHit(ChanceToHit(attacker, defender))) {
    Gui::DisplayMoveMissedMessage();
    return;
  }

  switch (move_used->MoveName()) {
    case MoveNames::kAcidArmor:
    case MoveNames::kBarrier:
      attacker->ChangeStat(StatNames::kDefense, 2);
      break;
    case MoveNames::kAgility:
      attacker->ChangeStat(StatNames::kSpeed, 2);
      break;
    case MoveNames::kAmnesia:
      attacker->ChangeStat(StatNames::kSpecial, 2);
      break;
    case MoveNames::kGrowth:
      attacker->ChangeStat(StatNames::kSpecial, 1);
      break;
    case MoveNames::kDefenseCurl:
    case MoveNames::kHarden:
    case MoveNames::kWithdraw:
      attacker->ChangeStat(StatNames::kDefense, 1);
      break;
    case MoveNames::kDoubleTeam:
    case MoveNames::kMinimize:
      attacker->ChangeStat(StatNames::kEvasion, -1);
      break;
    case MoveNames::kMeditate:
    case MoveNames::kSharpen:
      attacker->ChangeStat(StatNames::kAttack, 1);
      break;
    case MoveNames::kSwordsDance:
      attacker->ChangeStat(StatNames::kAttack, 2);
      break;
    case MoveNames::kFlash:
    case MoveNames::kKinesis:
    case MoveNames::kSmokescreen:
    case MoveNames::kSandAttack:
      defender->ChangeStat(StatNames::kAccuracy, -1);
      break;
    case MoveNames::kGrowl:
      defender->ChangeStat(StatNames::kAttack, -1);
      break;
    case MoveNames::kLeer:
    case MoveNames::kTailWhip:
      defender->ChangeStat(StatNames::kDefense, -1);
      break;
    case MoveNames::kScreech:
      defender->ChangeStat(StatNames::kDefense, -2);
      break;
    case MoveNames::kStringShot:
      defender->ChangeStat(StatNames::kSpeed, -1);
      break;
    default:
      assert(false);
  }
}

void UseOneHitKoMove(const std::shared_ptr<Pokemon> &attacker,
                     const std::shared_ptr<Pokemon> &defender,
                     Team &defender_team) {
  int attacker_speed =
      attacker->GetNormalStatsContainer()[StatNames::kSpeed]->InGameStat();
  int defender_speed =
      defender->GetNormalStatsContainer()[StatNames::kSpeed]->InGameStat();

  if ((attacker->Level() < defender->Level()) ||
      (attacker_speed < defender_speed) ||
      (!static_cast<bool>(TypeProduct(attacker->MoveUsed(), defender)))) {
    Gui::DisplayMoveFailedMessage();
    return;
  }

  attacker->MoveUsed()->DecrementPp(1);

  if (!MoveHit(ChanceToHit(attacker, defender))) {
    Gui::DisplayMoveMissedMessage();
    return;
  }

  int defender_hp = defender->GetNormalStatsContainer().HpStat()->CurrentHp();
  defender->GetNormalStatsContainer().HpStat()->SubtractHp(defender_hp);
  Gui::DisplayOneHitKoMoveLandedMessage();
  Gui::DisplayPokemonFaintedMessage(defender->SpeciesName());
}

void UseSelfKoMove(const std::shared_ptr<Pokemon> &attacker,
                   const std::shared_ptr<Pokemon> &defender) {
  if (!static_cast<bool>(TypeProduct(attacker->MoveUsed(), defender))) {
    Gui::DisplayMoveFailedMessage();
    return;
  }

  attacker->MoveUsed()->DecrementPp(1);

  if (!MoveHit(ChanceToHit(attacker, defender))) {
    Gui::DisplayMoveMissedMessage();
    return;
  }

  bool move_crit = false;
  double crit_chance = CriticalHitChance(attacker);

  if (MoveCrit(crit_chance > 255.0 / 256.0 ? 255.0 / 256.0 : crit_chance)) {
    move_crit = true;
    Gui::DisplayMoveCritMessage();
  }

  int damage_done = DamageDone(attacker, defender, move_crit);
  defender->GetNormalStatsContainer().HpStat()->SubtractHp(damage_done);
  Gui::DisplayDamageDoneMessage(damage_done);
  int attacker_hp = attacker->GetNormalStatsContainer().HpStat()->CurrentHp();
  attacker->GetNormalStatsContainer().HpStat()->SubtractHp(attacker_hp);
  Gui::DisplayPokemonFaintedMessage(attacker->SpeciesName());
}

} //namespace

void UseMove(Team &attacker, Team &defender) {
  std::shared_ptr<Pokemon> attacking_member = attacker.ActiveMember();
  std::shared_ptr<Pokemon> defending_member = defender.ActiveMember();

  if (!attacking_member->GetNormalStatsContainer().HpStat()->CurrentHp()) {
    return;
  }

  if (!defending_member->GetNormalStatsContainer().HpStat()->CurrentHp()) {
    Gui::DisplayMoveFailedMessage();
    return;
  }

  MoveNames move_used_name = attacker.ActiveMember()->MoveUsed()->MoveName();
  Gui::DisplayPokemonUsedMoveMessage(attacking_member);

  if (IsSwitch(move_used_name)) {
    HardSwitch(attacker);
  } else if (OnlyChangesStat(move_used_name)) {
    UseChangeStatMove(attacking_member, defending_member);
  } else if (IsOneHitKo(move_used_name)) {
    UseOneHitKoMove(attacking_member, defending_member, defender);
  } else if (IsSelfKoMove(move_used_name)) {
    UseSelfKoMove(attacking_member, defending_member);
  } else if (IsDamaging(move_used_name)) {
    UseDamagingMove(attacking_member, defending_member);
  }

  // if someone faints, the other user doesn't get to make a move, unless
  // it's a switch or pass.
  // if user uses recharge move, but defender faints, doesn't recharge
}

} //namespace artificialtrainer