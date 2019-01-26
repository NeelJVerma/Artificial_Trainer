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
  auto operator=(const Iv &iv) -> Iv& = default;
  Iv() = default;
  explicit Iv(const int &value);

  auto Value() const -> int;

 private:
  int value_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_IV_H
