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
  void ReplaceMovesWithStruggleIfNeeded(
      const std::shared_ptr<Pokemon> &active_pokemon_one,
      const std::shared_ptr<Pokemon> &active_pokemon_two);
  bool OneMovesFirst(const std::shared_ptr<Pokemon> &active_pokemon_one,
                     const std::shared_ptr<Pokemon> &active_pokemon_two) const;
  bool HandleMove(Team &attacker, Team &defender);
  void PlayerPicksForcedSwitch(Team &team);
  void HandleEndOfTurnStatuses(const std::shared_ptr<Pokemon> &attacker,
                               const std::shared_ptr<Pokemon> &defender,
                               Team &team);
  bool CheckIfActivePokemonIsStillAlive(const std::shared_ptr<Pokemon> &pokemon,
                                        Team &team);
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_BATTLE_H
