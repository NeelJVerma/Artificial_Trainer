/**
 * @project Artificial Trainer
 * @brief The Disable class.
 *
 * @file disable.h
 * @author Neel Verma
 * @date 2/16/19
 */

#ifndef ARTIFICIAL_TRAINER_DISABLE_H
#define ARTIFICIAL_TRAINER_DISABLE_H

namespace artificialtrainer {

/**
 * @brief The Disable class. This class is responsible for keeping track of
 * the state of a Pokemon's disable, it it gets a move disabled.
 *
 * @author Neel Verma
 * @date 2/16/19
 */

class Disable {
 public:
  Disable(const Disable &disable) = default;
  Disable &operator=(const Disable &disable) = default;
  Disable();
  bool IsActive() const;
  void Activate();
  void AdvanceOneTurn();

 private:
  static const int kMaxTurns;
  int num_turns_disabled_;
  bool WillEnd() const;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_DISABLE_H