/**
 * @project Artificial Trainer
 * @brief A function to get the effectiveness of a type matchup.
 *
 * @file effectiveness.h
 * @author Neel Verma
 * @date 1/26/19
 */

#ifndef ARTIFICIAL_TRAINER_EFFECTIVENESS_H
#define ARTIFICIAL_TRAINER_EFFECTIVENESS_H

#include "type.h"

namespace artificialtrainer {
double Effectiveness(const TypeNames &attacking,
                     const TypeNames &defending);

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_EFFECTIVENESS_H