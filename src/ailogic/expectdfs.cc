//
// Created by neel on 4/20/19.
//

#include <iostream>
#include "expectdfs.h"
#include "../battlemanager/battlemanager.h"
#include "movenode.h"
#include "../stringconverter/stringconverter.h"
#include "../move/usemove.h"
#include "../clientelements/gui.h"

namespace artificialtrainer {
namespace {
void SimulateTurn(Team &human_team, Team &ai_team) {
  bool human_moves_first = BattleManager::HumanMovesFirst(human_team, ai_team);
  BattleManager::HandleBothTeamsMoves(human_moves_first, human_team, ai_team);
  // THIS WILL HAVE TO BE DIFFERENT SO THEERE IS NO INTERRUPT
  BattleManager::HandleFainting(human_moves_first, human_team, ai_team);
  human_team.ActiveMember()->ResetEndOfTurnFlags();
  ai_team.ActiveMember()->ResetEndOfTurnFlags();
}

std::vector<std::shared_ptr<MoveNode>> AllValidMoves(const Team &team) {
  MovesContainer moves_container = team.ActiveMember()->GetMovesContainer();
  std::vector<std::shared_ptr<MoveNode>> valid_moves;

  for (int i = 0; i < moves_container.Size(); i++) {
    if (BattleManager::IsValidMoveChoice(team, moves_container[i], true)) {
      valid_moves.push_back(std::make_shared<MoveNode>(i));
    }
  }

  return valid_moves;
}

} //namespace

void ExpectDfs(Team &human_team, Team &ai_team, int depth) {
  if (ai_team.ActiveMember()->IsFainted() ||
      human_team.ActiveMember()->IsFainted()) {
    return;
  }

  if (depth == 2) {
    return;
  }

  std::vector<std::shared_ptr<MoveNode>> valid_moves_human =
      AllValidMoves(human_team);
  std::vector<std::shared_ptr<MoveNode>> valid_moves_ai =
      AllValidMoves(ai_team);

  for (const auto &human_move : valid_moves_human) {
    for (const auto &ai_move : valid_moves_ai) {
      human_team.ActiveMember()->SetMoveUsed(
          human_team.ActiveMember()->GetMovesContainer()[
              human_move->MoveIndex()]);
      ai_team.ActiveMember()->SetMoveUsed(
          ai_team.ActiveMember()->GetMovesContainer()[ai_move->MoveIndex()]);
      Team saved_human(human_team.ActiveTeam(), human_team.FaintedTeam());
      Team saved_ai(ai_team.ActiveTeam(), ai_team.FaintedTeam());
      BattleManager::HandleBothTeamsMoves(
          BattleManager::HumanMovesFirst(human_team, ai_team),
          human_team, ai_team);
      //ExpectDfs(human_team, ai_team, depth + 1);
      human_team = Team(saved_human.ActiveTeam(), saved_human.FaintedTeam());
      ai_team = Team(saved_ai.ActiveTeam(), saved_ai.FaintedTeam());
    }
  }
}

} //namespace artificialtrainer