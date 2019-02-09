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
  static const int kMaxTeamSize = 6;

  Team(const Team &team) = delete;
  Team &operator=(const Team &team) = default;
  Team() = default;

  auto FaintActivePokemon() -> void;
  auto AddPokemon(const std::shared_ptr<Pokemon> &pokemon) -> void;
  auto ActiveTeamSize() const -> int;
  auto FaintedTeamSize() const -> int;
  auto ActiveTeam() const -> std::vector<std::shared_ptr<Pokemon>>;
  auto FaintedTeam() const -> std::vector<std::shared_ptr<Pokemon>>;
  auto SeenPokemon(const SpeciesNames &species) -> bool;
  auto SetActiveMember(const int &index) -> void;
  auto ActiveMember() -> std::shared_ptr<Pokemon>;
  auto IndexOfActiveMember() const -> int;

 private:
  std::vector<std::shared_ptr<Pokemon>> active_team_;
  std::vector<std::shared_ptr<Pokemon>> fainted_team_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_TEAM_H
