/**
 * @project Artificial Trainer
 * @brief The implementation of the Substitute class.
 *
 * @file substitute.cc
 * @author Neel Verma
 * @date 2/19/19
 */

#include "substitute.h"

namespace artificialtrainer {

/**
  * @brief: The default constructor for the Substitute class.
  */

Substitute::Substitute() : current_hp_(0) {
}

/**
  * @brief: A function that activates a Pokemon's substitute.
  */

void Substitute::Activate(const int &current_hp) {
  current_hp_ = current_hp;
}

/**
  * @brief: A function that denotes whether or not substitute is active.
  * @return bool: Whether or not substitute is active.
  */

bool Substitute::IsActive() const {
  return static_cast<bool>(current_hp_);
}

/**
  * @brief: A function that takes damage for the substitute
  * @param const int &damage_done: The damage done.
  */

void Substitute::TakeDamage(const int &damage_done) {
  if (current_hp_ - damage_done <= 0) {
    current_hp_ = 0;
  } else {
    current_hp_ -= damage_done;
  }
}

} //namespace artificialtrainer