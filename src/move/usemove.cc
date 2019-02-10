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

auto DoDamage(const std::shared_ptr<Pokemon> &attacker,
              const std::shared_ptr<Pokemon> &defender) -> void {

}

auto HardSwitch(Team &attacker) -> void {
  std::shared_ptr<Pokemon> old_active_member = attacker.ActiveMember();
  attacker.HardSwitch();
  Gui::DisplaySwitchMessage(old_active_member->SpeciesName(),
                            attacker.ActiveMember()->SpeciesName());
}

auto MoveHit(const double &chance_to_hit) -> bool {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_real_distribution<> distribution(1.0, 100.0);
  return distribution(generator) <= chance_to_hit;
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

  /*if (defender_team.ActiveTeam().size() > 1) {

  }*/
}

} //namespace

auto UseMove(Team &attacker, Team &defender) -> void {
  std::shared_ptr<Pokemon> attacking_member = attacker.ActiveMember();
  std::shared_ptr<Pokemon> defending_member = defender.ActiveMember();
  MoveNames move_used_name = attacker.ActiveMember()->MoveUsed()->MoveName();

  if (IsSwitch(move_used_name)) {
    HardSwitch(attacker);
  } else if (OnlyChangesStat(move_used_name)) {
    UseChangeStatMove(attacking_member, defending_member);
  } else if (IsOneHitKo(move_used_name)) {
    DoOneHitKoMove(attacking_member, defending_member, defender);
  }

  // if someone faints, the other user doesn't get to make a move, unless
  // it's a switch or pass.
  // if user uses recharge move, but defender faints, doesn't recharge
}

} //namespace artificialtrainer