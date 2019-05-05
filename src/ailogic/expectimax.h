/**
 * @project Artificial Trainer
 * @brief The function that calls the expect minimax.
 *
 * @file expectimax.h
 * @author Neel Verma
 * @date 4/20/19
 */

#ifndef ARTIFICIAL_TRAINER_EXPECTIMAX_H
#define ARTIFICIAL_TRAINER_EXPECTIMAX_H

#include "../team/team.h"
#include "movenode.h"

namespace artificialtrainer {
MoveNode ExpectiMax(Team &human_team, Team &ai_team);

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_EXPECTIMAX_H
