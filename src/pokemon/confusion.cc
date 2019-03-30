//
// Created by neel on 2/16/19.
//

#include "confusion.h"
#include "../random/randomgenerator.h"

namespace artificialtrainer {
Confusion::Confusion() : num_turns_confused_(0) {
}

bool Confusion::IsActive() const {
  return static_cast<bool>(num_turns_confused_);
}

void Confusion::Activate() {
  if (IsActive()) {
    return;
  }

  num_turns_confused_ = 1;
}

void Confusion::AdvanceOneTurn() {
  if (!IsActive()) {
    return;
  }

  if (num_turns_confused_ == kMaxTurns || WillBreakOut()) {
    num_turns_confused_ = 0;
  } else {
    num_turns_confused_++;
  }
}

bool Confusion::WillBreakOut() const {
  if (num_turns_confused_ == 1) {
    return false;
  }

  return RandomIntDistribution(2, kMaxTurns) == num_turns_confused_;
}

} //namespace artificialtrainer