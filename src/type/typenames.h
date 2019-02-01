//
// Created by neel on 1/31/19.
//

#ifndef ARTIFICIAL_TRAINER_TYPENAMES_H
#define ARTIFICIAL_TRAINER_TYPENAMES_H

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

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_TYPENAMES_H
