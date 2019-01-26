//
// Created by neel on 1/23/19.
//

#ifndef ARTIFICIAL_TRAINER_GUI_H
#define ARTIFICIAL_TRAINER_GUI_H

#include <iostream>
#include "../stat/statnames.h"

namespace artificialtrainer {
class Gui {
 public:
  static auto DisplayWelcomeMessage() -> void;
  static auto DisplayPickTeamMessage(const bool &player_one) -> void;
  static auto DisplayPokemonChoices() -> void;
  static auto DisplayPickPokemonMessage(const int &num) -> void;
  static auto DisplayInvalidChoiceMessage() -> void;
  static auto DisplayPickEvMessage(StatNames stat_name) -> void;
  static auto DisplayPickIvMessage(StatNames stat_name) -> void;
  static auto DisplayPickLevelMessage() -> void;
};

} // namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_GUI_H
