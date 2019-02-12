//
// Created by neel on 1/30/19.
//

#include <cassert>
#include "typecontainer.h"
#include "type.h"

namespace artificialtrainer {
namespace {
std::pair<TypeNames, TypeNames> TypePair(const SpeciesNames &species_name) {
  switch (species_name) {
    case SpeciesNames::kBulbasaur:
      return std::make_pair(TypeNames::kGrass, TypeNames::kPoison);
    case SpeciesNames::kIvysaur:
      return std::make_pair(TypeNames::kGrass, TypeNames::kPoison);
    case SpeciesNames::kVenusaur:
      return std::make_pair(TypeNames::kGrass, TypeNames::kPoison);
    case SpeciesNames::kCharmander:
      return std::make_pair(TypeNames::kFire, TypeNames::kNoType);
    case SpeciesNames::kCharmeleon:
      return std::make_pair(TypeNames::kFire, TypeNames::kNoType);
    case SpeciesNames::kCharizard:
      return std::make_pair(TypeNames::kFire, TypeNames::kFlying);
    case SpeciesNames::kSquirtle:
      return std::make_pair(TypeNames::kWater, TypeNames::kNoType);
    case SpeciesNames::kWartortle:
      return std::make_pair(TypeNames::kWater, TypeNames::kNoType);
    case SpeciesNames::kBlastoise:
      return std::make_pair(TypeNames::kWater, TypeNames::kNoType);
    case SpeciesNames::kCaterpie:
      return std::make_pair(TypeNames::kBug, TypeNames::kNoType);
    case SpeciesNames::kMetapod:
      return std::make_pair(TypeNames::kBug, TypeNames::kNoType);
    case SpeciesNames::kButterfree:
      return std::make_pair(TypeNames::kBug, TypeNames::kFlying);
    case SpeciesNames::kWeedle:
      return std::make_pair(TypeNames::kBug, TypeNames::kPoison);
    case SpeciesNames::kKakuna:
      return std::make_pair(TypeNames::kBug, TypeNames::kPoison);
    case SpeciesNames::kBeedrill:
      return std::make_pair(TypeNames::kBug, TypeNames::kPoison);
    case SpeciesNames::kPidgey:
      return std::make_pair(TypeNames::kNormal, TypeNames::kFlying);
    case SpeciesNames::kPidgeotto:
      return std::make_pair(TypeNames::kNormal, TypeNames::kFlying);
    case SpeciesNames::kPidgeot:
      return std::make_pair(TypeNames::kNormal, TypeNames::kFlying);
    case SpeciesNames::kRattata:
      return std::make_pair(TypeNames::kNormal, TypeNames::kNoType);
    case SpeciesNames::kRaticate:
      return std::make_pair(TypeNames::kNormal, TypeNames::kNoType);
    case SpeciesNames::kSpearow:
      return std::make_pair(TypeNames::kNormal, TypeNames::kFlying);
    case SpeciesNames::kFearow:
      return std::make_pair(TypeNames::kNormal, TypeNames::kFlying);
    case SpeciesNames::kEkans:
      return std::make_pair(TypeNames::kPoison, TypeNames::kNoType);
    case SpeciesNames::kArbok:
      return std::make_pair(TypeNames::kPoison, TypeNames::kNoType);
    case SpeciesNames::kPikachu:
      return std::make_pair(TypeNames::kElectric, TypeNames::kNoType);
    case SpeciesNames::kRaichu:
      return std::make_pair(TypeNames::kElectric, TypeNames::kNoType);
    case SpeciesNames::kSandshrew:
      return std::make_pair(TypeNames::kGround, TypeNames::kNoType);
    case SpeciesNames::kSandslash:
      return std::make_pair(TypeNames::kGround, TypeNames::kNoType);
    case SpeciesNames::kNidoranF:
      return std::make_pair(TypeNames::kPoison, TypeNames::kNoType);
    case SpeciesNames::kNidorina:
      return std::make_pair(TypeNames::kPoison, TypeNames::kNoType);
    case SpeciesNames::kNidoqueen:
      return std::make_pair(TypeNames::kPoison, TypeNames::kGround);
    case SpeciesNames::kNidoranM:
      return std::make_pair(TypeNames::kPoison, TypeNames::kNoType);
    case SpeciesNames::kNidorino:
      return std::make_pair(TypeNames::kPoison, TypeNames::kNoType);
    case SpeciesNames::kNidoking:
      return std::make_pair(TypeNames::kPoison, TypeNames::kGround);
    case SpeciesNames::kClefairy:
      return std::make_pair(TypeNames::kNormal, TypeNames::kNoType);
    case SpeciesNames::kClefable:
      return std::make_pair(TypeNames::kNormal, TypeNames::kNoType);
    case SpeciesNames::kVulpix:
      return std::make_pair(TypeNames::kFire, TypeNames::kNoType);
    case SpeciesNames::kNinetales:
      return std::make_pair(TypeNames::kFire, TypeNames::kNoType);
    case SpeciesNames::kJigglypuff:
      return std::make_pair(TypeNames::kNormal, TypeNames::kNoType);
    case SpeciesNames::kWigglytuff:
      return std::make_pair(TypeNames::kNormal, TypeNames::kNoType);
    case SpeciesNames::kZubat:
      return std::make_pair(TypeNames::kPoison, TypeNames::kFlying);
    case SpeciesNames::kGolbat:
      return std::make_pair(TypeNames::kPoison, TypeNames::kFlying);
    case SpeciesNames::kOddish:
      return std::make_pair(TypeNames::kGrass, TypeNames::kPoison);
    case SpeciesNames::kGloom:
      return std::make_pair(TypeNames::kGrass, TypeNames::kPoison);
    case SpeciesNames::kVileplume:
      return std::make_pair(TypeNames::kGrass, TypeNames::kPoison);
    case SpeciesNames::kParas:
      return std::make_pair(TypeNames::kBug, TypeNames::kGrass);
    case SpeciesNames::kParasect:
      return std::make_pair(TypeNames::kBug, TypeNames::kGrass);
    case SpeciesNames::kVenonat:
      return std::make_pair(TypeNames::kBug, TypeNames::kPoison);
    case SpeciesNames::kVenomoth:
      return std::make_pair(TypeNames::kBug, TypeNames::kPoison);
    case SpeciesNames::kDiglett:
      return std::make_pair(TypeNames::kGround, TypeNames::kNoType);
    case SpeciesNames::kDugtrio:
      return std::make_pair(TypeNames::kGround, TypeNames::kNoType);
    case SpeciesNames::kMeowth:
      return std::make_pair(TypeNames::kNormal, TypeNames::kNoType);
    case SpeciesNames::kPersian:
      return std::make_pair(TypeNames::kNormal, TypeNames::kNoType);
    case SpeciesNames::kPsyduck:
      return std::make_pair(TypeNames::kWater, TypeNames::kNoType);
    case SpeciesNames::kGolduck:
      return std::make_pair(TypeNames::kWater, TypeNames::kNoType);
    case SpeciesNames::kMankey:
      return std::make_pair(TypeNames::kFighting, TypeNames::kNoType);
    case SpeciesNames::kPrimeape:
      return std::make_pair(TypeNames::kFighting, TypeNames::kNoType);
    case SpeciesNames::kGrowlithe:
      return std::make_pair(TypeNames::kFire, TypeNames::kNoType);
    case SpeciesNames::kArcanine:
      return std::make_pair(TypeNames::kFire, TypeNames::kNoType);
    case SpeciesNames::kPoliwag:
      return std::make_pair(TypeNames::kWater, TypeNames::kNoType);
    case SpeciesNames::kPoliwhirl:
      return std::make_pair(TypeNames::kWater, TypeNames::kNoType);
    case SpeciesNames::kPoliwrath:
      return std::make_pair(TypeNames::kWater, TypeNames::kFighting);
    case SpeciesNames::kAbra:
      return std::make_pair(TypeNames::kPsychic, TypeNames::kNoType);
    case SpeciesNames::kKadabra:
      return std::make_pair(TypeNames::kPsychic, TypeNames::kNoType);
    case SpeciesNames::kAlakazam:
      return std::make_pair(TypeNames::kPsychic, TypeNames::kNoType);
    case SpeciesNames::kMachop:
      return std::make_pair(TypeNames::kFighting, TypeNames::kNoType);
    case SpeciesNames::kMachoke:
      return std::make_pair(TypeNames::kFighting, TypeNames::kNoType);
    case SpeciesNames::kMachamp:
      return std::make_pair(TypeNames::kFighting, TypeNames::kNoType);
    case SpeciesNames::kBellsprout:
      return std::make_pair(TypeNames::kGrass, TypeNames::kPoison);
    case SpeciesNames::kWeepinbell:
      return std::make_pair(TypeNames::kGrass, TypeNames::kPoison);
    case SpeciesNames::kVictreebel:
      return std::make_pair(TypeNames::kGrass, TypeNames::kPoison);
    case SpeciesNames::kTentacool:
      return std::make_pair(TypeNames::kWater, TypeNames::kPoison);
    case SpeciesNames::kTentacruel:
      return std::make_pair(TypeNames::kWater, TypeNames::kPoison);
    case SpeciesNames::kGeodude:
      return std::make_pair(TypeNames::kRock, TypeNames::kGround);
    case SpeciesNames::kGraveler:
      return std::make_pair(TypeNames::kRock, TypeNames::kGround);
    case SpeciesNames::kGolem:
      return std::make_pair(TypeNames::kRock, TypeNames::kGround);
    case SpeciesNames::kPonyta:
      return std::make_pair(TypeNames::kFire, TypeNames::kNoType);
    case SpeciesNames::kRapidash:
      return std::make_pair(TypeNames::kFire, TypeNames::kNoType);
    case SpeciesNames::kSlowpoke:
      return std::make_pair(TypeNames::kWater, TypeNames::kPsychic);
    case SpeciesNames::kSlowbro:
      return std::make_pair(TypeNames::kWater, TypeNames::kPsychic);
    case SpeciesNames::kMagnemite:
      return std::make_pair(TypeNames::kElectric, TypeNames::kNoType);
    case SpeciesNames::kMagneton:
      return std::make_pair(TypeNames::kElectric, TypeNames::kNoType);
    case SpeciesNames::kFarfetchd:
      return std::make_pair(TypeNames::kNormal, TypeNames::kFlying);
    case SpeciesNames::kDoduo:
      return std::make_pair(TypeNames::kNormal, TypeNames::kFlying);
    case SpeciesNames::kDodrio:
      return std::make_pair(TypeNames::kNormal, TypeNames::kFlying);
    case SpeciesNames::kSeel:
      return std::make_pair(TypeNames::kWater, TypeNames::kNoType);
    case SpeciesNames::kDewgong:
      return std::make_pair(TypeNames::kWater, TypeNames::kIce);
    case SpeciesNames::kGrimer:
      return std::make_pair(TypeNames::kPoison, TypeNames::kNoType);
    case SpeciesNames::kMuk:
      return std::make_pair(TypeNames::kPoison, TypeNames::kNoType);
    case SpeciesNames::kShellder:
      return std::make_pair(TypeNames::kWater, TypeNames::kNoType);
    case SpeciesNames::kCloyster:
      return std::make_pair(TypeNames::kWater, TypeNames::kIce);
    case SpeciesNames::kGastly:
      return std::make_pair(TypeNames::kGhost, TypeNames::kPoison);
    case SpeciesNames::kHaunter:
      return std::make_pair(TypeNames::kGhost, TypeNames::kPoison);
    case SpeciesNames::kGengar:
      return std::make_pair(TypeNames::kGhost, TypeNames::kPoison);
    case SpeciesNames::kOnix:
      return std::make_pair(TypeNames::kRock, TypeNames::kGround);
    case SpeciesNames::kDrowzee:
      return std::make_pair(TypeNames::kPsychic, TypeNames::kNoType);
    case SpeciesNames::kHypno:
      return std::make_pair(TypeNames::kPsychic, TypeNames::kNoType);
    case SpeciesNames::kKrabby:
      return std::make_pair(TypeNames::kWater, TypeNames::kNoType);
    case SpeciesNames::kKingler:
      return std::make_pair(TypeNames::kWater, TypeNames::kNoType);
    case SpeciesNames::kVoltorb:
      return std::make_pair(TypeNames::kElectric, TypeNames::kNoType);
    case SpeciesNames::kElectrode:
      return std::make_pair(TypeNames::kElectric, TypeNames::kNoType);
    case SpeciesNames::kExeggcute:
      return std::make_pair(TypeNames::kGrass, TypeNames::kPsychic);
    case SpeciesNames::kExeggutor:
      return std::make_pair(TypeNames::kGrass, TypeNames::kPsychic);
    case SpeciesNames::kCubone:
      return std::make_pair(TypeNames::kGround, TypeNames::kNoType);
    case SpeciesNames::kMarowak:
      return std::make_pair(TypeNames::kGround, TypeNames::kNoType);
    case SpeciesNames::kHitmonlee:
      return std::make_pair(TypeNames::kFighting, TypeNames::kNoType);
    case SpeciesNames::kHitmonchan:
      return std::make_pair(TypeNames::kFighting, TypeNames::kNoType);
    case SpeciesNames::kLickitung:
      return std::make_pair(TypeNames::kNormal, TypeNames::kNoType);
    case SpeciesNames::kKoffing:
      return std::make_pair(TypeNames::kPoison, TypeNames::kNoType);
    case SpeciesNames::kWeezing:
      return std::make_pair(TypeNames::kPoison, TypeNames::kNoType);
    case SpeciesNames::kRhyhorn:
      return std::make_pair(TypeNames::kGround, TypeNames::kRock);
    case SpeciesNames::kRhydon:
      return std::make_pair(TypeNames::kGround, TypeNames::kRock);
    case SpeciesNames::kChansey:
      return std::make_pair(TypeNames::kNormal, TypeNames::kNoType);
    case SpeciesNames::kTangela:
      return std::make_pair(TypeNames::kGrass, TypeNames::kNoType);
    case SpeciesNames::kKangaskhan:
      return std::make_pair(TypeNames::kNormal, TypeNames::kNoType);
    case SpeciesNames::kHorsea:
      return std::make_pair(TypeNames::kWater, TypeNames::kNoType);
    case SpeciesNames::kSeadra:
      return std::make_pair(TypeNames::kWater, TypeNames::kNoType);
    case SpeciesNames::kGoldeen:
      return std::make_pair(TypeNames::kWater, TypeNames::kNoType);
    case SpeciesNames::kSeaking:
      return std::make_pair(TypeNames::kWater, TypeNames::kNoType);
    case SpeciesNames::kStaryu:
      return std::make_pair(TypeNames::kWater, TypeNames::kNoType);
    case SpeciesNames::kStarmie:
      return std::make_pair(TypeNames::kWater, TypeNames::kPsychic);
    case SpeciesNames::kMrMime:
      return std::make_pair(TypeNames::kPsychic, TypeNames::kNoType);
    case SpeciesNames::kScyther:
      return std::make_pair(TypeNames::kBug, TypeNames::kFlying);
    case SpeciesNames::kJynx:
      return std::make_pair(TypeNames::kIce, TypeNames::kPsychic);
    case SpeciesNames::kElectabuzz:
      return std::make_pair(TypeNames::kElectric, TypeNames::kNoType);
    case SpeciesNames::kMagmar:
      return std::make_pair(TypeNames::kFire, TypeNames::kNoType);
    case SpeciesNames::kPinsir:
      return std::make_pair(TypeNames::kBug, TypeNames::kNoType);
    case SpeciesNames::kTauros:
      return std::make_pair(TypeNames::kNormal, TypeNames::kNoType);
    case SpeciesNames::kMagikarp:
      return std::make_pair(TypeNames::kWater, TypeNames::kNoType);
    case SpeciesNames::kGyarados:
      return std::make_pair(TypeNames::kWater, TypeNames::kFlying);
    case SpeciesNames::kLapras:
      return std::make_pair(TypeNames::kWater, TypeNames::kIce);
    case SpeciesNames::kDitto:
      return std::make_pair(TypeNames::kNormal, TypeNames::kNoType);
    case SpeciesNames::kEevee:
      return std::make_pair(TypeNames::kNormal, TypeNames::kNoType);
    case SpeciesNames::kVaporeon:
      return std::make_pair(TypeNames::kWater, TypeNames::kNoType);
    case SpeciesNames::kJolteon:
      return std::make_pair(TypeNames::kElectric, TypeNames::kNoType);
    case SpeciesNames::kFlareon:
      return std::make_pair(TypeNames::kFire, TypeNames::kNoType);
    case SpeciesNames::kPorygon:
      return std::make_pair(TypeNames::kNormal, TypeNames::kNoType);
    case SpeciesNames::kOmanyte:
      return std::make_pair(TypeNames::kRock, TypeNames::kWater);
    case SpeciesNames::kOmastar:
      return std::make_pair(TypeNames::kRock, TypeNames::kWater);
    case SpeciesNames::kKabuto:
      return std::make_pair(TypeNames::kRock, TypeNames::kWater);
    case SpeciesNames::kKabutops:
      return std::make_pair(TypeNames::kRock, TypeNames::kWater);
    case SpeciesNames::kAerodactyl:
      return std::make_pair(TypeNames::kRock, TypeNames::kFlying);
    case SpeciesNames::kSnorlax:
      return std::make_pair(TypeNames::kNormal, TypeNames::kNoType);
    case SpeciesNames::kArticuno:
      return std::make_pair(TypeNames::kIce, TypeNames::kFlying);
    case SpeciesNames::kZapdos:
      return std::make_pair(TypeNames::kElectric, TypeNames::kFlying);
    case SpeciesNames::kMoltres:
      return std::make_pair(TypeNames::kFire, TypeNames::kFlying);
    case SpeciesNames::kDratini:
      return std::make_pair(TypeNames::kDragon, TypeNames::kNoType);
    case SpeciesNames::kDragonair:
      return std::make_pair(TypeNames::kDragon, TypeNames::kNoType);
    case SpeciesNames::kDragonite:
      return std::make_pair(TypeNames::kDragon, TypeNames::kFlying);
    case SpeciesNames::kMewtwo:
      return std::make_pair(TypeNames::kPsychic, TypeNames::kNoType);
    case SpeciesNames::kMew:
      return std::make_pair(TypeNames::kPsychic, TypeNames::kNoType);
    default:
      assert(false);
  }
}

} //namespace

TypeContainer::TypeContainer(const SpeciesNames &species_name)
    : types_(TypePair(species_name)) {
}

TypeNames TypeContainer::FirstType() const {
  return types_.first;
}

TypeNames TypeContainer::SecondType() const {
  return types_.second;
}

bool TypeContainer::MoveMatchesType(const MoveNames &move_name) const {
  return Type(move_name) == types_.first || Type(move_name) == types_.second;
}

} //namespace artificialtrainer