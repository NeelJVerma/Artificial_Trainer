/**
 * @project Artificial Trainer
 * @brief The implementation of the Iv class.
 *
 * @file iv.cc
 * @author Neel Verma
 * @date 1/25/19
 */

#include "iv.h"

namespace artificialtrainer {
const int Iv::kMaxIv = 15;

/**
  * @brief: A constructor for the Iv class.
  * @param const int &value: The value to set.
  */

Iv::Iv(const int &value) {
  value_ = value;
}

/**
  * @brief: An accessor for the value.
  * @return bool: The value.
  */

int Iv::Value() const {
  return value_;
}

} //namespace artificialtrainer