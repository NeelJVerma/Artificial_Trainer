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
  const int kMaxNumTurns = 100;
  Team team_one_;
  Team team_two_;
  auto BattleOver() const -> bool;
  auto StartBattle() -> void;
  auto HandleTurn() -> void;
  auto HandleMove(const std::shared_ptr<Pokemon> &attacker,
                  const std::shared_ptr<Pokemon> &defender,
                  const bool &attacker_on_team_one) -> void;
  auto PlayerPicksMove(Team &team, const bool &team_one) -> void;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_BATTLE_H
