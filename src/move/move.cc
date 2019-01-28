//
// Created by neel on 1/27/19.
//

#include "move.h"
#include "../type/type.h"
#include "basepower.h"

namespace artificialtrainer {
Move::Move(const Moves &move_name, const int &current_pp)
    : move_name_(move_name), current_pp_(current_pp) {
}

auto Move::MoveName() const -> Moves {
  return move_name_;
}

auto Move::CurrentPp() const -> int {
  return current_pp_;
}

auto Move::DecrementPp(const int &amount) -> void {
  current_pp_ -= amount;
}

auto IsPhysical(const Moves &move_name) -> bool {
  switch (Type(move_name)) {
    case Types::kNormal:
    case Types::kFighting:
    case Types::kPoison:
    case Types::kGround:
    case Types::kFlying:
    case Types::kBug:
    case Types::kRock:
    case Types::kGhost:
      return true;
    default:
      return false;
  };
}

auto IsSpecial(const Moves &move_name) -> bool {
  switch (Type(move_name)) {
    case Types::kFire:
    case Types::kWater:
    case Types::kElectric:
    case Types::kGrass:
    case Types::kIce:
    case Types::kPsychic:
    case Types::kDragon:
      return true;
    default:
      return false;
  };
}

auto IsDamaging(const Moves &move_name) -> bool {
  return BasePower(move_name) != 0;
}

auto IsUseless(const Moves &move_name) -> bool {
  switch (move_name) {
    case Moves::kRoar:
    case Moves::kSplash:
    case Moves::kWhirlwind:
    case Moves::kTeleport:
      return true;
    default:
      return false;
  }
}

} //namespace artificialtrainer