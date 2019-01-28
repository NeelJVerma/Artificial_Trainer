//
// Created by neel on 1/26/19.
//

#include "type.h"

namespace artificialtrainer {
auto Type(const Moves &move_name) -> Types {
  switch (move_name) {
    case Moves::kBarrage:
    case Moves::kBide:
    case Moves::kBind:
    case Moves::kBite:
    case Moves::kBodySlam:
    case Moves::kCometPunch:
    case Moves::kConstrict:
    case Moves::kConversion:
    case Moves::kCut:
    case Moves::kDefenseCurl:
    case Moves::kDisable:
    case Moves::kDizzyPunch:
    case Moves::kDoubleTeam:
    case Moves::kDoubleEdge:
    case Moves::kDoubleSlap:
    case Moves::kEggBomb:
    case Moves::kExplosion:
    case Moves::kFlash:
    case Moves::kFocusEnergy:
    case Moves::kFuryAttack:
    case Moves::kFurySwipes:
    case Moves::kGlare:
    case Moves::kGrowl:
    case Moves::kGrowth:
    case Moves::kGuillotine:
    case Moves::kGust:
    case Moves::kHarden:
    case Moves::kHeadbutt:
    case Moves::kHornAttack:
    case Moves::kHornDrill:
    case Moves::kHyperBeam:
    case Moves::kHyperFang:
    case Moves::kKarateChop:
    case Moves::kLeer:
    case Moves::kLovelyKiss:
    case Moves::kMegaKick:
    case Moves::kMegaPunch:
    case Moves::kMetronome:
    case Moves::kMimic:
    case Moves::kMinimize:
    case Moves::kPayDay:
    case Moves::kPound:
    case Moves::kQuickAttack:
    case Moves::kRage:
    case Moves::kRazorWind:
    case Moves::kRecover:
    case Moves::kRoar:
    case Moves::kScratch:
    case Moves::kScreech:
    case Moves::kSelfDestruct:
    case Moves::kSharpen:
    case Moves::kSing:
    case Moves::kSkullBash:
    case Moves::kSlam:
    case Moves::kSlash:
    case Moves::kSmokescreen:
    case Moves::kSoftBoiled:
    case Moves::kSonicBoom:
    case Moves::kSpikeCannon:
    case Moves::kSplash:
    case Moves::kStomp:
    case Moves::kStrength:
    case Moves::kStruggle:
    case Moves::kSubstitute:
    case Moves::kSuperFang:
    case Moves::kSupersonic:
    case Moves::kSwift:
    case Moves::kSwordsDance:
    case Moves::kTackle:
    case Moves::kTailWhip:
    case Moves::kTakeDown:
    case Moves::kThrash:
    case Moves::kTransform:
    case Moves::kTriAttack:
    case Moves::kViceGrip:
    case Moves::kWhirlwind:
    case Moves::kWrap:return Types::kNormal;
    case Moves::kCounter:
    case Moves::kDoubleKick:
    case Moves::kHighJumpKick:
    case Moves::kJumpKick:
    case Moves::kLowKick:
    case Moves::kRollingKick:
    case Moves::kSeismicToss:
    case Moves::kSubmission:return Types::kFighting;
    case Moves::kDrillPeck:
    case Moves::kFly:
    case Moves::kMirrorMove:
    case Moves::kPeck:
    case Moves::kSkyAttack:
    case Moves::kWingAttack:return Types::kFlying;
    case Moves::kAcid:
    case Moves::kAcidArmor:
    case Moves::kPoisonGas:
    case Moves::kPoisonSting:
    case Moves::kPoisonPowder:
    case Moves::kSludge:
    case Moves::kSmog:
    case Moves::kToxic:return Types::kPoison;
    case Moves::kBoneClub:
    case Moves::kBonemerang:
    case Moves::kDig:
    case Moves::kEarthquake:
    case Moves::kFissure:
    case Moves::kSandAttack:return Types::kGround;
    case Moves::kRockSlide:
    case Moves::kRockThrow:return Types::kRock;
    case Moves::kLeechLife:
    case Moves::kPinMissile:
    case Moves::kStringShot:
    case Moves::kTwineedle:return Types::kBug;
    case Moves::kConfuseRay:
    case Moves::kLick:
    case Moves::kNightShade:return Types::kGhost;
    case Moves::kEmber:
    case Moves::kFireBlast:
    case Moves::kFirePunch:
    case Moves::kFireSpin:
    case Moves::kFlamethrower:return Types::kFire;
    case Moves::kBubble:
    case Moves::kBubbleBeam:
    case Moves::kClamp:
    case Moves::kCrabhammer:
    case Moves::kHydroPump:
    case Moves::kSurf:
    case Moves::kWaterGun:
    case Moves::kWaterfall:
    case Moves::kWithdraw:return Types::kWater;
    case Moves::kAbsorb:
    case Moves::kLeechSeed:
    case Moves::kMegaDrain:
    case Moves::kPetalDance:
    case Moves::kRazorLeaf:
    case Moves::kSleepPowder:
    case Moves::kSolarBeam:
    case Moves::kSpore:
    case Moves::kStunSpore:
    case Moves::kVineWhip:return Types::kGrass;
    case Moves::kThunder:
    case Moves::kThunderWave:
    case Moves::kThunderbolt:
    case Moves::kThunderPunch:
    case Moves::kThunderShock:return Types::kElectric;
    case Moves::kAgility:
    case Moves::kAmnesia:
    case Moves::kBarrier:
    case Moves::kConfusion:
    case Moves::kDreamEater:
    case Moves::kHypnosis:
    case Moves::kKinesis:
    case Moves::kLightScreen:
    case Moves::kMeditate:
    case Moves::kPsybeam:
    case Moves::kPsychic:
    case Moves::kPsywave:
    case Moves::kReflect:
    case Moves::kRest:
    case Moves::kTeleport:return Types::kPsychic;
    case Moves::kAuroraBeam:
    case Moves::kBlizzard:
    case Moves::kHaze:
    case Moves::kIceBeam:
    case Moves::kIcePunch:
    case Moves::kMist:return Types::kIce;
    case Moves::kDragonRage:return Types::kDragon;
    default:return Types::kNoType;
  };
}

} //namespace artificialtrainer