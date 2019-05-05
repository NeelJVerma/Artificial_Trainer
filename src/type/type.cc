/**
 * @project Artificial Trainer
 * @brief The implementation of the Type function.
 *
 * @file type.cc
 * @author Neel Verma
 * @date 1/26/19
 */

#include "type.h"

namespace artificialtrainer {

/**
  * @brief: A function to get the type of a given move.
  * @param const MoveNames &move_name: The move name.
  * @return TypeNames: The type of the move.
  */

TypeNames Type(const MoveNames &move_name) {
  switch (move_name) {
    case MoveNames::kBarrage:
    case MoveNames::kBide:
    case MoveNames::kBind:
    case MoveNames::kBite:
    case MoveNames::kBodySlam:
    case MoveNames::kCometPunch:
    case MoveNames::kConstrict:
    case MoveNames::kConversion:
    case MoveNames::kCut:
    case MoveNames::kDefenseCurl:
    case MoveNames::kDisable:
    case MoveNames::kDizzyPunch:
    case MoveNames::kDoubleTeam:
    case MoveNames::kDoubleEdge:
    case MoveNames::kDoubleSlap:
    case MoveNames::kEggBomb:
    case MoveNames::kExplosion:
    case MoveNames::kFlash:
    case MoveNames::kFocusEnergy:
    case MoveNames::kFuryAttack:
    case MoveNames::kFurySwipes:
    case MoveNames::kGlare:
    case MoveNames::kGrowl:
    case MoveNames::kGrowth:
    case MoveNames::kGuillotine:
    case MoveNames::kGust:
    case MoveNames::kHarden:
    case MoveNames::kHeadbutt:
    case MoveNames::kHornAttack:
    case MoveNames::kHornDrill:
    case MoveNames::kHyperBeam:
    case MoveNames::kHyperFang:
    case MoveNames::kKarateChop:
    case MoveNames::kLeer:
    case MoveNames::kLovelyKiss:
    case MoveNames::kMegaKick:
    case MoveNames::kMegaPunch:
    case MoveNames::kMetronome:
    case MoveNames::kMimic:
    case MoveNames::kMinimize:
    case MoveNames::kPayDay:
    case MoveNames::kPound:
    case MoveNames::kQuickAttack:
    case MoveNames::kRage:
    case MoveNames::kRazorWind:
    case MoveNames::kRecover:
    case MoveNames::kRoar:
    case MoveNames::kScratch:
    case MoveNames::kScreech:
    case MoveNames::kSelfDestruct:
    case MoveNames::kSharpen:
    case MoveNames::kSing:
    case MoveNames::kSkullBash:
    case MoveNames::kSlam:
    case MoveNames::kSlash:
    case MoveNames::kSmokescreen:
    case MoveNames::kSoftBoiled:
    case MoveNames::kSonicBoom:
    case MoveNames::kSpikeCannon:
    case MoveNames::kSplash:
    case MoveNames::kStomp:
    case MoveNames::kStrength:
    case MoveNames::kStruggle:
    case MoveNames::kSubstitute:
    case MoveNames::kSuperFang:
    case MoveNames::kSupersonic:
    case MoveNames::kSwift:
    case MoveNames::kSwordsDance:
    case MoveNames::kTackle:
    case MoveNames::kTailWhip:
    case MoveNames::kTakeDown:
    case MoveNames::kThrash:
    case MoveNames::kTransform:
    case MoveNames::kTriAttack:
    case MoveNames::kViceGrip:
    case MoveNames::kWhirlwind:
    case MoveNames::kWrap:
      return TypeNames::kNormal;
    case MoveNames::kCounter:
    case MoveNames::kDoubleKick:
    case MoveNames::kHighJumpKick:
    case MoveNames::kJumpKick:
    case MoveNames::kLowKick:
    case MoveNames::kRollingKick:
    case MoveNames::kSeismicToss:
    case MoveNames::kSubmission:
      return TypeNames::kFighting;
    case MoveNames::kDrillPeck:
    case MoveNames::kFly:
    case MoveNames::kMirrorMove:
    case MoveNames::kPeck:
    case MoveNames::kSkyAttack:
    case MoveNames::kWingAttack:
      return TypeNames::kFlying;
    case MoveNames::kAcid:
    case MoveNames::kAcidArmor:
    case MoveNames::kPoisonGas:
    case MoveNames::kPoisonSting:
    case MoveNames::kPoisonPowder:
    case MoveNames::kSludge:
    case MoveNames::kSmog:
    case MoveNames::kToxic:
      return TypeNames::kPoison;
    case MoveNames::kBoneClub:
    case MoveNames::kBonemerang:
    case MoveNames::kDig:
    case MoveNames::kEarthquake:
    case MoveNames::kFissure:
    case MoveNames::kSandAttack:
      return TypeNames::kGround;
    case MoveNames::kRockSlide:
    case MoveNames::kRockThrow:
      return TypeNames::kRock;
    case MoveNames::kLeechLife:
    case MoveNames::kPinMissile:
    case MoveNames::kStringShot:
    case MoveNames::kTwineedle:
      return TypeNames::kBug;
    case MoveNames::kConfuseRay:
    case MoveNames::kLick:
    case MoveNames::kNightShade:
      return TypeNames::kGhost;
    case MoveNames::kEmber:
    case MoveNames::kFireBlast:
    case MoveNames::kFirePunch:
    case MoveNames::kFireSpin:
    case MoveNames::kFlamethrower:
      return TypeNames::kFire;
    case MoveNames::kBubble:
    case MoveNames::kBubbleBeam:
    case MoveNames::kClamp:
    case MoveNames::kCrabhammer:
    case MoveNames::kHydroPump:
    case MoveNames::kSurf:
    case MoveNames::kWaterGun:
    case MoveNames::kWaterfall:
    case MoveNames::kWithdraw:
      return TypeNames::kWater;
    case MoveNames::kAbsorb:
    case MoveNames::kLeechSeed:
    case MoveNames::kMegaDrain:
    case MoveNames::kPetalDance:
    case MoveNames::kRazorLeaf:
    case MoveNames::kSleepPowder:
    case MoveNames::kSolarBeam:
    case MoveNames::kSpore:
    case MoveNames::kStunSpore:
    case MoveNames::kVineWhip:
      return TypeNames::kGrass;
    case MoveNames::kThunder:
    case MoveNames::kThunderWave:
    case MoveNames::kThunderbolt:
    case MoveNames::kThunderPunch:
    case MoveNames::kThunderShock:
      return TypeNames::kElectric;
    case MoveNames::kAgility:
    case MoveNames::kAmnesia:
    case MoveNames::kBarrier:
    case MoveNames::kConfusion:
    case MoveNames::kDreamEater:
    case MoveNames::kHypnosis:
    case MoveNames::kKinesis:
    case MoveNames::kLightScreen:
    case MoveNames::kMeditate:
    case MoveNames::kPsybeam:
    case MoveNames::kPsychic:
    case MoveNames::kPsywave:
    case MoveNames::kReflect:
    case MoveNames::kRest:
    case MoveNames::kTeleport:
      return TypeNames::kPsychic;
    case MoveNames::kAuroraBeam:
    case MoveNames::kBlizzard:
    case MoveNames::kHaze:
    case MoveNames::kIceBeam:
    case MoveNames::kIcePunch:
    case MoveNames::kMist:
      return TypeNames::kIce;
    case MoveNames::kDragonRage:
      return TypeNames::kDragon;
    default:
      return TypeNames::kNoType;
  }
}

} //namespace artificialtrainer