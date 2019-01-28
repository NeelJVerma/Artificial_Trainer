//
// Created by neel on 1/25/19.
//

#ifndef ARTIFICIAL_TRAINER_BATTLE_H
#define ARTIFICIAL_TRAINER_BATTLE_H

#include "../team/team.h"

namespace artificialtrainer {
class Battle {
 public:
  Battle() = default;
  auto Play() -> void;

 private:
  Team team_one_;
  Team team_two_;
  auto BattleOver() const -> bool;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_BATTLE_H
