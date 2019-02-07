//
// Created by neel on 2/6/19.
//

#ifndef ARTIFICIAL_TRAINER_USEMOVE_H
#define ARTIFICIAL_TRAINER_USEMOVE_H

#include "../pokemon/pokemon.h"

namespace artificialtrainer {
auto UseMove(std::shared_ptr<Pokemon> attacker,
             std::shared_ptr<Pokemon> defender) -> void;

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_USEMOVE_H
