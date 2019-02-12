//
// Created by neel on 1/26/19.
//

#ifndef ARTIFICIAL_TRAINER_BASEPOWER_H
#define ARTIFICIAL_TRAINER_BASEPOWER_H

#include "movenames.h"

namespace artificialtrainer {
enum class PowerClasses : int {
  kNone,
  kVariable,
  kOneHitKo,
  kUnchanged
};

int BasePower(const MoveNames &move_name);

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_BASEPOWER_H
