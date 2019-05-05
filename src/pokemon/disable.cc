/**
 * @project Artificial Trainer
 * @brief The implementation of the Disable class.
 *
 * @file disable.cc
 * @author Neel Verma
 * @date 2/16/19
 */

#include "disable.h"
#include "../random/randomgenerator.h"

namespace artificialtrainer {
const int Disable::kMaxTurns = 7;

/**
  * @brief: The default constructor for the Disable class.
  */

Disable::Disable() : num_turns_disabled_(0) {
}

/**
  * @brief: A function that denotes whether or not disable is active.
  * @return bool: Whether or not disable is active.
  */

bool Disable::IsActive() const {
  return static_cast<bool>(num_turns_disabled_);
}

/**
  * @brief: A function that activates a Pokemon's disable.
  */

void Disable::Activate() {
  if (IsActive()) {
    return;
  }

  num_turns_disabled_ = 1;
}

/**
  * @brief: A function that denotes whether or not disable will end.
  * @return: Whether or not disable will end.
  */

bool Disable::WillEnd() const {
  if (num_turns_disabled_ == 1) {
    return false;
  }

  return RandomIntDistribution(2, kMaxTurns) == num_turns_disabled_;
}

/**
  * @brief: A function that advances disable by one turn.
  */

void Disable::AdvanceOneTurn() {
  if (!IsActive()) {
    return;
  }

  if (num_turns_disabled_ == kMaxTurns || WillEnd()) {
    num_turns_disabled_ = 0;
  } else {
    num_turns_disabled_++;
  }
}

} //namespace artificialtrainer