/**
 * @project Artificial Trainer
 * @brief The Iv class.
 *
 * @file iv.h
 * @author Neel Verma
 * @date 1/25/19
 */

#ifndef ARTIFICIAL_TRAINER_IV_H
#define ARTIFICIAL_TRAINER_IV_H

namespace artificialtrainer {

/**
 * @brief The Iv class. This class tracks an iv value. The resaon I gave it a
 * class was to give it more of a symbolic name as opposed to just an integer
 * value.
 *
 * @author Neel Verma
 * @date 1/25/19
 */

class Iv {
 public:
  static const int kMaxIv;
  Iv(const Iv &iv) = default;
  Iv &operator=(const Iv &iv) = default;
  Iv() = default;
  explicit Iv(const int &value);
  int Value() const;

 private:
  int value_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_IV_H
