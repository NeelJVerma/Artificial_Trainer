//
// Created by neel on 1/23/19.
//

#ifndef ARTIFICIAL_TRAINER_POKEMON_H
#define ARTIFICIAL_TRAINER_POKEMON_H

#include "species.h"

namespace artificialtrainer {
class Pokemon {
 public:
  Pokemon(const Pokemon &pokemon) = delete;
  Pokemon& operator=(const Pokemon &pokemon) = delete;
  Pokemon() = default;

 private:
  unsigned hp_;
  unsigned attack_;
  unsigned defense_;
  unsigned special_;
  unsigned speed_;
  unsigned accuracy_;
  unsigned evasion_;
  Species species_;
  // moves
  // types
  // statuses
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_POKEMON_H
