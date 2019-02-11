//
// Created by neel on //.
//

#include <cassert>
#include "stringconverter.h"

namespace artificialtrainer {
auto StringConverter::SpeciesToString(
    const SpeciesNames &species_name) -> std::string {
  switch (species_name) {
    case SpeciesNames::kBulbasaur:
      return "Bulbasaur";
    case SpeciesNames::kIvysaur:
      return "Ivysaur";
    case SpeciesNames::kVenusaur:
      return "Venusaur";
    case SpeciesNames::kCharmander:
      return "Charmander";
    case SpeciesNames::kCharmeleon:
      return "Charmeleon";
    case SpeciesNames::kCharizard:
      return "Charizard";
    case SpeciesNames::kSquirtle:
      return "Squirtle";
    case SpeciesNames::kWartortle:
      return "Wartortle";
    case SpeciesNames::kBlastoise:
      return "Blastoise";
    case SpeciesNames::kCaterpie:
      return "Caterpie";
    case SpeciesNames::kMetapod:
      return "Metapod";
    case SpeciesNames::kButterfree:
      return "Butterfree";
    case SpeciesNames::kWeedle:
      return "Weedle";
    case SpeciesNames::kKakuna:
      return "Kakuna";
    case SpeciesNames::kBeedrill:
      return "Beedrill";
    case SpeciesNames::kPidgey:
      return "Pidgey";
    case SpeciesNames::kPidgeotto:
      return "Pidgeotto";
    case SpeciesNames::kPidgeot:
      return "Pidgeot";
    case SpeciesNames::kRattata:
      return "Rattata";
    case SpeciesNames::kRaticate:
      return "Raticate";
    case SpeciesNames::kSpearow:
      return "Spearow";
    case SpeciesNames::kFearow:
      return "Fearow";
    case SpeciesNames::kEkans:
      return "Ekans";
    case SpeciesNames::kArbok:
      return "Arbok";
    case SpeciesNames::kPikachu:
      return "Pikachu";
    case SpeciesNames::kRaichu:
      return "Raichu";
    case SpeciesNames::kSandshrew:
      return "Sandshrew";
    case SpeciesNames::kSandslash:
      return "Sandslash";
    case SpeciesNames::kNidoranF:
      return "Nidoran (female)";
    case SpeciesNames::kNidorina:
      return "Nidorina";
    case SpeciesNames::kNidoqueen:
      return "Nidoqueen";
    case SpeciesNames::kNidoranM:
      return "Nidoran (male)";
    case SpeciesNames::kNidorino:
      return "Nidorino";
    case SpeciesNames::kNidoking:
      return "Nidoking";
    case SpeciesNames::kClefairy:
      return "Clefairy";
    case SpeciesNames::kClefable:
      return "Clefable";
    case SpeciesNames::kVulpix:
      return "Vulpix";
    case SpeciesNames::kNinetales:
      return "Ninetales";
    case SpeciesNames::kJigglypuff:
      return "Jigglypuff";
    case SpeciesNames::kWigglytuff:
      return "Wigglytuff";
    case SpeciesNames::kZubat:
      return "Zubat";
    case SpeciesNames::kGolbat:
      return "Golbat";
    case SpeciesNames::kOddish:
      return "Oddish";
    case SpeciesNames::kGloom:
      return "Gloom";
    case SpeciesNames::kVileplume:
      return "Vileplume";
    case SpeciesNames::kParas:
      return "Paras";
    case SpeciesNames::kParasect:
      return "Parasect";
    case SpeciesNames::kVenonat:
      return "Venonat";
    case SpeciesNames::kVenomoth:
      return "Venomoth";
    case SpeciesNames::kDiglett:
      return "Diglett";
    case SpeciesNames::kDugtrio:
      return "Dugtrio";
    case SpeciesNames::kMeowth:
      return "Meowth";
    case SpeciesNames::kPersian:
      return "Persian";
    case SpeciesNames::kPsyduck:
      return "Psyduck";
    case SpeciesNames::kGolduck:
      return "Golduck";
    case SpeciesNames::kMankey:
      return "Mankey";
    case SpeciesNames::kPrimeape:
      return "Primeape";
    case SpeciesNames::kGrowlithe:
      return "Growlithe";
    case SpeciesNames::kArcanine:
      return "Arcanine";
    case SpeciesNames::kPoliwag:
      return "Poliwag";
    case SpeciesNames::kPoliwhirl:
      return "Poliwhirl";
    case SpeciesNames::kPoliwrath:
      return "Poliwrath";
    case SpeciesNames::kAbra:
      return "Abra";
    case SpeciesNames::kKadabra:
      return "Kadabra";
    case SpeciesNames::kAlakazam:
      return "Alakazam";
    case SpeciesNames::kMachop:
      return "Machop";
    case SpeciesNames::kMachoke:
      return "Machoke";
    case SpeciesNames::kMachamp:
      return "Machamp";
    case SpeciesNames::kBellsprout:
      return "Bellsprout";
    case SpeciesNames::kWeepinbell:
      return "Weepinbell";
    case SpeciesNames::kVictreebel:
      return "Victreebell";
    case SpeciesNames::kTentacool:
      return "Tentacool";
    case SpeciesNames::kTentacruel:
      return "Tentacruel";
    case SpeciesNames::kGeodude:
      return "Geodude";
    case SpeciesNames::kGraveler:
      return "Graveler";
    case SpeciesNames::kGolem:
      return "Golem";
    case SpeciesNames::kPonyta:
      return "Ponyta";
    case SpeciesNames::kRapidash:
      return "Rapidash";
    case SpeciesNames::kSlowpoke:
      return "Slowpoke";
    case SpeciesNames::kSlowbro:
      return "Slowbro";
    case SpeciesNames::kMagnemite:
      return "Magnemite";
    case SpeciesNames::kMagneton:
      return "Magneton";
    case SpeciesNames::kFarfetchd:
      return "Farfetch'd";
    case SpeciesNames::kDoduo:
      return "Doduo";
    case SpeciesNames::kDodrio:
      return "Dodrio";
    case SpeciesNames::kSeel:
      return "Seel";
    case SpeciesNames::kDewgong:
      return "Dewgong";
    case SpeciesNames::kGrimer:
      return "Grimer";
    case SpeciesNames::kMuk:
      return "Muk";
    case SpeciesNames::kShellder:
      return "Shellder";
    case SpeciesNames::kCloyster:
      return "Cloyster";
    case SpeciesNames::kGastly:
      return "Gastly";
    case SpeciesNames::kHaunter:
      return "Haunter";
    case SpeciesNames::kGengar:
      return "Gengar";
    case SpeciesNames::kOnix:
      return "Onix";
    case SpeciesNames::kDrowzee:
      return "Drowzee";
    case SpeciesNames::kHypno:
      return "Hypno";
    case SpeciesNames::kKrabby:
      return "Krabby";
    case SpeciesNames::kKingler:
      return "Kingler";
    case SpeciesNames::kVoltorb:
      return "Voltorb";
    case SpeciesNames::kElectrode:
      return "Electrode";
    case SpeciesNames::kExeggcute:
      return "Exeggcute";
    case SpeciesNames::kExeggutor:
      return "Exeggutor";
    case SpeciesNames::kCubone:
      return "Cubone";
    case SpeciesNames::kMarowak:
      return "Marowak";
    case SpeciesNames::kHitmonlee:
      return "Hitmonlee";
    case SpeciesNames::kHitmonchan:
      return "Hitmonchan";
    case SpeciesNames::kLickitung:
      return "Lickitung";
    case SpeciesNames::kKoffing:
      return "Koffing";
    case SpeciesNames::kWeezing:
      return "Weezing";
    case SpeciesNames::kRhyhorn:
      return "Rhyhorn";
    case SpeciesNames::kRhydon:
      return "Rhydon";
    case SpeciesNames::kChansey:
      return "Chansey";
    case SpeciesNames::kTangela:
      return "Tangela";
    case SpeciesNames::kKangaskhan:
      return "Kangaskhan";
    case SpeciesNames::kHorsea:
      return "Horsea";
    case SpeciesNames::kSeadra:
      return "Seadra";
    case SpeciesNames::kGoldeen:
      return "Goldeen";
    case SpeciesNames::kSeaking:
      return "Seaking";
    case SpeciesNames::kStaryu:
      return "Staryu";
    case SpeciesNames::kStarmie:
      return "Starmie";
    case SpeciesNames::kMrMime:
      return "Mr. Mime";
    case SpeciesNames::kScyther:
      return "Scyther";
    case SpeciesNames::kJynx:
      return "Jynx";
    case SpeciesNames::kElectabuzz:
      return "Electabuzz";
    case SpeciesNames::kMagmar:
      return "Magmar";
    case SpeciesNames::kPinsir:
      return "Pinsir";
    case SpeciesNames::kTauros:
      return "Tauros";
    case SpeciesNames::kMagikarp:
      return "Magikarp";
    case SpeciesNames::kGyarados:
      return "Gyarados";
    case SpeciesNames::kLapras:
      return "Lapras";
    case SpeciesNames::kDitto:
      return "Ditto";
    case SpeciesNames::kEevee:
      return "Eevee";
    case SpeciesNames::kVaporeon:
      return "Vaporeon";
    case SpeciesNames::kJolteon:
      return "Jolteon";
    case SpeciesNames::kFlareon:
      return "Flareon";
    case SpeciesNames::kPorygon:
      return "Porygon";
    case SpeciesNames::kOmanyte:
      return "Omanyte";
    case SpeciesNames::kOmastar:
      return "Omastar";
    case SpeciesNames::kKabuto:
      return "Kabuto";
    case SpeciesNames::kKabutops:
      return "Kabutops";
    case SpeciesNames::kAerodactyl:
      return "Aerodactyl";
    case SpeciesNames::kSnorlax:
      return "Snorlax";
    case SpeciesNames::kArticuno:
      return "Articuno";
    case SpeciesNames::kZapdos:
      return "Zapdos";
    case SpeciesNames::kMoltres:
      return "Moltres";
    case SpeciesNames::kDratini:
      return "Dratini";
    case SpeciesNames::kDragonair:
      return "Dragonair";
    case SpeciesNames::kDragonite:
      return "Dragonite";
    case SpeciesNames::kMewtwo:
      return "Mewtwo";
    case SpeciesNames::kMew:
      return "Mew";
    default:
      assert(false);
  }
}

auto StringConverter::StatToString(const StatNames &stat_name) -> std::string {
  switch (stat_name) {
    case StatNames::kAttack:
      return "Attack";
    case StatNames::kDefense:
      return "Defense";
    case StatNames::kSpecial:
      return "Special";
    case StatNames::kSpeed:
      return "Speed";
    case StatNames::kHp:
      return "Hp";
    case StatNames::kAccuracy:
      return "Accuracy";
    case StatNames::kEvasion:
      return "Evasion";
    default:
      assert(false);
  }
}

auto StringConverter::MoveToString(const MoveNames &move_name) -> std::string {
  switch (move_name) {
    case MoveNames::kAbsorb:
      return "Absorb";
    case MoveNames::kAcid:
      return "Acid";
    case MoveNames::kAcidArmor:
      return "Acid Armor";
    case MoveNames::kAgility:
      return "Agility";
    case MoveNames::kAmnesia:
      return "Amnesia";
    case MoveNames::kAuroraBeam:
      return "Aurora Beam";
    case MoveNames::kBarrage:
      return "Barrage";
    case MoveNames::kBarrier:
      return "Barrier";
    case MoveNames::kBide:
      return "Bide";
    case MoveNames::kBind:
      return "Bind";
    case MoveNames::kBite:
      return "Bite";
    case MoveNames::kBlizzard:
      return "Blizzard";
    case MoveNames::kBodySlam:
      return "Body Slam";
    case MoveNames::kBoneClub:
      return "Bone Club";
    case MoveNames::kBonemerang:
      return "Bonemerang";
    case MoveNames::kBubble:
      return "Bubble";
    case MoveNames::kBubbleBeam:
      return "Bubble Beam";
    case MoveNames::kClamp:
      return "Clamp";
    case MoveNames::kCometPunch:
      return "Comet Punch";
    case MoveNames::kConfuseRay:
      return "Confuse Ray";
    case MoveNames::kConfusion:
      return "Confusion";
    case MoveNames::kConstrict:
      return "Constrict";
    case MoveNames::kConversion:
      return "Conversion";
    case MoveNames::kCounter:
      return "Counter";
    case MoveNames::kCrabhammer:
      return "Crabhammer";
    case MoveNames::kCut:
      return "Cut";
    case MoveNames::kDefenseCurl:
      return "Defense Curl";
    case MoveNames::kDig:
      return "Dig";
    case MoveNames::kDisable:
      return "Disable";
    case MoveNames::kDizzyPunch:
      return "Dizzy Punch";
    case MoveNames::kDoubleKick:
      return "Double Kick";
    case MoveNames::kDoubleTeam:
      return "Double Team";
    case MoveNames::kDoubleEdge:
      return "Double Edge";
    case MoveNames::kDoubleSlap:
      return "Double Slap";
    case MoveNames::kDragonRage:
      return "Dragon Rage";
    case MoveNames::kDreamEater:
      return "Dream Eater";
    case MoveNames::kDrillPeck:
      return "Drill Peck";
    case MoveNames::kEarthquake:
      return "Earthquake";
    case MoveNames::kEggBomb:
      return "Egg Bomb";
    case MoveNames::kEmber:
      return "Ember";
    case MoveNames::kExplosion:
      return "Explosion";
    case MoveNames::kFireBlast:
      return "Fire Blast";
    case MoveNames::kFirePunch:
      return "Fire Punch";
    case MoveNames::kFireSpin:
      return "Fire Spin";
    case MoveNames::kFissure:
      return "Fissure";
    case MoveNames::kFlamethrower:
      return "Flamethrower";
    case MoveNames::kFlash:
      return "Flash";
    case MoveNames::kFly:
      return "Fly";
    case MoveNames::kFocusEnergy:
      return "Focus Energy";
    case MoveNames::kFuryAttack:
      return "Fury Attack";
    case MoveNames::kFurySwipes:
      return "Fury Swipes";
    case MoveNames::kGlare:
      return "Glare";
    case MoveNames::kGrowl:
      return "Growl";
    case MoveNames::kGrowth:
      return "Growth";
    case MoveNames::kGuillotine:
      return "Guillotine";
    case MoveNames::kGust:
      return "Gust";
    case MoveNames::kHarden:
      return "Harden";
    case MoveNames::kHaze:
      return "Haze";
    case MoveNames::kHeadbutt:
      return "Headbutt";
    case MoveNames::kHighJumpKick:
      return "High Jump Kick";
    case MoveNames::kHornAttack:
      return "Horn Attack";
    case MoveNames::kHornDrill:
      return "Horn Drill";
    case MoveNames::kHydroPump:
      return "Hydro Pump";
    case MoveNames::kHyperBeam:
      return "Hyper Beam";
    case MoveNames::kHyperFang:
      return "Hyper Fang";
    case MoveNames::kHypnosis:
      return "Hypnosis";
    case MoveNames::kIceBeam:
      return "Ice Beam";
    case MoveNames::kIcePunch:
      return "Ice Punch";
    case MoveNames::kJumpKick:
      return "Jump Kick";
    case MoveNames::kKarateChop:
      return "Karate Chop";
    case MoveNames::kKinesis:
      return "Kinesis";
    case MoveNames::kLeechLife:
      return "Leech Life";
    case MoveNames::kLeechSeed:
      return "Leech Seed";
    case MoveNames::kLeer:
      return "Leer";
    case MoveNames::kLick:
      return "Lick";
    case MoveNames::kLightScreen:
      return "Light Screen";
    case MoveNames::kLovelyKiss:
      return "Lovely Kiss";
    case MoveNames::kLowKick:
      return "Low Kick";
    case MoveNames::kMeditate:
      return "Meditate";
    case MoveNames::kMegaDrain:
      return "Mega Drain";
    case MoveNames::kMegaKick:
      return "Mega Kick";
    case MoveNames::kMegaPunch:
      return "Mega Punch";
    case MoveNames::kMetronome:
      return "Metronome";
    case MoveNames::kMimic:
      return "Mimic";
    case MoveNames::kMinimize:
      return "Minimize";
    case MoveNames::kMirrorMove:
      return "Mirror Move";
    case MoveNames::kMist:
      return "Mist";
    case MoveNames::kNightShade:
      return "Night Shade";
    case MoveNames::kPayDay:
      return "Pay Day";
    case MoveNames::kPeck:
      return "Peck";
    case MoveNames::kPetalDance:
      return "Petal Dance";
    case MoveNames::kPinMissile:
      return "Pin Missile";
    case MoveNames::kPoisonGas:
      return "Poison Gas";
    case MoveNames::kPoisonSting:
      return "Poison Sting";
    case MoveNames::kPoisonPowder:
      return "Poison Powder";
    case MoveNames::kPound:
      return "Pound";
    case MoveNames::kPsybeam:
      return "Psybeam";
    case MoveNames::kPsychic:
      return "Psychic";
    case MoveNames::kPsywave:
      return "Psywave";
    case MoveNames::kQuickAttack:
      return "Quick Attack";
    case MoveNames::kRage:
      return "Rage";
    case MoveNames::kRazorLeaf:
      return "Razor Leaf";
    case MoveNames::kRazorWind:
      return "Razor Wind";
    case MoveNames::kRecover:
      return "Recover";
    case MoveNames::kReflect:
      return "Reflect";
    case MoveNames::kRest:
      return "Rest";
    case MoveNames::kRoar:
      return "Roar";
    case MoveNames::kRockSlide:
      return "Rock Slide";
    case MoveNames::kRockThrow:
      return "Rock Throw";
    case MoveNames::kRollingKick:
      return "Rolling Kick";
    case MoveNames::kSandAttack:
      return "Sand Attack";
    case MoveNames::kScratch:
      return "Scratch";
    case MoveNames::kScreech:
      return "Screech";
    case MoveNames::kSeismicToss:
      return "Seismic Toss";
    case MoveNames::kSelfDestruct:
      return "Self Destruct";
    case MoveNames::kSharpen:
      return "Sharpen";
    case MoveNames::kSing:
      return "Sing";
    case MoveNames::kSkullBash:
      return "Skull Bash";
    case MoveNames::kSkyAttack:
      return "Sky Attack";
    case MoveNames::kSlam:
      return "Slam";
    case MoveNames::kSlash:
      return "Slash";
    case MoveNames::kSleepPowder:
      return "Sleep Powder";
    case MoveNames::kSludge:
      return "Sludge";
    case MoveNames::kSmog:
      return "Smog";
    case MoveNames::kSmokescreen:
      return "Smoke Screen";
    case MoveNames::kSoftBoiled:
      return "Soft Boiled";
    case MoveNames::kSolarBeam:
      return "Solar Beam";
    case MoveNames::kSonicBoom:
      return "Sonic Boom";
    case MoveNames::kSpikeCannon:
      return "Spike Cannon";
    case MoveNames::kSplash:
      return "Splash";
    case MoveNames::kSpore:
      return "Spore";
    case MoveNames::kStomp:
      return "Stomp";
    case MoveNames::kStrength:
      return "Strength";
    case MoveNames::kStringShot:
      return "String Shot";
    case MoveNames::kStruggle:
      return "Struggle";
    case MoveNames::kStunSpore:
      return "Stun Spore";
    case MoveNames::kSubmission:
      return "Submission";
    case MoveNames::kSubstitute:
      return "Substitute";
    case MoveNames::kSuperFang:
      return "Super Fang";
    case MoveNames::kSupersonic:
      return "Supersonic";
    case MoveNames::kSurf:
      return "Surf";
    case MoveNames::kSwift:
      return "Swift";
    case MoveNames::kSwordsDance:
      return "Swords Dance";
    case MoveNames::kTackle:
      return "Tackle";
    case MoveNames::kTailWhip:
      return "Tail Whip";
    case MoveNames::kTakeDown:
      return "Take Down";
    case MoveNames::kTeleport:
      return "Teleport";
    case MoveNames::kThrash:
      return "Thrash";
    case MoveNames::kThunder:
      return "Thunder";
    case MoveNames::kThunderWave:
      return "Thunder Wave";
    case MoveNames::kThunderbolt:
      return "Thunderbolt";
    case MoveNames::kThunderPunch:
      return "Thunder Punch";
    case MoveNames::kThunderShock:
      return "Thunder Shock";
    case MoveNames::kToxic:
      return "Toxic";
    case MoveNames::kTransform:
      return "Transform";
    case MoveNames::kTriAttack:
      return "Tri Attack";
    case MoveNames::kTwineedle:
      return "Twineedle";
    case MoveNames::kViceGrip:
      return "Vice Grip";
    case MoveNames::kVineWhip:
      return "Vine Whip";
    case MoveNames::kWaterGun:
      return "Water Gun";
    case MoveNames::kWaterfall:
      return "Waterfall";
    case MoveNames::kWhirlwind:
      return "Whirlwind";
    case MoveNames::kWingAttack:
      return "Wind Attack";
    case MoveNames::kWithdraw:
      return "Withdraw";
    case MoveNames::kWrap:
      return "Wrap";
    case MoveNames::kPass:
      return "Pass";
    case MoveNames::kSwitch1:
      return "Switch 1";
    case MoveNames::kSwitch2:
      return "Switch 2";
    case MoveNames::kSwitch3:
      return "Switch 3";
    case MoveNames::kSwitch4:
      return "Switch 4";
    case MoveNames::kSwitch5:
      return "Switch 5";
    case MoveNames::kSwitch6:
      return "Switch 6";
    case MoveNames::kHitSelf:
      return "Hit Self";
    default:
      assert(false);
  }
}

auto StringConverter::TypeToString(const TypeNames &type_name) -> std::string {
  switch (type_name) {
    case TypeNames::kNormal:
      return "Normal";
    case TypeNames::kFighting:
        return "Fighting";
    case TypeNames::kFlying:
      return "Flying";
    case TypeNames::kPoison:
      return "Poison";
    case TypeNames::kGround:
      return "Ground";
    case TypeNames::kRock:
      return "Rock";
    case TypeNames::kBug:
      return "Bug";
    case TypeNames::kGhost:
      return "Ghost";
    case TypeNames::kFire:
      return "Fire";
    case TypeNames::kWater:
      return "Water";
    case TypeNames::kGrass:
      return "Grass";
    case TypeNames::kElectric:
      return "Electric";
    case TypeNames::kPsychic:
      return "Psychic";
    case TypeNames::kIce:
      return "Ice";
    case TypeNames::kDragon:
      return "Dragon";
    case TypeNames::kNoType:
      return "No Type";
    default:
      assert(false);
  }
}

} //namespace artificialtrainer