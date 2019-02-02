//
// Created by neel on 1/23/19.
//

#include "pokemon.h"

namespace artificialtrainer {
Pokemon::Pokemon(const SpeciesNames &species_name,
                 const StatsContainer &stats_container,
                 const MovesContainer &moves_container, const TypeContainer
                 &type_container, const int &level)
    : species_name_(species_name),
      stats_container_(stats_container),
      moves_container_(moves_container),
      type_container_(type_container),
      level_(level),
      is_active_(false) {
}

Pokemon::Pokemon()
    : species_name_(SpeciesNames::kBulbasaur),
      stats_container_{},
      moves_container_{},
      type_container_{},
      level_(0),
      is_active_(false) {
}

auto Pokemon::GetStatsContainer() const -> StatsContainer {
  return stats_container_;
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

} //namespace artificialtrainer