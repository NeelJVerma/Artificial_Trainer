//
// Created by neel on 1/23/19.
//

#include <iostream>
#include <random>
#include "pokemon.h"
#include "../clientelements/gui.h"

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
      move_used_(nullptr),
      level_(level),
      is_active_(false) {
}

Pokemon::Pokemon() : species_name_(SpeciesNames::kBulbasaur),
                     normal_stats_container_{},
                     exclusive_in_game_stats_container_{},
                     moves_container_{},
                     type_container_{},
                     move_used_(nullptr),
                     level_(0),
                     is_active_(false) {
}

NormalStatsContainer Pokemon::GetNormalStatsContainer() const {
  return normal_stats_container_;
}

ExclusiveInGameStatsContainer Pokemon::
GetExclusiveInGameStatsContainer() const {
  return exclusive_in_game_stats_container_;
}

MovesContainer Pokemon::GetMovesContainer() const {
  return moves_container_;
}

TypeContainer Pokemon::GetTypeContainer() const {
  return type_container_;
}

SpeciesNames Pokemon::SpeciesName() const {
  return species_name_;
}

int Pokemon::Level() const {
  return level_;
}

bool Pokemon::IsActive() const {
  return is_active_;
}

void Pokemon::SetIsActive(const bool &is_active) {
  is_active_ = is_active;
}

void Pokemon::SetMoveUsed(const int &index) {
  move_used_ = moves_container_[index];
}

void Pokemon::SetMoveUsed(const std::shared_ptr<Move> &move) {
  move_used_ = move;
}

std::shared_ptr<Move> Pokemon::MoveUsed() const {
  return move_used_;
}

void Pokemon::ResetStats() {
  for (int i = 0; i < kNumNormalStats; i++) {
    normal_stats_container_[static_cast<StatNames>(i)]->ResetStat();
  }

  for (int i = kNumNormalStats + 1;
       i <= kNumNormalStats + kNumExclusiveInGameStats; i++) {
    exclusive_in_game_stats_container_[static_cast<StatNames>(i)]->ResetStat();
  }
}

void Pokemon::RaiseStat(const StatNames &stat_name,
                        const int &num_stages) {
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

void Pokemon::LowerStat(const StatNames &stat_name,
                        const int &num_stages) {
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

void Pokemon::ChangeStat(const StatNames &stat_name,
                         const int &num_stages) {
  num_stages < 0 ? LowerStat(stat_name, num_stages) : RaiseStat(stat_name,
                                                                num_stages);
}

void Pokemon::SetUsedFocusEnergy(const bool &used_focus_energy) {
  flags_.used_focus_energy = used_focus_energy;
}

bool Pokemon::UsedFocusEnergy() const {
  return flags_.used_focus_energy;
}

void Pokemon::SetFlinched(const bool &flinched) {
  flags_.flinched = flinched;
}

bool Pokemon::IsFlinched() const {
  return flags_.flinched;
}


bool Pokemon::Confuse() {
  return flags_.confusion.Activate();
}

bool Pokemon::IsConfused() const {
  return flags_.confusion.IsActive();
}

void Pokemon::SetStatus(const StatusNames &status_name) {
  flags_.status = status_name;
}

StatusNames Pokemon::Status() const {
  return flags_.status;
}

void Pokemon::SetVanished(const bool &vanished) {
  flags_.vanished = vanished;
}

bool Pokemon::IsVanished() const {
  return flags_.vanished;
}

bool Pokemon::HandleConfusion() {
  if (!flags_.confusion.IsActive()) {
    return true;
  }

  Gui::DisplayConfusedMessage(species_name_);

  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<> distribution(1, 100);

  if (distribution(generator) <= 50) {
    Gui::DisplayHitSelfMessage(species_name_);
    flags_.confusion.AdvanceOneTurn();
    return false;
  }

  flags_.confusion.AdvanceOneTurn();
  return true;
}

void Pokemon::ResetEndOfTurnFlags() {
  flags_.flinched = false;
  move_used_->SetDamageDone(0);

  if (move_used_->MoveName() == MoveNames::kConfusion) {
    std::vector<std::shared_ptr<Move>> current_moves =
        moves_container_.CurrentMoves();
    current_moves.erase(current_moves.begin() + current_moves.size() - 1);
  }
}

void Pokemon::ResetSwitchFlags() {
  ResetStats();
  flags_.confusion = Confusion{};
  flags_.used_focus_energy = false;
}

} //namespace artificialtrainer