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
    case TypeNames::kNormal:
    case TypeNames::kFighting:
    case TypeNames::kPoison:
    case TypeNames::kGround:
    case TypeNames::kFlying:
    case TypeNames::kBug:
    case TypeNames::kRock:
    case TypeNames::kGhost:
      return true;
    default:
      return false;
  };
}

auto IsSpecial(const MoveNames &move_name) -> bool {
  switch (Type(move_name)) {
    case TypeNames::kFire:
    case TypeNames::kWater:
    case TypeNames::kElectric:
    case TypeNames::kGrass:
    case TypeNames::kIce:
    case TypeNames::kPsychic:
    case TypeNames::kDragon:
      return true;
    default:
      return false;
  };
}

auto IsDamaging(const MoveNames &move_name) -> bool {
  return BasePower(move_name) != static_cast<int>(PowerClasses::kNone);
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

auto IsSwitch(const MoveNames &move_name) -> bool {
  switch (move_name) {
    case MoveNames::kSwitch1:
    case MoveNames::kSwitch2:
    case MoveNames::kSwitch3:
    case MoveNames::kSwitch4:
    case MoveNames::kSwitch5:
    case MoveNames::kSwitch6:
      return true;
    default:
      return false;
  }
}

auto OnlyChangesStat(const MoveNames &move_name) -> bool {
  switch (move_name) {
    case MoveNames::kAcidArmor:
    case MoveNames::kAgility:
    case MoveNames::kAmnesia:
    case MoveNames::kBarrier:
    case MoveNames::kDefenseCurl:
    case MoveNames::kDoubleTeam:
    case MoveNames::kGrowth:
    case MoveNames::kHarden:
    case MoveNames::kMeditate:
    case MoveNames::kMinimize:
    case MoveNames::kSharpen:
    case MoveNames::kSwordsDance:
    case MoveNames::kWithdraw:
    case MoveNames::kFlash:
    case MoveNames::kGrowl:
    case MoveNames::kKinesis:
    case MoveNames::kLeer:
    case MoveNames::kSandAttack:
    case MoveNames::kScreech:
    case MoveNames::kSmokescreen:
    case MoveNames::kStringShot:
    case MoveNames::kTailWhip:
      return true;
    default:
      return false;
  }
}

} //namespace artificialtrainer