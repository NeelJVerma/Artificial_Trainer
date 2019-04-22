//
// Created by neel on 4/20/19.
//

#ifndef ARTIFICIAL_TRAINER_BATTLEMANAGER_H
#define ARTIFICIAL_TRAINER_BATTLEMANAGER_H

#include "../team/team.h"

namespace artificialtrainer {
class BattleManager {
 public:
  static void HumanPicksMove(Team &team);
  static bool IsValidMoveChoice(const Team &team,
                                const std::shared_ptr<Move> &move,
                                const bool &is_called_by_ai);
  static bool HumanMovesFirst(const Team &human_team, const Team &ai_team);
  static bool HandleMove(Team &attacker, Team &defender);
  static void HumanPicksForcedSwitch(Team &human_team);
  static bool IsValidSwitchChoice(const Team &team, const int &index);
  static void HandleEndOfTurnStatuses(const std::shared_ptr<Pokemon> &attacker,
                                      const std::shared_ptr<Pokemon> &defender);
  static void HandleFainting(const bool &human_moves_first, Team &human_team,
                             Team &ai_team);
  static void HandleBothTeamsMoves(const bool &human_moves_first,
                                   Team &human_team, Team &ai_team);
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_BATTLEMANAGER_H
