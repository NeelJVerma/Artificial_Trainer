//
// Created by neel on 1/23/19.
//

#ifndef ARTIFICIAL_TRAINER_STATNAMES_H
#define ARTIFICIAL_TRAINER_STATNAMES_H

namespace artificialtrainer {
enum class StatNames : int {
  kHp,
  kAttack,
  kDefense,
  kSpecial,
  kSpeed,
  kAccuracy,
  kEvasion
};

const int kNumNormalStats = static_cast<int>(StatNames::kSpeed);

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_STATNAMES_H
