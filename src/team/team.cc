//
// Created by neel on 1/24/19.
//

#include "team.h"

namespace artificialtrainer {
auto Team::AddPokemon(const std::shared_ptr<Pokemon> &pokemon) -> void {
  team_.push_back(pokemon);
}

auto Team::FaintPokemon(const int &index) -> void {
  team_.erase(team_.begin() + index);
}

auto Team::TeamSize() const -> int {
  return static_cast<int>(team_.size());
}

auto Team::operator[](const int &index) -> std::shared_ptr<Pokemon> {
  if (index < 0 || index >= team_.size()) {
    throw std::out_of_range("Index doesn't exist");
  }

  return team_[index];
}

} //namespace artificialtrainer