//
// Created by neel on 4/6/19.
//

#include "pickleadingpokemon.h"
#include "../type/effectiveness.h"
#include "typesum.h"

namespace artificialtrainer {
void PickLeadingPokemon(Team &picking_team, const Team &other_team) {
  int max_score = 0;
  int leading_index = 0;
  int i = 0;

  for (const auto &picking : picking_team.ActiveTeam()) {
    int overall_type_sum = 0;

    for (const auto &other : other_team.ActiveTeam()) {
      overall_type_sum += TypeSum(picking, other);
    }

    if (overall_type_sum > max_score) {
      max_score = overall_type_sum;
      leading_index = i;
    }

    i++;
  }

  picking_team.SetActiveMember(leading_index);
}

} //namespace artificialtrainer