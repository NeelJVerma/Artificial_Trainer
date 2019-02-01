//
// Created by neel on 1/25/19.
//

#include <string>
#include <iostream>
#include <algorithm>
#include "inputhandler.h"
#include "sanitizer.h"
#include "../pokemon/speciesnames.h"
#include "gui.h"

namespace artificialtrainer {
auto InputHandler::GetIntInput(const int lower, const int upper) -> int {
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