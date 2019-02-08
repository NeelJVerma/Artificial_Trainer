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

auto DoOneHitKoMove(const std::shared_ptr<Pokemon> &attacker,
                    const std::shared_ptr<Pokemon> &defender) {
  int attacker_speed =
      attacker->GetNormalStatsContainer()[StatNames::kSpeed]->InGameStat();
  int defender_speed =
      defender->GetNormalStatsContainer()[StatNames::kSpeed]->InGameStat();

  if ((attacker->Level() < defender->Level()) ||
      (attacker_speed < defender_speed)) {
    Gui::DisplayMoveFailedMessage();
    return;
  }

  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_real_distribution<> distribution(1.0, 100.0);
  attacker->MoveUsed()->DecrementPp(1);

  if (distribution(generator) > CalculateChanceToHit(attacker, defender)) {
    Gui::DisplayMoveMissedMessage();
    return;
  }

  int defender_hp = defender->GetNormalStatsContainer().HpStat()->CurrentHp();
  defender->GetNormalStatsContainer().HpStat()->SubtractHp(defender_hp);
  Gui::DisplayOneHitKoMoveLandedMessage();
  Gui::DisplayPokemonFaintedMessage(defender->SpeciesName());
}

auto DoDamage(const std::shared_ptr<Pokemon> &attacker,
              const std::shared_ptr<Pokemon> &defender) -> void {

}

} //namespace

auto UseMove(std::shared_ptr<Pokemon> attacker,
             std::shared_ptr<Pokemon> defender) -> MoveResults {
  if (attacker->GetNormalStatsContainer().HpStat()->CurrentHp()) {
    Gui::DisplayPokemonUsedMoveMessage(attacker);
  }

  if (static_cast<PowerClasses>(BasePower(attacker->MoveUsed()->MoveName())) ==
      PowerClasses::kOneHitKo) {
    DoOneHitKoMove(attacker, defender);

    if (!defender->GetNormalStatsContainer().HpStat()->CurrentHp()) {
      return MoveResults::kDefenderFainted;
    }
  }
}

} //namespace artificialtrainer