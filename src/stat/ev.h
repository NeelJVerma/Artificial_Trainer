//
// Created by neel on 1/25/19.
//

#ifndef ARTIFICIAL_TRAINER_EV_H
#define ARTIFICIAL_TRAINER_EV_H

namespace artificialtrainer {
class Ev {
 public:
  static const int kMaxEv;
  Ev(const Ev &ev) = default;
  Ev &operator=(const Ev &ev) = default;
  Ev() = default;
  explicit Ev(const int &value);
  int Value() const;

 private:
  int value_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_EV_H
