/**
 * @project Artificial Trainer
 * @brief The implementation of the Bide class.
 *
 * @file bide.cc
 * @author Neel Verma
 * @date 2/22/19
 */

#include <random>
#include "bide.h"

namespace artificialtrainer {

/**
  * @brief: The default constructor for the Bide class.
  */

Bide::Bide() : num_turns_active_(0), damage_added_(0), total_damage_(0) {
}

/**
  * @brief: A function that denotes whether or not bide is active.
  * @return bool: Whether or not bide is active.
  */

bool Bide::IsActive() const {
  return static_cast<bool>(num_turns_active_);
}

/**
  * @brief: A function that activates a Pokemon's bide.
  */

void Bide::Activate() {
  if (IsActive()) {
    return;
  }

  num_turns_active_ = 1;
}

/**
  * @brief: A function that advances the bide counter by one turn.
  * @return bool: Whether or not bide ended on the current advance.
  */

bool Bide::AdvanceOneTurn() {
  if (!IsActive()) {
    return false;
  }

  if (num_turns_active_ >= kMaxTurns) {
    return true;
  }

  num_turns_active_++;
  return false;
}

/**
  * @brief: A mutator for damage added. If no damage was done on a turn, bid
  * will add the previous damage taken, which is why we need to track this.
  * @param const int &damage_added: The damage added.
  */

void Bide::SetDamageAdded(const int &damage_added) {
  damage_added_ = damage_added;
}

/**
  * @brief: A function that adds damage to the current bide.
  */

void Bide::AddDamage() {
  total_damage_ += damage_added_;
}

/**
  * @brief: An accessor for the total damage.
  * @return int: The total damage.
  */

int Bide::TotalDamage() const {
  return total_damage_;
}

} //namespace artificialtrainer