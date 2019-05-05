/**
 * @project Artificial Trainer
 * @brief The function to pick the leading Pokemon for a given team.
 *
 * @file pickleadingpokemon.h
 * @author Neel Verma
 * @date 4/6/19
 */

#ifndef ARTIFICIAL_TRAINER_PICKLEADINGPOKEMON_H
#define ARTIFICIAL_TRAINER_PICKLEADINGPOKEMON_H

#include "../team/team.h"

namespace artificialtrainer {
void PickLeadingPokemon(Team &picking_team, const Team &other_team);

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_PICKLEADINGPOKEMON_H
