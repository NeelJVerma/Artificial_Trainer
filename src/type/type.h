//
// Created by neel on 1/26/19.
//

#ifndef ARTIFICIAL_TRAINER_TYPE_H
#define ARTIFICIAL_TRAINER_TYPE_H

#include "../move/moves.h"

namespace artificialtrainer {
enum class Types : int {
  kNormal,
  kFighting,
  kFlying,
  kPoison,
  kGround,
  kRock,
  kBug,
  kGhost,
  kFire,
  kWater,
  kGrass,
  kElectric,
  kPsychic,
  kIce,
  kDragon,
  kNoType
};

const int kNumTypes = static_cast<int>(Types::kNoType) + 1;
auto Type(const Moves &move_name) -> Types;

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_TYPE_H
