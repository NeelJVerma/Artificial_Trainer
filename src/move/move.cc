//
// Created by neel on 1/27/19.
//

#include "move.h"
#include "../type/type.h"
#include "basepower.h"

namespace artificialtrainer {
Move::Move(const MoveNames &move_name, const int &current_pp)
    : move_name_(move_name), current_pp_(current_pp) {
}

auto Move::MoveName() const -> MoveNames {
  return move_name_;
}

auto Move::CurrentPp() const -> int {
  return current_pp_;
}

auto Move::DecrementPp(const int &amount) -> void {
  current_pp_ -= amount;
}

auto IsPhysical(const MoveNames &move_name) -> bool {
  switch (Type(move_name)) {
    case TypesNames::kNormal:
    case TypesNames::kFighting:
    case TypesNames::kPoison:
    case TypesNames::kGround:
    case TypesNames::kFlying:
    case TypesNames::kBug:
    case TypesNames::kRock:
    case TypesNames::kGhost:
      return true;
    default:
      return false;
  };
}

auto IsSpecial(const MoveNames &move_name) -> bool {
  switch (Type(move_name)) {
    case TypesNames::kFire:
    case TypesNames::kWater:
    case TypesNames::kElectric:
    case TypesNames::kGrass:
    case TypesNames::kIce:
    case TypesNames::kPsychic:
    case TypesNames::kDragon:
      return true;
    default:
      return false;
  };
}

auto IsDamaging(const MoveNames &move_name) -> bool {
  return BasePower(move_name) != 0;
}

auto IsUseless(const MoveNames &move_name) -> bool {
  switch (move_name) {
    case MoveNames::kRoar:
    case MoveNames::kSplash:
    case MoveNames::kWhirlwind:
    case MoveNames::kTeleport:
      return true;
    default:
      return false;
  }
}

} //namespace artificialtrainer