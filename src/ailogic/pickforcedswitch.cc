//
// Created by neel on 4/6/19.
//

#include "pickforcedswitch.h"
#include "typesum.h"

namespace artificialtrainer {
void PickForcedSwitch(Team &picking_team,
                      const std::shared_ptr<Pokemon> &active_defender) {
  int max_score = 0;
  int switch_index = 0;
  int i = 0;

  for (const auto &picking : picking_team.ActiveTeam()) {
    if (picking->IsActive()) {
      continue;
    }

    int type_sum = TypeSum(picking, active_defender);

    if (type_sum > max_score) {
      max_score = type_sum;
      switch_index = i;
    }

    i++;
  }

  picking_team.SetActiveMember(switch_index);
}

} //namespace artificialtrainer