//
// Created by neel on 2/6/19.
//

#include <iostream>
#include <cmath>
#include "usemove.h"
#include "../stringconverter/stringconverter.h"
#include "baseaccuracy.h"
#include "basepower.h"

namespace artificialtrainer {
namespace {
auto CalculateChanceToHit(const std::shared_ptr<Pokemon> &attacker,
                          const std::shared_ptr<Pokemon> &defender) -> double {
  std::shared_ptr<Move> move_used = attacker->MoveUsed();

  if (BaseAccuracy(move_used->MoveName()) == kNeverMiss) {
    return 100;
  }

  ExclusiveInGameStatsContainer attacker_stats =
      attacker->GetExclusiveInGameStatsContainer();
  ExclusiveInGameStatsContainer defender_stats =
      defender->GetExclusiveInGameStatsContainer();
  double chance = static_cast<double>(BaseAccuracy(move_used->MoveName())) *
      (attacker_stats[StatNames::kAccuracy]->CalculatedModifier() /
          defender_stats[StatNames::kEvasion]->CalculatedModifier());

  return (chance > 100 ? 100 : chance);
}

} //namespace

auto UseMove(std::shared_ptr<Pokemon> attacker,
             std::shared_ptr<Pokemon> defender) -> void {
}

} //namespace artificialtrainer