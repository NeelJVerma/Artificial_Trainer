/**
 * @project Artificial Trainer
 * @brief An implementation of the Priority function.
 *
 * @file priority.cc
 * @author Neel Verma
 * @date 1/30/19
 */

#include "priority.h"

namespace artificialtrainer {

/**
  * @brief: This function gets priority of a given move.
  * @param const MoveNames &move_name: The name of the move to get the
  * priority of.
  * @return int: The priority of the move.
  */

int Priority(const MoveNames &move_name) {
  switch (move_name) {
    case MoveNames::kSwitch1:
    case MoveNames::kSwitch2:
    case MoveNames::kSwitch3:
    case MoveNames::kSwitch4:
    case MoveNames::kSwitch5:
    case MoveNames::kSwitch6:
    case MoveNames::kPass:
      return 2;
    case MoveNames::kQuickAttack:
      return 1;
    case MoveNames::kCounter:
      return -1;
    default:
      return 0;
  }
}

} //namespace artificialtrainer