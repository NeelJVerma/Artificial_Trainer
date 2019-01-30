//
// Created by neel on 1/24/19.
//

#ifndef ARTIFICIAL_TRAINER_TEAM_H
#define ARTIFICIAL_TRAINER_TEAM_H

#include <vector>
#include "../pokemon/pokemon.h"

namespace artificialtrainer {
class Team {
 public:
  static const int kMaxTeamSize = 6;

  Team(const Team &team) = delete;
  Team &operator=(const Team &team) = default;
  Team() = default;

  auto FaintPokemon(const int &index) -> void;
  auto AddPokemon(const Pokemon &pokemon) -> void;
  auto TeamSize() const -> int;
  auto SeenPokemon(const SpeciesNames &species) -> bool;
  auto operator[](const int &index) -> Pokemon;

 private:
  std::vector<Pokemon> team_;
  std::vector<Pokemon> fainted_team_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_TEAM_H
