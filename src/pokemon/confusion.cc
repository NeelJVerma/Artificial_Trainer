//
// Created by neel on 2/16/19.
//

#include <random>
#include "confusion.h"
#include "../clientelements/gui.h"

namespace artificialtrainer {
Confusion::Confusion() : num_turns_confused_(0) {
}

bool Confusion::IsActive() const {
  return static_cast<bool>(num_turns_confused_);
}

bool Confusion::Activate() {
  if (IsActive()) {
    return false;
  }

  num_turns_confused_ = 1;
  return true;
}

void Confusion::AdvanceOneTurn() {
  if (!IsActive()) {
    return;
  }

  if (num_turns_confused_ == kMaxTurns || WillBreakOut()) {
    Gui::DisplayConfusionEndedMessage();
    num_turns_confused_ = 0;
  } else {
    num_turns_confused_++;
  }
}

bool Confusion::WillBreakOut() const {
  if (num_turns_confused_ == 1) {
    return false;
  }

  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<> distribution(2, kMaxTurns);
  return distribution(generator) == num_turns_confused_;
}

} //namespace artificialtrainer