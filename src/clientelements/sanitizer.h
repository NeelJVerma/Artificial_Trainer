/**
 * @project Artificial Trainer
 * @brief The Sanitizer class.
 *
 * @file sanitizer.h
 * @author Neel Verma
 * @date 1/24/19
 */

#ifndef ARTIFICIAL_TRAINER_SANITIZER_H
#define ARTIFICIAL_TRAINER_SANITIZER_H

namespace artificialtrainer {

/**
 * @brief The Sanitizer class. This static class is responsible for
 * validation of all console input.
 *
 * @author Neel Verma
 * @date 1/24/19
 */

class Sanitizer {
 public:
  static bool CheckIntegerInput(const int &lower, const int &upper,
                                const int &check_var);
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_SANITIZER_H
