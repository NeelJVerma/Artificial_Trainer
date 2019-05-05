/**
 * @project Artificial Trainer
 * @brief The implementation of the Move class.
 *
 * @file move.cc
 * @author Neel Verma
 * @date 1/27/19
 */

#include <cassert>
#include "move.h"
#include "../type/type.h"
#include "basepower.h"

namespace artificialtrainer {

/**
  * @brief: One constructor for the Move class.
  * @param const MoveNames &move_name: The name of the move.
  * @param const int &current_pp: The pp of the move.
  */

Move::Move(const MoveNames &move_name, const int &current_pp)
    : move_name_(move_name), current_pp_(current_pp), damage_done_(0),
      disabled_(false) {
}

/**
  * @brief: An accessor for the move name.
  * @return MoveNames: The move name.
  */

MoveNames Move::MoveName() const {
  return move_name_;
}

/**
  * @brief: An accessor for the move pp.
  * @return int: The move pp.
  */

int Move::CurrentPp() const {
  return current_pp_;
}

/**
  * @brief: An function to decrement the pp of the move.
  * @param const int &amount: The amount to decrement by.
  */

void Move::DecrementPp(const int &amount) {
  if (current_pp_ - amount < 0) {
    current_pp_ = 0;
    return;
  }

  current_pp_ -= amount;
}

/**
  * @brief: An mutator for the damage done.
  * @param const int &damage_done: The damage done.
  */

void Move::SetDamageDone(const int &damage_done) {
  damage_done_ = damage_done;
}

/**
  * @brief: An accessor for the damage done.
  * @return int: The damage done.
  */

int Move::DamageDone() const {
  return damage_done_;
}

/**
  * @brief: An mutator for disabled.
  * @param const bool &disabled: Whether or not the move is disabled..
  */

void Move::SetDisabled(const bool &disabled) {
  disabled_ = disabled;
}

/**
  * @brief: An accessor for the disabled.
  * @return bool: Whether or not the move is disabled.
  */

bool Move::IsDisabled() const {
  return disabled_;
}

/**
  * @brief: A function to reset the move with a given move name and pp.
  * @param const MoveNames &move_name: The move name to set.
  * @param const int &current_pp: The pp to set.
  */

void Move::ResetMove(const MoveNames &move_name, const int &current_pp) {
  move_name_ = move_name;
  current_pp_ = current_pp;
  disabled_ = false;
  damage_done_ = 0;
}

/**
  * @brief: A function to tell whether or not the given move is damaging.
  * @param const MoveNames& move_name: The name of the move to check.
  * @return bool: Whether or not the move is damaging.
  */

bool IsDamaging(const MoveNames &move_name) {
  return static_cast<bool>(BasePower(move_name));
}

/**
  * @brief: A function to tell whether or not the given move is physical.
  * @param const MoveNames& move_name: The name of the move to check.
  * @return bool: Whether or not the move is physical.
  */

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

/**
  * @brief: A function to tell whether or not the given move is special.
  * @param const MoveNames& move_name: The name of the move to check.
  * @return bool: Whether or not the move is special.
  */

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

/**
  * @brief: A function to tell whether or not the given move is a switch move.
  * @param const MoveNames& move_name: The name of the move to check.
  * @return bool: Whether or not the move is a switch move.
  */

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

/**
  * @brief: A function to tell whether or not the given move has a high
  * critical hit ratio.
  * @param const MoveNames& move_name: The name of the move to check.
  * @return bool: Whether or not the move has a high critical hit ratio.
  */

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

/**
  * @brief: A function to tell whether or not the given move is self ko'ing.
  * @param const MoveNames& move_name: The name of the move to check.
  * @return bool: Whether or not the move is self ko'ing.
  */

bool IsSelfKo(const MoveNames &move_name) {
  switch (move_name) {
    case MoveNames::kExplosion:
    case MoveNames::kSelfDestruct:
      return true;
    default:
      return false;
  }
}

/**
  * @brief: A function to tell whether or not the given move has a side
  * effect if it missed.
  * @param const MoveNames& move_name: The name of the move to check.
  * @return bool: Whether or not the move has a side effect if it missed.
  */

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

/**
  * @brief: A function to tell whether or not the given move is binding.
  * @param const MoveNames& move_name: The name of the move to check.
  * @return bool: Whether or not the move is binding.
  */

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

/**
  * @brief: A function to tell whether or not the given move is draining.
  * @param const MoveNames& move_name: The name of the move to check.
  * @return bool: Whether or not the move is draining.
  */

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

/**
  * @brief: A function to tell whether or not the given move always hits twice.
  * @param const MoveNames& move_name: The name of the move to check.
  * @return bool: Whether or not the move always hits twice.
  */

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

/**
  * @brief: A function to tell whether or not the given move hits two to five
  * times.
  * @param const MoveNames& move_name: The name of the move to check.
  * @return bool: Whether or not the move hits two to five times.
  */

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

/**
  * @brief: A function to tell whether or not the given move works if the
  * defender is vanished.
  * @param const MoveNames& move_name: The name of the move to check.
  * @return bool: Whether or not the move works if the defender is vanished.
  */

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

/**
  * @brief: A function to tell whether or not the given move is vanish.
  * @param const MoveNames& move_name: The name of the move to check.
  * @return bool: Whether or not the move is vanish.
  */

bool IsVanish(const MoveNames &move_name) {
  switch (move_name) {
    case MoveNames::kFly:
    case MoveNames::kDig:
      return true;
    default:
      return false;
  }
}

/**
  * @brief: A function to tell whether or not the given move is charge up.
  * @param const MoveNames& move_name: The name of the move to check.
  * @return bool: Whether or not the move is charge up.
  */

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

/**
  * @brief: A function to tell whether or not the given move is lock in.
  * @param const MoveNames& move_name: The name of the move to check.
  * @return bool: Whether or not the move is lock in.
  */

bool IsLockIn(const MoveNames &move_name) {
  switch (move_name) {
    case MoveNames::kPetalDance:
    case MoveNames::kThrash:
    case MoveNames::kRage:
      return true;
    default:
      return false;
  }
}

/**
  * @brief: A function that returns the variable effect chance of a given move.
  * @param const MoveNames& move_name: The name of the move to check.
  * @return int: The variable effect chance of the move.
  */

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