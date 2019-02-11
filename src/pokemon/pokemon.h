//
// Created by neel on 1/23/19.
//

#ifndef ARTIFICIAL_TRAINER_POKEMON_H
#define ARTIFICIAL_TRAINER_POKEMON_H

#include "speciesnames.h"
#include "../stat/normalstatscontainer.h"
#include "../move/movescontainer.h"
#include "../type/typecontainer.h"
#include "../stat/exclusiveingamestatscontainer.h"

namespace artificialtrainer {
struct InGameFlags {
  bool flying = false;
  bool digging = false;
  bool used_focus_energy = false;
  // TODO: ADD MORE WHEN NEEDED
};

class Pokemon {
 public:
  static const int kMaxLevel = 100;

  Pokemon(const Pokemon &pokemon) = default;
  auto operator=(const Pokemon &pokemon) -> Pokemon & = default;
  Pokemon();
  Pokemon(const SpeciesNames &species_name,
          const NormalStatsContainer &stats_container,
          const MovesContainer &moves_container,
          const TypeContainer &type_container, const int &level);
  auto GetNormalStatsContainer() const -> NormalStatsContainer;
  auto GetExclusiveInGameStatsContainer() const
    -> ExclusiveInGameStatsContainer;
  auto GetMovesContainer() const -> MovesContainer;
  auto GetTypeContainer() const -> TypeContainer;
  auto SpeciesName() const -> SpeciesNames;
  auto Level() const -> int;
  auto IsActive() const -> bool;
  auto SetIsActive(const bool &is_active) -> void;
  auto SetMoveUsed(const int &index) -> void;
  auto MoveUsed() const -> std::shared_ptr<Move>;
  auto ResetStats() -> void;
  auto ChangeStat(const StatNames &stat_name, const int &num_stages) -> void;
  auto SetUsedFocusEnergy(const bool &used) -> void;
  auto UsedFocusEnergy() const -> bool;

  // TODO: ADD IN GAME FLAG ATTRIBUTES. SETTING/GETTING

 private:
  NormalStatsContainer normal_stats_container_;
  ExclusiveInGameStatsContainer exclusive_in_game_stats_container_;
  MovesContainer moves_container_;
  std::shared_ptr<Move> move_used_;
  TypeContainer type_container_;
  SpeciesNames species_name_;
  InGameFlags flags_;
  int level_;
  bool is_active_;
  auto LowerStat(const StatNames &stat_name, const int &num_stages) -> void;
  auto RaiseStat(const StatNames &stat_name, const int &num_stages) -> void;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_POKEMON_H
