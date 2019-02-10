//
// Created by neel on 1/24/19.
//

#include <stdexcept>
#include "team.h"

namespace artificialtrainer {
auto Team::AddPokemon(const std::shared_ptr<Pokemon> &pokemon) -> void {
  active_team_.push_back(pokemon);
}

auto Team::FaintActivePokemon() -> void {
  fainted_team_.push_back(ActiveMember());
  active_team_.erase(active_team_.begin() + IndexOfActiveMember());
  ActiveMember()->SetIsActive(false);
}

auto Team::ActiveTeamSize() const -> int {
  return static_cast<int>(active_team_.size());
}

auto Team::FaintedTeamSize() const -> int {
  return static_cast<int>(fainted_team_.size());
}

auto Team::ActiveTeam() const -> std::vector<std::shared_ptr<Pokemon>> {
  return active_team_;
}

auto Team::FaintedTeam() const -> std::vector<std::shared_ptr<Pokemon>> {
  return fainted_team_;
}

auto Team::SeenPokemon(const SpeciesNames &species) -> bool {
  for (const auto &in_team : active_team_) {
    if (species == in_team->SpeciesName()) {
      return true;
    }
  }

  return false;
}

auto Team::SetActiveMember(const int &index) -> void {
  active_team_[index]->SetIsActive(true);
}

auto Team::ActiveMember() -> std::shared_ptr<Pokemon> {
  for (auto &pokemon : active_team_) {
    if (pokemon->IsActive()) {
      return pokemon;
    }
  }

  return nullptr;
}

auto Team::IndexOfActiveMember() const -> int {
  int i = 0;

  for (auto &pokemon : active_team_) {
    if (pokemon->IsActive()) {
      return i;
    }

    i++;
  }

  return -1;
}

} //namespace artificialtrainer