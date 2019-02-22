//
// Created by neel on 1/23/19.
//

#include "gui.h"
#include "../pokemon/speciesnames.h"
#include "../stringconverter/stringconverter.h"
#include "../move/basepower.h"

namespace artificialtrainer {
void Gui::DisplayWelcomeMessage() {
  std::cout << "Welcome to Artificial Trainer, a Gen 1 battle simulator/AI!"
            << std::endl;
}

void Gui::DisplayPickTeamMessage(const bool &player_one) {
  std::cout << "Player " << (player_one ? "one" : "two") << ", select your "
                                                            "team" << std::endl;
}

void Gui::DisplayPokemonChoices() {
  std::cout << "Team choices:" << std::endl;

  for (int i = 0; i < kNumSpecies; ++i) {
    std::cout << std::to_string(i + 1) << ". "
              << StringConverter::SpeciesToString(static_cast<SpeciesNames>(i))
              << std::endl;
  }
}

void Gui::DisplayPickPokemonMessage(const int &num) {
  std::cout << "Pick Pokemon number " << num << '.' << std::endl;
}

void Gui::DisplayInvalidChoiceMessage() {
  std::cout << "Invalid choice. Select again." << std::endl;
}

void Gui::DisplayPickEvMessage(const StatNames &stat_name) {
  std::cout << "Pick the " << StringConverter::StatToString(stat_name) << " ev."
            << std::endl;
}

void Gui::DisplayPickIvMessage(const StatNames &stat_name) {
  std::cout << "Pick the " << StringConverter::StatToString(stat_name) << " iv."
            << std::endl;
}

void Gui::DisplayPickLevelMessage() {
  std::cout << "Pick this Pokemon's level." << std::endl;
}

void Gui::DisplayPokemonLearnset(const std::vector<MoveNames> &moveset) {
  std::cout << "Learned moves:" << std::endl;

  for (MoveNames move_name : moveset) {
    std::cout << static_cast<int>(move_name) << ". "
              << StringConverter::MoveToString(move_name) << std::endl;
  }
}

void Gui::DisplayPickMoveMessage(const int &move_number) {
  std::cout << "Pick move number " << move_number << " for this Pokemon"
            << std::endl;
}

void Gui::DisplayPlayerTeam(const Team &team, const bool &player_one) {
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

void Gui::DisplayPickLeadingPokemonMessage(const bool &player_one) {
  std::cout << "Player " << (player_one ? "one" : "two")
            << ", select your leading Pokemon" << std::endl;
}

void Gui::DisplayActivePokemonData(const std::shared_ptr<Pokemon> &pokemon,
                                   const bool &player_one) {
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
                << ": " << moves_container[i]->CurrentPp() << " pp, "
                << StringConverter::TypeToString(
                    Type(moves_container[i]->MoveName())) << " type"
                << std::endl;
    } else {
      std::cout << i + 1 << ". "
                << StringConverter::MoveToString(moves_container[i]->MoveName())
                << std::endl;
    }
  }

  std::cout << std::endl;
}

void Gui::DisplayTurnNumber(const int &turn_number) {
  std::cout << "Turn number: " << turn_number << std::endl;
}

void Gui::DisplayPickInBattleMoveMessage(const bool &player_one) {
  std::cout << "Player " << (player_one ? "one" : "two") << ", select your move"
            << std::endl;
}

void Gui::DisplayMoveFailedMessage() {
  std::cout << "The move failed" << std::endl;
}

void Gui::DisplayMoveMissedMessage() {
  std::cout << "The move missed" << std::endl;
}

void Gui::DisplayPokemonFaintedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name) << " fainted"
            << std::endl;
}

void Gui::DisplayOneHitKoMoveLandedMessage() {
  std::cout << "The one hit ko move landed" << std::endl;
}

void Gui::DisplayInvalidMoveChoiceMessage() {
  std::cout << "Invalid move choice" << std::endl;
}

void Gui::DisplayPokemonUsedMoveMessage(const SpeciesNames &species_name,
                                        const MoveNames &move_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " used "
            << StringConverter::MoveToString(move_name)
            << std::endl;
}

void Gui::DisplayBattleOverMessage() {
  std::cout << "Battle over" << std::endl;
}

void Gui::DisplaySwitchMessage(const SpeciesNames &one,
                               const SpeciesNames &two) {
  std::cout << StringConverter::SpeciesToString(one)
            << " successfully switched out with "
            << StringConverter::SpeciesToString(two) << std::endl;
}

void Gui::DisplayForceSwitchMessage() {
  std::cout << "Pick a Pokemon to switch into" << std::endl;
}

void Gui::DisplayAvailableSwitchOptions(const Team &team) {
  std::cout << "Available switches:" << std::endl;
  int i = 1;

  for (const auto &pokemon : team.ActiveTeam()) {
    std::cout << i++ << ". "
              << StringConverter::SpeciesToString(pokemon->SpeciesName())
              << ": "
              << pokemon->GetNormalStatsContainer().HpStat()->CurrentHp()
              << " hp." << std::endl;
  }
}

void Gui::DisplayMoveCritMessage() {
  std::cout << "The move landed a critical hit" << std::endl;
}

void Gui::DisplayMoveHadNoEffectMessage() {
  std::cout << "The move had no effect" << std::endl;
}

void Gui::DisplayDamageDoneMessage(const int &damage_done) {
  std::cout << "The move did " << damage_done << " damage" << std::endl;
}

