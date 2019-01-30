//
// Created by neel on 1/23/19.
//

#ifndef ARTIFICIAL_TRAINER_POKEMON_H
#define ARTIFICIAL_TRAINER_POKEMON_H

#include "speciesnames.h"
#include "../stat/statscontainer.h"
#include "../move/movescontainer.h"

namespace artificialtrainer {
class Pokemon {
 public:
  static const int kMaxLevel = 100;

  Pokemon(const Pokemon &pokemon) = default;
  auto operator=(const Pokemon &pokemon) -> Pokemon & = default;
  Pokemon() = default;
  Pokemon(const SpeciesNames &species, const StatsContainer &stats_container,
          const MovesContainer &moves_container, const int &level);
  auto GetStatsContainer() const -> StatsContainer;
  auto GetMovesContainer() const -> MovesContainer;
  auto GetSpecies() const -> SpeciesNames;
  auto Level() const -> int;

 private:
  StatsContainer stats_container_;
  MovesContainer moves_container_;
  SpeciesNames species_;
  int level_;
  // moves
  // types
  // statuses
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_POKEMON_H
