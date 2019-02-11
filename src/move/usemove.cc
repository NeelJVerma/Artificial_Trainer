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
auto CalculateChanceToHit(const std::shared_ptr<Pokemon> &attacker,
                          const std::shared_ptr<Pokemon> &defender) -> double {
  std::shared_ptr<Move> move_used = attacker->MoveUsed();

  if (BaseAccuracy(move_used->MoveName()) == kNeverMiss) {
    return (move_used->MoveName() == MoveNames::kSwift ? 255 / 256 : 100.0);
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

auto TypeProduct(const std::shared_ptr<Move> &move_used,
                 const std::shared_ptr<Pokemon> &defender) -> double {
  TypeNames move_type = Type(move_used->MoveName());
  TypeContainer defender_types = defender->GetTypeContainer();
  return Effectiveness(move_type, defender_types.FirstType()) *
      Effectiveness(move_type, defender_types.SecondType());
}

auto MoveCrit(const double &crit_chance) {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_real_distribution<> distribution(0.0, 1.0);
  return distribution(generator) <= crit_chance;
}

auto MoveHit(const double &chance_to_hit) -> bool {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_real_distribution<> distribution(1.0, 100.0);
  return distribution(generator) <= chance_to_hit;
}

auto DamageRandomFactor() -> int {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<> distribution(217, 255);
  return distribution(generator);
}

auto DamageBonus(const std::shared_ptr<Pokemon> &attacker,
                 const std::shared_ptr<Pokemon> &defender) -> double {
  std::shared_ptr<Move> move_used = attacker->MoveUsed();
  return ((attacker->GetTypeContainer().MoveMatchesType(
      move_used->MoveName())) ? 1.5 : 1.0) * TypeProduct(move_used, defender);
}

auto DoDamage(const std::shared_ptr<Pokemon> &attacker,
              const std::shared_ptr<Pokemon> &defender) -> void {
  NormalStatsContainer attacker_stats = attacker->GetNormalStatsContainer();
  NormalStatsContainer defender_stats = defender->GetNormalStatsContainer();
  ExclusiveInGameStatsContainer ex_attacker_stats =
      attacker->GetExclusiveInGameStatsContainer();
  ExclusiveInGameStatsContainer ex_defender_stats =
      defender->GetExclusiveInGameStatsContainer();
  std::shared_ptr<Move> move_used = attacker->MoveUsed();
  attacker->MoveUsed()->DecrementPp(1);

  if (IsUseless(move_used->MoveName())) {
    Gui::DisplayMoveHadNoEffectMessage();
    return;
  }

  if (!MoveHit(CalculateChanceToHit(attacker, defender))) {
    Gui::DisplayMoveMissedMessage();
    return;
  }

  double crit_chance;
  double attacker_base_speed =
      static_cast<double>(attacker_stats[StatNames::kSpeed]->BaseStat());

  if (HasHighCriticalHitRatio(move_used->MoveName()) &&
      attacker->UsedFocusEnergy()) {
    crit_chance = attacker_base_speed / 256;
  } else if (HasHighCriticalHitRatio(move_used->MoveName())) {
    crit_chance = attacker_base_speed / 64;
  } else if (attacker->UsedFocusEnergy()) {
    crit_chance = attacker_base_speed / 2048;
  } else {
    crit_chance = attacker_base_speed / 512;
  }

  bool move_crit = false;

  if (MoveCrit(crit_chance > 255.0 / 256.0 ? 255.0 / 256.0 : crit_chance)) {
    move_crit = true;
    Gui::DisplayMoveCritMessage();
  }

  std::shared_ptr<NormalStat> attack;
  std::shared_ptr<NormalStat> defense;

  if (IsPhysical(move_used->MoveName())) {
    attack = attacker_stats[StatNames::kAttack];
    defense = defender_stats[StatNames::kDefense];
  } else {
    attack = attacker_stats[StatNames::kSpecial];
    defense = defender_stats[StatNames::kSpecial];
  }

  int calculated_attack;
  int calculated_defense;

  if (move_crit) {
    calculated_attack = attack->InitialStat();
    calculated_defense = defense->InitialStat();
  } else {
    calculated_attack = attack->InGameStat();
    calculated_defense = defense->InGameStat();
  }

  int damage_done = static_cast<int>(floor((((((((((static_cast<double>(
      attacker->Level()) * (move_crit ? 2 : 1) * 2 / 5))) + 2 *
      static_cast<double>(calculated_attack) * BasePower(
      move_used->MoveName()) / calculated_defense) / 50)) + 2) *
      DamageBonus(attacker, defender)) * DamageRandomFactor() / 255)));
  int defender_hp = defender->GetNormalStatsContainer().HpStat()->CurrentHp();
  defender->GetNormalStatsContainer().HpStat()->SubtractHp(
      defender_hp - damage_done < 0 ? defender_hp : damage_done);
  Gui::DisplayDamageDoneMessage(damage_done);
}

auto HardSwitch(Team &attacker) -> void {
  std::shared_ptr<Pokemon> old_active_member = attacker.ActiveMember();
  attacker.HardSwitch();
  Gui::DisplaySwitchMessage(old_active_member->SpeciesName(),
                            attacker.ActiveMember()->SpeciesName());
}

auto UseChangeStatMove(const std::shared_ptr<Pokemon> &attacker,
                       const std::shared_ptr<Pokemon> &defender) -> void {
  std::shared_ptr<Move> move_used = attacker->MoveUsed();
  move_used->DecrementPp(1);

  if (!MoveHit(CalculateChanceToHit(attacker, defender))) {
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

auto DoOneHitKoMove(const std::shared_ptr<Pokemon> &attacker,
                    const std::shared_ptr<Pokemon> &defender,
                    Team &defender_team) -> void {
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

  if (!MoveHit(CalculateChanceToHit(attacker, defender))) {
    Gui::DisplayMoveMissedMessage();
    return;
  }

  int defender_hp = defender->GetNormalStatsContainer().HpStat()->CurrentHp();
  defender->GetNormalStatsContainer().HpStat()->SubtractHp(defender_hp);
  Gui::DisplayOneHitKoMoveLandedMessage();
  Gui::DisplayPokemonFaintedMessage(defender->SpeciesName());
}

} //namespace

auto UseMove(Team &attacker, Team &defender) -> void {
  std::shared_ptr<Pokemon> attacking_member = attacker.ActiveMember();
  std::shared_ptr<Pokemon> defending_member = defender.ActiveMember();

  // TODO: TEST THIS
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
    DoOneHitKoMove(attacking_member, defending_member, defender);
  } else if (IsDamaging(move_used_name)) {
    DoDamage(attacking_member, defending_member);
    // TODO: HANDLE SIDE EFFECT, WRAP IT IN A FUNCTION
  }

  // if someone faints, the other user doesn't get to make a move, unless
  // it's a switch or pass.
  // if user uses recharge move, but defender faints, doesn't recharge
}

} //namespace artificialtrainer