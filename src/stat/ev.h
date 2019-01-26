//
// Created by neel on 1/25/19.
//

#ifndef ARTIFICIAL_TRAINER_EV_H
#define ARTIFICIAL_TRAINER_EV_H

namespace artificialtrainer {
class Ev {
 public:
  static const int kMaxEv = 65535;

  Ev(const Ev &ev) = default;
  auto operator=(const Ev &ev) -> Ev& = default;
  Ev() = default;
  explicit Ev(const int &value);

  auto Value() const -> int;

 private:
  int value_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_EV_H
