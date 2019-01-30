//
// Created by neel on 1/24/19.
//

#include <stdexcept>
#include "team.h"

namespace artificialtrainer {
auto Team::AddPokemon(const Pokemon &pokemon) -> void {
  active_team_.push_back(pokemon);
}

auto Team::FaintPokemon(const int &index) -> void {
  fainted_team_.push_back(active_team_[index]);
  active_team_.erase(active_team_.begin() + index);
}

auto Team::ActiveTeamSize() const -> int {
  return static_cast<int>(active_team_.size());
}

auto Team::FaintedTeamSize() const -> int {
  return static_cast<int>(fainted_team_.size());
}

auto Team::ActiveTeam() const -> std::vector<Pokemon> {
  return active_team_;
}

auto Team::FaintedTeam() const -> std::vector<Pokemon> {
  return fainted_team_;
}

auto Team::SeenPokemon(const SpeciesNames &species) -> bool {
  for (const auto &in_team : active_team_) {
    if (species == in_team.SpeciesName()) {
      return true;
    }
  }

  return false;
}

} //namespace artificialtrainer