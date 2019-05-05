/**
 * @project Artificial Trainer
 * @brief The Ev class.
 *
 * @file ev.h
 * @author Neel Verma
 * @date 1/25/19
 */

#ifndef ARTIFICIAL_TRAINER_EV_H
#define ARTIFICIAL_TRAINER_EV_H

namespace artificialtrainer {

/**
 * @brief The Ev class. This class tracks an ev value. The resaon I gave it a
 * class was to give it more of a symbolic name as opposed to just an integer
 * value.
 *
 * @author Neel Verma
 * @date 1/25/19
 */

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
