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
  std::vector<std::shared_ptr<Pokemon>> active_team = team.ActiveTeam();
  std::vector<std::shared_ptr<Pokemon>> fainted_team = team.FaintedTeam();

  std::cout << "Active team " << (player_one ? "one" : "two") << ':'
            << std::endl;
  int i = 1;

  for (const auto &pokemon : active_team) {
    std::cout << i++ << ". "
              << StringConverter::SpeciesToString(pokemon->SpeciesName())
              << ": "
              << pokemon->GetNormalStatsContainer().HpStat()->CurrentHp()
              << " hp." << std::endl;
  }

  std::cout << std::endl;
  std::cout << "Fainted team " << (player_one ? "one" : "two") << ':'
            << std::endl;
  i = 1;

  for (const auto &pokemon : fainted_team) {
    std::cout << i++ << ". "
              << StringConverter::SpeciesToString(pokemon->SpeciesName())
              << '.' << std::endl;
  }

  std::cout << std::endl;
}

auto Gui::DisplayPickLeadingPokemonMessage(const bool &player_one) -> void {
  std::cout << "Player " << (player_one ? "one" : "two")
            << ", select your leading Pokemon" << std::endl;
}

auto Gui::DisplayActivePokemonData(const std::shared_ptr<Pokemon> &pokemon,
                                   const bool &player_one) -> void {
  std::cout << "Active pokemon for player " << (player_one ? "one" : "two")
            << ':' << std::endl;
  std::cout << StringConverter::SpeciesToString(pokemon->SpeciesName())
            << ": level " << pokemon->Level() << std::endl;
  TypeContainer type_container = pokemon->GetTypeContainer();
  std::cout << "Types: "
            << StringConverter::TypeToString(type_container.FirstType()) << ", "
            << StringConverter::TypeToString(type_container.SecondType())
            << std::endl;
  NormalStatsContainer stats_container = pokemon->GetNormalStatsContainer();
  std::shared_ptr<Hp> hp_stat = stats_container.HpStat();
  std::cout << "Hp: " << hp_stat->HpAsPercent() << "% ("
            << hp_stat->CurrentHp() << '/' << hp_stat->MaxHp() << ')'
            << std::endl;

  for (int i = 0; i < kNumNormalStats; i++) {
    auto stat_name = static_cast<StatNames>(i);
    std::cout << StringConverter::StatToString(stat_name)
              << ": " << stats_container[stat_name]->InGameStat() << std::endl;
  }

  ExclusiveInGameStatsContainer ex_stats_container =
      pokemon->GetExclusiveInGameStatsContainer();

  for (int i = kNumNormalStats + 1;
       i <= kNumNormalStats + kNumExclusiveInGameStats; i++) {
    auto stat_name = static_cast<StatNames>(i);
    std::cout << StringConverter::StatToString(stat_name)
              << ": " << ex_stats_container[stat_name]->Numerator() << '/'
              << ex_stats_container[stat_name]->Denominator() << std::endl;
  }

  MovesContainer moves_container = pokemon->GetMovesContainer();
  std::cout << "Moves:" << std::endl;

  for (int i = 0; i < moves_container.Size(); i++) {
    int move = static_cast<int>(moves_container[i]->MoveName());

    if (move < static_cast<int>(MoveNames::kPass)) {
      std::cout << i + 1 << ". "
                << StringConverter::MoveToString(moves_container[i]->MoveName())
                << ": " << moves_container[i]->CurrentPp() << " pp"
                << std::endl;
    } else {
      std::cout << i + 1 << ". "
                << StringConverter::MoveToString(moves_container[i]->MoveName())
                << std::endl;
    }
  }

  std::cout << std::endl;
}

auto Gui::DisplayTurnNumber(const int &turn_number) -> void {
  std::cout << "Turn number: " << turn_number << std::endl;
}

auto Gui::DisplayPickInBattleMoveMessage(const bool &player_one) -> void {
  std::cout << "Player " << (player_one ? "one" : "two") << ", select your move"
            << std::endl;
}

auto Gui::DisplayMoveFailedMessage() -> void {
  std::cout << "The move failed" << std::endl;
}

auto Gui::DisplayMoveMissedMessage() -> void {
  std::cout << "The move missed" << std::endl;
}

auto Gui::DisplayPokemonFaintedMessage(const SpeciesNames &species_name)
-> void {
  std::cout << StringConverter::SpeciesToString(species_name) << " fainted"
            << std::endl;
}

auto Gui::DisplayOneHitKoMoveLandedMessage() -> void {
  std::cout << "The one hit ko move landed" << std::endl;
}

auto Gui::DisplayInvalidMoveChoiceMessage() -> void {
  std::cout << "Invalid move choice" << std::endl;
}

auto Gui::DisplayPokemonUsedMoveMessage(
    const std::shared_ptr<Pokemon> &pokemon) -> void {
  std::cout << StringConverter::SpeciesToString(pokemon->SpeciesName())
            << " used "
            << StringConverter::MoveToString(pokemon->MoveUsed()->MoveName())
            << std::endl;
}

auto Gui::DisplayBattleOverMessage() -> void {
  std::cout << "Battle over" << std::endl;
}

auto Gui::DisplaySwitchMessage(const SpeciesNames &one,
                               const SpeciesNames &two) -> void {
  std::cout << StringConverter::SpeciesToString(one)
            << " successfully switched out with "
            << StringConverter::SpeciesToString(two) << std::endl;
}

} //namespace artificialtrainer