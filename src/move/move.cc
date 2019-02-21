//
// Created by neel on 1/27/19.
//

#include <cassert>
#include "move.h"
#include "../type/type.h"
#include "basepower.h"

namespace artificialtrainer {
Move::Move(const MoveNames &move_name, const int &current_pp)
    : move_name_(move_name), current_pp_(current_pp), damage_done_(0),
      disabled_(false) {
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

void Move::SetDisabled(const bool &disabled) {
  disabled_ = disabled;
}

bool Move::IsDisabled() const {
  return disabled_;
}

void Move::ResetMove(const MoveNames &move_name, const int &current_pp) {
  move_name_ = move_name;
  current_pp_ = current_pp;
  disabled_ = false;
  damage_done_ = 0;
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

bool IsSpecial(const MoveNames &move_name) {
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

bool HasSideEffectIfMissed(const MoveNames &move_name) {
  switch (move_name) {
    case MoveNames::kHighJumpKick:
    case MoveNames::kJumpKick:
    case MoveNames::kExplosion:
    case MoveNames::kSelfDestruct:
      return true;
    default:
      return false;
  }
}

bool IsBinding(const MoveNames &move_name) {
  switch (move_name) {
    case MoveNames::kBind:
    case MoveNames::kClamp:
    case MoveNames::kFireSpin:
    case MoveNames::kWrap:
      return true;
    default:
      return false;
  }
}

bool IsDraining(const MoveNames &move_name) {
  switch (move_name) {
    case MoveNames::kAbsorb:
    case MoveNames::kMegaDrain:
    case MoveNames::kLeechLife:
    case MoveNames::kDreamEater:
      return true;
    default:
      return false;
  }
}

bool AlwaysHitsTwice(const MoveNames &move_name) {
  switch (move_name) {
    case MoveNames::kTwineedle:
    case MoveNames::kBonemerang:
    case MoveNames::kDoubleKick:
      return true;
    default:
      return false;
  }
}

bool HitsTwoToFiveTimes(const MoveNames &move_name) {
  switch (move_name) {
    case MoveNames::kBarrage:
    case MoveNames::kCometPunch:
    case MoveNames::kDoubleSlap:
    case MoveNames::kFuryAttack:
    case MoveNames::kFurySwipes:
    case MoveNames::kPinMissile:
    case MoveNames::kSpikeCannon:
      return true;
    default:
      return false;
  }
}

bool WorksIfDefenderIsVanished(const MoveNames &move_name) {
  switch (move_name) {
    case MoveNames::kAcidArmor:
    case MoveNames::kAgility:
    case MoveNames::kAmnesia:
    case MoveNames::kBarrier:
    case MoveNames::kBide:
    case MoveNames::kConversion:
    case MoveNames::kDefenseCurl:
    case MoveNames::kDig:
    case MoveNames::kDoubleTeam:
    case MoveNames::kExplosion:
    case MoveNames::kFly:
    case MoveNames::kFocusEnergy:
    case MoveNames::kGrowth:
    case MoveNames::kHarden:
    case MoveNames::kHighJumpKick:
    case MoveNames::kJumpKick:
    case MoveNames::kLightScreen:
    case MoveNames::kMeditate:
    case MoveNames::kMetronome:
    case MoveNames::kMimic:
    case MoveNames::kMinimize:
    case MoveNames::kMirrorMove:
    case MoveNames::kMist:
    case MoveNames::kRecover:
    case MoveNames::kReflect:
    case MoveNames::kRest:
    case MoveNames::kSelfDestruct:
    case MoveNames::kSharpen:
    case MoveNames::kRazorWind:
    case MoveNames::kSkullBash:
    case MoveNames::kSkyAttack:
    case MoveNames::kSoftBoiled:
    case MoveNames::kSolarBeam:
    case MoveNames::kSubstitute:
    case MoveNames::kSwift:
    case MoveNames::kSwordsDance:
    case MoveNames::kTransform:
    case MoveNames::kWithdraw:
      return true;
    default:
      return false;
  }
}

bool IsVanish(const MoveNames &move_name) {
  switch (move_name) {
    case MoveNames::kFly:
    case MoveNames::kDig:
      return true;
    default:
      return false;
  }
}

bool IsChargeUp(const MoveNames &move_name) {
  switch (move_name) {
    case MoveNames::kRazorWind:
    case MoveNames::kSkullBash:
    case MoveNames::kSkyAttack:
    case MoveNames::kSolarBeam:
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