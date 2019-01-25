//
// Created by neel on 1/23/19.
//

#ifndef ARTIFICIAL_TRAINER_GUI_H
#define ARTIFICIAL_TRAINER_GUI_H

#include <iostream>

namespace artificialtrainer {
class Gui {
 public:
  static auto DisplayWelcomeMessage() -> void;
  static auto DisplayPickTeamMessage(const bool &player_one) -> void;
  static auto DisplayPokemonChoices() -> void;
  static auto DisplayPickPokemonMessage(const int &num) -> void;
  static auto DisplayInvalidChoiceMessage() -> void;
};

} // namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_GUI_H
