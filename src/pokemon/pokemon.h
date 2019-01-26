//
// Created by neel on 1/23/19.
//

#ifndef ARTIFICIAL_TRAINER_POKEMON_H
#define ARTIFICIAL_TRAINER_POKEMON_H

#include "species.h"
#include "../stat/statscontainer.h"

namespace artificialtrainer {
class Pokemon {
 public:
  static const int kMaxLevel = 100;
  
  Pokemon(const Pokemon &pokemon) = default;
  Pokemon& operator=(const Pokemon &pokemon) = delete;
  Pokemon() = default;
  Pokemon(const Species &species, const StatsContainer &statsContainer, const
  int &level);

 private:
  StatsContainer statsContainer_;
  Species species_;
  int level_;
  // moves
  // types
  // statuses
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_POKEMON_H
