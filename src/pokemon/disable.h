//
// Created by neel on 2/16/19.
//

#ifndef ARTIFICIAL_TRAINER_DISABLE_H
#define ARTIFICIAL_TRAINER_DISABLE_H

namespace artificialtrainer {
class Disable {
 public:
  Disable(const Disable &disable) = default;
  Disable &operator=(const Disable &disable) = default;
  Disable();
  bool IsActive() const;
  void Activate();
  void AdvanceOneTurn();

 private:
  static const int kMaxTurns = 7;
  int num_turns_disabled_;
  bool WillReEnable() const;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_DISABLE_H