//
// Created by neel on 1/24/19.
//

#ifndef ARTIFICIAL_TRAINER_TEAM_H
#define ARTIFICIAL_TRAINER_TEAM_H

#include <vector>
#include <memory>
#include "../pokemon/pokemon.h"

namespace artificialtrainer {
class Team {
 public:
  Team(const Team &team) = delete;
  Team& operator=(const Team &team) = delete;
  Team() = default;

  void RemovePokemon(const unsigned &index);
  void AddPokemon(const std::shared_ptr<Pokemon> &pokemon);
  auto TeamSize() const -> unsigned;

 private:
  std::vector<std::shared_ptr<Pokemon>> team_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_TEAM_H
