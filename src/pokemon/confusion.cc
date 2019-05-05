/**
 * @project Artificial Trainer
 * @brief The implementation of the Confusion class.
 *
 * @file confusion.cc
 * @author Neel Verma
 * @date 2/16/19
 */

#include "confusion.h"
#include "../random/randomgenerator.h"

namespace artificialtrainer {
const int Confusion::kMaxTurns = 4;

/**
  * @brief: The default constructor for the Confusion class.
  */

Confusion::Confusion() : num_turns_confused_(0) {
}

/**
  * @brief: A function that denotes whether or not confusion is active.
  * @return bool: Whether or not confusion is active.
  */

bool Confusion::IsActive() const {
  return static_cast<bool>(num_turns_confused_);
}

/**
  * @brief: A function that activates a Pokemon's confusion.
  */

void Confusion::Activate() {
  if (IsActive()) {
    return;
  }

  num_turns_confused_ = 1;
}

/**
  * @brief: A function that denotes whether or not confusion will end.
  * @return: Whether or not confusion will end.
  */

bool Confusion::WillEnd() const {
  if (num_turns_confused_ == 1) {
    return false;
  }

  return RandomIntDistribution(2, kMaxTurns) == num_turns_confused_;
}

/**
  * @brief: A function that advances confusion by one turn.
  */

void Confusion::AdvanceOneTurn() {
  if (!IsActive()) {
    return;
  }

  if (num_turns_confused_ == kMaxTurns || WillEnd()) {
    num_turns_confused_ = 0;
  } else {
    num_turns_confused_++;
  }
}

} //namespace artificialtrainer