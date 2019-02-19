//
// Created by neel on 1/23/19.
//

#ifndef ARTIFICIAL_TRAINER_GUI_H
#define ARTIFICIAL_TRAINER_GUI_H

#include <iostream>
#include <vector>
#include "../stat/statnames.h"
#include "../move/movenames.h"
#include "../team/team.h"

namespace artificialtrainer {
class Gui {
 public:
  static void DisplayWelcomeMessage();
  static void DisplayPickTeamMessage(const bool &player_one);
  static void DisplayPokemonChoices();
  static void DisplayPickPokemonMessage(const int &num);
  static void DisplayInvalidChoiceMessage();
  static void DisplayPickEvMessage(const StatNames &stat_name);
  static void DisplayPickIvMessage(const StatNames &stat_name);
  static void DisplayPickLevelMessage();
  static void DisplayPokemonLearnset(
      const std::vector<MoveNames> &moveset);
  static void DisplayPickMoveMessage(const int &move_number);
  static void DisplayPlayerTeam(const Team &team,
                                const bool &player_one);
  static void DisplayPickLeadingPokemonMessage(const bool &player_one);
  static void DisplayActivePokemonData(const std::shared_ptr<Pokemon> &pokemon,
                                       const bool &player_one);
  static void DisplayTurnNumber(const int &turn_number);
  static void DisplayPickInBattleMoveMessage(const bool &player_one);
  static void DisplayMoveFailedMessage();
  static void DisplayMoveMissedMessage();
  static void DisplayOneHitKoMoveLandedMessage();
  static void DisplayPokemonFaintedMessage(const SpeciesNames &species_name);
  static void DisplayInvalidMoveChoiceMessage();
  static void DisplayPokemonUsedMoveMessage(const SpeciesNames &species_name,
                                            const MoveNames &move_name);
  static void DisplayBattleOverMessage();
  static void DisplaySwitchMessage(const SpeciesNames &one,
                                   const SpeciesNames &two);
  static void DisplayForceSwitchMessage();
  static void DisplayAvailableSwitchOptions(const Team &team);
  static void DisplayMoveCritMessage();
  static void DisplayMoveHadNoEffectMessage();
  static void DisplayDamageDoneMessage(const int &damage_done);
  static void DisplayNotVeryEffectiveMessage();
  static void DisplaySuperEffectiveMessage();
  static void DisplayHpAbsorbedMessage(const SpeciesNames &species_name,
                                       const int &absorbed);
  static void DisplayFlinchedMessage(const SpeciesNames &species_name);
  static void DisplayConfusedMessage(const SpeciesNames &species_name);
  static void DisplayConfusionStartedMessage(const SpeciesNames &species_name);
  static void DisplayHitSelfMessage(const SpeciesNames &species_name);
  static void DisplayConfusionEndedMessage();
  static void DisplayDisableEndedMessage();
  static void DisplayMoveDisabledMessage(const MoveNames &move_name);
  static void DisplayRecoilDamageMessage(const SpeciesNames &species_name,
                                         const int &damage_done);
  static void DisplayPokemonCopiedMoveMessage(const SpeciesNames &species_name,
                                              const MoveNames &move_name);
  static void DisplayMistStartedMessage(const SpeciesNames &species_name);
  static void DisplayIsUnderMistMessage(const SpeciesNames &species_name);
  static void DisplayIsBehindSubstituteMessage(
      const SpeciesNames &species_name);
  static void DisplaySubstituteTooKDamageMessage(const int &damage_done);
  static void DisplaySubstituteFadedMessage(const SpeciesNames &species_name);
  static void DisplayIsBehindSubstituteMessage();
  static void DisplayBurnStartedMessage(const SpeciesNames &species_name);
  static void DisplayIsBurnedMessage(const SpeciesNames &species_name);
};

} // namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_GUI_H
