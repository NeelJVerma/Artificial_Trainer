/**
 * @project Artificial Trainer
 * @brief A function to get the entire learnset of a given Pokemon.
 *
 * @file learnset.h
 * @author Neel Verma
 * @date 1/27/19
 */

#ifndef ARTIFICIAL_TRAINER_LEARNSET_H
#define ARTIFICIAL_TRAINER_LEARNSET_H

#include <vector>
#include "speciesnames.h"
#include "../move/movenames.h"

namespace artificialtrainer {
std::vector<MoveNames> Learnset(const SpeciesNames &species_name);

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_LEARNSET_H
