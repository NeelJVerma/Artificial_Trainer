//
// Created by neel on 1/26/19.
//

#ifndef ARTIFICIAL_TRAINER_EFFECTIVENESS_H
#define ARTIFICIAL_TRAINER_EFFECTIVENESS_H

#include "type.h"

namespace artificialtrainer {
auto Effectiveness(const TypesNames &attacking,
                   const TypesNames &defending) -> double;

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_EFFECTIVENESS_H