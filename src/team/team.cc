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
  std::shared_ptr<Pokemon> old_active_member = ActiveMember();
  fainted_team_.push_back(old_active_member);
  active_team_.erase(active_team_.begin() + IndexOfActiveMember());
  old_active_member->SetIsActive(false);
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

auto Team::HardSwitch() -> void {
  std::shared_ptr<Pokemon> old_active_pokemon = ActiveMember();
  int switch_index = static_cast<int>(
      old_active_pokemon->MoveUsed()->MoveName()) - static_cast<int>(
      MoveNames::kSwitch1);
  old_active_pokemon->SetIsActive(false);
  old_active_pokemon->ResetStats();
  active_team_[switch_index]->SetIsActive(true);
  SetActiveMember(switch_index);
}

auto Team::ForceSwitch(const int &switch_index) -> void {
  active_team_[switch_index]->SetIsActive(true);
  SetActiveMember(switch_index);
}

} //namespace artificialtrainer