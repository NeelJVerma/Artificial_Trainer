/**
 * @project Artificial Trainer
 * @brief The implementation of the Ev class.
 *
 * @file ev.cc
 * @author Neel Verma
 * @date 1/25/19
 */

#include "ev.h"

namespace artificialtrainer {
const int Ev::kMaxEv = 65535;

/**
  * @brief: A constructor for the Ev class.
  * @param const int &value: The value to set.
  */

Ev::Ev(const int &value) {
  value_ = value;
}

/**
  * @brief: An accessor for the value.
  * @return bool: The value.
  */

int Ev::Value() const {
  return value_;
}

} //namespace artificialtrainer