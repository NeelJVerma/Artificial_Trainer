/**
 * @project Artificial Trainer
 * @brief A function for the attacking team's Pokemon to use a move.
 *
 * @file usemove.h
 * @author Neel Verma
 * @date 2/6/19
 */

#ifndef ARTIFICIAL_TRAINER_USEMOVE_H
#define ARTIFICIAL_TRAINER_USEMOVE_H

#include "../team/team.h"

namespace artificialtrainer {
void UseMove(Team &attacker, Team &defender, const bool &is_called_by_ai);

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_USEMOVE_H
