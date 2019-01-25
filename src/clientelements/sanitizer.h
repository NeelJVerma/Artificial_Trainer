//
// Created by neel on 1/24/19.
//

#ifndef ARTIFICIAL_TRAINER_SANITIZER_H
#define ARTIFICIAL_TRAINER_SANITIZER_H

namespace artificialtrainer {
class Sanitizer {
 public:
  static auto CheckIntegerInput(const int &lower, const int &upper,
      const int &check_var) -> bool;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_SANITIZER_H
