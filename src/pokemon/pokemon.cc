//
// Created by neel on 1/23/19.
//

#include <iostream>
#include <random>
#include "pokemon.h"
#include "../clientelements/gui.h"
#include "../type/type.h"

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


void Pokemon::Confuse() {
  flags_.confusion.Activate();
}

void Pokemon::DisableMove() {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<> distribution(0, EndOfNormalMovesIndex() - 1);
  int random_index = distribution(generator);
  moves_container_[random_index]->SetDisabled(true);
  Gui::DisplayMoveDisabledMessage(moves_container_[random_index]->MoveName());
  flags_.disable.Activate();
}

bool Pokemon::HasMoveDisabled() const {
  return flags_.disable.IsActive();
}

bool Pokemon::IsConfused() const {
  return flags_.confusion.IsActive();
}

void Pokemon::SetVanished(const bool &vanished) {
  flags_.vanished = vanished;
}

bool Pokemon::IsVanished() const {
  return flags_.vanished;
}

int Pokemon::EndOfNormalMovesIndex() const {
  int end_normal_moves_index = 0;

  for (int i = 0; i < moves_container_.Size(); i++) {
    if (moves_container_[i]->MoveName() == MoveNames::kPass) {
      end_normal_moves_index = i;
      break;
    }
  }

  return end_normal_moves_index;
}

void Pokemon::UseConversion() {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<> distribution(0, EndOfNormalMovesIndex() - 1);
  TypeNames random_type = Type(
      moves_container_[distribution(generator)]->MoveName());
  type_container_.ResetTypeFromConversion(random_type);
}

bool Pokemon::HandleConfusion() {
  // TODO: IF POKEMON IS RECHARGING OR STATUS PREVENTS THEM FROM ATTACKING,
  //  RETURN TRUE
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

void Pokemon::ReEnableDisabledMove() {
  for (int i = 0; i < EndOfNormalMovesIndex(); i++) {
    if (moves_container_[i]->IsDisabled()) {
      moves_container_[i]->SetDisabled(false);
    }
  }
}

void Pokemon::HandleDisable() {
  if (!flags_.disable.IsActive()) {
    ReEnableDisabledMove();
    return;
  }

  flags_.disable.AdvanceOneTurn();
}

void Pokemon::AbsorbHp(const int &damage_done) {
  int absored = damage_done >> 1;
  normal_stats_container_.HpStat()->AddHp(absored);
  Gui::DisplayHpAbsorbedMessage(species_name_, absored);
}

void Pokemon::ResetEndOfTurnFlags() {
  flags_.flinched = false;
  move_used_->SetDamageDone(0);
}

void Pokemon::ResetSwitchFlags() {
  ResetStats();
  flags_.confusion = Confusion{};
  flags_.disable = Disable{};
  flags_.used_focus_energy = false;
  type_container_ = TypeContainer(species_name_);
}

} //namespace artificialtrainer