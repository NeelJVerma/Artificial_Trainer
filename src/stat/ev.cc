//
// Created by neel on 1/25/19.
//

#include "ev.h"

namespace artificialtrainer {
Ev::Ev(const int &value) {
  value_ = value;
}

auto Ev::Value() const -> int {
  return value_;
}

} //namespace artificialtrainer