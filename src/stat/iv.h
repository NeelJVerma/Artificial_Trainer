//
// Created by neel on 1/25/19.
//

#ifndef ARTIFICIAL_TRAINER_IV_H
#define ARTIFICIAL_TRAINER_IV_H

namespace artificialtrainer {
class Iv {
 public:
  static const int kMaxIv = 15;
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
