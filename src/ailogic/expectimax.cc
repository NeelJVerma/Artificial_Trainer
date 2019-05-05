/**
 * @project Artificial Trainer
 * @brief Implementation of the expect minimax.
 *
 * @file expectimax.cc
 * @author Neel Verma
 * @date 4/20/19
 */

#include <algorithm>
#include <cassert>
#include "expectimax.h"
#include "../battlemanager/battlemanager.h"
#include "../stringconverter/stringconverter.h"
#include "../move/usemove.h"
#include "../clientelements/gui.h"

namespace artificialtrainer {
namespace {
const int kMaxDepth = 7; // Max depth for the minimax.

/**
  * @brief: A function to return all the valid moves a particular Pokemon has
  * at a given moment.
  * @param const Team &team: The team whose turn it currently is in the minimax
  * tree.
  * @return std::vector<MoveNode>: A vector of all moves the current Pokemon
  * can make at the time this function is called.
  */

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

/**
  * @brief: Gives the heuristic value for a certain game state. The heuristic
  * used is (ac / am) - (dc / dm), where ac, am, dc, and dm are the attacker
  * current hp and max hp, and the defender's current hp and max hp,
  * respectively.
  * @param const Team &attacking_team: The team that is attacking. The
  * heuristic is going to be relative to the attacking team.
  * @param const Team &defending_team: The defending team. You have the
  * option of passing in individual Pokemon, but when I optimize my
  * evaluation function, the teams will need to be passed in.
  * @return double: The heuristic value for the current attacker and game state.
  */

double Heuristic(const Team &attacking_team, const Team &defending_team) {
  std::shared_ptr<Hp> attacker_hp = attacking_team.ActiveMember()->HpStat();
  std::shared_ptr<Hp> defender_hp = defending_team.ActiveMember()->HpStat();
  return ((static_cast<double>(
      attacker_hp->CurrentHp()) / attacker_hp->MaxHp()) -
      (static_cast<double>(
          defender_hp->CurrentHp()) / defender_hp->MaxHp()));
}

/**
  * @brief: The minimax algorithm. This is a very raw version of the
  * algorithm with respect to this specific game. Because there are actions
  * that need to be handled after both players have moved and who moves first
  * is determined on speed, it was hard to handle in the time frame. So, I
  * have the ai always moving first and such actions described happen on an
  * odd depth, since the ai calls from depth 0, the human on 1, and so on.
  * @param Team &human_team: The human's team.
  * @param Team &ai_team: The ai's team.
  * @param: const int &depth: The depth the tree is currently at.
  * @param double alpha: The alpha value for a given node.
  * @param double beta: The beta value for a given node.
  * @param: std::vector<MoveNode> &root_values: The is a vector of all of the
  * moves the ai has available on the turn the minimax is called. This vector
  * gets filled at a depth of 0, because the ai has those moves immediately
  * available.
  * @return double: The heurisitc value for a given node, which is propogated
  * up the tree.
  */

double ExpectiMaxHelper(Team &human_team,
                        Team &ai_team,
                        const int &depth,
                        double alpha,
                        double beta,
                        std::vector<MoveNode> &root_values) {
  if (depth > kMaxDepth || ai_team.ActiveTeam().empty() ||
      human_team.ActiveTeam().empty()) {
    if (depth & 1) {
      return Heuristic(human_team, ai_team);
    }

    return Heuristic(ai_team, human_team);
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

/**
  * @brief: A function to find the first switch the ai has available. This
  * function is only called for the ai, and in the case where it found no
  * "optimal" moves and has at least one switch available.
  * @param const Team &team: The ai team who is looking to pick a switch.
  * @return MoveNode: The switch option the ai selected.
  */

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

/**
  * @brief: The function that calls the minimax and finds the best move.
  * @param Team &human_team: The human's team.
  * @param: Team &ai_team: The ai's team.
  * @return MoveNode: The best move for the ai.
  */

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