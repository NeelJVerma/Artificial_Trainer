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
  void FaintActivePokemon();
  void AddPokemon(const std::shared_ptr<Pokemon> &pokemon);
  std::vector<std::shared_ptr<Pokemon>> ActiveTeam() const;
  std::vector<std::shared_ptr<Pokemon>> FaintedTeam() const;
  bool SeenPokemon(const SpeciesNames &species) const;
  void SetActiveMember(const int &index);
  std::shared_ptr<Pokemon> ActiveMember() const;
  int IndexOfActiveMember() const;
  void HardSwitch();
  void SwitchAction(const int &switch_index);

 private:
  std::vector<std::shared_ptr<Pokemon>> active_team_;
  std::vector<std::shared_ptr<Pokemon>> fainted_team_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_TEAM_H
