//
// Created by neel on 2/15/19.
//

#ifndef ARTIFICIAL_TRAINER_STATUSNAMES_H
#define ARTIFICIAL_TRAINER_STATUSNAMES_H

namespace artificialtrainer {
enum class StatusNames : int {
  kClear,
  kBurned,
  kFrozen,
  kAsleep,
  kAsleepRest,
  kParalyzed,
  kPoisoned,
  kPoisonedToxic
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_STATUSNAMES_H
