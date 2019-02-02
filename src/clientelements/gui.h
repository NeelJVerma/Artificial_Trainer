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
  static auto DisplayWelcomeMessage() -> void;
  static auto DisplayPickTeamMessage(const bool &player_one) -> void;
  static auto DisplayPokemonChoices() -> void;
  static auto DisplayPickPokemonMessage(const int &num) -> void;
  static auto DisplayInvalidChoiceMessage() -> void;
  static auto DisplayPickEvMessage(const StatNames &stat_name) -> void;
  static auto DisplayPickIvMessage(const StatNames &stat_name) -> void;
  static auto DisplayPickLevelMessage() -> void;
  static auto DisplayPokemonLearnset(
      const std::vector<MoveNames> &moveset) -> void;
  static auto DisplayPickMoveMessage(const int &move_number) -> void;
  static auto DisplayPlayerTeam(const Team &team,
                                const bool &player_one) -> void;
  static auto DisplayPickLeadingPokemonMessage(const bool &player_one) -> void;
  static auto DisplayActivePokemonData(const Pokemon &pokemon,
                                       const bool &player_one) -> void;
  static auto DisplayPickInBattleMoveMessage(const bool &player_one) -> void;
};

} // namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_GUI_H
