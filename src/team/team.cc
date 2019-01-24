//
// Created by neel on 1/24/19.
//

#include "team.h"

namespace artificialtrainer {
void Team::AddPokemon(const std::shared_ptr<Pokemon> &pokemon) {
  team_.push_back(pokemon);
}

void Team::RemovePokemon(const unsigned &index) {
  team_.erase(team_.begin() + index);
}

auto Team::TeamSize() const -> unsigned {
  return static_cast<unsigned>(team_.size());
}

} //namespace artificialtrainer