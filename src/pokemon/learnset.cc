//
// Created by neel on 1/27/19.
//

#include "learnset.h"

namespace artificialtrainer {
auto Learnset(const Species &species) -> std::vector<Moves> {
  switch (species) {
    case Species::kBulbasaur:
      return std::vector<Moves>{Moves::kGrowl, Moves::kTackle,
                                Moves::kVineWhip, Moves::kLeechSeed,
                                Moves::kPoisonPowder, Moves::kRazorLeaf,
                                Moves::kGrowth, Moves::kSleepPowder,
                                Moves::kSolarBeam, Moves::kCut,
                                Moves::kSwordsDance, Moves::kToxic,
                                Moves::kBodySlam, Moves::kTakeDown,
                                Moves::kDoubleEdge, Moves::kRage,
                                Moves::kMegaDrain, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kReflect,
                                Moves::kBide, Moves::kRest, Moves::kSubstitute};
    case Species::kIvysaur:
      return std::vector<Moves>{Moves::kGrowl, Moves::kTackle,
                                Moves::kVineWhip, Moves::kLeechSeed,
                                Moves::kPoisonPowder, Moves::kRazorLeaf,
                                Moves::kGrowth, Moves::kSleepPowder,
                                Moves::kSolarBeam, Moves::kCut,
                                Moves::kSwordsDance, Moves::kToxic,
                                Moves::kBodySlam, Moves::kTakeDown,
                                Moves::kDoubleEdge, Moves::kRage,
                                Moves::kMegaDrain, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kReflect,
                                Moves::kBide, Moves::kRest, Moves::kSubstitute};
    case Species::kVenusaur:
      return std::vector<Moves>{Moves::kGrowl, Moves::kTackle,
                                Moves::kVineWhip, Moves::kLeechSeed,
                                Moves::kPoisonPowder, Moves::kRazorLeaf,
                                Moves::kGrowth, Moves::kSleepPowder,
                                Moves::kSolarBeam, Moves::kCut,
                                Moves::kSwordsDance, Moves::kToxic,
                                Moves::kBodySlam, Moves::kTakeDown,
                                Moves::kDoubleEdge, Moves::kRage,
                                Moves::kMegaDrain, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kReflect,
                                Moves::kBide, Moves::kRest,
                                Moves::kSubstitute, Moves::kHyperBeam};
    case Species::kCharmander:
      return std::vector<Moves>{Moves::kGrowl, Moves::kScratch,
                                Moves::kEmber, Moves::kLeer,
                                Moves::kSlash, Moves::kFlamethrower,
                                Moves::kFireSpin, Moves::kCut,
                                Moves::kStrength, Moves::kRage,
                                Moves::kMegaPunch, Moves::kSwordsDance,
                                Moves::kMegaKick, Moves::kToxic,
                                Moves::kBodySlam, Moves::kTakeDown,
                                Moves::kDoubleEdge, Moves::kSubmission,
                                Moves::kCounter, Moves::kSeismicToss,
                                Moves::kDragonRage, Moves::kDig,
                                Moves::kMimic, Moves::kDoubleTeam,
                                Moves::kReflect, Moves::kBide,
                                Moves::kFireBlast, Moves::kSwift,
                                Moves::kSkullBash, Moves::kRest,
                                Moves::kSubstitute};
    case Species::kCharmeleon:
      return std::vector<Moves>{Moves::kGrowl, Moves::kScratch,
                                Moves::kEmber, Moves::kLeer,
                                Moves::kSlash, Moves::kFlamethrower,
                                Moves::kFireSpin, Moves::kCut,
                                Moves::kStrength, Moves::kRage,
                                Moves::kMegaPunch, Moves::kSwordsDance,
                                Moves::kMegaKick, Moves::kToxic,
                                Moves::kBodySlam, Moves::kTakeDown,
                                Moves::kDoubleEdge, Moves::kSubmission,
                                Moves::kCounter, Moves::kSeismicToss,
                                Moves::kDragonRage, Moves::kDig,
                                Moves::kMimic, Moves::kDoubleTeam,
                                Moves::kReflect, Moves::kBide,
                                Moves::kFireBlast, Moves::kSwift,
                                Moves::kSkullBash, Moves::kRest,
                                Moves::kSubstitute};
    case Species::kCharizard:
      return std::vector<Moves>{Moves::kGrowl, Moves::kScratch,
                                Moves::kEmber, Moves::kLeer,
                                Moves::kSlash, Moves::kFlamethrower,
                                Moves::kFireSpin, Moves::kCut,
                                Moves::kStrength, Moves::kRage,
                                Moves::kMegaPunch, Moves::kSwordsDance,
                                Moves::kMegaKick, Moves::kToxic,
                                Moves::kBodySlam, Moves::kTakeDown,
                                Moves::kDoubleEdge, Moves::kHyperBeam,
                                Moves::kSubmission, Moves::kCounter,
                                Moves::kSeismicToss, Moves::kDragonRage,
                                Moves::kDig, Moves::kMimic, Moves::kDoubleTeam,
                                Moves::kReflect, Moves::kBide,
                                Moves::kFireBlast, Moves::kSwift,
                                Moves::kSkullBash, Moves::kRest,
                                Moves::kSubstitute, Moves::kEarthquake,
                                Moves::kFissure};
    case Species::kSquirtle:
      return std::vector<Moves>{Moves::kTackle, Moves::kTailWhip,
                                Moves::kBubble, Moves::kWaterGun,
                                Moves::kBite, Moves::kWithdraw,
                                Moves::kSkullBash, Moves::kHydroPump,
                                Moves::kStrength, Moves::kSurf,
                                Moves::kMegaPunch, Moves::kBubbleBeam,
                                Moves::kMegaKick, Moves::kToxic,
                                Moves::kBodySlam, Moves::kTakeDown,
                                Moves::kDoubleEdge, Moves::kSubmission,
                                Moves::kCounter, Moves::kSeismicToss,
                                Moves::kIceBeam, Moves::kBlizzard,
                                Moves::kRage, Moves::kDig, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kReflect,
                                Moves::kBide, Moves::kRest, Moves::kSubstitute};
    case Species::kWartortle:
      return std::vector<Moves>{Moves::kTackle, Moves::kTailWhip,
                                Moves::kBubble, Moves::kWaterGun,
                                Moves::kBite, Moves::kWithdraw,
                                Moves::kSkullBash, Moves::kHydroPump,
                                Moves::kStrength, Moves::kSurf,
                                Moves::kMegaPunch, Moves::kBubbleBeam,
                                Moves::kMegaKick, Moves::kToxic,
                                Moves::kBodySlam, Moves::kTakeDown,
                                Moves::kDoubleEdge, Moves::kSubmission,
                                Moves::kCounter, Moves::kSeismicToss,
                                Moves::kIceBeam, Moves::kBlizzard,
                                Moves::kRage, Moves::kDig, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kReflect,
                                Moves::kBide, Moves::kRest, Moves::kSubstitute};
    case Species::kBlastoise:
      return std::vector<Moves>{Moves::kTackle, Moves::kTailWhip,
                                Moves::kBubble, Moves::kWaterGun,
                                Moves::kBite, Moves::kWithdraw,
                                Moves::kSkullBash, Moves::kHydroPump,
                                Moves::kStrength, Moves::kSurf,
                                Moves::kMegaPunch, Moves::kBubbleBeam,
                                Moves::kMegaKick, Moves::kToxic,
                                Moves::kBodySlam, Moves::kTakeDown,
                                Moves::kDoubleEdge, Moves::kSubmission,
                                Moves::kCounter, Moves::kSeismicToss,
                                Moves::kIceBeam, Moves::kBlizzard,
                                Moves::kRage, Moves::kDig, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kReflect,
                                Moves::kBide, Moves::kRest,
                                Moves::kSubstitute, Moves::kHyperBeam,
                                Moves::kEarthquake, Moves::kFissure};
    case Species::kCaterpie:
      return std::vector<Moves>{Moves::kStringShot, Moves::kTackle};
    case Species::kMetapod:
      return std::vector<Moves>{Moves::kHarden, Moves::kStringShot,
                                Moves::kTackle};
    case Species::kButterfree:
      return std::vector<Moves>{Moves::kConfusion, Moves::kPoisonPowder,
                                Moves::kStunSpore, Moves::kSleepPowder,
                                Moves::kSupersonic, Moves::kWhirlwind,
                                Moves::kPsybeam, Moves::kHarden,
                                Moves::kStringShot, Moves::kTackle,
                                Moves::kRazorWind, Moves::kToxic,
                                Moves::kTakeDown, Moves::kDoubleEdge,
                                Moves::kHyperBeam, Moves::kRage,
                                Moves::kMegaDrain, Moves::kSolarBeam,
                                Moves::kPsychic, Moves::kTeleport,
                                Moves::kMimic, Moves::kDoubleTeam,
                                Moves::kReflect, Moves::kBide, Moves::kSwift,
                                Moves::kRest, Moves::kPsywave,
                                Moves::kSubstitute};
    case Species::kWeedle:
      return std::vector<Moves>{Moves::kPoisonSting, Moves::kStringShot};
    case Species::kKakuna:
      return std::vector<Moves>{Moves::kPoisonSting, Moves::kStringShot,
                                Moves::kHarden};
    case Species::kBeedrill:
      return std::vector<Moves>{Moves::kFuryAttack, Moves::kFocusEnergy,
                                Moves::kTwineedle, Moves::kRage,
                                Moves::kPinMissile, Moves::kAgility,
                                Moves::kHarden, Moves::kPoisonSting,
                                Moves::kStringShot, Moves::kCut,
                                Moves::kSwordsDance, Moves::kToxic,
                                Moves::kTakeDown, Moves::kDoubleEdge,
                                Moves::kHyperBeam, Moves::kMegaDrain,
                                Moves::kMimic, Moves::kDoubleTeam,
                                Moves::kReflect, Moves::kBide, Moves::kSwift,
                                Moves::kSkullBash, Moves::kRest,
                                Moves::kSubstitute};
    case Species::kPidgey:
      return std::vector<Moves>{Moves::kGust, Moves::kSandAttack,
                                Moves::kQuickAttack, Moves::kWhirlwind,
                                Moves::kWingAttack, Moves::kAgility,
                                Moves::kMirrorMove, Moves::kFly,
                                Moves::kRazorWind, Moves::kToxic,
                                Moves::kTakeDown, Moves::kDoubleEdge,
                                Moves::kRage, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kReflect,
                                Moves::kBide, Moves::kSwift,
                                Moves::kSkyAttack, Moves::kRest,
                                Moves::kSubstitute};
    case Species::kPidgeotto:
      return std::vector<Moves>{Moves::kGust, Moves::kSandAttack,
                                Moves::kQuickAttack, Moves::kWhirlwind,
                                Moves::kWingAttack, Moves::kAgility,
                                Moves::kMirrorMove, Moves::kFly,
                                Moves::kRazorWind, Moves::kToxic,
                                Moves::kTakeDown, Moves::kDoubleEdge,
                                Moves::kRage, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kReflect,
                                Moves::kBide, Moves::kSwift,
                                Moves::kSkyAttack, Moves::kRest,
                                Moves::kSubstitute};
    case Species::kPidgeot:
      return std::vector<Moves>{Moves::kGust, Moves::kSandAttack,
                                Moves::kQuickAttack, Moves::kWhirlwind,
                                Moves::kWingAttack, Moves::kAgility,
                                Moves::kMirrorMove, Moves::kFly,
                                Moves::kRazorWind, Moves::kToxic,
                                Moves::kTakeDown, Moves::kDoubleEdge,
                                Moves::kRage, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kReflect,
                                Moves::kBide, Moves::kSwift,
                                Moves::kSkyAttack, Moves::kRest,
                                Moves::kSubstitute, Moves::kHyperBeam};
    case Species::kRattata:
      return std::vector<Moves>{Moves::kTackle, Moves::kTailWhip,
                                Moves::kQuickAttack, Moves::kHyperFang,
                                Moves::kFocusEnergy, Moves::kSuperFang,
                                Moves::kToxic, Moves::kBodySlam,
                                Moves::kTakeDown, Moves::kDoubleEdge,
                                Moves::kBubbleBeam, Moves::kWaterGun,
                                Moves::kBlizzard, Moves::kRage,
                                Moves::kThunderbolt, Moves::kThunder,
                                Moves::kDig, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kBide,
                                Moves::kSwift, Moves::kSkullBash,
                                Moves::kRest, Moves::kSubstitute};
    case Species::kRaticate:
      return std::vector<Moves>{Moves::kTackle, Moves::kTailWhip,
                                Moves::kQuickAttack, Moves::kHyperFang,
                                Moves::kFocusEnergy, Moves::kSuperFang,
                                Moves::kToxic, Moves::kBodySlam,
                                Moves::kTakeDown, Moves::kDoubleEdge,
                                Moves::kBubbleBeam, Moves::kWaterGun,
                                Moves::kBlizzard, Moves::kRage,
                                Moves::kThunderbolt, Moves::kThunder,
                                Moves::kDig, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kBide,
                                Moves::kSwift, Moves::kSkullBash,
                                Moves::kRest, Moves::kSubstitute,
                                Moves::kIceBeam, Moves::kHyperBeam};
    case Species::kSpearow:
      return std::vector<Moves>{Moves::kGrowl, Moves::kPeck, Moves::kLeer,
                                Moves::kFuryAttack, Moves::kMirrorMove,
                                Moves::kDrillPeck, Moves::kAgility,
                                Moves::kFly, Moves::kRazorWind,
                                Moves::kWhirlwind, Moves::kToxic,
                                Moves::kTakeDown, Moves::kDoubleEdge,
                                Moves::kRage, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kBide,
                                Moves::kSwift, Moves::kSkyAttack,
                                Moves::kRest, Moves::kSubstitute};
    case Species::kFearow:
      return std::vector<Moves>{Moves::kGrowl, Moves::kPeck, Moves::kLeer,
                                Moves::kFuryAttack, Moves::kMirrorMove,
                                Moves::kDrillPeck, Moves::kAgility,
                                Moves::kFly, Moves::kRazorWind,
                                Moves::kWhirlwind, Moves::kToxic,
                                Moves::kTakeDown, Moves::kDoubleEdge,
                                Moves::kRage, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kBide,
                                Moves::kSwift, Moves::kSkyAttack,
                                Moves::kRest, Moves::kSubstitute,
                                Moves::kHyperBeam};
    case Species::kEkans:
      return std::vector<Moves>{Moves::kLeer, Moves::kWrap,
                                Moves::kPoisonSting, Moves::kBite,
                                Moves::kGlare, Moves::kScreech, Moves::kAcid,
                                Moves::kStrength, Moves::kToxic,
                                Moves::kBodySlam, Moves::kTakeDown,
                                Moves::kDoubleEdge, Moves::kRage,
                                Moves::kMegaDrain, Moves::kEarthquake,
                                Moves::kFissure, Moves::kDig, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kBide,
                                Moves::kSkullBash, Moves::kRest,
                                Moves::kRockSlide, Moves::kSubstitute};
    case Species::kArbok:
      return std::vector<Moves>{Moves::kLeer, Moves::kWrap,
                                Moves::kPoisonSting, Moves::kBite,
                                Moves::kGlare, Moves::kScreech, Moves::kAcid,
                                Moves::kStrength, Moves::kToxic,
                                Moves::kBodySlam, Moves::kTakeDown,
                                Moves::kDoubleEdge, Moves::kRage,
                                Moves::kMegaDrain, Moves::kEarthquake,
                                Moves::kFissure, Moves::kDig, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kBide,
                                Moves::kSkullBash, Moves::kRest,
                                Moves::kRockSlide, Moves::kSubstitute};
    case Species::kPikachu:
      return std::vector<Moves>{Moves::kGrowl, Moves::kThunderShock,
                                Moves::kThunderWave, Moves::kQuickAttack,
                                Moves::kSwift, Moves::kAgility,
                                Moves::kThunder, Moves::kFlash,
                                Moves::kMegaPunch, Moves::kMegaKick,
                                Moves::kToxic, Moves::kBodySlam,
                                Moves::kTakeDown, Moves::kDoubleEdge,
                                Moves::kPayDay, Moves::kSubmission,
                                Moves::kSeismicToss, Moves::kRage,
                                Moves::kThunderbolt, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kReflect,
                                Moves::kBide, Moves::kSkullBash,
                                Moves::kRest, Moves::kSubstitute};
    case Species::kRaichu:
      return std::vector<Moves>{Moves::kGrowl, Moves::kThunderShock,
                                Moves::kThunderWave, Moves::kQuickAttack,
                                Moves::kSwift, Moves::kAgility,
                                Moves::kThunder, Moves::kFlash,
                                Moves::kMegaPunch, Moves::kMegaKick,
                                Moves::kToxic, Moves::kBodySlam,
                                Moves::kTakeDown, Moves::kDoubleEdge,
                                Moves::kPayDay, Moves::kSubmission,
                                Moves::kSeismicToss, Moves::kRage,
                                Moves::kThunderbolt, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kReflect,
                                Moves::kBide, Moves::kSkullBash,
                                Moves::kRest, Moves::kSubstitute,
                                Moves::kHyperBeam};
    case Species::kSandshrew:
      return std::vector<Moves>{Moves::kScratch, Moves::kSandAttack,
                                Moves::kSlash, Moves::kPoisonSting,
                                Moves::kSwift, Moves::kFurySwipes,
                                Moves::kCut, Moves::kStrength,
                                Moves::kSwordsDance, Moves::kToxic,
                                Moves::kBodySlam, Moves::kTakeDown,
                                Moves::kDoubleEdge, Moves::kSubmission,
                                Moves::kSeismicToss, Moves::kRage,
                                Moves::kEarthquake, Moves::kFissure,
                                Moves::kDig, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kBide,
                                Moves::kSkullBash, Moves::kRest,
                                Moves::kSubstitute, Moves::kRockSlide};
    case Species::kSandslash:
      return std::vector<Moves>{Moves::kScratch, Moves::kSandAttack,
                                Moves::kSlash, Moves::kPoisonSting,
                                Moves::kSwift, Moves::kFurySwipes,
                                Moves::kCut, Moves::kStrength,
                                Moves::kSwordsDance, Moves::kToxic,
                                Moves::kBodySlam, Moves::kTakeDown,
                                Moves::kDoubleEdge, Moves::kSubmission,
                                Moves::kSeismicToss, Moves::kRage,
                                Moves::kEarthquake, Moves::kFissure,
                                Moves::kDig, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kBide,
                                Moves::kSkullBash, Moves::kRest,
                                Moves::kSubstitute, Moves::kRockSlide,
                                Moves::kHyperBeam};
    case Species::kNidoranF:
      return std::vector<Moves>{Moves::kGrowl, Moves::kTackle,
                                Moves::kScratch, Moves::kPoisonSting,
                                Moves::kTailWhip, Moves::kBite,
                                Moves::kFurySwipes, Moves::kDoubleKick,
                                Moves::kToxic, Moves::kBodySlam,
                                Moves::kTakeDown, Moves::kDoubleEdge,
                                Moves::kBlizzard, Moves::kRage,
                                Moves::kThunderbolt, Moves::kThunder,
                                Moves::kMimic, Moves::kDoubleTeam,
                                Moves::kReflect, Moves::kBide,
                                Moves::kSkullBash, Moves::kRest,
                                Moves::kSubstitute};
    case Species::kNidorina:
      return std::vector<Moves>{Moves::kGrowl, Moves::kTackle,
                                Moves::kScratch, Moves::kPoisonSting,
                                Moves::kTailWhip, Moves::kBite,
                                Moves::kFurySwipes, Moves::kDoubleKick,
                                Moves::kToxic, Moves::kBodySlam,
                                Moves::kTakeDown, Moves::kDoubleEdge,
                                Moves::kBlizzard, Moves::kRage,
                                Moves::kThunderbolt, Moves::kThunder,
                                Moves::kMimic, Moves::kDoubleTeam,
                                Moves::kReflect, Moves::kBide,
                                Moves::kSkullBash, Moves::kRest,
                                Moves::kSubstitute, Moves::kHornDrill,
                                Moves::kBubbleBeam, Moves::kWaterGun,
                                Moves::kIceBeam};
    case Species::kNidoqueen:
      return std::vector<Moves>{Moves::kGrowl, Moves::kTackle,
                                Moves::kScratch, Moves::kPoisonSting,
                                Moves::kTailWhip, Moves::kBite,
                                Moves::kFurySwipes, Moves::kDoubleKick,
                                Moves::kToxic, Moves::kBodySlam,
                                Moves::kTakeDown, Moves::kDoubleEdge,
                                Moves::kBlizzard, Moves::kRage,
                                Moves::kThunderbolt, Moves::kThunder,
                                Moves::kMimic, Moves::kDoubleTeam,
                                Moves::kReflect, Moves::kBide,
                                Moves::kSkullBash, Moves::kRest,
                                Moves::kSubstitute, Moves::kHornDrill,
                                Moves::kBubbleBeam, Moves::kWaterGun,
                                Moves::kIceBeam, Moves::kSurf,
                                Moves::kStrength, Moves::kMegaPunch,
                                Moves::kMegaKick, Moves::kHyperBeam,
                                Moves::kPayDay, Moves::kSubmission,
                                Moves::kCounter, Moves::kSeismicToss,
                                Moves::kEarthquake, Moves::kFissure,
                                Moves::kFireBlast, Moves::kRockSlide};
    case Species::kNidoranM:
      return std::vector<Moves>{Moves::kLeer, Moves::kTackle,
                                Moves::kHornAttack, Moves::kPoisonSting,
                                Moves::kFocusEnergy, Moves::kFuryAttack,
                                Moves::kHornDrill, Moves::kDoubleKick,
                                Moves::kToxic, Moves::kBodySlam,
                                Moves::kTakeDown, Moves::kDoubleEdge,
                                Moves::kBlizzard, Moves::kRage,
                                Moves::kThunderbolt, Moves::kThunder,
                                Moves::kMimic, Moves::kDoubleTeam,
                                Moves::kReflect, Moves::kBide,
                                Moves::kSkullBash, Moves::kRest,
                                Moves::kSubstitute};
    case Species::kNidorino:
      return std::vector<Moves>{Moves::kLeer, Moves::kTackle,
                                Moves::kHornAttack, Moves::kPoisonSting,
                                Moves::kFocusEnergy, Moves::kFuryAttack,
                                Moves::kHornDrill, Moves::kDoubleKick,
                                Moves::kToxic, Moves::kBodySlam,
                                Moves::kTakeDown, Moves::kDoubleEdge,
                                Moves::kBlizzard, Moves::kRage,
                                Moves::kThunderbolt, Moves::kThunder,
                                Moves::kMimic, Moves::kDoubleTeam,
                                Moves::kReflect, Moves::kBide,
                                Moves::kSkullBash, Moves::kRest,
                                Moves::kSubstitute, Moves::kBubbleBeam,
                                Moves::kWaterGun, Moves::kIceBeam};
    case Species::kNidoking:
      return std::vector<Moves>{Moves::kHornAttack, Moves::kTackle,
                                Moves::kThrash, Moves::kPoisonSting,
                                Moves::kLeer, Moves::kFocusEnergy,
                                Moves::kFuryAttack, Moves::kHornDrill,
                                Moves::kDoubleKick, Moves::kToxic,
                                Moves::kBodySlam, Moves::kTakeDown,
                                Moves::kDoubleEdge, Moves::kBlizzard,
                                Moves::kRage, Moves::kThunderbolt,
                                Moves::kThunder, Moves::kMimic,
                                Moves::kDoubleTeam, Moves::kReflect,
                                Moves::kBide, Moves::kSkullBash, Moves::kRest,
                                Moves::kSubstitute, Moves::kHornDrill,
                                Moves::kBubbleBeam, Moves::kWaterGun,
                                Moves::kIceBeam, Moves::kSurf,
                                Moves::kStrength, Moves::kMegaPunch,
                                Moves::kMegaKick, Moves::kHyperBeam,
                                Moves::kPayDay, Moves::kSubmission,
                                Moves::kCounter, Moves::kSeismicToss,
                                Moves::kEarthquake, Moves::kFissure,
                                Moves::kFireBlast, Moves::kRockSlide};
    case Species::kClefairy: return 48;
    case Species::kClefable: return 73;
    case Species::kVulpix: return 40;
    case Species::kNinetales: return 75;
    case Species::kJigglypuff: return 20;
    case Species::kWigglytuff: return 45;
    case Species::kZubat: return 35;
    case Species::kGolbat: return 70;
    case Species::kOddish: return 55;
    case Species::kGloom: return 70;
    case Species::kVileplume: return 85;
    case Species::kParas: return 55;
    case Species::kParasect: return 80;
    case Species::kVenonat: return 50;
    case Species::kVenomoth: return 60;
    case Species::kDiglett: return 25;
    case Species::kDugtrio: return 50;
    case Species::kMeowth: return 35;
    case Species::kPersian: return 60;
    case Species::kPsyduck: return 48;
    case Species::kGolduck: return 78;
    case Species::kMankey: return 35;
    case Species::kPrimeape: return 60;
    case Species::kGrowlithe: return 45;
    case Species::kArcanine: return 80;
    case Species::kPoliwag: return 40;
    case Species::kPoliwhirl: return 65;
    case Species::kPoliwrath: return 95;
    case Species::kAbra: return 15;
    case Species::kKadabra: return 30;
    case Species::kAlakazam: return 45;
    case Species::kMachop: return 50;
    case Species::kMachoke: return 70;
    case Species::kMachamp: return 80;
    case Species::kBellsprout: return 35;
    case Species::kWeepinbell: return 50;
    case Species::kVictreebel: return 65;
    case Species::kTentacool: return 35;
    case Species::kTentacruel: return 65;
    case Species::kGeodude: return 100;
    case Species::kGraveler: return 115;
    case Species::kGolem: return 130;
    case Species::kPonyta: return 55;
    case Species::kRapidash: return 70;
    case Species::kSlowpoke: return 65;
    case Species::kSlowbro: return 110;
    case Species::kMagnemite: return 70;
    case Species::kMagneton: return 95;
    case Species::kFarfetchd: return 55;
    case Species::kDoduo: return 45;
    case Species::kDodrio: return 70;
    case Species::kSeel: return 55;
    case Species::kDewgong: return 80;
    case Species::kGrimer: return 50;
    case Species::kMuk: return 75;
    case Species::kShellder: return 100;
    case Species::kCloyster: return 180;
    case Species::kGastly: return 30;
    case Species::kHaunter: return 45;
    case Species::kGengar: return 60;
    case Species::kOnix: return 160;
    case Species::kDrowzee: return 45;
    case Species::kHypno: return 70;
    case Species::kKrabby: return 90;
    case Species::kKingler: return 115;
    case Species::kVoltorb: return 50;
    case Species::kElectrode: return 70;
    case Species::kExeggcute: return 80;
    case Species::kExeggutor: return 85;
    case Species::kCubone: return 95;
    case Species::kMarowak: return 110;
    case Species::kHitmonlee: return 53;
    case Species::kHitmonchan: return 79;
    case Species::kLickitung: return 75;
    case Species::kKoffing: return 95;
    case Species::kWeezing: return 120;
    case Species::kRhyhorn: return 95;
    case Species::kRhydon: return 120;
    case Species::kChansey: return 5;
    case Species::kTangela: return 115;
    case Species::kKangaskhan: return 80;
    case Species::kHorsea: return 70;
    case Species::kSeadra: return 95;
    case Species::kGoldeen: return 60;
    case Species::kSeaking: return 65;
    case Species::kStaryu: return 55;
    case Species::kStarmie: return 85;
    case Species::kMrMime: return 65;
    case Species::kScyther: return 80;
    case Species::kJynx: return 35;
    case Species::kElectabuzz: return 57;
    case Species::kMagmar: return 57;
    case Species::kPinsir: return 100;
    case Species::kTauros: return 95;
    case Species::kMagikarp: return 55;
    case Species::kGyarados: return 79;
    case Species::kLapras: return 80;
    case Species::kDitto: return 48;
    case Species::kEevee: return 50;
    case Species::kVaporeon: return 60;
    case Species::kJolteon: return 60;
    case Species::kFlareon: return 60;
    case Species::kPorygon: return 70;
    case Species::kOmanyte: return 100;
    case Species::kOmastar: return 125;
    case Species::kKabuto: return 90;
    case Species::kKabutops: return 105;
    case Species::kAerodactyl: return 65;
    case Species::kSnorlax: return 65;
    case Species::kArticuno: return 100;
    case Species::kZapdos: return 85;
    case Species::kMoltres: return 90;
    case Species::kDratini: return 45;
    case Species::kDragonair: return 65;
    case Species::kDragonite: return 95;
    case Species::kMewtwo: return 90;
    case Species::kMew: return 100;
    default: break;
  };
}

} //namespace artificialtrainer