//
// Created by neel on 1/26/19.
//

#ifndef ARTIFICIAL_TRAINER_TYPE_H
#define ARTIFICIAL_TRAINER_TYPE_H

#include "../move/movenames.h"
#include "typenames.h"

namespace artificialtrainer {
auto Type(const MoveNames &move_name) -> TypeNames;

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_TYPE_H