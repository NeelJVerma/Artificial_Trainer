/**
 * @project Artificial Trainer
 * @brief The Battle class.
 *
 * @file battle.h
 * @author Neel Verma
 * @date 1/25/19
 */

#ifndef ARTIFICIAL_TRAINER_BATTLE_H
#define ARTIFICIAL_TRAINER_BATTLE_H

#include "../team/team.h"

namespace artificialtrainer {

/**
 * @brief The Battle class. This class is responsible for executing a
 * complete battle.
 *
 * @author Neel Verma
 * @date 1/25/19
 */

class Battle {
 public:
  Battle();
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
