//
// Created by neel on 1/23/19.
//

#ifndef ARTIFICIAL_TRAINER_STATNAMES_H
#define ARTIFICIAL_TRAINER_STATNAMES_H

namespace artificialtrainer {
enum class StatNames : int {
  kAttack,
  kDefense,
  kSpecial,
  kSpeed,
  kHp,
  kAccuracy,
  kEvasion
};

const int kNumNormalStats = static_cast<int>(StatNames::kSpeed) + 1;
const int kNumExclusiveInGameStats =
    static_cast<int>(StatNames::kEvasion) - static_cast<int>(StatNames::kHp);

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_STATNAMES_H
