//
// Created by neel on 1/25/19.
//

#ifndef ARTIFICIAL_TRAINER_INPUTHANDLER_H
#define ARTIFICIAL_TRAINER_INPUTHANDLER_H

namespace artificialtrainer {
class InputHandler {
 public:
  static auto GetIntInput(const int lower, const int upper) -> int;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_INPUTHANDLER_H
