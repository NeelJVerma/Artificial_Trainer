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
  void Play();

 private:
  const int kMaxNumTurns = 100;
  Team team_one_;
  Team team_two_;
  bool BattleOver() const;
  void StartBattle();
  void HandleTurn();
  void PlayerPicksMove(Team &team, const bool &team_one);
  bool HandleMove(Team &attacker, Team &defender);
  void PlayerPicksForcedSwitch(Team &team);
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_BATTLE_H
