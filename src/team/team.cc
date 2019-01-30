//
// Created by neel on 1/24/19.
//

#include <stdexcept>
#include "team.h"

namespace artificialtrainer {
auto Team::AddPokemon(const Pokemon &pokemon) -> void {
  team_.push_back(pokemon);
}

auto Team::FaintPokemon(const int &index) -> void {
  fainted_team_.push_back(team_[index]);
  team_.erase(team_.begin() + index);
}

auto Team::TeamSize() const -> int {
  return static_cast<int>(team_.size());
}

auto Team::operator[](const int &index) -> Pokemon {
  if (index < 0 || index >= team_.size()) {
    throw std::out_of_range("Index doesn't exist");
  }

  return team_[index];
}

auto Team::SeenPokemon(const SpeciesNames &species) -> bool {
  for (const auto &in_team : team_) {
    if (species == in_team.SpeciesName()) {
      return true;
    }
  }

  return false;
}

} //namespace artificialtrainer