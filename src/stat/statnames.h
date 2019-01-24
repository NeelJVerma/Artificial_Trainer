//
// Created by neel on 1/23/19.
//

#ifndef ARTIFICIAL_TRAINER_STATNAMES_H
#define ARTIFICIAL_TRAINER_STATNAMES_H

namespace artificialtrainer {
enum class StatNames : unsigned {
  kHp,
  kAttack,
  kDefense,
  kSpecial,
  kSpeed,
  kAccuracy,
  kEvasion
};

const unsigned kNumNormalStats = static_cast<unsigned>(StatNames::kSpeed);

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_STATNAMES_H
