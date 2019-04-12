//
// Created by neel on 4/6/19.
//

#ifndef ARTIFICIAL_TRAINER_TYPESUM_H
#define ARTIFICIAL_TRAINER_TYPESUM_H

#include "../pokemon/pokemon.h"

namespace artificialtrainer {
int TypeSum(const std::shared_ptr<Pokemon> &pokemon_one,
            const std::shared_ptr<Pokemon> &pokemon_two);

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_TYPESUM_H
