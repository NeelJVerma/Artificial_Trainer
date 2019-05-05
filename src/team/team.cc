/**
 * @project Artifical Trainer
 * @brief The implementation of the Team class.
 *
 * @file team.cc
 * @author Neel Verma
 * @date 1/24/19
 */

#include <stdexcept>
#include "../clientelements/gui.h"
#include "../stringconverter/stringconverter.h"

namespace artificialtrainer {

/**
  * @brief: A constructor for the Team class.
  * @param const std::vector<std::shared_ptr<Pokemon>> &active_team: The
  * active team.
  * @param const std::vector<std::shared_ptr<Pokemon>> &fainted_team: The
  * fainted team.
  * @param const bool &is_human: Whether or not the team is the human's.
  */

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

/**
  * @brief: A function to add a Pokemon to the team.
  * @param const std::shared_ptr<Pokemon> &pokemon: The Pokemon to add.
  */

void Team::AddPokemon(const std::shared_ptr<Pokemon> &pokemon) {
  active_team_.push_back(pokemon);
}

/**
  * @brief: A function to faint the active Pokemon.
  */

void Team::FaintActivePokemon() {
  std::shared_ptr<Pokemon> old_active_member = ActiveMember();
  fainted_team_.push_back(old_active_member);
  active_team_.erase(active_team_.begin() + IndexOfActiveMember());
  old_active_member->SetIsActive(false);
}

/**
  * @brief: An accessor for the active team.
  * @return std::vector<std::shared_ptr<Pokemon>>: The active team.
  */

std::vector<std::shared_ptr<Pokemon>> Team::ActiveTeam() const {
  return active_team_;
}

/**
  * @brief: An accessor for the fainted team.
  * @return std::vector<std::shared_ptr<Pokemon>>: The fainted team.
  */

std::vector<std::shared_ptr<Pokemon>> Team::FaintedTeam() const {
  return fainted_team_;
}

/**
  * @brief: A function to determine whether or not a Pokemon is on the team.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * to check.
  * @return bool: Whether or not the Pokemon is on the team.
  */

bool Team::SeenPokemon(const SpeciesNames &species) const {
  for (const auto &in_team : active_team_) {
    if (species == in_team->SpeciesName()) {
      return true;
    }
  }

  return false;
}

/**
  * @brief: A function to set the active member of the team.
  * @param const int &index: The index of the Pokemon to set.
  */

void Team::SetActiveMember(const int &index) {
  active_team_[index]->SetIsActive(true);
}

/**
  * @brief: A function to get the active member.
  * @return td::shared_ptr<Pokemon>: The active member.
  */

std::shared_ptr<Pokemon> Team::ActiveMember() const {
  for (const auto &pokemon : active_team_) {
    if (pokemon->IsActive()) {
      return pokemon;
    }
  }

  return nullptr;
}

/**
  * @brief: A function to get the index of the active member.
  * @return int: The index of the active member. -1 if there is none.
  */

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

/**
  * @brief: A function to hard switch for the team.
  */

void Team::HardSwitch() {
  std::shared_ptr<Pokemon> old_active_pokemon = ActiveMember();
  int switch_index = static_cast<int>(
      old_active_pokemon->MoveUsed()->MoveName()) - static_cast<int>(
      MoveNames::kSwitch1);
  old_active_pokemon->SetIsActive(false);
  old_active_pokemon->ResetSwitchFlags();
  active_team_[switch_index]->SetIsActive(true);
}

/**
  * @brief: An mutator for is human.
  * @param const bool &is_human: The boolean to set.
  */

void Team::SetIsHuman(const bool &is_human) {
  is_human_ = is_human;
}

/**
  * @brief: An accessor for is human.
  * @return bool: Whether or not the team is the human's.
  */

bool Team::IsHuman() const {
  return is_human_;
}

} //namespace artificialtrainer