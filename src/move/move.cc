//
// Created by neel on 1/27/19.
//

#include <cassert>
#include "move.h"
#include "../type/type.h"
#include "basepower.h"

namespace artificialtrainer {
Move::Move(const MoveNames &move_name, const int &current_pp)
    : move_name_(move_name), current_pp_(current_pp), damage_done_(0) {
}

MoveNames Move::MoveName() const {
  return move_name_;
}

int Move::CurrentPp() const {
  return current_pp_;
}

void Move::DecrementPp(const int &amount) {
  if (current_pp_ - amount < 0) {
    current_pp_ = 0;
    return;
  }

  current_pp_ -= amount;
}

void Move::SetDamageDone(const int &damage_done) {
  damage_done_ = damage_done;
}

int Move::DamageDone() const {
  return damage_done_;
}

bool IsDamaging(const MoveNames &move_name) {
  return static_cast<bool>(BasePower(move_name));
}

bool IsPhysical(const MoveNames &move_name) {
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
  }
}

bool IsSwitch(const MoveNames &move_name) {
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

bool HasHighCriticalHitRatio(const MoveNames &move_name) {
  switch (move_name) {
    case MoveNames::kCrabhammer:
    case MoveNames::kKarateChop:
    case MoveNames::kRazorLeaf:
    case MoveNames::kSlash:
      return true;
    default:
      return false;
  }
}

bool IsSelfKo(const MoveNames &move_name) {
  switch (move_name) {
    case MoveNames::kExplosion:
    case MoveNames::kSelfDestruct:
      return true;
    default:
      return false;
  }
}

int VariableEffectChance(const MoveNames &move_name) {
  switch (move_name) {
    case MoveNames::kAcid:
    case MoveNames::kAuroraBeam:
    case MoveNames::kBite:
    case MoveNames::kBlizzard:
    case MoveNames::kBoneClub:
    case MoveNames::kBubbleBeam:
    case MoveNames::kBubble:
    case MoveNames::kConfusion:
    case MoveNames::kConstrict:
    case MoveNames::kEmber:
    case MoveNames::kFirePunch:
    case MoveNames::kFlamethrower:
    case MoveNames::kHyperFang:
    case MoveNames::kIceBeam:
    case MoveNames::kIcePunch:
    case MoveNames::kPsybeam:
    case MoveNames::kThunder:
    case MoveNames::kThunderbolt:
    case MoveNames::kThunderPunch:
    case MoveNames::kThunderShock:
      return 10;
    case MoveNames::kPoisonSting:
    case MoveNames::kTwineedle:
      return 20;
    case MoveNames::kBodySlam:
    case MoveNames::kFireBlast:
    case MoveNames::kHeadbutt:
    case MoveNames::kLick:
    case MoveNames::kLowKick:
    case MoveNames::kPsychic:
    case MoveNames::kRollingKick:
    case MoveNames::kSmog:
    case MoveNames::kSludge:
    case MoveNames::kStomp:
      return 33;
    default:
      assert(false);
  }
}

} //namespace artificialtrainer