/**
 * @project Artificial Trainer
 * @brief The Gui class.
 *
 * @file gui.h
 * @author Neel Verma
 * @date 1/23/19
 */

#ifndef ARTIFICIAL_TRAINER_GUI_H
#define ARTIFICIAL_TRAINER_GUI_H

#include <vector>
#include "../stat/statnames.h"
#include "../move/movenames.h"
#include "../team/team.h"

namespace artificialtrainer {

/**
 * @brief The Gui class. This static class is responsible for all console
 * output.
 *
 * @author Neel Verma
 * @date 1/23/19
 */

class Gui {
 public:
  static void DisplayWelcomeMessage();
  static void DisplayInvalidChoiceMessage();
  static void DisplayPickingTeamMessage(const bool &player_one);
  static void DisplayPlayerTeam(const Team &team,
                                const bool &player_one);
  static void DisplayPickLeadingPokemonMessage(const bool &player_one);
  static void DisplayAiPickedLeadingPokemonMessage(
      const SpeciesNames &species_name);
  static void DisplayActivePokemonData(const std::shared_ptr<Pokemon> &pokemon,
                                       const bool &player_one);
  static void DisplayTurnNumber(const int &turn_number);
  static void DisplayPickInBattleMoveMessage();
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
  static void DisplayConfusionEndedMessage(const SpeciesNames &species_name);
  static void DisplayDisableEndedMessage(const SpeciesNames &species_name);
  static void DisplayMoveDisabledMessage(const MoveNames &move_name);
  static void DisplayRecoilDamageMessage(const SpeciesNames &species_name,
                                         const int &damage_done);
  static void DisplayPokemonCopiedMoveMessage(const SpeciesNames &species_name,
                                              const MoveNames &move_name);
  static void DisplayMistStartedMessage(const SpeciesNames &species_name);
  static void DisplayIsUnderMistMessage(const SpeciesNames &species_name);
  static void DisplaySubstituteStartedMessage(
      const SpeciesNames &species_name);
  static void DisplaySubstituteTookDamageMessage(const int &damage_done);
  static void DisplaySubstituteFadedMessage(const SpeciesNames &species_name);
  static void DisplayIsBehindSubstituteMessage(
      const SpeciesNames &species_name);
  static void DisplayBurnStartedMessage(const SpeciesNames &species_name);
  static void DisplayIsBurnedMessage(const SpeciesNames &species_name);
  static void DisplayTookBurnDamageMessage(const SpeciesNames &species_name,
                                           const int &damage_done);
  static void DisplayIsSeededMessage(const SpeciesNames &species_name);
  static void DisplayLeechSeedStartedMessage(const SpeciesNames &species_name);
  static void DisplayHadHpSappedMessage(const SpeciesNames &species_name,
                                        const int &sapped);
  static void DisplayFreezeStartedMessage(const SpeciesNames &species_name);
  static void DisplayIsFrozenMessage(const SpeciesNames &species_name);
  static void DisplayParalysisStartedMessage(const SpeciesNames &species_name);
  static void DisplayFullyParalyzedMessage(const SpeciesNames &species_name);
  static void DisplayPoisonStartedMessage(const SpeciesNames &species_name,
                                          const bool &is_toxic);
  static void DisplayIsPoisonedMessage(const SpeciesNames &species_name,
                                       const bool &is_toxic);
  static void DisplayTookPoisonDamageMessage(const SpeciesNames &species_name,
                                             const int &damage_done);
  static void DisplaySleepStartedMessage(const SpeciesNames &species_name);
  static void DisplayIsAsleepMessage(const SpeciesNames &species_name);
  static void DisplayWokeUpMessage(const SpeciesNames &species_name);
  static void DisplayRecoveredAllHpMessage(const SpeciesNames &species_name);
  static void DisplayHazeResetMessage();
  static void DisplayPokemonVanishedMessage(const SpeciesNames &species_name);
  static void DisplayChargingUpMessage(const SpeciesNames &species_name);
  static void DisplayIsLockedInMessage(const SpeciesNames &species_name);
  static void DisplayLockInEndedMessage(const SpeciesNames &species_name);
  static void DisplayIsRagingMessage(const SpeciesNames &species_name);
  static void DisplayRageEndedMessage();
  static void DisplayIsTrappedMessage(const SpeciesNames &species_name);
  static void DisplayUsedTrapMoveMessage(const SpeciesNames &species_name);
  static void DisplayTrapEndedMessage(const SpeciesNames &species_name);
  static void DisplayTransformMessage(const SpeciesNames &user,
                                      const SpeciesNames &target);
  static void DisplayIsBidingMessage(const SpeciesNames &species_name);
  static void DisplayBideEndedMessage(const SpeciesNames &species_name);
  static void DisplayMustFinishVanishMessage(const SpeciesNames &species_name);
  static void DisplayMustFinishChargingUpMessage(
      const SpeciesNames &species_name);
  static void DisplayMustFinishLockInMessage(const SpeciesNames &species_name);
  static void DisplayMustRemainTrappedMessage(const SpeciesNames &species_name);
  static void DisplayMustRechargeMessage(const SpeciesNames &species_name);
  static void DisplayMustFinishBideMessage(const SpeciesNames &species_name);
  static void DisplayCantPassMessage(const SpeciesNames &species_name);
  static void DisplayMustFinishRagingMessage(const SpeciesNames &species_name);
  static void DisplayMustFinishTrapMessage(const SpeciesNames &species_name);
  static void DisplayStatChangeMessage(const SpeciesNames &species_name,
                                       const StatNames &stat_name,
                                       const int &num_stages);
  static void DisplayAiForceSwitchMessage(const SpeciesNames &species_name);
  static void DisplayCantUseStruggleMessage(const SpeciesNames &species_name);
};

} // namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_GUI_H
