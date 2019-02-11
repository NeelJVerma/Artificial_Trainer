//
// Created by neel on 1/26/19.
//

#include <cassert>
#include <limits>
#include "pp.h"

namespace artificialtrainer {
const int kUnlimited = std::numeric_limits<int>::max();

auto Pp(const MoveNames &move_name) -> int {
  switch (move_name) {
    case MoveNames::kAbsorb:
      return 20;
    case MoveNames::kAcid:
      return 30;
    case MoveNames::kAcidArmor:
      return 40;
    case MoveNames::kAgility:
      return 30;
    case MoveNames::kAmnesia:
      return 20;
    case MoveNames::kAuroraBeam:
      return 20;
    case MoveNames::kBarrage:
      return 20;
    case MoveNames::kBarrier:
      return 30;
    case MoveNames::kBide:
      return 10;
    case MoveNames::kBind:
      return 20;
    case MoveNames::kBite:
      return 25;
    case MoveNames::kBlizzard:
      return 5;
    case MoveNames::kBodySlam:
      return 15;
    case MoveNames::kBoneClub:
      return 20;
    case MoveNames::kBonemerang:
      return 10;
    case MoveNames::kBubble:
      return 30;
    case MoveNames::kBubbleBeam:
      return 20;
    case MoveNames::kClamp:
      return 10;
    case MoveNames::kCometPunch:
      return 15;
    case MoveNames::kConfuseRay:
      return 10;
    case MoveNames::kConfusion:
      return 25;
    case MoveNames::kConstrict:
      return 35;
    case MoveNames::kConversion:
      return 30;
    case MoveNames::kCounter:
      return 20;
    case MoveNames::kCrabhammer:
      return 10;
    case MoveNames::kCut:
      return 30;
    case MoveNames::kDefenseCurl:
      return 40;
    case MoveNames::kDig:
      return 10;
    case MoveNames::kDisable:
      return 20;
    case MoveNames::kDizzyPunch:
      return 10;
    case MoveNames::kDoubleKick:
      return 30;
    case MoveNames::kDoubleTeam:
      return 15;
    case MoveNames::kDoubleEdge:
      return 15;
    case MoveNames::kDoubleSlap:
      return 10;
    case MoveNames::kDragonRage:
      return 10;
    case MoveNames::kDreamEater:
      return 15;
    case MoveNames::kDrillPeck:
      return 20;
    case MoveNames::kEarthquake:
      return 10;
    case MoveNames::kEggBomb:
      return 10;
    case MoveNames::kEmber:
      return 25;
    case MoveNames::kExplosion:
      return 5;
    case MoveNames::kFireBlast:
      return 5;
    case MoveNames::kFirePunch:
      return 15;
    case MoveNames::kFireSpin:
      return 15;
    case MoveNames::kFissure:
      return 5;
    case MoveNames::kFlamethrower:
      return 15;
    case MoveNames::kFlash:
      return 20;
    case MoveNames::kFly:
      return 15;
    case MoveNames::kFocusEnergy:
      return 30;
    case MoveNames::kFuryAttack:
      return 20;
    case MoveNames::kFurySwipes:
      return 15;
    case MoveNames::kGlare:
      return 30;
    case MoveNames::kGrowl:
      return 40;
    case MoveNames::kGrowth:
      return 40;
    case MoveNames::kGuillotine:
      return 5;
    case MoveNames::kGust:
      return 35;
    case MoveNames::kHarden:
      return 30;
    case MoveNames::kHaze:
      return 30;
    case MoveNames::kHeadbutt:
      return 15;
    case MoveNames::kHighJumpKick:
      return 20;
    case MoveNames::kHornAttack:
      return 25;
    case MoveNames::kHornDrill:
      return 5;
    case MoveNames::kHydroPump:
      return 5;
    case MoveNames::kHyperBeam:
      return 5;
    case MoveNames::kHyperFang:
      return 15;
    case MoveNames::kHypnosis:
      return 20;
    case MoveNames::kIceBeam:
      return 10;
    case MoveNames::kIcePunch:
      return 15;
    case MoveNames::kJumpKick:
      return 20;
    case MoveNames::kKarateChop:
      return 25;
    case MoveNames::kKinesis:
      return 15;
    case MoveNames::kLeechLife:
      return 15;
    case MoveNames::kLeechSeed:
      return 10;
    case MoveNames::kLeer:
      return 30;
    case MoveNames::kLick:
      return 30;
    case MoveNames::kLightScreen:
      return 30;
    case MoveNames::kLovelyKiss:
      return 10;
    case MoveNames::kLowKick:
      return 20;
    case MoveNames::kMeditate:
      return 40;
    case MoveNames::kMegaDrain:
      return 10;
    case MoveNames::kMegaKick:
      return 5;
    case MoveNames::kMegaPunch:
      return 20;
    case MoveNames::kMetronome:
      return 10;
    case MoveNames::kMimic:
      return 10;
    case MoveNames::kMinimize:
      return 20;
    case MoveNames::kMirrorMove:
      return 20;
    case MoveNames::kMist:
      return 30;
    case MoveNames::kNightShade:
      return 15;
    case MoveNames::kPayDay:
      return 20;
    case MoveNames::kPeck:
      return 35;
    case MoveNames::kPetalDance:
      return 20;
    case MoveNames::kPinMissile:
      return 20;
    case MoveNames::kPoisonGas:
      return 40;
    case MoveNames::kPoisonSting:
      return 35;
    case MoveNames::kPoisonPowder:
      return 35;
    case MoveNames::kPound:
      return 35;
    case MoveNames::kPsybeam:
      return 20;
    case MoveNames::kPsychic:
      return 10;
    case MoveNames::kPsywave:
      return 15;
    case MoveNames::kQuickAttack:
      return 30;
    case MoveNames::kRage:
      return 20;
    case MoveNames::kRazorLeaf:
      return 25;
    case MoveNames::kRazorWind:
      return 10;
    case MoveNames::kRecover:
      return 20;
    case MoveNames::kReflect:
      return 20;
    case MoveNames::kRest:
      return 10;
    case MoveNames::kRoar:
      return 20;
    case MoveNames::kRockSlide:
      return 10;
    case MoveNames::kRockThrow:
      return 15;
    case MoveNames::kRollingKick:
      return 15;
    case MoveNames::kSandAttack:
      return 15;
    case MoveNames::kScratch:
      return 35;
    case MoveNames::kScreech:
      return 10;
    case MoveNames::kSeismicToss:
      return 20;
    case MoveNames::kSelfDestruct:
      return 5;
    case MoveNames::kSharpen:
      return 30;
    case MoveNames::kSing:
      return 15;
    case MoveNames::kSkullBash:
      return 15;
    case MoveNames::kSkyAttack:
      return 5;
    case MoveNames::kSlam:
      return 20;
    case MoveNames::kSlash:
      return 20;
    case MoveNames::kSleepPowder:
      return 15;
    case MoveNames::kSludge:
      return 20;
    case MoveNames::kSmog:
      return 20;
    case MoveNames::kSmokescreen:
      return 20;
    case MoveNames::kSoftBoiled:
      return 10;
    case MoveNames::kSolarBeam:
      return 10;
    case MoveNames::kSonicBoom:
      return 20;
    case MoveNames::kSpikeCannon:
      return 15;
    case MoveNames::kSplash:
      return 40;
    case MoveNames::kSpore:
      return 15;
    case MoveNames::kStomp:
      return 20;
    case MoveNames::kStrength:
      return 15;
    case MoveNames::kStringShot:
      return 40;
    case MoveNames::kStruggle:
      return 1;
    case MoveNames::kStunSpore:
      return 30;
    case MoveNames::kSubmission:
      return 20;
    case MoveNames::kSubstitute:
      return 10;
    case MoveNames::kSuperFang:
      return 10;
    case MoveNames::kSupersonic:
      return 20;
    case MoveNames::kSurf:
      return 15;
    case MoveNames::kSwift:
      return 20;
    case MoveNames::kSwordsDance:
      return 30;
    case MoveNames::kTackle:
      return 35;
    case MoveNames::kTailWhip:
      return 30;
    case MoveNames::kTakeDown:
      return 20;
    case MoveNames::kTeleport:
      return 20;
    case MoveNames::kThrash:
      return 20;
    case MoveNames::kThunder:
      return 10;
    case MoveNames::kThunderWave:
      return 20;
    case MoveNames::kThunderbolt:
      return 15;
    case MoveNames::kThunderPunch:
      return 15;
    case MoveNames::kThunderShock:
      return 30;
    case MoveNames::kToxic:
      return 10;
    case MoveNames::kTransform:
      return 10;
    case MoveNames::kTriAttack:
      return 10;
    case MoveNames::kTwineedle:
      return 20;
    case MoveNames::kViceGrip:
      return 30;
    case MoveNames::kVineWhip:
      return 10;
    case MoveNames::kWaterGun:
      return 25;
    case MoveNames::kWaterfall:
      return 15;
    case MoveNames::kWhirlwind:
      return 20;
    case MoveNames::kWingAttack:
      return 35;
    case MoveNames::kWithdraw:
      return 40;
    case MoveNames::kWrap:
      return 20;
    case MoveNames::kPass:
    case MoveNames::kSwitch1:
    case MoveNames::kSwitch2:
    case MoveNames::kSwitch3:
    case MoveNames::kSwitch4:
    case MoveNames::kSwitch5:
    case MoveNames::kSwitch6:
    case MoveNames::kHitSelf:
      return kUnlimited;
    default:
      assert(false);
  }
}

} //namespace artificialtrainer