//
// Created by neel on 2/6/19.
//

#ifndef ARTIFICIAL_TRAINER_USEMOVE_H
#define ARTIFICIAL_TRAINER_USEMOVE_H

#include "../pokemon/pokemon.h"

namespace artificialtrainer {
enum class MoveResults : int {
  kAttackerSwitched,
  kDefenderSwitched,
  kSuccess,
  kAttackerFainted,
  kDefenderFainted
};

auto UseMove(std::shared_ptr<Pokemon> attacker,
             std::shared_ptr<Pokemon> defender) -> MoveResults;

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_USEMOVE_H
