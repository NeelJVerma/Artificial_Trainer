//
// Created by neel on 1/30/19.
//

#include "priority.h"

namespace artificialtrainer {
auto Priority(const MoveNames &move_name) -> int {
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