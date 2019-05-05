/**
 * @project Artificial Trainer
 * @brief The InputHandler class.
 *
 * @file inputhandler.h
 * @author Neel Verma
 * @date 1/25/19
 */

#ifndef ARTIFICIAL_TRAINER_INPUTHANDLER_H
#define ARTIFICIAL_TRAINER_INPUTHANDLER_H

namespace artificialtrainer {

/**
 * @brief The InputHandler class. This static class is responsible for all
 * console input.
 *
 * @author Neel Verma
 * @date 1/25/19
 */

class InputHandler {
 public:
  static int GetIntInput(const int lower, const int upper);
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_INPUTHANDLER_H
