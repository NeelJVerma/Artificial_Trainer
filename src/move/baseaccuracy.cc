//
// Created by neel on 1/26/19.
//

#include <cassert>
#include "movenames.h"
#include "baseaccuracy.h"

namespace artificialtrainer {

auto BaseAccuracy(const MoveNames &move_name) -> int {
  switch (move_name) {
    case MoveNames::kAbsorb:
      return 100;
    case MoveNames::kAcid:
      return 100;
    case MoveNames::kAcidArmor:
      return kNeverMiss;
    case MoveNames::kAgility:
      return kNeverMiss;
    case MoveNames::kAmnesia:
      return kNeverMiss;
    case MoveNames::kAuroraBeam:
      return 100;
    case MoveNames::kBarrage:
      return 85;
    case MoveNames::kBarrier:
      return kNeverMiss;
    case MoveNames::kBide:
      return 100;
    case MoveNames::kBind:
      return 75;
    case MoveNames::kBite:
      return 100;
    case MoveNames::kBlizzard:
      return 90;
    case MoveNames::kBodySlam:
      return 100;
    case MoveNames::kBoneClub:
      return 85;
    case MoveNames::kBonemerang:
      return 90;
    case MoveNames::kBubble:
      return 100;
    case MoveNames::kBubbleBeam:
      return 100;
    case MoveNames::kClamp:
      return 75;
    case MoveNames::kCometPunch:
      return 85;
    case MoveNames::kConfuseRay:
      return 100;
    case MoveNames::kConfusion:
      return 100;
    case MoveNames::kConstrict:
      return 100;
    case MoveNames::kConversion:
      return kNeverMiss;
    case MoveNames::kCounter:
      return 100;
    case MoveNames::kCrabhammer:
      return 85;
    case MoveNames::kCut:
      return 95;
    case MoveNames::kDefenseCurl:
      return kNeverMiss;
    case MoveNames::kDig:
      return 100;
    case MoveNames::kDisable:
      return 55;
    case MoveNames::kDizzyPunch:
      return 100;
    case MoveNames::kDoubleKick:
      return 100;
    case MoveNames::kDoubleTeam:
      return kNeverMiss;
    case MoveNames::kDoubleEdge:
      return 100;
    case MoveNames::kDoubleSlap:
      return 85;
    case MoveNames::kDragonRage:
      return 100;
    case MoveNames::kDreamEater:
      return 100;
    case MoveNames::kDrillPeck:
      return 100;
    case MoveNames::kEarthquake:
      return 100;
    case MoveNames::kEggBomb:
      return 75;
    case MoveNames::kEmber:
      return 100;
    case MoveNames::kExplosion:
      return 100;
    case MoveNames::kFireBlast:
      return 85;
    case MoveNames::kFirePunch:
      return 100;
    case MoveNames::kFireSpin:
      return 70;
    case MoveNames::kFissure:
      return 30;
    case MoveNames::kFlamethrower:
      return 100;
    case MoveNames::kFlash:
      return 70;
    case MoveNames::kFly:
      return 95;
    case MoveNames::kFocusEnergy:
      return kNeverMiss;
    case MoveNames::kFuryAttack:
      return 85;
    case MoveNames::kFurySwipes:
      return 80;
    case MoveNames::kGlare:
      return 75;
    case MoveNames::kGrowl:
      return 100;
    case MoveNames::kGrowth:
      return kNeverMiss;
    case MoveNames::kGuillotine:
      return 30;
    case MoveNames::kGust:
      return 100;
    case MoveNames::kHarden:
      return kNeverMiss;
    case MoveNames::kHaze:
      return kNeverMiss;
    case MoveNames::kHeadbutt:
      return 100;
    case MoveNames::kHighJumpKick:
      return 90;
    case MoveNames::kHornAttack:
      return 100;
    case MoveNames::kHornDrill:
      return 30;
    case MoveNames::kHydroPump:
      return 80;
    case MoveNames::kHyperBeam:
      return 90;
    case MoveNames::kHyperFang:
      return 90;
    case MoveNames::kHypnosis:
      return 60;
    case MoveNames::kIceBeam:
      return 100;
    case MoveNames::kIcePunch:
      return 100;
    case MoveNames::kJumpKick:
      return 95;
    case MoveNames::kKarateChop:
      return 100;
    case MoveNames::kKinesis:
      return 80;
    case MoveNames::kLeechLife:
      return 100;
    case MoveNames::kLeechSeed:
      return 90;
    case MoveNames::kLeer:
      return 100;
    case MoveNames::kLick:
      return 100;
    case MoveNames::kLightScreen:
      return kNeverMiss;
    case MoveNames::kLovelyKiss:
      return 75;
    case MoveNames::kLowKick:
      return 90;
    case MoveNames::kMeditate:
      return kNeverMiss;
    case MoveNames::kMegaDrain:
      return 100;
    case MoveNames::kMegaKick:
      return 75;
    case MoveNames::kMegaPunch:
      return 85;
    case MoveNames::kMetronome:
      return kNeverMiss;
    case MoveNames::kMimic:
      return 100;
    case MoveNames::kMinimize:
      return kNeverMiss;
    case MoveNames::kMirrorMove:
      return kNeverMiss;
    case MoveNames::kMist:
      return kNeverMiss;
    case MoveNames::kNightShade:
      return 100;
    case MoveNames::kPayDay:
      return 100;
    case MoveNames::kPeck:
      return 100;
    case MoveNames::kPetalDance:
      return 100;
    case MoveNames::kPinMissile:
      return 85;
    case MoveNames::kPoisonGas:
      return 55;
    case MoveNames::kPoisonSting:
      return 100;
    case MoveNames::kPoisonPowder:
      return 75;
    case MoveNames::kPound:
      return 100;
    case MoveNames::kPsybeam:
      return 100;
    case MoveNames::kPsychic:
      return 100;
    case MoveNames::kPsywave:
      return 80;
    case MoveNames::kQuickAttack:
      return 100;
    case MoveNames::kRage:
      return 100;
    case MoveNames::kRazorLeaf:
      return 95;
    case MoveNames::kRazorWind:
      return 75;
    case MoveNames::kRecover:
      return kNeverMiss;
    case MoveNames::kReflect:
      return kNeverMiss;
    case MoveNames::kRest:
      return kNeverMiss;
    case MoveNames::kRoar:
      return 100;
    case MoveNames::kRockSlide:
      return 90;
    case MoveNames::kRockThrow:
      return 65;
    case MoveNames::kRollingKick:
      return 85;
    case MoveNames::kSandAttack:
      return 100;
    case MoveNames::kScratch:
      return 100;
    case MoveNames::kScreech:
      return 85;
    case MoveNames::kSeismicToss:
      return 100;
    case MoveNames::kSelfDestruct:
      return 100;
    case MoveNames::kSharpen:
      return kNeverMiss;
    case MoveNames::kSing:
      return 55;
    case MoveNames::kSkullBash:
      return 100;
    case MoveNames::kSkyAttack:
      return 90;
    case MoveNames::kSlam:
      return 75;
    case MoveNames::kSlash:
      return 100;
    case MoveNames::kSleepPowder:
      return 75;
    case MoveNames::kSludge:
      return 100;
    case MoveNames::kSmog:
      return 100;
    case MoveNames::kSmokescreen:
      return 100;
    case MoveNames::kSoftBoiled:
      return kNeverMiss;
    case MoveNames::kSolarBeam:
      return 100;
    case MoveNames::kSonicBoom:
      return 90;
    case MoveNames::kSpikeCannon:
      return 100;
    case MoveNames::kSplash:
      return kNeverMiss;
    case MoveNames::kSpore:
      return 100;
    case MoveNames::kStomp:
      return 100;
    case MoveNames::kStrength:
      return 100;
    case MoveNames::kStringShot:
      return 95;
    case MoveNames::kStruggle:
      return 100;
    case MoveNames::kStunSpore:
      return 75;
    case MoveNames::kSubmission:
      return 80;
    case MoveNames::kSubstitute:
      return kNeverMiss;
    case MoveNames::kSuperFang:
      return 90;
    case MoveNames::kSupersonic:
      return 55;
    case MoveNames::kSurf:
      return 100;
    case MoveNames::kSwift:
      return kNeverMiss;
    case MoveNames::kSwordsDance:
      return kNeverMiss;
    case MoveNames::kTackle:
      return 95;
    case MoveNames::kTailWhip:
      return 100;
    case MoveNames::kTakeDown:
      return 85;
    case MoveNames::kTeleport:
      return kNeverMiss;
    case MoveNames::kThrash:
      return 100;
    case MoveNames::kThunder:
      return 70;
    case MoveNames::kThunderWave:
      return 100;
    case MoveNames::kThunderbolt:
      return 100;
    case MoveNames::kThunderPunch:
      return 100;
    case MoveNames::kThunderShock:
      return 100;
    case MoveNames::kToxic:
      return 85;
    case MoveNames::kTransform:
      return kNeverMiss;
    case MoveNames::kTriAttack:
      return 100;
    case MoveNames::kTwineedle:
      return 100;
    case MoveNames::kViceGrip:
      return 100;
    case MoveNames::kVineWhip:
      return 100;
    case MoveNames::kWaterGun:
      return 100;
    case MoveNames::kWaterfall:
      return 100;
    case MoveNames::kWhirlwind:
      return 100;
    case MoveNames::kWingAttack:
      return 100;
    case MoveNames::kWithdraw:
      return kNeverMiss;
    case MoveNames::kWrap:
      return 85;
    case MoveNames::kPass:
    case MoveNames::kSwitch1:
    case MoveNames::kSwitch2:
    case MoveNames::kSwitch3:
    case MoveNames::kSwitch4:
    case MoveNames::kSwitch5:
    case MoveNames::kSwitch6:
    case MoveNames::kHitSelf:
      return kNeverMiss;
    default:
      assert(false);
  }
}

} //namespace artificialtrainer