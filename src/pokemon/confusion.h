/**
 * @project Artificial Trainer
 * @brief The Confusion class.
 *
 * @file confusion.h
 * @author Neel Verma
 * @date 2/16/19
 */

#ifndef ARTIFICIAL_TRAINER_CONFUSION_H
#define ARTIFICIAL_TRAINER_CONFUSION_H

namespace artificialtrainer {

/**
 * @brief The Confusion class. This class is responsible for keeping track of
 * the state of a Pokemon's confusion, it it gets confused.
 *
 * @author Neel Verma
 * @date 2/16/19
 */

class Confusion {
 public:
  Confusion(const Confusion &confusion) = default;
  Confusion &operator=(const Confusion &confusion) = default;
  Confusion();
  bool IsActive() const;
  void Activate();
  void AdvanceOneTurn();

 private:
  static const int kMaxTurns;
  int num_turns_confused_;
  bool WillEnd() const;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_CONFUSION_H
