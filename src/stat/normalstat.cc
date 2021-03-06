/**
 * @project Artificial Trainer
 * @brief The implementation of the NormalStat class.
 *
 * @file normalstat.cc
 * @author Neel Verma
 * @date 1/24/19
 */

#include <cassert>
#include <cmath>
#include "normalstat.h"

namespace artificialtrainer {
namespace {

/**
  * @brief: A function to get the base attack stat for a given Pokemon.
  * @param const SpeciesNames &species: The species name of the Pokemon.
  * @return int: The base attack stat of the Pokemon.
  */

int GetAttackFromSpecies(const SpeciesNames &species_name) {
  switch (species_name) {
    case SpeciesNames::kBulbasaur:
      return 49;
    case SpeciesNames::kIvysaur:
      return 62;
    case SpeciesNames::kVenusaur:
      return 82;
    case SpeciesNames::kCharmander:
      return 52;
    case SpeciesNames::kCharmeleon:
      return 64;
    case SpeciesNames::kCharizard:
      return 84;
    case SpeciesNames::kSquirtle:
      return 48;
    case SpeciesNames::kWartortle:
      return 63;
    case SpeciesNames::kBlastoise:
      return 83;
    case SpeciesNames::kCaterpie:
      return 30;
    case SpeciesNames::kMetapod:
      return 20;
    case SpeciesNames::kButterfree:
      return 45;
    case SpeciesNames::kWeedle:
      return 35;
    case SpeciesNames::kKakuna:
      return 25;
    case SpeciesNames::kBeedrill:
      return 80;
    case SpeciesNames::kPidgey:
      return 45;
    case SpeciesNames::kPidgeotto:
      return 60;
    case SpeciesNames::kPidgeot:
      return 80;
    case SpeciesNames::kRattata:
      return 56;
    case SpeciesNames::kRaticate:
      return 81;
    case SpeciesNames::kSpearow:
      return 60;
    case SpeciesNames::kFearow:
      return 90;
    case SpeciesNames::kEkans:
      return 60;
    case SpeciesNames::kArbok:
      return 85;
    case SpeciesNames::kPikachu:
      return 55;
    case SpeciesNames::kRaichu:
      return 90;
    case SpeciesNames::kSandshrew:
      return 75;
    case SpeciesNames::kSandslash:
      return 100;
    case SpeciesNames::kNidoranF:
      return 47;
    case SpeciesNames::kNidorina:
      return 62;
    case SpeciesNames::kNidoqueen:
      return 82;
    case SpeciesNames::kNidoranM:
      return 57;
    case SpeciesNames::kNidorino:
      return 72;
    case SpeciesNames::kNidoking:
      return 92;
    case SpeciesNames::kClefairy:
      return 45;
    case SpeciesNames::kClefable:
      return 70;
    case SpeciesNames::kVulpix:
      return 41;
    case SpeciesNames::kNinetales:
      return 76;
    case SpeciesNames::kJigglypuff:
      return 45;
    case SpeciesNames::kWigglytuff:
      return 70;
    case SpeciesNames::kZubat:
      return 45;
    case SpeciesNames::kGolbat:
      return 80;
    case SpeciesNames::kOddish:
      return 50;
    case SpeciesNames::kGloom:
      return 65;
    case SpeciesNames::kVileplume:
      return 80;
    case SpeciesNames::kParas:
      return 70;
    case SpeciesNames::kParasect:
      return 95;
    case SpeciesNames::kVenonat:
      return 55;
    case SpeciesNames::kVenomoth:
      return 65;
    case SpeciesNames::kDiglett:
      return 55;
    case SpeciesNames::kDugtrio:
      return 80;
    case SpeciesNames::kMeowth:
      return 45;
    case SpeciesNames::kPersian:
      return 70;
    case SpeciesNames::kPsyduck:
      return 52;
    case SpeciesNames::kGolduck:
      return 82;
    case SpeciesNames::kMankey:
      return 80;
    case SpeciesNames::kPrimeape:
      return 105;
    case SpeciesNames::kGrowlithe:
      return 70;
    case SpeciesNames::kArcanine:
      return 110;
    case SpeciesNames::kPoliwag:
      return 50;
    case SpeciesNames::kPoliwhirl:
      return 65;
    case SpeciesNames::kPoliwrath:
      return 85;
    case SpeciesNames::kAbra:
      return 20;
    case SpeciesNames::kKadabra:
      return 35;
    case SpeciesNames::kAlakazam:
      return 50;
    case SpeciesNames::kMachop:
      return 80;
    case SpeciesNames::kMachoke:
      return 100;
    case SpeciesNames::kMachamp:
      return 130;
    case SpeciesNames::kBellsprout:
      return 75;
    case SpeciesNames::kWeepinbell:
      return 90;
    case SpeciesNames::kVictreebel:
      return 105;
    case SpeciesNames::kTentacool:
      return 40;
    case SpeciesNames::kTentacruel:
      return 70;
    case SpeciesNames::kGeodude:
      return 80;
    case SpeciesNames::kGraveler:
      return 95;
    case SpeciesNames::kGolem:
      return 110;
    case SpeciesNames::kPonyta:
      return 85;
    case SpeciesNames::kRapidash:
      return 100;
    case SpeciesNames::kSlowpoke:
      return 65;
    case SpeciesNames::kSlowbro:
      return 75;
    case SpeciesNames::kMagnemite:
      return 35;
    case SpeciesNames::kMagneton:
      return 60;
    case SpeciesNames::kFarfetchd:
      return 65;
    case SpeciesNames::kDoduo:
      return 85;
    case SpeciesNames::kDodrio:
      return 110;
    case SpeciesNames::kSeel:
      return 45;
    case SpeciesNames::kDewgong:
      return 70;
    case SpeciesNames::kGrimer:
      return 80;
    case SpeciesNames::kMuk:
      return 105;
    case SpeciesNames::kShellder:
      return 65;
    case SpeciesNames::kCloyster:
      return 95;
    case SpeciesNames::kGastly:
      return 35;
    case SpeciesNames::kHaunter:
      return 50;
    case SpeciesNames::kGengar:
      return 65;
    case SpeciesNames::kOnix:
      return 45;
    case SpeciesNames::kDrowzee:
      return 48;
    case SpeciesNames::kHypno:
      return 73;
    case SpeciesNames::kKrabby:
      return 105;
    case SpeciesNames::kKingler:
      return 130;
    case SpeciesNames::kVoltorb:
      return 30;
    case SpeciesNames::kElectrode:
      return 50;
    case SpeciesNames::kExeggcute:
      return 40;
    case SpeciesNames::kExeggutor:
      return 95;
    case SpeciesNames::kCubone:
      return 50;
    case SpeciesNames::kMarowak:
      return 80;
    case SpeciesNames::kHitmonlee:
      return 120;
    case SpeciesNames::kHitmonchan:
      return 105;
    case SpeciesNames::kLickitung:
      return 55;
    case SpeciesNames::kKoffing:
      return 65;
    case SpeciesNames::kWeezing:
      return 90;
    case SpeciesNames::kRhyhorn:
      return 85;
    case SpeciesNames::kRhydon:
      return 130;
    case SpeciesNames::kChansey:
      return 5;
    case SpeciesNames::kTangela:
      return 55;
    case SpeciesNames::kKangaskhan:
      return 95;
    case SpeciesNames::kHorsea:
      return 40;
    case SpeciesNames::kSeadra:
      return 65;
    case SpeciesNames::kGoldeen:
      return 67;
    case SpeciesNames::kSeaking:
      return 92;
    case SpeciesNames::kStaryu:
      return 45;
    case SpeciesNames::kStarmie:
      return 75;
    case SpeciesNames::kMrMime:
      return 45;
    case SpeciesNames::kScyther:
      return 110;
    case SpeciesNames::kJynx:
      return 50;
    case SpeciesNames::kElectabuzz:
      return 83;
    case SpeciesNames::kMagmar:
      return 95;
    case SpeciesNames::kPinsir:
      return 125;
    case SpeciesNames::kTauros:
      return 100;
    case SpeciesNames::kMagikarp:
      return 10;
    case SpeciesNames::kGyarados:
      return 125;
    case SpeciesNames::kLapras:
      return 85;
    case SpeciesNames::kDitto:
      return 48;
    case SpeciesNames::kEevee:
      return 55;
    case SpeciesNames::kVaporeon:
      return 65;
    case SpeciesNames::kJolteon:
      return 65;
    case SpeciesNames::kFlareon:
      return 130;
    case SpeciesNames::kPorygon:
      return 60;
    case SpeciesNames::kOmanyte:
      return 40;
    case SpeciesNames::kOmastar:
      return 60;
    case SpeciesNames::kKabuto:
      return 80;
    case SpeciesNames::kKabutops:
      return 115;
    case SpeciesNames::kAerodactyl:
      return 105;
    case SpeciesNames::kSnorlax:
      return 110;
    case SpeciesNames::kArticuno:
      return 85;
    case SpeciesNames::kZapdos:
      return 90;
    case SpeciesNames::kMoltres:
      return 100;
    case SpeciesNames::kDratini:
      return 64;
    case SpeciesNames::kDragonair:
      return 84;
    case SpeciesNames::kDragonite:
      return 134;
    case SpeciesNames::kMewtwo:
      return 110;
    case SpeciesNames::kMew:
      return 100;
    default:
      assert(false);
  }
}

/**
  * @brief: A function to get the base defense stat for a given Pokemon.
  * @param const SpeciesNames &species: The species name of the Pokemon.
  * @return int: The base defense stat of the Pokemon.
  */

int GetDefenseFromSpecies(const SpeciesNames &species_name) {
  switch (species_name) {
    case SpeciesNames::kBulbasaur:
      return 49;
    case SpeciesNames::kIvysaur:
      return 63;
    case SpeciesNames::kVenusaur:
      return 83;
    case SpeciesNames::kCharmander:
      return 43;
    case SpeciesNames::kCharmeleon:
      return 58;
    case SpeciesNames::kCharizard:
      return 78;
    case SpeciesNames::kSquirtle:
      return 65;
    case SpeciesNames::kWartortle:
      return 80;
    case SpeciesNames::kBlastoise:
      return 100;
    case SpeciesNames::kCaterpie:
      return 35;
    case SpeciesNames::kMetapod:
      return 55;
    case SpeciesNames::kButterfree:
      return 50;
    case SpeciesNames::kWeedle:
      return 30;
    case SpeciesNames::kKakuna:
      return 50;
    case SpeciesNames::kBeedrill:
      return 40;
    case SpeciesNames::kPidgey:
      return 40;
    case SpeciesNames::kPidgeotto:
      return 55;
    case SpeciesNames::kPidgeot:
      return 75;
    case SpeciesNames::kRattata:
      return 35;
    case SpeciesNames::kRaticate:
      return 60;
    case SpeciesNames::kSpearow:
      return 30;
    case SpeciesNames::kFearow:
      return 65;
    case SpeciesNames::kEkans:
      return 44;
    case SpeciesNames::kArbok:
      return 69;
    case SpeciesNames::kPikachu:
      return 30;
    case SpeciesNames::kRaichu:
      return 55;
    case SpeciesNames::kSandshrew:
      return 85;
    case SpeciesNames::kSandslash:
      return 110;
    case SpeciesNames::kNidoranF:
      return 52;
    case SpeciesNames::kNidorina:
      return 67;
    case SpeciesNames::kNidoqueen:
      return 87;
    case SpeciesNames::kNidoranM:
      return 40;
    case SpeciesNames::kNidorino:
      return 57;
    case SpeciesNames::kNidoking:
      return 77;
    case SpeciesNames::kClefairy:
      return 48;
    case SpeciesNames::kClefable:
      return 73;
    case SpeciesNames::kVulpix:
      return 40;
    case SpeciesNames::kNinetales:
      return 75;
    case SpeciesNames::kJigglypuff:
      return 20;
    case SpeciesNames::kWigglytuff:
      return 45;
    case SpeciesNames::kZubat:
      return 35;
    case SpeciesNames::kGolbat:
      return 70;
    case SpeciesNames::kOddish:
      return 55;
    case SpeciesNames::kGloom:
      return 70;
    case SpeciesNames::kVileplume:
      return 85;
    case SpeciesNames::kParas:
      return 55;
    case SpeciesNames::kParasect:
      return 80;
    case SpeciesNames::kVenonat:
      return 50;
    case SpeciesNames::kVenomoth:
      return 60;
    case SpeciesNames::kDiglett:
      return 25;
    case SpeciesNames::kDugtrio:
      return 50;
    case SpeciesNames::kMeowth:
      return 35;
    case SpeciesNames::kPersian:
      return 60;
    case SpeciesNames::kPsyduck:
      return 48;
    case SpeciesNames::kGolduck:
      return 78;
    case SpeciesNames::kMankey:
      return 35;
    case SpeciesNames::kPrimeape:
      return 60;
    case SpeciesNames::kGrowlithe:
      return 45;
    case SpeciesNames::kArcanine:
      return 80;
    case SpeciesNames::kPoliwag:
      return 40;
    case SpeciesNames::kPoliwhirl:
      return 65;
    case SpeciesNames::kPoliwrath:
      return 95;
    case SpeciesNames::kAbra:
      return 15;
    case SpeciesNames::kKadabra:
      return 30;
    case SpeciesNames::kAlakazam:
      return 45;
    case SpeciesNames::kMachop:
      return 50;
    case SpeciesNames::kMachoke:
      return 70;
    case SpeciesNames::kMachamp:
      return 80;
    case SpeciesNames::kBellsprout:
      return 35;
    case SpeciesNames::kWeepinbell:
      return 50;
    case SpeciesNames::kVictreebel:
      return 65;
    case SpeciesNames::kTentacool:
      return 35;
    case SpeciesNames::kTentacruel:
      return 65;
    case SpeciesNames::kGeodude:
      return 100;
    case SpeciesNames::kGraveler:
      return 115;
    case SpeciesNames::kGolem:
      return 130;
    case SpeciesNames::kPonyta:
      return 55;
    case SpeciesNames::kRapidash:
      return 70;
    case SpeciesNames::kSlowpoke:
      return 65;
    case SpeciesNames::kSlowbro:
      return 110;
    case SpeciesNames::kMagnemite:
      return 70;
    case SpeciesNames::kMagneton:
      return 95;
    case SpeciesNames::kFarfetchd:
      return 55;
    case SpeciesNames::kDoduo:
      return 45;
    case SpeciesNames::kDodrio:
      return 70;
    case SpeciesNames::kSeel:
      return 55;
    case SpeciesNames::kDewgong:
      return 80;
    case SpeciesNames::kGrimer:
      return 50;
    case SpeciesNames::kMuk:
      return 75;
    case SpeciesNames::kShellder:
      return 100;
    case SpeciesNames::kCloyster:
      return 180;
    case SpeciesNames::kGastly:
      return 30;
    case SpeciesNames::kHaunter:
      return 45;
    case SpeciesNames::kGengar:
      return 60;
    case SpeciesNames::kOnix:
      return 160;
    case SpeciesNames::kDrowzee:
      return 45;
    case SpeciesNames::kHypno:
      return 70;
    case SpeciesNames::kKrabby:
      return 90;
    case SpeciesNames::kKingler:
      return 115;
    case SpeciesNames::kVoltorb:
      return 50;
    case SpeciesNames::kElectrode:
      return 70;
    case SpeciesNames::kExeggcute:
      return 80;
    case SpeciesNames::kExeggutor:
      return 85;
    case SpeciesNames::kCubone:
      return 95;
    case SpeciesNames::kMarowak:
      return 110;
    case SpeciesNames::kHitmonlee:
      return 53;
    case SpeciesNames::kHitmonchan:
      return 79;
    case SpeciesNames::kLickitung:
      return 75;
    case SpeciesNames::kKoffing:
      return 95;
    case SpeciesNames::kWeezing:
      return 120;
    case SpeciesNames::kRhyhorn:
      return 95;
    case SpeciesNames::kRhydon:
      return 120;
    case SpeciesNames::kChansey:
      return 5;
    case SpeciesNames::kTangela:
      return 115;
    case SpeciesNames::kKangaskhan:
      return 80;
    case SpeciesNames::kHorsea:
      return 70;
    case SpeciesNames::kSeadra:
      return 95;
    case SpeciesNames::kGoldeen:
      return 60;
    case SpeciesNames::kSeaking:
      return 65;
    case SpeciesNames::kStaryu:
      return 55;
    case SpeciesNames::kStarmie:
      return 85;
    case SpeciesNames::kMrMime:
      return 65;
    case SpeciesNames::kScyther:
      return 80;
    case SpeciesNames::kJynx:
      return 35;
    case SpeciesNames::kElectabuzz:
      return 57;
    case SpeciesNames::kMagmar:
      return 57;
    case SpeciesNames::kPinsir:
      return 100;
    case SpeciesNames::kTauros:
      return 95;
    case SpeciesNames::kMagikarp:
      return 55;
    case SpeciesNames::kGyarados:
      return 79;
    case SpeciesNames::kLapras:
      return 80;
    case SpeciesNames::kDitto:
      return 48;
    case SpeciesNames::kEevee:
      return 50;
    case SpeciesNames::kVaporeon:
      return 60;
    case SpeciesNames::kJolteon:
      return 60;
    case SpeciesNames::kFlareon:
      return 60;
    case SpeciesNames::kPorygon:
      return 70;
    case SpeciesNames::kOmanyte:
      return 100;
    case SpeciesNames::kOmastar:
      return 125;
    case SpeciesNames::kKabuto:
      return 90;
    case SpeciesNames::kKabutops:
      return 105;
    case SpeciesNames::kAerodactyl:
      return 65;
    case SpeciesNames::kSnorlax:
      return 65;
    case SpeciesNames::kArticuno:
      return 100;
    case SpeciesNames::kZapdos:
      return 85;
    case SpeciesNames::kMoltres:
      return 90;
    case SpeciesNames::kDratini:
      return 45;
    case SpeciesNames::kDragonair:
      return 65;
    case SpeciesNames::kDragonite:
      return 95;
    case SpeciesNames::kMewtwo:
      return 90;
    case SpeciesNames::kMew:
      return 100;
    default:
      assert(false);
  }
}

/**
  * @brief: A function to get the base special stat for a given Pokemon.
  * @param const SpeciesNames &species: The species name of the Pokemon.
  * @return int: The base special stat of the Pokemon.
  */

int GetSpecialFromSpecies(const SpeciesNames &species_name) {
  switch (species_name) {
    case SpeciesNames::kBulbasaur:
      return 65;
    case SpeciesNames::kIvysaur:
      return 80;
    case SpeciesNames::kVenusaur:
      return 100;
    case SpeciesNames::kCharmander:
      return 50;
    case SpeciesNames::kCharmeleon:
      return 65;
    case SpeciesNames::kCharizard:
      return 85;
    case SpeciesNames::kSquirtle:
      return 50;
    case SpeciesNames::kWartortle:
      return 65;
    case SpeciesNames::kBlastoise:
      return 85;
    case SpeciesNames::kCaterpie:
      return 20;
    case SpeciesNames::kMetapod:
      return 25;
    case SpeciesNames::kButterfree:
      return 80;
    case SpeciesNames::kWeedle:
      return 20;
    case SpeciesNames::kKakuna:
      return 25;
    case SpeciesNames::kBeedrill:
      return 45;
    case SpeciesNames::kPidgey:
      return 35;
    case SpeciesNames::kPidgeotto:
      return 50;
    case SpeciesNames::kPidgeot:
      return 70;
    case SpeciesNames::kRattata:
      return 25;
    case SpeciesNames::kRaticate:
      return 50;
    case SpeciesNames::kSpearow:
      return 31;
    case SpeciesNames::kFearow:
      return 61;
    case SpeciesNames::kEkans:
      return 40;
    case SpeciesNames::kArbok:
      return 65;
    case SpeciesNames::kPikachu:
      return 50;
    case SpeciesNames::kRaichu:
      return 90;
    case SpeciesNames::kSandshrew:
      return 30;
    case SpeciesNames::kSandslash:
      return 55;
    case SpeciesNames::kNidoranF:
      return 40;
    case SpeciesNames::kNidorina:
      return 55;
    case SpeciesNames::kNidoqueen:
      return 75;
    case SpeciesNames::kNidoranM:
      return 40;
    case SpeciesNames::kNidorino:
      return 55;
    case SpeciesNames::kNidoking:
      return 75;
    case SpeciesNames::kClefairy:
      return 60;
    case SpeciesNames::kClefable:
      return 85;
    case SpeciesNames::kVulpix:
      return 65;
    case SpeciesNames::kNinetales:
      return 100;
    case SpeciesNames::kJigglypuff:
      return 25;
    case SpeciesNames::kWigglytuff:
      return 50;
    case SpeciesNames::kZubat:
      return 40;
    case SpeciesNames::kGolbat:
      return 75;
    case SpeciesNames::kOddish:
      return 75;
    case SpeciesNames::kGloom:
      return 85;
    case SpeciesNames::kVileplume:
      return 100;
    case SpeciesNames::kParas:
      return 55;
    case SpeciesNames::kParasect:
      return 80;
    case SpeciesNames::kVenonat:
      return 40;
    case SpeciesNames::kVenomoth:
      return 90;
    case SpeciesNames::kDiglett:
      return 45;
    case SpeciesNames::kDugtrio:
      return 70;
    case SpeciesNames::kMeowth:
      return 40;
    case SpeciesNames::kPersian:
      return 65;
    case SpeciesNames::kPsyduck:
      return 50;
    case SpeciesNames::kGolduck:
      return 80;
    case SpeciesNames::kMankey:
      return 35;
    case SpeciesNames::kPrimeape:
      return 60;
    case SpeciesNames::kGrowlithe:
      return 50;
    case SpeciesNames::kArcanine:
      return 80;
    case SpeciesNames::kPoliwag:
      return 40;
    case SpeciesNames::kPoliwhirl:
      return 50;
    case SpeciesNames::kPoliwrath:
      return 70;
    case SpeciesNames::kAbra:
      return 105;
    case SpeciesNames::kKadabra:
      return 120;
    case SpeciesNames::kAlakazam:
      return 135;
    case SpeciesNames::kMachop:
      return 35;
    case SpeciesNames::kMachoke:
      return 50;
    case SpeciesNames::kMachamp:
      return 65;
    case SpeciesNames::kBellsprout:
      return 70;
    case SpeciesNames::kWeepinbell:
      return 85;
    case SpeciesNames::kVictreebel:
      return 100;
    case SpeciesNames::kTentacool:
      return 100;
    case SpeciesNames::kTentacruel:
      return 120;
    case SpeciesNames::kGeodude:
      return 30;
    case SpeciesNames::kGraveler:
      return 45;
    case SpeciesNames::kGolem:
      return 55;
    case SpeciesNames::kPonyta:
      return 65;
    case SpeciesNames::kRapidash:
      return 80;
    case SpeciesNames::kSlowpoke:
      return 40;
    case SpeciesNames::kSlowbro:
      return 80;
    case SpeciesNames::kMagnemite:
      return 95;
    case SpeciesNames::kMagneton:
      return 120;
    case SpeciesNames::kFarfetchd:
      return 58;
    case SpeciesNames::kDoduo:
      return 35;
    case SpeciesNames::kDodrio:
      return 60;
    case SpeciesNames::kSeel:
      return 70;
    case SpeciesNames::kDewgong:
      return 95;
    case SpeciesNames::kGrimer:
      return 40;
    case SpeciesNames::kMuk:
      return 65;
    case SpeciesNames::kShellder:
      return 45;
    case SpeciesNames::kCloyster:
      return 85;
    case SpeciesNames::kGastly:
      return 100;
    case SpeciesNames::kHaunter:
      return 115;
    case SpeciesNames::kGengar:
      return 130;
    case SpeciesNames::kOnix:
      return 30;
    case SpeciesNames::kDrowzee:
      return 90;
    case SpeciesNames::kHypno:
      return 115;
    case SpeciesNames::kKrabby:
      return 25;
    case SpeciesNames::kKingler:
      return 50;
    case SpeciesNames::kVoltorb:
      return 55;
    case SpeciesNames::kElectrode:
      return 80;
    case SpeciesNames::kExeggcute:
      return 60;
    case SpeciesNames::kExeggutor:
      return 125;
    case SpeciesNames::kCubone:
      return 40;
    case SpeciesNames::kMarowak:
      return 50;
    case SpeciesNames::kHitmonlee:
      return 35;
    case SpeciesNames::kHitmonchan:
      return 35;
    case SpeciesNames::kLickitung:
      return 60;
    case SpeciesNames::kKoffing:
      return 60;
    case SpeciesNames::kWeezing:
      return 85;
    case SpeciesNames::kRhyhorn:
      return 30;
    case SpeciesNames::kRhydon:
      return 45;
    case SpeciesNames::kChansey:
      return 105;
    case SpeciesNames::kTangela:
      return 100;
    case SpeciesNames::kKangaskhan:
      return 40;
    case SpeciesNames::kHorsea:
      return 70;
    case SpeciesNames::kSeadra:
      return 95;
    case SpeciesNames::kGoldeen:
      return 50;
    case SpeciesNames::kSeaking:
      return 80;
    case SpeciesNames::kStaryu:
      return 70;
    case SpeciesNames::kStarmie:
      return 100;
    case SpeciesNames::kMrMime:
      return 100;
    case SpeciesNames::kScyther:
      return 55;
    case SpeciesNames::kJynx:
      return 95;
    case SpeciesNames::kElectabuzz:
      return 85;
    case SpeciesNames::kMagmar:
      return 85;
    case SpeciesNames::kPinsir:
      return 55;
    case SpeciesNames::kTauros:
      return 70;
    case SpeciesNames::kMagikarp:
      return 20;
    case SpeciesNames::kGyarados:
      return 100;
    case SpeciesNames::kLapras:
      return 95;
    case SpeciesNames::kDitto:
      return 48;
    case SpeciesNames::kEevee:
      return 65;
    case SpeciesNames::kVaporeon:
      return 110;
    case SpeciesNames::kJolteon:
      return 110;
    case SpeciesNames::kFlareon:
      return 110;
    case SpeciesNames::kPorygon:
      return 75;
    case SpeciesNames::kOmanyte:
      return 90;
    case SpeciesNames::kOmastar:
      return 115;
    case SpeciesNames::kKabuto:
      return 45;
    case SpeciesNames::kKabutops:
      return 70;
    case SpeciesNames::kAerodactyl:
      return 60;
    case SpeciesNames::kSnorlax:
      return 65;
    case SpeciesNames::kArticuno:
      return 125;
    case SpeciesNames::kZapdos:
      return 125;
    case SpeciesNames::kMoltres:
      return 125;
    case SpeciesNames::kDratini:
      return 50;
    case SpeciesNames::kDragonair:
      return 70;
    case SpeciesNames::kDragonite:
      return 100;
    case SpeciesNames::kMewtwo:
      return 154;
    case SpeciesNames::kMew:
      return 100;
    default:
      assert(false);
  }
}

/**
  * @brief: A function to get the base speed stat for a given Pokemon.
  * @param const SpeciesNames &species: The species name of the Pokemon.
  * @return int: The base speed stat of the Pokemon.
  */

int GetSpeedFromSpecies(const SpeciesNames &species_name) {
  switch (species_name) {
    case SpeciesNames::kBulbasaur:
      return 45;
    case SpeciesNames::kIvysaur:
      return 60;
    case SpeciesNames::kVenusaur:
      return 80;
    case SpeciesNames::kCharmander:
      return 60;
    case SpeciesNames::kCharmeleon:
      return 80;
    case SpeciesNames::kCharizard:
      return 100;
    case SpeciesNames::kSquirtle:
      return 43;
    case SpeciesNames::kWartortle:
      return 58;
    case SpeciesNames::kBlastoise:
      return 78;
    case SpeciesNames::kCaterpie:
      return 45;
    case SpeciesNames::kMetapod:
      return 30;
    case SpeciesNames::kButterfree:
      return 70;
    case SpeciesNames::kWeedle:
      return 50;
    case SpeciesNames::kKakuna:
      return 35;
    case SpeciesNames::kBeedrill:
      return 75;
    case SpeciesNames::kPidgey:
      return 56;
    case SpeciesNames::kPidgeotto:
      return 71;
    case SpeciesNames::kPidgeot:
      return 91;
    case SpeciesNames::kRattata:
      return 72;
    case SpeciesNames::kRaticate:
      return 97;
    case SpeciesNames::kSpearow:
      return 70;
    case SpeciesNames::kFearow:
      return 100;
    case SpeciesNames::kEkans:
      return 55;
    case SpeciesNames::kArbok:
      return 80;
    case SpeciesNames::kPikachu:
      return 90;
    case SpeciesNames::kRaichu:
      return 100;
    case SpeciesNames::kSandshrew:
      return 40;
    case SpeciesNames::kSandslash:
      return 65;
    case SpeciesNames::kNidoranF:
      return 41;
    case SpeciesNames::kNidorina:
      return 56;
    case SpeciesNames::kNidoqueen:
      return 76;
    case SpeciesNames::kNidoranM:
      return 50;
    case SpeciesNames::kNidorino:
      return 65;
    case SpeciesNames::kNidoking:
      return 85;
    case SpeciesNames::kClefairy:
      return 35;
    case SpeciesNames::kClefable:
      return 60;
    case SpeciesNames::kVulpix:
      return 65;
    case SpeciesNames::kNinetales:
      return 100;
    case SpeciesNames::kJigglypuff:
      return 20;
    case SpeciesNames::kWigglytuff:
      return 45;
    case SpeciesNames::kZubat:
      return 55;
    case SpeciesNames::kGolbat:
      return 90;
    case SpeciesNames::kOddish:
      return 30;
    case SpeciesNames::kGloom:
      return 40;
    case SpeciesNames::kVileplume:
      return 50;
    case SpeciesNames::kParas:
      return 25;
    case SpeciesNames::kParasect:
      return 30;
    case SpeciesNames::kVenonat:
      return 45;
    case SpeciesNames::kVenomoth:
      return 90;
    case SpeciesNames::kDiglett:
      return 95;
    case SpeciesNames::kDugtrio:
      return 120;
    case SpeciesNames::kMeowth:
      return 90;
    case SpeciesNames::kPersian:
      return 115;
    case SpeciesNames::kPsyduck:
      return 55;
    case SpeciesNames::kGolduck:
      return 85;
    case SpeciesNames::kMankey:
      return 70;
    case SpeciesNames::kPrimeape:
      return 95;
    case SpeciesNames::kGrowlithe:
      return 60;
    case SpeciesNames::kArcanine:
      return 95;
    case SpeciesNames::kPoliwag:
      return 90;
    case SpeciesNames::kPoliwhirl:
      return 90;
    case SpeciesNames::kPoliwrath:
      return 70;
    case SpeciesNames::kAbra:
      return 90;
    case SpeciesNames::kKadabra:
      return 105;
    case SpeciesNames::kAlakazam:
      return 120;
    case SpeciesNames::kMachop:
      return 35;
    case SpeciesNames::kMachoke:
      return 45;
    case SpeciesNames::kMachamp:
      return 55;
    case SpeciesNames::kBellsprout:
      return 40;
    case SpeciesNames::kWeepinbell:
      return 55;
    case SpeciesNames::kVictreebel:
      return 70;
    case SpeciesNames::kTentacool:
      return 70;
    case SpeciesNames::kTentacruel:
      return 100;
    case SpeciesNames::kGeodude:
      return 20;
    case SpeciesNames::kGraveler:
      return 35;
    case SpeciesNames::kGolem:
      return 45;
    case SpeciesNames::kPonyta:
      return 90;
    case SpeciesNames::kRapidash:
      return 105;
    case SpeciesNames::kSlowpoke:
      return 15;
    case SpeciesNames::kSlowbro:
      return 30;
    case SpeciesNames::kMagnemite:
      return 45;
    case SpeciesNames::kMagneton:
      return 70;
    case SpeciesNames::kFarfetchd:
      return 60;
    case SpeciesNames::kDoduo:
      return 75;
    case SpeciesNames::kDodrio:
      return 100;
    case SpeciesNames::kSeel:
      return 45;
    case SpeciesNames::kDewgong:
      return 70;
    case SpeciesNames::kGrimer:
      return 25;
    case SpeciesNames::kMuk:
      return 50;
    case SpeciesNames::kShellder:
      return 40;
    case SpeciesNames::kCloyster:
      return 70;
    case SpeciesNames::kGastly:
      return 80;
    case SpeciesNames::kHaunter:
      return 95;
    case SpeciesNames::kGengar:
      return 110;
    case SpeciesNames::kOnix:
      return 70;
    case SpeciesNames::kDrowzee:
      return 42;
    case SpeciesNames::kHypno:
      return 67;
    case SpeciesNames::kKrabby:
      return 50;
    case SpeciesNames::kKingler:
      return 75;
    case SpeciesNames::kVoltorb:
      return 100;
    case SpeciesNames::kElectrode:
      return 140;
    case SpeciesNames::kExeggcute:
      return 40;
    case SpeciesNames::kExeggutor:
      return 55;
    case SpeciesNames::kCubone:
      return 35;
    case SpeciesNames::kMarowak:
      return 45;
    case SpeciesNames::kHitmonlee:
      return 87;
    case SpeciesNames::kHitmonchan:
      return 76;
    case SpeciesNames::kLickitung:
      return 30;
    case SpeciesNames::kKoffing:
      return 35;
    case SpeciesNames::kWeezing:
      return 60;
    case SpeciesNames::kRhyhorn:
      return 25;
    case SpeciesNames::kRhydon:
      return 40;
    case SpeciesNames::kChansey:
      return 50;
    case SpeciesNames::kTangela:
      return 60;
    case SpeciesNames::kKangaskhan:
      return 90;
    case SpeciesNames::kHorsea:
      return 60;
    case SpeciesNames::kSeadra:
      return 85;
    case SpeciesNames::kGoldeen:
      return 63;
    case SpeciesNames::kSeaking:
      return 68;
    case SpeciesNames::kStaryu:
      return 85;
    case SpeciesNames::kStarmie:
      return 115;
    case SpeciesNames::kMrMime:
      return 90;
    case SpeciesNames::kScyther:
      return 105;
    case SpeciesNames::kJynx:
      return 95;
    case SpeciesNames::kElectabuzz:
      return 105;
    case SpeciesNames::kMagmar:
      return 93;
    case SpeciesNames::kPinsir:
      return 85;
    case SpeciesNames::kTauros:
      return 110;
    case SpeciesNames::kMagikarp:
      return 80;
    case SpeciesNames::kGyarados:
      return 81;
    case SpeciesNames::kLapras:
      return 60;
    case SpeciesNames::kDitto:
      return 48;
    case SpeciesNames::kEevee:
      return 55;
    case SpeciesNames::kVaporeon:
      return 65;
    case SpeciesNames::kJolteon:
      return 130;
    case SpeciesNames::kFlareon:
      return 65;
    case SpeciesNames::kPorygon:
      return 40;
    case SpeciesNames::kOmanyte:
      return 35;
    case SpeciesNames::kOmastar:
      return 55;
    case SpeciesNames::kKabuto:
      return 55;
    case SpeciesNames::kKabutops:
      return 80;
    case SpeciesNames::kAerodactyl:
      return 130;
    case SpeciesNames::kSnorlax:
      return 30;
    case SpeciesNames::kArticuno:
      return 85;
    case SpeciesNames::kZapdos:
      return 100;
    case SpeciesNames::kMoltres:
      return 90;
    case SpeciesNames::kDratini:
      return 50;
    case SpeciesNames::kDragonair:
      return 70;
    case SpeciesNames::kDragonite:
      return 80;
    case SpeciesNames::kMewtwo:
      return 130;
    case SpeciesNames::kMew:
      return 100;
    default:
      assert(false);
  }
}

/**
  * @brief: A function to get the base stat for a given Pokemon.
  * @param const SpeciesNames &species: The species name of the Pokemon.
  * @param const StatNames &stat_name: The name of the stat.
  * @return int: The base stat of the Pokemon.
  */

int GetBase(const SpeciesNames &species_name,
            const StatNames &stat_name) {
  switch (stat_name) {
    case StatNames::kAttack:
      return GetAttackFromSpecies(species_name);
    case StatNames::kDefense:
      return GetDefenseFromSpecies(species_name);
    case StatNames::kSpecial:
      return GetSpecialFromSpecies(species_name);
    case StatNames::kSpeed:
      return GetSpeedFromSpecies(species_name);
    default:
      assert(false);
  }
}

} //namespace

/**
  * @brief: One constructor for the NormalStat class.
  * @param const SpeciesNames &species_name: The species name of the Pokemon.
  * @param const int &level: The level of the Pokemon.
  * @param const Ev &ev_stat: The ev of the hp.
  * @param const Iv &iv_stat: The iv of the hp.
  */

NormalStat::NormalStat(const SpeciesNames &species_name, const int &level,
                       const StatNames &stat_name, const Ev &ev, const Iv &iv)
    : base_stat_(GetBase(species_name,
                         stat_name)),
      numerator_(kMinFactor),
      denominator_(kMinFactor),
      level_(level),
      ev_stat_(ev),
      iv_stat_(iv) {
}

/**
  * @brief: An accessor for the base stat.
  * @return int: The base stat.
  */

int NormalStat::BaseStat() const {
  return base_stat_;
}

/**
  * @brief: A function to get the in game stat.
  * @return double: The in game stat.
  */

double NormalStat::CalculatedStat() const {
  return static_cast<double>(numerator_) / denominator_;
}

/**
  * @brief: A function to raise the numerator of the stat.
  * @param const int &num_stages: The number of stages to raise.
  */

void NormalStat::RaiseNumerator(const int &num_stages) {
  numerator_ += num_stages;
}

/**
  * @brief: A function to raise the denominator of the stat.
  * @param const int &num_stages: The number of stages to raise.
  */

void NormalStat::RaiseDenominator(const int &num_stages) {
  denominator_ += num_stages;
}

/**
  * @brief: A function to lower the numerator of the stat.
  * @param const int &num_stages: The number of stages to lower.
  */

void NormalStat::LowerNumerator(const int &num_stages) {
  numerator_ -= num_stages;
}

/**
  * @brief: A function to lower the denominator of the stat.
  * @param const int &num_stages: The number of stages to lower.
  */

void NormalStat::LowerDenominator(const int &num_stages) {
  denominator_ -= num_stages;
}

/**
  * @brief: An accessor for the numerator.
  * @return int: The numerator.
  */

int NormalStat::Numerator() const {
  return numerator_;
}

/**
  * @brief: An accessor for the denominator.
  * @return int: The denominator.
  */

int NormalStat::Denominator() const {
  return denominator_;
}

/**
  * @brief: A function to reset the stat.
  */

void NormalStat::ResetStat() {
  numerator_ = kMinFactor;
  denominator_ = kMinFactor;
}

/**
  * @brief: A function to calculate the in game stat. The formula is as
  * follows: 5 + floor(level / 100 * ((base stat * 2) + 2 * IV + EV / 1024)).
  * @return int: The in game stat.
  */

int NormalStat::InGameStat() const {
  int initial_stat = static_cast<int>(5 + floor(static_cast<double>(level_) /
      100 * ((base_stat_ * 2) + 2 * iv_stat_.Value() + static_cast<double>(
      ev_stat_.Value()) / 1024)));
  return static_cast<int>(floor(initial_stat * (
      static_cast<double>(numerator_) / denominator_)));
}

/**
  * @brief: A function to reset the stat with the given parameters.
  * @param const int &new_numerator: The new numerator of the stat.
  * @param const int &new_denominator: The new denominator of the stat.
  */

void NormalStat::ResetStat(const int &new_numerator,
                           const int &new_denominator) {
  numerator_ = new_numerator;
  denominator_ = new_denominator;
}

/**
  * @brief: A function to get the initial stat (before any modifiers). This
  * is needed because if a move crits, the original attack and defense
  * (special or regular)  are used.
  * @return int: The initial stat.
  */

int NormalStat::InitialStat() {
  int old_numerator = numerator_;
  int old_denominator = denominator_;
  numerator_ = kMinFactor;
  denominator_ = kMinFactor;
  int return_stat = InGameStat();
  numerator_ = old_numerator;
  denominator_ = old_denominator;
  return return_stat;
}

} //nammespace artificialtrainer