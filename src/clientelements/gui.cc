//
// Created by neel on 1/23/19.
//

#include "gui.h"
#include "../pokemon/species.h"
#include "../stringconversions/stringconverter.h"

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
        << SpeciesToString(static_cast<Species>(i)) << std::endl;
  }
}

auto Gui::DisplayPickPokemonMessage(const int &num) -> void {
  std::cout << "Pick Pokemon number " << num << '.' << std::endl;
}

auto Gui::DisplayInvalidChoiceMessage() -> void {
  std::cout << "Invalid choice. Select again." << std::endl;
}

auto Gui::DisplayPickEvMessage(const StatNames &stat_name) -> void {
  std::cout << "Pick the " << StatToString(stat_name) << " ev." << std::endl;
}

auto Gui::DisplayPickIvMessage(const StatNames &stat_name) -> void {
  std::cout << "Pick the " << StatToString(stat_name) << " iv." << std::endl;
}

auto Gui::DisplayPickLevelMessage() -> void {
  std::cout << "Pick this Pokemon's level." << std::endl;
}

auto Gui::DisplayPickMoveMessage(const int &move_number) -> void {
  std::cout << "Pick move number " << move_number << " for this Pokemon"
      << std::endl;
}

auto Gui::DisplayPickInBattleMoveMessage(const bool &player_one) -> void {
  std::cout << "Player " << (player_one ? "one" : "two") << ", select your "
                                                            "move" << std::endl;
}

} //namespace artificialtrainer