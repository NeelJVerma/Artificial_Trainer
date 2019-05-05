/**
 * @project Artificial Trainer
 * @brief The implementation of the InputHandler class.
 *
 * @file inputhandler.cc
 * @author Neel Verma
 * @date 1/25/19
 */

#include <string>
#include <iostream>
#include <algorithm>
#include "inputhandler.h"
#include "sanitizer.h"
#include "../pokemon/speciesnames.h"
#include "gui.h"

namespace artificialtrainer {

/**
  * @brief: This function gets int input from the user.
  * @param const int lower: The lower bound of the input range.
  * @param const int upper: The upper bound of the input range.
  * @return int: The int input, which is validated.
  */

int InputHandler::GetIntInput(const int lower, const int upper) {
  int return_int;

  while (true) {
    std::string input;
    getline(std::cin, input);

    if (!input.length() ||
        !std::all_of(input.begin(), input.end(), ::isdigit)) {
      continue;
    }

    return_int = std::stoi(input);

    if (Sanitizer::CheckIntegerInput(lower, upper, return_int)) {
      break;
    }

    Gui::DisplayInvalidChoiceMessage();
  }

  return return_int;
}

} //namespace artificialtrainer