//
// Created by neel on 4/20/19.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "expectimax.h"
#include "../battlemanager/battlemanager.h"
#include "../stringconverter/stringconverter.h"
#include "../move/usemove.h"
#include "../clientelements/gui.h"

namespace artificialtrainer {
namespace {
std::vector<MoveNode> AllValidMoves(const Team &team) {
  MovesContainer moves_container = team.ActiveMember()->GetMovesContainer();
  std::vector<MoveNode> valid_moves;

  for (int i = 0; i < moves_container.Size(); i++) {
    std::shared_ptr<Move> move = moves_container[i];

    if (BattleManager::IsValidMoveChoice(team, move, true)) {
      valid_moves.emplace_back(MoveNode(i));
    }
  }

  return valid_moves;
}

double Heuristic(const Team &human_team, const Team &ai_team,
                 const int &depth) {
  std::shared_ptr<Hp> human_hp = human_team.ActiveMember()->HpStat();
  std::shared_ptr<Hp> ai_hp = ai_team.ActiveMember()->HpStat();
  return ((static_cast<double>(ai_hp->CurrentHp()) / ai_hp->MaxHp()) - 3 *
      (static_cast<double>(human_hp->CurrentHp()) / human_hp->MaxHp()) - 0.3 *
      depth);
}

double ExpectiMaxHelper(Team &human_team,
                        Team &ai_team,
                        int depth,
                        double alpha,
                        double beta,
                        std::vector<MoveNode> &root_values) {
  if (depth > 7 || ai_team.ActiveTeam().empty() ||
      human_team.ActiveTeam().empty()) {
    return Heuristic(human_team, ai_team, depth);
  }

  Team saved_human(human_team.ActiveTeam(), human_team.FaintedTeam(), true);
  Team saved_ai(ai_team.ActiveTeam(), ai_team.FaintedTeam(), false);
  std::vector<double> scores;

  for (auto &move : (depth & 1 ? AllValidMoves(human_team) : AllValidMoves(
      ai_team))) {
    if (depth & 1) {
      human_team.ActiveMember()->SetMoveUsed(
          human_team.ActiveMember()->GetMovesContainer()[
              move.MoveIndex()]);
      if (!human_team.ActiveMember()->IsFainted() &&
          !ai_team.ActiveMember()->IsFainted()) {
        UseMove(human_team, ai_team, true);
        BattleManager::HandleEndOfTurnStatuses(human_team.ActiveMember(),
                                               ai_team.ActiveMember(), true);
      }

      BattleManager::HandleFainting(false, human_team, ai_team, true);
      scores.push_back(
          ExpectiMaxHelper(
              human_team, ai_team, depth + 1, alpha, beta, root_values));

      if (move.HeuristicValue() < beta) {
        beta = move.HeuristicValue();
      }

      if (alpha >= beta) {
        break;
      }
    } else {
      ai_team.ActiveMember()->SetMoveUsed(
          ai_team.ActiveMember()->GetMovesContainer()[move.MoveIndex()]);

      if (!human_team.ActiveMember()->IsFainted() &&
          !ai_team.ActiveMember()->IsFainted()) {
        UseMove(ai_team, human_team, true);
      }

      double score = ExpectiMaxHelper(
          human_team, ai_team, depth + 1, alpha, beta, root_values);
      scores.push_back(score);

      if (move.HeuristicValue() > alpha) {
        alpha = move.HeuristicValue();
      }

      if (beta <= alpha) {
        break;
      }

      if (!depth) {
        move.SetHeuristicValue(score);
        root_values.push_back(move);
      }
    }

    human_team = Team(
        saved_human.ActiveTeam(), saved_human.FaintedTeam(), true);
    ai_team = Team(saved_ai.ActiveTeam(), saved_ai.FaintedTeam(), false);
  }

  if (depth & 1) {
    return *std::min_element(scores.begin(), scores.end());
  }

  return *std::max_element(scores.begin(), scores.end());
}

} //namespace

MoveNode ExpectiMax(Team &human_team, Team &ai_team) {
  std::vector<MoveNode> root_values;
  auto max_int = static_cast<double>(std::numeric_limits<int>::max());
  ExpectiMaxHelper(human_team,
                   ai_team,
                   0,
                   max_int * -1.0,
                   max_int,
                   root_values);
  return *std::max_element(root_values.begin(), root_values.end(), [](
      const MoveNode &one,
      const MoveNode &two) {
    return one.HeuristicValue() > two.HeuristicValue();
  });
}

} //namespace artificialtrainer