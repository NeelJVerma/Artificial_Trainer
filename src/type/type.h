//
// Created by neel on 1/26/19.
//

#ifndef ARTIFICIAL_TRAINER_TYPE_H
#define ARTIFICIAL_TRAINER_TYPE_H

#include "../move/movenames.h"

namespace artificialtrainer {
enum class TypeNames : int {
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

const int kNumTypes = static_cast<int>(TypeNames::kNoType) + 1;
auto Type(const MoveNames &move_name) -> TypeNames;

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_TYPE_H
