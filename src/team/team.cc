//
// Created by neel on 1/24/19.
//

#include "team.h"

namespace artificialtrainer {
auto Team::AddPokemon(const std::shared_ptr<Pokemon> &pokemon) -> void {
  team_.push_back(pokemon);
}

auto Team::RemovePokemon(const int &index) -> void {
  team_.erase(team_.begin() + index);
}

auto Team::TeamSize() const -> int {
  return static_cast<int>(team_.size());
}

} //namespace artificialtrainer