//
// Created by neel on 1/27/19.
//

#ifndef ARTIFICIAL_TRAINER_LEARNSET_H
#define ARTIFICIAL_TRAINER_LEARNSET_H

#include <vector>
#include "speciesnames.h"
#include "../move/movenames.h"

namespace artificialtrainer {
std::vector<MoveNames> Learnset(const SpeciesNames &species_name);

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_LEARNSET_H
