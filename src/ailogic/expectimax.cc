//
// Created by neel on 4/20/19.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cassert>
#include "expectimax.h"
#include "../battlemanager/battlemanager.h"
#include "../stringconverter/stringconverter.h"
#include "../move/usemove.h"
#include "../clientelements/gui.h"

namespace artificialtrainer {
namespace {
const int kMaxDepth = 7;

std::vector<MoveNode> AllValidMoves(const Team &team) {
  MovesContainer moves_container = team.ActiveMember()->GetMovesContainer();
  std::vector<MoveNode> valid_moves;

  for (int i = 0; i < moves_container.Size(); i++) {
    std::shared_ptr<Move> move = moves_container[i];

    if (BattleManager::IsValidMoveChoice(team, move, true) &&
        !IsSwitch(move->MoveName())) {
      valid_moves.emplace_back(MoveNode(i));
    }
  }

  return valid_moves;
}

double Heuristic(const Team &attacking_team, const Team &defending_team,
                 const int &depth) {
  std::shared_ptr<Hp> attacker_hp = attacking_team.ActiveMember()->HpStat();
  std::shared_ptr<Hp> defender_hp = defending_team.ActiveMember()->HpStat();
  return ((static_cast<double>(
      attacker_hp->CurrentHp()) / attacker_hp->MaxHp()) -
      (static_cast<double>(
          defender_hp->CurrentHp()) / defender_hp->MaxHp()));
}

double ExpectiMaxHelper(Team &human_team,
                        Team &ai_team,
                        int depth,
                        double alpha,
                        double beta,
                        std::vector<MoveNode> &root_values) {
  if (depth > kMaxDepth || ai_team.ActiveTeam().empty() ||
      human_team.ActiveTeam().empty()) {
    if (depth & 1) {
      return Heuristic(human_team, ai_team, depth);
    }

    return Heuristic(ai_team, human_team, depth);
  }

  Team saved_human = Team(human_team.ActiveTeam(),
                          human_team.FaintedTeam(),
                          true);
  Team saved_ai = Team(ai_team.ActiveTeam(), ai_team.FaintedTeam(), false);
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
    if (scores.empty()) {
      return static_cast<double>(std::numeric_limits<int>::max());
    }

    return *std::min_element(scores.begin(), scores.end());
  }

  if (scores.empty()) {
    return static_cast<double>(std::numeric_limits<int>::max()) * -1;
  }

  return *std::max_element(scores.begin(), scores.end());
}

MoveNode FindFirstSwitch(const Team &team) {
  MovesContainer moves_container = team.ActiveMember()->GetMovesContainer();

  for (int i = 0; i < moves_container.Size(); i++) {
    std::shared_ptr<Move> move = moves_container[i];

    if (BattleManager::IsValidMoveChoice(team, move, true) &&
        IsSwitch(move->MoveName())) {
      return MoveNode(i);
    }
  }

  assert(false);
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
  bool found_good_move = false;
  bool switching_is_valid = false;

  for (const auto &move : root_values) {
    if (move.HeuristicValue() > 0.0) {
      found_good_move = true;
    }

    std::shared_ptr<Move> move_ptr =
        ai_team.ActiveMember()->GetMovesContainer()[move.MoveIndex()];

    if (BattleManager::IsValidMoveChoice(ai_team, move_ptr, true) &&
        IsSwitch(move_ptr->MoveName())) {
      switching_is_valid = true;
    }
  }

  if (!found_good_move && ai_team.ActiveTeam().size() > 1 &&
      switching_is_valid) {
    return FindFirstSwitch(ai_team);
  }

  return *std::max_element(root_values.begin(), root_values.end(), [](
      const MoveNode &one,
      const MoveNode &two) {
    return one.HeuristicValue() < two.HeuristicValue();
  });
}

} //namespace artificialtrainer