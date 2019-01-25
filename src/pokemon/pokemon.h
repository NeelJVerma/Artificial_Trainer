//
// Created by neel on 1/23/19.
//

#ifndef ARTIFICIAL_TRAINER_POKEMON_H
#define ARTIFICIAL_TRAINER_POKEMON_H

#include "species.h"

namespace artificialtrainer {
class Pokemon {
 public:
  Pokemon(const Pokemon &pokemon) = default;
  Pokemon& operator=(const Pokemon &pokemon) = delete;
  Pokemon() = default;

 private:
  int hp_;
  int attack_;
  int defense_;
  int special_;
  int speed_;
  int accuracy_;
  int evasion_;
  Species species_;
  // moves
  // types
  // statuses
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_POKEMON_H
