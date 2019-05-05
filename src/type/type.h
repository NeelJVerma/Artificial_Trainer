/**
 * @project Artificial Trainer
 * @brief A function to get the type of a move.
 *
 * @file type.h
 * @author Neel Verma
 * @date 1/26/19
 */

#ifndef ARTIFICIAL_TRAINER_TYPE_H
#define ARTIFICIAL_TRAINER_TYPE_H

#include "../move/movenames.h"
#include "typenames.h"

namespace artificialtrainer {
TypeNames Type(const MoveNames &move_name);

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_TYPE_H
