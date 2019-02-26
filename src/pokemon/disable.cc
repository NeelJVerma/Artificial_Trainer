//
// Created by neel on 2/16/19.
//

#include <random>
#include "disable.h"

namespace artificialtrainer {
Disable::Disable() : num_turns_disabled_(0) {
}

bool Disable::IsActive() const {
  return static_cast<bool>(num_turns_disabled_);
}

void Disable::Activate() {
  if (IsActive()) {
    return;
  }

  num_turns_disabled_ = 1;
}

void Disable::AdvanceOneTurn() {
  if (!IsActive()) {
    return;
  }

  if (num_turns_disabled_ == kMaxTurns || WillReEnable()) {
    num_turns_disabled_ = 0;
  } else {
    num_turns_disabled_++;
  }
}

bool Disable::WillReEnable() const {
  if (num_turns_disabled_ == 1) {
    return false;
  }

  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<> distribution(2, kMaxTurns);
  return distribution(generator) == num_turns_disabled_;
}

} //namespace artificialtrainer