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
  std::shared_ptr<Pokemon> old_active_pokemon = attacker.ActiveMember();
  int switch_index = static_cast<int>(
      old_active_pokemon->MoveUsed()->MoveName()) - static_cast<int>(
      MoveNames::kSwitch1);
  old_active_pokemon->SetIsActive(false);
  attacker.ActiveTeam()[switch_index]->SetIsActive(true);
  attacker.SetActiveMember(switch_index);
  Gui::DisplaySwitchMessage(old_active_pokemon->SpeciesName(),
                            attacker.ActiveMember()->SpeciesName());
}

} //namespace

auto UseMove(Team &attacker, Team &defender) -> MoveResults {
  int switch_beg = static_cast<int>(MoveNames::kSwitch1);
  int switch_end = static_cast<int>(MoveNames::kSwitch6);
  int selected = static_cast<int>(
      attacker.ActiveMember()->MoveUsed()->MoveName());

  if (selected <= switch_end && selected >= switch_beg) {
    Switch(attacker);
  }
}

} //namespace artificialtrainer