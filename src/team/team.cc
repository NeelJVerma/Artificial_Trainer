//
// Created by neel on 1/24/19.
//

#include <stdexcept>
#include "../clientelements/gui.h"

namespace artificialtrainer {
void Team::AddPokemon(const std::shared_ptr<Pokemon> &pokemon) {
  active_team_.push_back(pokemon);
}

void Team::FaintActivePokemon() {
  std::shared_ptr<Pokemon> old_active_member = ActiveMember();
  fainted_team_.push_back(old_active_member);
  active_team_.erase(active_team_.begin() + IndexOfActiveMember());
  old_active_member->SetIsActive(false);
}

std::vector<std::shared_ptr<Pokemon>> Team::ActiveTeam() const {
  return active_team_;
}

std::vector<std::shared_ptr<Pokemon>> Team::FaintedTeam() const {
  return fainted_team_;
}

bool Team::SeenPokemon(const SpeciesNames &species) const {
  for (const auto &in_team : active_team_) {
    if (species == in_team->SpeciesName()) {
      return true;
    }
  }

  return false;
}

void Team::SetActiveMember(const int &index) {
  active_team_[index]->SetIsActive(true);
}

std::shared_ptr<Pokemon> Team::ActiveMember() const {
  for (const auto &pokemon : active_team_) {
    if (pokemon->IsActive()) {
      return pokemon;
    }
  }

  return nullptr;
}

int Team::IndexOfActiveMember() const {
  int i = 0;

  for (auto &pokemon : active_team_) {
    if (pokemon->IsActive()) {
      return i;
    }

    i++;
  }

  return -1;
}

void Team::SwitchAction(const int &switch_index) {
  active_team_[switch_index]->SetIsActive(true);
  SetActiveMember(switch_index);
}

void Team::HardSwitch() {
  std::shared_ptr<Pokemon> old_active_pokemon = ActiveMember();
  int switch_index = static_cast<int>(
      old_active_pokemon->MoveUsed()->MoveName()) - static_cast<int>(
      MoveNames::kSwitch1);
  old_active_pokemon->SetIsActive(false);
  old_active_pokemon->ResetSwitchFlags();
  SwitchAction(switch_index);
}

} //namespace artificialtrainer