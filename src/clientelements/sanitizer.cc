//
// Created by neel on 1/24/19.
//

#include "sanitizer.h"

namespace artificialtrainer {
auto Sanitizer::CheckIntegerInput(const int &lower, const int &upper,
                                  const int &check_var) -> bool {
  return (check_var <= upper && check_var >= lower);
}

} //namespace artificialtrainer