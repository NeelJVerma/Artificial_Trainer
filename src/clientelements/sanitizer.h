//
// Created by neel on 1/24/19.
//

#ifndef ARTIFICIAL_TRAINER_SANITIZER_H
#define ARTIFICIAL_TRAINER_SANITIZER_H

namespace artificialtrainer {
class Sanitizer {
 public:
  static bool CheckIntegerInput(const unsigned &lower, const unsigned &upper, const unsigned &check_var);
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_SANITIZER_H
