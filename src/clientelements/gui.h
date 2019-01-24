//
// Created by neel on 1/23/19.
//

#ifndef ARTIFICIAL_TRAINER_GUI_H
#define ARTIFICIAL_TRAINER_GUI_H

#include <iostream>

namespace artificialtrainer {
class Gui {
 public:
  static void DisplayWelcomeMessage();
  static void DisplayPickTeamMessage(const bool &player_one);
  static void DisplayPokemonChoices();
  static void DisplayPickPokemonMessage(const unsigned &num);
  static void DisplayInvalidChoiceMessage();
};

} // namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_GUI_H
