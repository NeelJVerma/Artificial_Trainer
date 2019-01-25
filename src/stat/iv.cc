//
// Created by neel on 1/25/19.
//

#include "iv.h"

namespace artificialtrainer {
Iv::Iv(const int &value) {
  value_ = value;
}

auto Iv::Value() const -> int {
  return value_;
}

auto Iv::operator=(const Iv &iv) -> Iv& {
  value_ = iv.Value();
}

} //namespace artificialtrainer