//
// Created by neel on 1/26/19.
//

#ifndef ARTIFICIAL_TRAINER_MOVES_H
#define ARTIFICIAL_TRAINER_MOVES_H

namespace artificialtrainer {
enum class Moves : int {
  //Gen 1 moves
  kAbsorb,
  kAcid,
  kAcidArmor,
  kAgility,
  kAmnesia,
  kAuroraBeam,
  kBarrage,
  kBarrier,
  kBide,
  kBind,
  kBite,
  kBlizard,
  kBodySlam,
  kBoneClub,
  kBonemerang,
  kBubble,
  kBubbleBeam,
  kClamp,
  kCometPunch,
  kConfuseRay,
  kConfusion,
  kConstrict,
  kConversion,
  kCounter,
  kCrabhammer,
  kCut,
  kDefenseCurl,
  kDig,
  kDisable,
  kDizzyPunch,
  kDoubleKick,
  kDoubleSlap,
  kDoubleTeam,
  kDoubleEdge,
  kDragonRage,
  kDreamEater,
  kDrillPick,
  kEarthquake,
  kEggBomb,
  kEmber,
  kExplosion,
  kFireBlast,
  kFirePunch,
  kFireSpin,
  kFissure,
  kFlamethrower,
  kFlash,
  kFly,
  kFocusEnergy,
  kFuryAttack,
  kFurySwipes,
  kGlare,
  kGrowl,
  kGrowth,
  kGuillotine,
  kGust,
  kHarden,
  kHaze,
  kHeadbutt,
  kHighJumpKick,
  kHornAttack,
  kHornDrill,
  kHydroPump,
  kHyperBeam,
  kHyperFang,
  kHypnosis,
  kIceBeam,
  kIcePunch,
  kJumpKick,
  kKarateChop,
  kKinesis,
  kLeechLife,
  kLeechSeed,
  kLeer,
  kLick,
  kLightScreen,
  kLovelyKiss,
  kLowKick,
  kMeditate,
  kMegaDrain,
  kMegaKick,
  kMegaPunch,
  kMetronome,
  kMimic,
  kMinimize,
  kMirrorMove,
  kMist,
  kNightShade,
  kPayDay,
  kPeck,
  kPetalDance,
  kPinMissile,
  kPoisonGas,
  kPoisonPowder,
  kPoisonSting,
  kPound,
  kPsybeam,
  kPsychic,
  kPsywave,
  kQuickAttack,
  kRage,
  kRazorLeaf,
  kRazorWind,
  kRecover,
  kReflect,
  kRest,
  kRoar,
  kRockSlide,
  kRockThrow,
  kRollingKick,
  kSandAttack,
  kScratch,
  kScreech,
  kSeismicToss,
  kSelfDestruct,
  kSharpen,
  kSing,
  kSkullBash,
  kSkyAttack,
  kSlam,
  kSlash,
  kSleepPowder,
  kSludge,
  kSmog,
  kSmokescreen,
  kSoftBoiled,
  kSolarBeam,
  kSonicBoom,
  kSpikeCannon,
  kSplash,
  kSpore,
  kStomp,
  kStrength,
  kStringShot,
  kStruggle,
  kStunSpore,
  kSubmission,
  kSubstitute,
  kSuperFang,
  kSupersonic,
  kSurf,
  kSwift,
  kSwordsDance,
  kTackle,
  kTailWhip,
  kTakeDown,
  kTeleport,
  kThrash,
  kThunder,
  kThunderPunch,
  kThunderShock,
  kThunderWave,
  kThunderbolt,
  kToxic,
  kTransform,
  kTriAttack,
  kTwineedle,
  kViceGrip,
  kVineWhip,
  kWaterGun,
  kWaterfall,
  kWhirlwind,
  kWingAttack,
  kWithdraw,
  kWrap,

  //Other moves
  kPass,
  kSwitch1,
  kSwitch2,
  kSwitch3,
  kSwitch4,
  kSwitch5,
  kSwitch6,
  kHitSelf
};

const int kNumMoves = static_cast<int>(Moves::kWrap) + 1;

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_MOVES_H
