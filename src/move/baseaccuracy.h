//
// Created by neel on 1/26/19.
//

#ifndef ARTIFICIAL_TRAINER_ACCURACY_H
#define ARTIFICIAL_TRAINER_ACCURACY_H

#include "movenames.h"

namespace artificialtrainer {
const int kNeverMiss = 101;

int BaseAccuracy(const MoveNames &move_name);

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_ACCURACY_H
