//
// Created by neel on 1/23/19.
//

#include "pokemon.h"

namespace artificialtrainer {
Pokemon::Pokemon(const Species &species,
    const StatsContainer &stats_container, const int &level)
    : species_(species),
      stats_container_(stats_container),
      level_(level) {
}

auto Pokemon::GetStatsContainer() const -> StatsContainer {
  return stats_container_;
}

auto Pokemon::GetSpecies() const -> Species {
  return species_;
}

auto Pokemon::Level() const -> int {
  return level_;
}

} //namespace artificialtrainer