void Gui::DisplayNotVeryEffectiveMessage() {
  std::cout << "The move was not very effective" << std::endl;
}

void Gui::DisplaySuperEffectiveMessage() {
  std::cout << "The move was super effective" << std::endl;
}

void Gui::DisplayFlinchedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name) << " flinched"
            << std::endl;
}

void Gui::DisplayConfusedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is confused" << std::endl;
}

void Gui::DisplayHitSelfMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " hit itself in confusion" << std::endl;
}

void Gui::DisplayHpAbsorbedMessage(const SpeciesNames &species_name,
                                   const int &absorbed) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " absorbed " << absorbed << " hp" << std::endl;
}

void Gui::DisplayConfusionEndedMessage() {
  std::cout << "The confusion ended" << std::endl;
}

void Gui::DisplayConfusionStartedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " became confused" << std::endl;
}

void Gui::DisplayDisableEndedMessage() {
  std::cout << "The disable ended" << std::endl;
}

void Gui::DisplayMoveDisabledMessage(const MoveNames &move_name) {
  std::cout << StringConverter::MoveToString(move_name)
            << " is disabled" << std::endl;
}

void Gui::DisplayRecoilDamageMessage(const SpeciesNames &species_name,
                                     const int &damage_done) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " took " << damage_done << " recoil damage" << std::endl;
}

void Gui::DisplayPokemonCopiedMoveMessage(const SpeciesNames &species_name,
                                          const MoveNames &move_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " copied " << StringConverter::MoveToString(move_name)
            << std::endl;
}

void Gui::DisplayMistStartedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is now under mist. It is protected from negative stat changes"
            << std::endl;
}

void Gui::DisplayIsUnderMistMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is under mist. Its stats won't go lower" << std::endl;
}

void Gui::DisplayIsBehindSubstituteMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is now behind a substitute" << std::endl;
}

void Gui::DisplaySubstituteTooKDamageMessage(const int &damage_done) {
  std::cout << "The substitute took " << damage_done << " damage" << std::endl;
}

void Gui::DisplaySubstituteFadedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << "\'s substitute faded" << std::endl;
}

void Gui::DisplayIsBehindSubstituteMessage() {
  std::cout << "Opponent can't change stats, confuse, or status "
               "pokemon behind a substitute" << std::endl;
}

void Gui::DisplayBurnStartedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " became burned" << std::endl;
}

void Gui::DisplayIsBurnedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is burned" << std::endl;
}

void Gui::DisplayTookBurnDamageMessage(const SpeciesNames &species_name,
                                       const int &damage_done) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " took " << damage_done << " damage from its burn" << std::endl;
}

void Gui::DisplayIsSeededMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is seeded" << std::endl;
}

void Gui::DisplayLeechSeedStartedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is now under the effects of leech seed" << std::endl;
}

void Gui::DisplayHadHpSappedMessage(const SpeciesNames &species_name,
                                    const int &sapped) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " had " << sapped << " hp sapped from it" << std::endl;
}

void Gui::DisplayFreezeStartedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is now frozen" << std::endl;
}

void Gui::DisplayIsFrozenMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is frozen. It can't attack" << std::endl;
}

void Gui::DisplayParalysisStartedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is now paralyzed" << std::endl;
}

void Gui::DisplayFullyParalyzedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is fully paralyzed. It can't attack" << std::endl;
}

void Gui::DisplayPoisonStartedMessage(const SpeciesNames &species_name,
                                      const bool &is_toxic) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is now "
            << (is_toxic ? "badly poisoned from toxic" : "poisoned")
            << std::endl;
}

void Gui::DisplayIsPoisonedMessage(const SpeciesNames &species_name,
                                   const bool &is_toxic) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is under the effects of " << (is_toxic ? "toxic" : "poison")
            << std::endl;
}

void Gui::DisplayTookPoisonDamageMessage(const SpeciesNames &species_name,
                                         const int &damage_done) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " took " << damage_done << " damage from poison" << std::endl;
}

void Gui::DisplaySleepStartedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is now asleep" << std::endl;
}

void Gui::DisplayIsAsleepMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is asleep. It can't attack" << std::endl;
}

void Gui::DisplayWokeUpMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " woke up" << std::endl;
}

void Gui::DisplayRecoveredAllHpMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " recovered all of its hp" << std::endl;
}

void Gui::DisplayHazeResetMessage() {
  std::cout << "All Pokemon had all stat changes and statuses reset. They "
               "also had all light screens, reflects, and leech seeds removed"
            << std::endl;
}

void Gui::DisplayPokemonVanishedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " just vanished" << std::endl;
}

void Gui::DisplayChargingUpMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is charging up for the move" << std::endl;
}

void Gui::DisplayIsRechargingMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is recharging. It can only use pass" << std::endl;
}

void Gui::DisplayIsLockedInMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " will be locked in for 2-3 turns" << std::endl;
}

void Gui::DisplayLockInEndedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is no longer locked in" << std::endl;
}

void Gui::DisplayIsRagingMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is now raging. It will only stop when either Pokemon faints."
               " Its attack will raise by 1 step each turn it is damaged"
               " by the opponent until it ends"
            << std::endl;
}

void Gui::DisplayRageEndedMessage() {
  std::cout << "Rage ended for all active Pokemon" << std::endl;
}

} //namespace artificialtrainer