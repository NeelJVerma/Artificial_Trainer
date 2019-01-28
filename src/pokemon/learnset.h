//
// Created by neel on 1/27/19.
//

#ifndef ARTIFICIAL_TRAINER_LEARNSET_H
#define ARTIFICIAL_TRAINER_LEARNSET_H

#include <vector>
#include "species.h"
#include "../move/moves.h"

namespace artificialtrainer {
auto Learnset(const Species &species) -> std::vector<Moves>;

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_LEARNSET_H
