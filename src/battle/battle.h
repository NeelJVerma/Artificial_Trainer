//
// Created by neel on 1/25/19.
//

#ifndef ARTIFICIAL_TRAINER_BATTLE_H
#define ARTIFICIAL_TRAINER_BATTLE_H

#include "../team/team.h"
#include "../pokemon/activepokemon.h"

namespace artificialtrainer {
class Battle {
 public:
  Battle() = default;
  auto Play() -> void;

 private:
  Team team_one_;
  Team team_two_;
  ActivePokemon active_pokemon_one;
  ActivePokemon activePokemon_two;
  auto BattleOver() const -> bool;
  auto StartBattle() -> void;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_BATTLE_H
