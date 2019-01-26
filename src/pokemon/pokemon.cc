//
// Created by neel on 1/23/19.
//

#include "pokemon.h"

namespace artificialtrainer {
Pokemon::Pokemon(const Species &species, const StatsContainer
&statsContainer, const int &level) : species_(species), statsContainer_
(statsContainer), level_(level) {
}

} //namespace artificialtrainer