//
// Created by neel on 2/22/19.
//

#include <random>
#include "bide.h"

namespace artificialtrainer {
Bide::Bide() : num_turns_active_(0), damage_added_(0) {
}

bool Bide::IsActive() const {
  return static_cast<bool>(num_turns_active_);
}

void Bide::Activate() {
  if (IsActive()) {
    return;
  }

  num_turns_active_ = 1;
}

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

void Bide::SetDamageAdded(const int &damage_added) {
  damage_added_ = damage_added;
}

void Bide::AddDamage() {
  total_damage_ += damage_added_;
}

int Bide::TotalDamage() const {
  return total_damage_;
}

} //namespace artificialtrainer