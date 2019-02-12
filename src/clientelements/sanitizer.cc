//
// Created by neel on 1/24/19.
//

#include "sanitizer.h"

namespace artificialtrainer {
bool Sanitizer::CheckIntegerInput(const int &lower, const int &upper,
                                  const int &check_var) {
  return check_var <= upper && check_var >= lower;
}

} //namespace artificialtrainer