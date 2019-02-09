//
// Created by neel on 2/6/19.
//

#ifndef ARTIFICIAL_TRAINER_USEMOVE_H
#define ARTIFICIAL_TRAINER_USEMOVE_H

#include "../team/team.h"
namespace artificialtrainer {
enum class MoveResults : int {
  kAttackerSwitched,
  kDefenderSwitched,
  kSuccess,
  kAttackerFainted,
  kDefenderFainted
};

auto UseMove(Team &attacker, Team &defender) -> void;

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_USEMOVE_H
