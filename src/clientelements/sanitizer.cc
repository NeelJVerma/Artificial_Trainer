//
// Created by neel on 1/24/19.
//

#include "sanitizer.h"

namespace artificialtrainer {
bool Sanitizer::CheckIntegerInput(const unsigned &lower, const unsigned &upper, const unsigned &check_var) {
  return (check_var <= upper && check_var >= lower);
}

} //namespace artificialtrainer