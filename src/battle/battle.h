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
  void StartBattle();
  void HandleTurn();

  // WILL UPDATE AFTER MINIMAX
  void PlayerPicksMove(Team &team, const bool &team_one);
  void ReplaceMovesWithStruggleIfNeeded();
  bool HumanMovesFirst() const;
  bool HandleMove(Team &attacker, Team &defender);
  void HumanPicksForcedSwitch();
  void HandleEndOfTurnStatuses(const std::shared_ptr<Pokemon> &attacker,
                               const std::shared_ptr<Pokemon> &defender);
  void HandleFainting(const bool &human_moves_first);
  void HandleBothTeamsMoves(const bool &human_moves_first);
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_BATTLE_H
