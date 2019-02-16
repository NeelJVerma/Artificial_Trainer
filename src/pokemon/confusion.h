//
// Created by neel on 2/16/19.
//

#ifndef ARTIFICIAL_TRAINER_CONFUSION_H
#define ARTIFICIAL_TRAINER_CONFUSION_H

namespace artificialtrainer {
class Confusion {
 public:
  Confusion(const Confusion &confusion) = default;
  Confusion &operator=(const Confusion &confusion) = default;
  Confusion();
  bool IsActive() const;
  bool Activate();
  void AdvanceOneTurn();

 private:
  static const int kMaxTurns = 4;
  int num_turns_confused_;
  bool WillBreakOut() const;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_CONFUSION_H
