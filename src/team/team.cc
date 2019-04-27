//
// Created by neel on 1/24/19.
//

#include <stdexcept>
#include "../clientelements/gui.h"
#include "../stringconverter/stringconverter.h"

namespace artificialtrainer {
Team::Team(const std::vector<std::shared_ptr<Pokemon>> &active_team,
           const std::vector<std::shared_ptr<Pokemon>> &fainted_team,
           const bool &is_human) {
  for (const auto &active : active_team) {
    active_team_.push_back(std::make_shared<Pokemon>(active->DeepCopy()));
  }

  for (const auto &fainted : fainted_team) {
    fainted_team_.push_back(std::make_shared<Pokemon>(fainted->DeepCopy()));
  }

  is_human_ = is_human;
}

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

void Team::HardSwitch() {
  std::shared_ptr<Pokemon> old_active_pokemon = ActiveMember();
  int switch_index = static_cast<int>(
      old_active_pokemon->MoveUsed()->MoveName()) - static_cast<int>(
      MoveNames::kSwitch1);
  old_active_pokemon->SetIsActive(false);
  old_active_pokemon->ResetSwitchFlags();
  active_team_[switch_index]->SetIsActive(true);
}

void Team::SetIsHuman(const bool &is_human) {
  is_human_ = is_human;
}

bool Team::IsHuman() const {
  return is_human_;
}

} //namespace artificialtrainer