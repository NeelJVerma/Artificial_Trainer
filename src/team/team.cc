//
// Created by neel on 1/24/19.
//

#include <stdexcept>
#include "../clientelements/gui.h"
#include "../stringconverter/stringconverter.h"

namespace artificialtrainer {
Team::Team(const std::vector<std::shared_ptr<Pokemon>> &active_team,
           const std::vector<std::shared_ptr<Pokemon>> &fainted_team) {
  for (const auto &active : active_team) {
    Pokemon deref_active = *active;
    active_team_.push_back(std::make_shared<Pokemon>(
        deref_active.SpeciesName(),
        deref_active.GetNormalStatsContainer(),
        deref_active.GetExclusiveInGameStatsContainer(),
        deref_active.GetMovesContainer(),
        deref_active.GetTypeContainer(),
        deref_active.Level(), deref_active.HpStat(),
        deref_active.MoveUsed(), deref_active.Flags(),
        deref_active.IsActive()));
  }

  for (const auto &fainted : fainted_team) {
    Pokemon deref_fainted = *fainted;
    fainted_team_.push_back(std::make_shared<Pokemon>(
        deref_fainted.SpeciesName(),
        deref_fainted.GetNormalStatsContainer(),
        deref_fainted.GetExclusiveInGameStatsContainer(),
        deref_fainted.GetMovesContainer(),
        deref_fainted.GetTypeContainer(),
        deref_fainted.Level(), deref_fainted.HpStat(),
        deref_fainted.MoveUsed(), deref_fainted.Flags(),
        deref_fainted.IsActive()));
  }
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

} //namespace artificialtrainer