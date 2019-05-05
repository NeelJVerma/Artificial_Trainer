/**
 * @project Artificial Trainer
 * @brief The implementation of the Gui class.
 *
 * @file gui.cc
 * @author Neel Verma
 * @date 1/23/19
 */

#include <iostream>
#include "gui.h"
#include "../pokemon/speciesnames.h"
#include "../stringconverter/stringconverter.h"
#include "../move/basepower.h"

namespace artificialtrainer {

/**
  * @brief: Displays the welcome to the game message.
  */

void Gui::DisplayWelcomeMessage() {
  std::cout << "Welcome to Artificial Trainer, a Gen 1 battle simulator/AI!"
            << std::endl;
}

/**
  * @brief: Display an invalid choice message.
  */

void Gui::DisplayInvalidChoiceMessage() {
  std::cout << "Invalid choice. Select again." << std::endl;
}

/**
  * @brief: Displays a message denoting which team is picking its Pokemon.
  * @param const bool &player_one: Whether to display the message for
  * player one or two.
  */

void Gui::DisplayPickingTeamMessage(const bool &player_one) {
  std::cout << "Picking team for player " << (player_one ? "one" : "two")
            << std::endl;
}

/**
  * @brief: Displays a message denoting that the ai picked its leading Pokemon.
  * @param const SpeciesNames &species_name: The species name of the  Pokemon
  * the ai picked.
  */

void Gui::DisplayAiPickedLeadingPokemonMessage(
    const SpeciesNames &species_name) {
  std::cout << "The AI picked "
            << StringConverter::SpeciesToString(species_name)
            << " as its leading Pokemon" << std::endl;
}

/**
  * @brief: Displays a player's team.
  * @param const Team &team: The team to display.
  * @param const bool &player_one: Whether to display the team for
  * player one or two.
  */

void Gui::DisplayPlayerTeam(const Team &team, const bool &player_one) {
  std::vector<std::shared_ptr<Pokemon>> active_team = team.ActiveTeam();
  std::vector<std::shared_ptr<Pokemon>> fainted_team = team.FaintedTeam();

  std::cout << "Active team " << (player_one ? "one" : "two") << ':'
            << std::endl;
  int i = 1;

  for (const auto &pokemon : active_team) {
    std::cout << i++ << ". "
              << StringConverter::SpeciesToString(pokemon->SpeciesName())
              << ": " << pokemon->HpStat()->CurrentHp() << " hp." << std::endl;
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

/**
  * @brief: Displays a message denoting which team is picking its
  * leading Pokemon.
  * @param const bool &player_one: Whether to display the message for
  * player one or two.
  */

void Gui::DisplayPickLeadingPokemonMessage(const bool &player_one) {
  std::cout << "Player " << (player_one ? "one" : "two")
            << ", select your leading Pokemon" << std::endl;
}

/**
  * @brief: Displays the active Pokemon's data.
  * @param const std::shared_ptr<Pokemon> &pokemon: The Pokemon.
  * @param const bool &player_one: Whether to display the Pokemon data for
  * player one or two.
  */

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
  std::shared_ptr<Hp> hp_stat = pokemon->HpStat();
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

/**
  * @brief: Displays the current turn number.
  * @param const int &turn_number: The turn number.
  */

void Gui::DisplayTurnNumber(const int &turn_number) {
  std::cout << "Turn number: " << turn_number << std::endl;
}

/**
  * @brief: Displays a message telling the human to pick its move.
  */

void Gui::DisplayPickInBattleMoveMessage() {
  std::cout << "Human player, select your move" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the move used just failed.
  */

void Gui::DisplayMoveFailedMessage() {
  std::cout << "The move failed" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the move used just missed.
  */

void Gui::DisplayMoveMissedMessage() {
  std::cout << "The move missed" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon fainted.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that fainted.
  */

void Gui::DisplayPokemonFaintedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name) << " fainted"
            << std::endl;
}

/**
  * @brief: Displays a message telling the user that the one hit ko move
  * used just landed.
  */

void Gui::DisplayOneHitKoMoveLandedMessage() {
  std::cout << "The one hit ko move landed" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the move selected is
  * invalid.
  */

void Gui::DisplayInvalidMoveChoiceMessage() {
  std::cout << "Invalid move choice" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon used
  * the given move.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that used the move.
  * @param const MoveNames &move_name: The name of the move used by the Pokemon.
  */

void Gui::DisplayPokemonUsedMoveMessage(const SpeciesNames &species_name,
                                        const MoveNames &move_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " used "
            << StringConverter::MoveToString(move_name)
            << std::endl;
}

/**
  * @brief: Displays a message telling the user that the battle is over.
  */

void Gui::DisplayBattleOverMessage() {
  std::cout << "Battle over" << std::endl;
}

/**
  * @brief: Displays a message telling the user that Pokemon one switched out
  * into Pokemon two.
  * @param const SpeciesNames &one: The species name of the first Pokemon
  * @param const SpeciesNames &two: The species name of the second Pokemon.
  */

void Gui::DisplaySwitchMessage(const SpeciesNames &one,
                               const SpeciesNames &two) {
  std::cout << StringConverter::SpeciesToString(one)
            << " successfully switched out with "
            << StringConverter::SpeciesToString(two) << std::endl;
}

/**
  * @brief: Displays a message telling the user to pick a Pokemon to switch
  * into.
  */

void Gui::DisplayForceSwitchMessage() {
  std::cout << "Pick a Pokemon to switch into" << std::endl;
}

/**
  * @brief: Displays all of the switch options a given team has.
  * @param const Team &team: The team.
  */

void Gui::DisplayAvailableSwitchOptions(const Team &team) {
  std::cout << "Available switches:" << std::endl;
  int i = 1;

  for (const auto &pokemon : team.ActiveTeam()) {
    std::cout << i++ << ". "
              << StringConverter::SpeciesToString(pokemon->SpeciesName())
              << ": " << pokemon->HpStat()->CurrentHp() << " hp." << std::endl;
  }
}

/**
  * @brief: Displays a message telling the user that the move used just
  * landed a critical hit.
  */

void Gui::DisplayMoveCritMessage() {
  std::cout << "The move landed a critical hit" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the move used had no
  * effect.
  */

void Gui::DisplayMoveHadNoEffectMessage() {
  std::cout << "The move had no effect" << std::endl;
}

/**
  * @brief: Displays the amount of damage done by the move.
  * @param const int &damage_done: The amount of damage done.
  */

void Gui::DisplayDamageDoneMessage(const int &damage_done) {
  std::cout << "The move did " << damage_done << " damage" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the move wasn't very
  * effective.
  */

void Gui::DisplayNotVeryEffectiveMessage() {
  std::cout << "The move was not very effective" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the move was super
  * effective.
  */

void Gui::DisplaySuperEffectiveMessage() {
  std::cout << "The move was super effective" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon flinched.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that flinched.
  */

void Gui::DisplayFlinchedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name) << " flinched"
            << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is now
  * confused.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is confused.
  */

void Gui::DisplayConfusedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is confused" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon just
  * hit itself in its confusion.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that hit itself.
  */

void Gui::DisplayHitSelfMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " hit itself in confusion" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon just
  * absorbed a given amount of hp.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that flinched.
  * @param const int &absorbed: The amaount of hp absorbed by the Pokemon.
  */

void Gui::DisplayHpAbsorbedMessage(const SpeciesNames &species_name,
                                   const int &absorbed) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " absorbed " << absorbed << " hp" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon
  * snapped out of its confusion.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that snapped out of confusion.
  */

void Gui::DisplayConfusionEndedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << "\'s confusion ended" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon
  * started its confusion.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is confused.
  */

void Gui::DisplayConfusionStartedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " became confused" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon's
  * disable ended.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that had its disable stopped.
  */

void Gui::DisplayDisableEndedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << "\'s disable ended" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given move is now
  * disabled.
  * @param const MoveNames &move_name: The name of the move that was disabled.
  */

void Gui::DisplayMoveDisabledMessage(const MoveNames &move_name) {
  std::cout << StringConverter::MoveToString(move_name)
            << " is disabled" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon had
  * recoil damage.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that had recoil damage.
  * @param const int &damage_done: The amount of recoil damage taken.
  */

void Gui::DisplayRecoilDamageMessage(const SpeciesNames &species_name,
                                     const int &damage_done) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " took " << damage_done << " recoil damage" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon copied
  * the given move.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that copied the move.
  * @param const MoveNames &move_name: The name of the move that just got
  * copied.
  */

void Gui::DisplayPokemonCopiedMoveMessage(const SpeciesNames &species_name,
                                          const MoveNames &move_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " copied " << StringConverter::MoveToString(move_name)
            << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is now
  * under mist.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is under mist.
  */

void Gui::DisplayMistStartedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is now under mist. It is protected from negative stat changes"
            << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is
  * currently under mist.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is under mist.
  */

void Gui::DisplayIsUnderMistMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is under mist. Its stats won't go lower" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is now
  * behind a substitute.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is behind the substitute.
  */

void Gui::DisplaySubstituteStartedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is now behind a substitute" << std::endl;
}

/**
  * @brief: Displays a message telling the user that a substitute took damage
  * @param const int &damage_done: The amount of damage done.
  */

void Gui::DisplaySubstituteTookDamageMessage(const int &damage_done) {
  std::cout << "The substitute took " << damage_done << " damage" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon's
  * substitute faded away.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is no longer behind a substitute.
  */

void Gui::DisplaySubstituteFadedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << "\'s substitute faded" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is
  * currently behind a substitute.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is behind a substitute.
  */

void Gui::DisplayIsBehindSubstituteMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is behind a substitute. The move failed" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is now
  * burned.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is burned.
  */

void Gui::DisplayBurnStartedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " became burned" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is
  * currently burned.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is burned.
  */

void Gui::DisplayIsBurnedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is burned" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon took
  * burn damage.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that took damage.
  * @param const int &damage_done: The amount of burn damage taken.
  */

void Gui::DisplayTookBurnDamageMessage(const SpeciesNames &species_name,
                                       const int &damage_done) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " took " << damage_done << " damage from its burn" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is
  * currently under the effects of leech seed.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is under the effects of leech seed.
  */

void Gui::DisplayIsSeededMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is seeded" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is now
  * under the effects of leech seed.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is under the effects of leech seed.
  */

void Gui::DisplayLeechSeedStartedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is now under the effects of leech seed" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon had
  * its hp sapped.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that had its hp sapped.
  * @param const int &sapped: The amount of hp taken from the Pokemon.
  */

void Gui::DisplayHadHpSappedMessage(const SpeciesNames &species_name,
                                    const int &sapped) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " had " << sapped << " hp sapped from it" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is now
  * frozen.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is frozen.
  */

void Gui::DisplayFreezeStartedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is now frozen" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is
  * currently frozen.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is frozen.
  */

void Gui::DisplayIsFrozenMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is frozen. It can't attack" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is now
  * paralyzed.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is paralyzed.
  */

void Gui::DisplayParalysisStartedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is now paralyzed" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is
  * fully paralyzed.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is fully paralyzed.
  */

void Gui::DisplayFullyParalyzedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is fully paralyzed. It can't attack" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is now
  * poisoned.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is poisoned.
  * @param const bool &is_toxic: Denotes whether the poison is toxic or not.
  */

void Gui::DisplayPoisonStartedMessage(const SpeciesNames &species_name,
                                      const bool &is_toxic) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is now "
            << (is_toxic ? "badly poisoned from toxic" : "poisoned")
            << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is
  * currently poisoned.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is poisoned.
  * @param const bool &is_toxic: Denotes whether the poison is toxic or not.
  */

void Gui::DisplayIsPoisonedMessage(const SpeciesNames &species_name,
                                   const bool &is_toxic) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is under the effects of " << (is_toxic ? "toxic" : "poison")
            << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon took
  * poison damage.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is poisoned.
  * @param const int &damage_done: The amount of damage the poison did to the
  * Pokemon.
  */

void Gui::DisplayTookPoisonDamageMessage(const SpeciesNames &species_name,
                                         const int &damage_done) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " took " << damage_done << " damage from poison" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is
  * now asleep.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is asleep.
  */

void Gui::DisplaySleepStartedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is now asleep" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is
  * currently asleep.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is asleep.
  */

void Gui::DisplayIsAsleepMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is asleep. It can't attack" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon just
  * woke up.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is woke up.
  */

void Gui::DisplayWokeUpMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " woke up" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon
  * recovered all of its hp.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that had its hp recovered.
  */

void Gui::DisplayRecoveredAllHpMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " recovered all of its hp" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given haze was just
  * used.
  */

void Gui::DisplayHazeResetMessage() {
  std::cout << "All Pokemon had all stat changes and statuses reset. They "
               "also had all light screens, reflects, and leech seeds removed"
            << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon just
  * vanished.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is vanished.
  */

void Gui::DisplayPokemonVanishedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " just vanished" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is
  * charging up.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is charging up.
  */

void Gui::DisplayChargingUpMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is charging up for the move" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is
  * must recharge.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that must recharge.
  */

void Gui::DisplayMustRechargeMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is recharging. It must use pass" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is
  * now locked in.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is locked in.
  */

void Gui::DisplayIsLockedInMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " will be locked in for 2-3 turns" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is
  * no longer locked in.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is no longer locked in.
  */

void Gui::DisplayLockInEndedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is no longer locked in" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is
  * now raging.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is raging.
  */

void Gui::DisplayIsRagingMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is now raging. It will only stop when either Pokemon faints."
               " Its attack will raise by 1 step each turn it is damaged"
               " by the opponent until it ends"
            << std::endl;
}

/**
  * @brief: Displays a message telling the user that rage ended for all Pokemon.
  */

void Gui::DisplayRageEndedMessage() {
  std::cout << "Rage ended for all active Pokemon" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is
  * now trapped.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is trapped.
  */

void Gui::DisplayIsTrappedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is now trapped. It can't make attacks of its own" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon used a
  * trap move.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that used a trap move.
  */

void Gui::DisplayUsedTrapMoveMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " used a trap move. It must use this move until this"
            << " wears off" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is
  * no longer trapped.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is no longer trapped.
  */

void Gui::DisplayTrapEndedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is no longer trapped" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the a given Pokemon
  * transformed into another Pokemon.
  * @param const SpeciesNames &user: The species name of the Pokemon
  * that transformed.
  * @param const SpeciesNames &target: The species name of the Pokemon that
  * the transformer transformed into.
  */

void Gui::DisplayTransformMessage(const SpeciesNames &user,
                                  const SpeciesNames &target) {
  std::cout << StringConverter::SpeciesToString(user)
            << " transformed into "
            << StringConverter::SpeciesToString(target) << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is
  * is now biding.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is biding.
  */

void Gui::DisplayIsBidingMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is now biding" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon's bide
  * ended.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is no longer biding.
  */

void Gui::DisplayBideEndedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << "\'s bide ended. It will now send back 2x the damage it took"
            << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon is
  * must complete its vanish move.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is vanished.
  */

void Gui::DisplayMustFinishVanishMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is vanished. It must complete its move" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon must
  * finish its charge up move.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is charging up.
  */

void Gui::DisplayMustFinishChargingUpMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is charging up. It must complete its move" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon must
  * finish its lock in move.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is locked in.
  */

void Gui::DisplayMustFinishLockInMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is locked in. It must complete its move" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon must
  * remain trapped.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that trapped.
  */

void Gui::DisplayMustRemainTrappedMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is trapped. It must use pass" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon must
  * finish biding.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is biding.
  */

void Gui::DisplayMustFinishBideMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is biding. It must use pass" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon can't
  * pass.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that can't pass.
  */

void Gui::DisplayCantPassMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " cannot use pass at this time" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon must
  * finish raging.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is raging.
  */

void Gui::DisplayMustFinishRagingMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " must finish its rage" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon must
  * finish its trap move.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is using a trap move.
  */

void Gui::DisplayMustFinishTrapMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is using a trap move. It must complete its move" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon had
  * its stats changed.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that had its stats changed.
  * @param const StatNames &stat_name: The name of the stat that was changed.
  * @param const int &num_stages: The number of stages the stat changed by.
  */

void Gui::DisplayStatChangeMessage(const SpeciesNames &species_name,
                                   const StatNames &stat_name,
                                   const int &num_stages) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " had its " << StringConverter::StatToString(stat_name)
            << (num_stages < 0 ? " lowered" : " raised") << " by "
            << abs(num_stages) << " stages" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the ai picked its forced
  * switch.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that is now active.
  */

void Gui::DisplayAiForceSwitchMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " is the ai's switch choice. It is now active" << std::endl;
}

/**
  * @brief: Displays a message telling the user that the given Pokemon can't
  * use struggle.
  * @param const SpeciesNames &species_name: The species name of the Pokemon
  * that can't use struggle.
  */

void Gui::DisplayCantUseStruggleMessage(const SpeciesNames &species_name) {
  std::cout << StringConverter::SpeciesToString(species_name)
            << " can't use struggle at this time" << std::endl;
}

} //namespace artificialtrainer