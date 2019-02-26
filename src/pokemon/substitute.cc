//
// Created by neel on 2/19/19.
//

#include "substitute.h"

namespace artificialtrainer {
Substitute::Substitute() : current_hp_(0) {
}

void Substitute::Activate(const int &current_hp) {
  current_hp_ = current_hp;
}

bool Substitute::IsActive() const {
  return static_cast<bool>(current_hp_);
}

void Substitute::TakeDamage(const int &damage_done) {
  if (current_hp_ - damage_done <= 0) {
    current_hp_ = 0;
  } else {
    current_hp_ -= damage_done;
  }
}

int Substitute::CurrentHp() const {
  return current_hp_;
}

} //namespace artificialtrainer