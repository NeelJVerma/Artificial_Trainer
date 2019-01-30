//
// Created by neel on 1/23/19.
//

#include "pokemon.h"

namespace artificialtrainer {
Pokemon::Pokemon(const SpeciesNames &species,
                 const StatsContainer &stats_container,
                 const MovesContainer &moves_container,
                 const int &level)
    : species_(species),
      stats_container_(stats_container),
      moves_container_(moves_container),
      level_(level) {
}

auto Pokemon::GetStatsContainer() const -> StatsContainer {
  return stats_container_;
}

auto Pokemon::GetMovesContainer() const -> MovesContainer {
  return moves_container_;
}

auto Pokemon::GetSpecies() const -> SpeciesNames {
  return species_;
}

auto Pokemon::Level() const -> int {
  return level_;
}

} //namespace artificialtrainer