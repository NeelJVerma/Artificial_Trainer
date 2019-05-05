/**
 * @project Artificial Trainer
 * @brief The implementation of the Sanitizer class.
 *
 * @file sanitizer.cc
 * @author Neel Verma
 * @date 1/24/19
 */

#include "sanitizer.h"

namespace artificialtrainer {

/**
  * @brief: This function checks if the input is valid.
  * @param const int lower: The lower bound of the input range.
  * @param const int upper: The upper bound of the input range.
  * @param const int &check_var: The input being checked.
  * @return bool: Whether or not the input was valid.
  */

bool Sanitizer::CheckIntegerInput(const int &lower, const int &upper,
                                  const int &check_var) {
  return check_var <= upper && check_var >= lower;
}

} //namespace artificialtrainer