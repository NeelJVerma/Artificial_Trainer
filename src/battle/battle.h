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
  void PlayerPicksMove(Team &team, const bool &team_one);
  void ReplaceMovesWithStruggleIfNeeded(
      const std::shared_ptr<Pokemon> &active_pokemon_one,
      const std::shared_ptr<Pokemon> &active_pokemon_two);
  bool HumanMovesFirst(const std::shared_ptr<Pokemon> &active_pokemon_one,
                       const std::shared_ptr<Pokemon> &active_pokemon_two) const;
  bool HandleMove(Team &attacker, Team &defender, const bool &is_ai);
  void PlayerPicksForcedSwitch(Team &team);
  void HandleEndOfTurnStatuses(const std::shared_ptr<Pokemon> &attacker,
                               const std::shared_ptr<Pokemon> &defender,
                               Team &attacking_team,
                               const Team &defending_team,
                               const bool &is_ai);
  bool PokemonHasHp(const std::shared_ptr<Pokemon> &pokemon);
  void HandleFainting(const bool &human_moves_first,
                      std::shared_ptr<Pokemon> active_pokemon_human,
                      std::shared_ptr<Pokemon> active_pokemon_ai);
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_BATTLE_H
