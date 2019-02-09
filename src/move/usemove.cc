//
// Created by neel on 2/6/19.
//

#include <cmath>
#include <random>
#include "usemove.h"
#include "../stringconverter/stringconverter.h"
#include "baseaccuracy.h"
#include "basepower.h"
#include "../clientelements/gui.h"

namespace artificialtrainer {
namespace {
auto CalculateChanceToHit(const std::shared_ptr<Pokemon> &attacker,
                          const std::shared_ptr<Pokemon> &defender) -> double {
  std::shared_ptr<Move> move_used = attacker->MoveUsed();

  if (BaseAccuracy(move_used->MoveName()) == kNeverMiss) {
    return (move_used->MoveName() == MoveNames::kSwift ? 255 / 256 : 100);
  }

  ExclusiveInGameStatsContainer attacker_stats =
      attacker->GetExclusiveInGameStatsContainer();
  ExclusiveInGameStatsContainer defender_stats =
      defender->GetExclusiveInGameStatsContainer();
  double chance = static_cast<double>(BaseAccuracy(move_used->MoveName())) *
      (attacker_stats[StatNames::kAccuracy]->CalculatedStat() /
          defender_stats[StatNames::kEvasion]->CalculatedStat());

  return (chance > 100 ? 100 : chance);
}

auto DoDamage(const std::shared_ptr<Pokemon> &attacker,
              const std::shared_ptr<Pokemon> &defender) -> void {

}

auto Switch(Team &attacker) -> void {
  std::shared_ptr<Pokemon> active_pokemon = attacker.ActiveMember();
  std::shared_ptr<Move> move = active_pokemon->MoveUsed();
  int switch_index = static_cast<int>(
      move->MoveName()) - static_cast<int>(MoveNames::kSwitch1);
  
}

} //namespace

auto UseMove(Team &attacker, Team &defender) -> MoveResults {
  Switch(attacker);
}

} //namespace artificialtrainer