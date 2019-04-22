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
  Team human_team_;
  Team ai_team_;
  bool BattleOver() const;
  void HandleTurn();
  void StartBattle();
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_BATTLE_H
