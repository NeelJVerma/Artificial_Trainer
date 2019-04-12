//
// Created by neel on 1/25/19.
//

#include "iv.h"

namespace artificialtrainer {
const int Iv::kMaxIv = 15;

Iv::Iv(const int &value) {
  value_ = value;
}

int Iv::Value() const {
  return value_;
}

} //namespace artificialtrainer