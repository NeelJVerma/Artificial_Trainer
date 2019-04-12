//
// Created by neel on 1/25/19.
//

#include "ev.h"

namespace artificialtrainer {
const int Ev::kMaxEv = 65535;

Ev::Ev(const int &value) {
  value_ = value;
}

int Ev::Value() const {
  return value_;
}

} //namespace artificialtrainer