/**
 * @project Artificial Trainer
 * @brief The function to pick a forced switch for a given team.
 *
 * @file pickforcedswitch.h
 * @author Neel Verma
 * @date 4/6/19
 */

#ifndef ARTIFICIAL_TRAINER_PICKFORCEDSWITCH_H
#define ARTIFICIAL_TRAINER_PICKFORCEDSWITCH_H

#include "../team/team.h"

namespace artificialtrainer {
void PickForcedSwitch(Team &picking_team,
                      const std::shared_ptr<Pokemon> &active_defender);

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_PICKFORCEDSWITCH_H
