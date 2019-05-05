/**
 * @project Artificial Trainer
 * @brief A function to get the base accuracy of a given move.
 *
 * @file baseaccuracy.h
 * @author Neel Verma
 * @date 1/26/19
 */

#ifndef ARTIFICIAL_TRAINER_ACCURACY_H
#define ARTIFICIAL_TRAINER_ACCURACY_H

#include "movenames.h"

namespace artificialtrainer {
const int kNeverMiss = 101;

int BaseAccuracy(const MoveNames &move_name);

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_ACCURACY_H
