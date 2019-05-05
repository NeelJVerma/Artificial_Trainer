/**
 * @project Artificial Trainer
 * @brief The implementation of the PickForcedSwitch function.
 *
 * @file pickforcedswitch.cc
 * @author Neel Verma
 * @date 4/6/19
 */

#include "pickforcedswitch.h"
#include "typesum.h"

namespace artificialtrainer {

/**
  * @brief: Given a team and the defending Pokemon on the other team, pick
  * the "best" switch in for when the current team's active Pokemon fainted.
  * @param Team &picking_team: The team that is picking the switch.
  * @param const std::shared_ptr<Pokemon> &active_defender: The defening
  * Pokemon on the other team.
  */

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