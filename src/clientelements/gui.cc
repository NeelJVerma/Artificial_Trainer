//
// Created by neel on 1/23/19.
//

#include "gui.h"
#include "../pokemon/speciesnames.h"
#include "../stringconverter/stringconverter.h"
#include "../move/basepower.h"

namespace artificialtrainer {
auto Gui::DisplayWelcomeMessage() -> void {
  std::cout << "Welcome to Artificial Trainer, a Gen 1 battle simulator/AI!"
            << std::endl;
}

auto Gui::DisplayPickTeamMessage(const bool &player_one) -> void {
  std::cout << "Player " << (player_one ? "one" : "two") << ", select your "
                                                            "team" << std::endl;
}

auto Gui::DisplayPokemonChoices() -> void {
  std::cout << "Team choices:" << std::endl;

  for (int i = 0; i < kNumSpecies; ++i) {
    std::cout << std::to_string(i + 1) << ". "
              << StringConverter::SpeciesToString(static_cast<SpeciesNames>(i))
              << std::endl;
  }
}

auto Gui::DisplayPickPokemonMessage(const int &num) -> void {
  std::cout << "Pick Pokemon number " << num << '.' << std::endl;
}

auto Gui::DisplayInvalidChoiceMessage() -> void {
  std::cout << "Invalid choice. Select again." << std::endl;
}

auto Gui::DisplayPickEvMessage(const StatNames &stat_name) -> void {
  std::cout << "Pick the " << StringConverter::StatToString(stat_name) << " ev."
            << std::endl;
}

auto Gui::DisplayPickIvMessage(const StatNames &stat_name) -> void {
  std::cout << "Pick the " << StringConverter::StatToString(stat_name) << " iv."
            << std::endl;
}

auto Gui::DisplayPickLevelMessage() -> void {
  std::cout << "Pick this Pokemon's level." << std::endl;
}

auto Gui::DisplayPokemonLearnset(
    const std::vector<MoveNames> &moveset) -> void {
  std::cout << "Learned moves:" << std::endl;

  for (MoveNames move_name : moveset) {
    std::cout << static_cast<int>(move_name) << ". "
              << StringConverter::MoveToString(move_name) << std::endl;
  }
}

auto Gui::DisplayPickMoveMessage(const int &move_number) -> void {
  std::cout << "Pick move number " << move_number << " for this Pokemon"
            << std::endl;
}

auto Gui::DisplayPlayerTeam(const Team &team, const bool &player_one) -> void {
  std::vector<Pokemon> active_team = team.ActiveTeam();
  std::vector<Pokemon> fainted_team = team.FaintedTeam();

  std::cout << "Active team " << (player_one ? "one" : "two") << ':'
            << std::endl;
  int i = 1;

  for (const auto &pokemon : active_team) {
    std::cout << i++ << ". "
              << StringConverter::SpeciesToString(pokemon.SpeciesName())
              << ": " << pokemon.GetStatsContainer().HpStat().CurrentHp()
              << " hp." << std::endl;
  }

  std::cout << std::endl;
  std::cout << "Fainted team " << (player_one ? "one" : "two") << ':'
            << std::endl;
  i = 1;

  for (const auto &pokemon : fainted_team) {
    std::cout << i++ << ". "
              << StringConverter::SpeciesToString(pokemon.SpeciesName())
              << '.' << std::endl;
  }

  std::cout << std::endl;
}

auto Gui::DisplayPickLeadingPokemonMessage(const bool &player_one) -> void {
  std::cout << "Player " << (player_one ? "one" : "two")
            << ", select your leading Pokemon" << std::endl;
}

auto Gui::DisplayPickInBattleMoveMessage(const bool &player_one) -> void {
  std::cout << "Player " << (player_one ? "one" : "two") << ", select your move"
            << std::endl;
}

} //namespace artificialtrainer