//
// Created by neel on 1/23/19.
//

#include <iostream>
#include "pokemon.h"

namespace artificialtrainer {
Pokemon::Pokemon(const SpeciesNames &species_name,
                 const NormalStatsContainer &stats_container,
                 const MovesContainer &moves_container, const TypeContainer
                 &type_container, const int &level)
    : species_name_(species_name),
      normal_stats_container_(stats_container),
      exclusive_in_game_stats_container_{},
      moves_container_(moves_container),
      type_container_(type_container),
      level_(level),
      is_active_(false) {
}

Pokemon::Pokemon() : species_name_(SpeciesNames::kBulbasaur),
                     normal_stats_container_{},
                     exclusive_in_game_stats_container_{},
                     moves_container_{},
                     type_container_{},
                     level_(0),
                     is_active_(false) {
}

auto Pokemon::GetNormalStatsContainer() const -> NormalStatsContainer {
  return normal_stats_container_;
}

auto Pokemon::GetExclusiveInGameStatsContainer() const
-> ExclusiveInGameStatsContainer {
  return exclusive_in_game_stats_container_;
}

auto Pokemon::GetMovesContainer() const -> MovesContainer {
  return moves_container_;
}

auto Pokemon::GetTypeContainer() const -> TypeContainer {
  return type_container_;
}

auto Pokemon::SpeciesName() const -> SpeciesNames {
  return species_name_;
}

auto Pokemon::Level() const -> int {
  return level_;
}

auto Pokemon::IsActive() const -> bool {
  return is_active_;
}

auto Pokemon::SetIsActive(const bool &is_active) -> void {
  is_active_ = is_active;
}

auto Pokemon::SetMoveUsed(const int &index) -> void {
  move_used_ = moves_container_[index];
}

auto Pokemon::MoveUsed() const -> std::shared_ptr<Move> {
  return move_used_;
}

auto Pokemon::ResetStats() -> void {
  for (int i = 0; i < kNumNormalStats; i++) {
    normal_stats_container_[static_cast<StatNames>(i)]->ResetStat();
  }

  for (int i = kNumNormalStats + 1;
       i <= kNumNormalStats + kNumExclusiveInGameStats; i++) {
    exclusive_in_game_stats_container_[static_cast<StatNames>(i)]->ResetStat();
  }
}

auto Pokemon::RaiseStat(const StatNames &stat_name,
                        const int &num_stages) -> void {
  if (stat_name != StatNames::kAccuracy && stat_name != StatNames::kEvasion) {
    std::shared_ptr<NormalStat> stat_to_boost =
        normal_stats_container_[stat_name];

    for (int i = 0; i < num_stages; i++) {
      if (stat_to_boost->Numerator() == NormalStat::kMaxFactor) {
        return;
      }

      if (stat_to_boost->InGameStat() < 1.0) {
        stat_to_boost->LowerDenominator(1);
      } else {
        stat_to_boost->RaiseNumerator(1);
      }
    }
  } else {
    std::shared_ptr<ExclusiveInGameStat> stat_to_boost =
        exclusive_in_game_stats_container_[stat_name];

    for (int i = 0; i < num_stages; i++) {
      if (stat_to_boost->Numerator() == ExclusiveInGameStat::kMaxFactor) {
        return;
      }

      if (stat_to_boost->CalculatedStat() < 1.0) {
        stat_to_boost->LowerDenominator(1);
      } else {
        stat_to_boost->RaiseNumerator(1);
      }
    }
  }
}

auto Pokemon::LowerStat(const StatNames &stat_name,
                        const int &num_stages) -> void {
  if (stat_name != StatNames::kAccuracy && stat_name != StatNames::kEvasion) {
    std::shared_ptr<NormalStat> stat_to_lower =
        normal_stats_container_[stat_name];

    for (int i = 0; i > num_stages; i--) {
      if (stat_to_lower->Denominator() == NormalStat::kMaxFactor) {
        return;
      }

      if (stat_to_lower->InGameStat() > 1.0) {
        stat_to_lower->LowerNumerator(1);
      } else {
        stat_to_lower->RaiseDenominator(1);
      }
    }
  } else {
    std::shared_ptr<ExclusiveInGameStat> stat_to_lower =
        exclusive_in_game_stats_container_[stat_name];

    for (int i = 0; i > num_stages; i--) {
      if (stat_to_lower->Denominator() == ExclusiveInGameStat::kMaxFactor) {
        return;
      }

      if (stat_to_lower->CalculatedStat() > 1.0) {
        stat_to_lower->LowerNumerator(1);
      } else {
        stat_to_lower->RaiseDenominator(1);
      }
    }
  }
}

auto Pokemon::ChangeStat(const StatNames &stat_name,
                         const int &num_stages) -> void {
  num_stages < 0 ? LowerStat(stat_name, num_stages) : RaiseStat(stat_name,
                                                                num_stages);
}

auto Pokemon::SetUsedFocusEnergy(const bool &used_focus_energy) -> void {
  flags_.used_focus_energy = true;
}

auto Pokemon::UsedFocusEnergy() const -> bool {
  return flags_.used_focus_energy;
}

auto Pokemon::SetFaintedSelf(const bool &fainted_self) -> void {
  flags_.fainted_self = fainted_self;
}

auto Pokemon::FaintedSelf() const -> bool {
  return flags_.fainted_self;
}

} //namespace artificialtrainer