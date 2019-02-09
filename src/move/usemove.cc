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

auto Switch(Team &attacker) -> void {
  std::shared_ptr<Pokemon> old_active_pokemon = attacker.ActiveMember();
  int switch_index = static_cast<int>(
      old_active_pokemon->MoveUsed()->MoveName()) - static_cast<int>(
      MoveNames::kSwitch1);
  old_active_pokemon->SetIsActive(false);
  old_active_pokemon->ResetStats();
  attacker.ActiveTeam()[switch_index]->SetIsActive(true);
  attacker.SetActiveMember(switch_index);
  Gui::DisplaySwitchMessage(old_active_pokemon->SpeciesName(),
                            attacker.ActiveMember()->SpeciesName());
}

auto MoveHit(const double &chance_to_hit) -> bool {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_real_distribution<> distribution(1.0, 100.0);
  return distribution(generator) <= chance_to_hit;
}

auto UseChangeStatMove(Team &attacker, Team &defender) -> void {
  std::shared_ptr<Pokemon> attacking_member = attacker.ActiveMember();
  std::shared_ptr<Pokemon> defending_member = defender.ActiveMember();
  std::shared_ptr<Move> move_used = attacking_member->MoveUsed();
  move_used->DecrementPp(1);

  if (!MoveHit(CalculateChanceToHit(attacker.ActiveMember(),
                                    defender.ActiveMember()))) {
    Gui::DisplayMoveMissedMessage();
    return;
  }

  switch (move_used->MoveName()) {
    case MoveNames::kAcidArmor:
    case MoveNames::kBarrier:
      attacking_member->ChangeStat(StatNames::kDefense, 2);
      break;
    case MoveNames::kAgility:
      attacking_member->ChangeStat(StatNames::kSpeed, 2);
      break;
    case MoveNames::kAmnesia:
      attacking_member->ChangeStat(StatNames::kSpecial, 2);
      break;
    case MoveNames::kGrowth:
      attacking_member->ChangeStat(StatNames::kSpecial, 1);
      break;
    case MoveNames::kDefenseCurl:
    case MoveNames::kHarden:
    case MoveNames::kWithdraw:
      attacking_member->ChangeStat(StatNames::kDefense, 1);
      break;
    case MoveNames::kDoubleTeam:
    case MoveNames::kMinimize:
      attacking_member->ChangeStat(StatNames::kEvasion, -1);
      break;
    case MoveNames::kMeditate:
    case MoveNames::kSharpen:
      attacking_member->ChangeStat(StatNames::kAttack, 1);
      break;
    case MoveNames::kSwordsDance:
      attacking_member->ChangeStat(StatNames::kAttack, 2);
      break;
    case MoveNames::kFlash:
    case MoveNames::kKinesis:
    case MoveNames::kSmokescreen:
    case MoveNames::kSandAttack:
      defending_member->ChangeStat(StatNames::kAccuracy, -1);
      break;
    case MoveNames::kGrowl:
      defending_member->ChangeStat(StatNames::kAttack, -1);
      break;
    case MoveNames::kLeer:
    case MoveNames::kTailWhip:
      defending_member->ChangeStat(StatNames::kDefense, -1);
      break;
    case MoveNames::kScreech:
      defending_member->ChangeStat(StatNames::kDefense, -2);
      break;
    case MoveNames::kStringShot:
      defending_member->ChangeStat(StatNames::kSpeed, -1);
      break;
    default:
      assert(false);
  }
}

} //namespace

auto UseMove(Team &attacker, Team &defender) -> void {
  MoveNames move_used_name = attacker.ActiveMember()->MoveUsed()->MoveName();

  if (IsSwitch(move_used_name)) {
    Switch(attacker);
  } else if (OnlyChangesStat(move_used_name)) {
    UseChangeStatMove(attacker, defender);
  }

  // if someone faints, the other user doesn't get to make a move, unless
  // it's a switch or pass.
  // if user uses recharge move, but defender faints, doesn't recharge
}

} //namespace artificialtrainer