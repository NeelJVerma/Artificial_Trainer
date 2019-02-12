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
  bool flinched = false;
  // TODO: ADD MORE WHEN NEEDED
};

class Pokemon {
 public:
  static const int kMaxLevel = 100;

  Pokemon(const Pokemon &pokemon) = default;
  Pokemon &operator=(const Pokemon &pokemon) = default;
  Pokemon();
  Pokemon(const SpeciesNames &species_name,
          const NormalStatsContainer &stats_container,
          const MovesContainer &moves_container,
          const TypeContainer &type_container, const int &level);
  NormalStatsContainer GetNormalStatsContainer() const;
  ExclusiveInGameStatsContainer GetExclusiveInGameStatsContainer() const;
  MovesContainer GetMovesContainer() const;
  TypeContainer GetTypeContainer() const;
  SpeciesNames SpeciesName() const;
  int Level() const;
  bool IsActive() const;
  void SetIsActive(const bool &is_active);
  void SetMoveUsed(const int &index);
  std::shared_ptr<Move> MoveUsed() const;
  void ResetStats();
  void ChangeStat(const StatNames &stat_name, const int &num_stages);
  void SetUsedFocusEnergy(const bool &used_focus_energy);
  bool UsedFocusEnergy() const;
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
  void LowerStat(const StatNames &stat_name, const int &num_stages);
  void RaiseStat(const StatNames &stat_name, const int &num_stages);
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_POKEMON_H
