/**
 * @project Artificial Trainer
 * @brief The implementation of the Hp class.
 *
 * @file hp.cc
 * @author Neel Verma
 * @date 1/25/19
 */

#include <cmath>
#include <cassert>
#include "hp.h"

namespace artificialtrainer {
namespace {

/**
  * @brief: A function to get the base hp stat for a given Pokemon.
  * @param const SpeciesNames &species: The species name of the Pokemon.
  * @return int: The base hp stat of the Pokemon.
  */

int BaseHp(const SpeciesNames &species) {
  switch (species) {
    case SpeciesNames::kBulbasaur:
      return 45;
    case SpeciesNames::kIvysaur:
      return 60;
    case SpeciesNames::kVenusaur:
      return 80;
    case SpeciesNames::kCharmander:
      return 39;
    case SpeciesNames::kCharmeleon:
      return 58;
    case SpeciesNames::kCharizard:
      return 78;
    case SpeciesNames::kSquirtle:
      return 44;
    case SpeciesNames::kWartortle:
      return 59;
    case SpeciesNames::kBlastoise:
      return 79;
    case SpeciesNames::kCaterpie:
      return 45;
    case SpeciesNames::kMetapod:
      return 50;
    case SpeciesNames::kButterfree:
      return 60;
    case SpeciesNames::kWeedle:
      return 40;
    case SpeciesNames::kKakuna:
      return 45;
    case SpeciesNames::kBeedrill:
      return 65;
    case SpeciesNames::kPidgey:
      return 40;
    case SpeciesNames::kPidgeotto:
      return 63;
    case SpeciesNames::kPidgeot:
      return 83;
    case SpeciesNames::kRattata:
      return 30;
    case SpeciesNames::kRaticate:
      return 55;
    case SpeciesNames::kSpearow:
      return 40;
    case SpeciesNames::kFearow:
      return 65;
    case SpeciesNames::kEkans:
      return 35;
    case SpeciesNames::kArbok:
      return 60;
    case SpeciesNames::kPikachu:
      return 35;
    case SpeciesNames::kRaichu:
      return 60;
    case SpeciesNames::kSandshrew:
      return 50;
    case SpeciesNames::kSandslash:
      return 75;
    case SpeciesNames::kNidoranF:
      return 55;
    case SpeciesNames::kNidorina:
      return 70;
    case SpeciesNames::kNidoqueen:
      return 90;
    case SpeciesNames::kNidoranM:
      return 46;
    case SpeciesNames::kNidorino:
      return 61;
    case SpeciesNames::kNidoking:
      return 81;
    case SpeciesNames::kClefairy:
      return 70;
    case SpeciesNames::kClefable:
      return 95;
    case SpeciesNames::kVulpix:
      return 38;
    case SpeciesNames::kNinetales:
      return 73;
    case SpeciesNames::kJigglypuff:
      return 115;
    case SpeciesNames::kWigglytuff:
      return 140;
    case SpeciesNames::kZubat:
      return 40;
    case SpeciesNames::kGolbat:
      return 75;
    case SpeciesNames::kOddish:
      return 45;
    case SpeciesNames::kGloom:
      return 60;
    case SpeciesNames::kVileplume:
      return 75;
    case SpeciesNames::kParas:
      return 35;
    case SpeciesNames::kParasect:
      return 60;
    case SpeciesNames::kVenonat:
      return 60;
    case SpeciesNames::kVenomoth:
      return 70;
    case SpeciesNames::kDiglett:
      return 10;
    case SpeciesNames::kDugtrio:
      return 35;
    case SpeciesNames::kMeowth:
      return 40;
    case SpeciesNames::kPersian:
      return 65;
    case SpeciesNames::kPsyduck:
      return 50;
    case SpeciesNames::kGolduck:
      return 80;
    case SpeciesNames::kMankey:
      return 40;
    case SpeciesNames::kPrimeape:
      return 65;
    case SpeciesNames::kGrowlithe:
      return 55;
    case SpeciesNames::kArcanine:
      return 90;
    case SpeciesNames::kPoliwag:
      return 40;
    case SpeciesNames::kPoliwhirl:
      return 65;
    case SpeciesNames::kPoliwrath:
      return 90;
    case SpeciesNames::kAbra:
      return 25;
    case SpeciesNames::kKadabra:
      return 40;
    case SpeciesNames::kAlakazam:
      return 55;
    case SpeciesNames::kMachop:
      return 70;
    case SpeciesNames::kMachoke:
      return 80;
    case SpeciesNames::kMachamp:
      return 90;
    case SpeciesNames::kBellsprout:
      return 50;
    case SpeciesNames::kWeepinbell:
      return 65;
    case SpeciesNames::kVictreebel:
      return 80;
    case SpeciesNames::kTentacool:
      return 40;
    case SpeciesNames::kTentacruel:
      return 80;
    case SpeciesNames::kGeodude:
      return 40;
    case SpeciesNames::kGraveler:
      return 55;
    case SpeciesNames::kGolem:
      return 80;
    case SpeciesNames::kPonyta:
      return 50;
    case SpeciesNames::kRapidash:
      return 65;
    case SpeciesNames::kSlowpoke:
      return 90;
    case SpeciesNames::kSlowbro:
      return 95;
    case SpeciesNames::kMagnemite:
      return 25;
    case SpeciesNames::kMagneton:
      return 50;
    case SpeciesNames::kFarfetchd:
      return 52;
    case SpeciesNames::kDoduo:
      return 35;
    case SpeciesNames::kDodrio:
      return 60;
    case SpeciesNames::kSeel:
      return 65;
    case SpeciesNames::kDewgong:
      return 90;
    case SpeciesNames::kGrimer:
      return 80;
    case SpeciesNames::kMuk:
      return 105;
    case SpeciesNames::kShellder:
      return 30;
    case SpeciesNames::kCloyster:
      return 50;
    case SpeciesNames::kGastly:
      return 30;
    case SpeciesNames::kHaunter:
      return 45;
    case SpeciesNames::kGengar:
      return 60;
    case SpeciesNames::kOnix:
      return 35;
    case SpeciesNames::kDrowzee:
      return 60;
    case SpeciesNames::kHypno:
      return 85;
    case SpeciesNames::kKrabby:
      return 30;
    case SpeciesNames::kKingler:
      return 55;
    case SpeciesNames::kVoltorb:
      return 40;
    case SpeciesNames::kElectrode:
      return 60;
    case SpeciesNames::kExeggcute:
      return 60;
    case SpeciesNames::kExeggutor:
      return 95;
    case SpeciesNames::kCubone:
      return 50;
    case SpeciesNames::kMarowak:
      return 60;
    case SpeciesNames::kHitmonlee:
      return 50;
    case SpeciesNames::kHitmonchan:
      return 50;
    case SpeciesNames::kLickitung:
      return 90;
    case SpeciesNames::kKoffing:
      return 40;
    case SpeciesNames::kWeezing:
      return 65;
    case SpeciesNames::kRhyhorn:
      return 80;
    case SpeciesNames::kRhydon:
      return 105;
    case SpeciesNames::kChansey:
      return 250;
    case SpeciesNames::kTangela:
      return 65;
    case SpeciesNames::kKangaskhan:
      return 105;
    case SpeciesNames::kHorsea:
      return 30;
    case SpeciesNames::kSeadra:
      return 55;
    case SpeciesNames::kGoldeen:
      return 45;
    case SpeciesNames::kSeaking:
      return 80;
    case SpeciesNames::kStaryu:
      return 30;
    case SpeciesNames::kStarmie:
      return 60;
    case SpeciesNames::kMrMime:
      return 40;
    case SpeciesNames::kScyther:
      return 70;
    case SpeciesNames::kJynx:
      return 65;
    case SpeciesNames::kElectabuzz:
      return 65;
    case SpeciesNames::kMagmar:
      return 65;
    case SpeciesNames::kPinsir:
      return 65;
    case SpeciesNames::kTauros:
      return 75;
    case SpeciesNames::kMagikarp:
      return 20;
    case SpeciesNames::kGyarados:
      return 95;
    case SpeciesNames::kLapras:
      return 130;
    case SpeciesNames::kDitto:
      return 48;
    case SpeciesNames::kEevee:
      return 55;
    case SpeciesNames::kVaporeon:
      return 130;
    case SpeciesNames::kJolteon:
      return 65;
    case SpeciesNames::kFlareon:
      return 65;
    case SpeciesNames::kPorygon:
      return 65;
    case SpeciesNames::kOmanyte:
      return 35;
    case SpeciesNames::kOmastar:
      return 70;
    case SpeciesNames::kKabuto:
      return 30;
    case SpeciesNames::kKabutops:
      return 60;
    case SpeciesNames::kAerodactyl:
      return 80;
    case SpeciesNames::kSnorlax:
      return 160;
    case SpeciesNames::kArticuno:
      return 90;
    case SpeciesNames::kZapdos:
      return 90;
    case SpeciesNames::kMoltres:
      return 90;
    case SpeciesNames::kDratini:
      return 41;
    case SpeciesNames::kDragonair:
      return 61;
    case SpeciesNames::kDragonite:
      return 91;
    case SpeciesNames::kMewtwo:
      return 106;
    case SpeciesNames::kMew:
      return 100;
    default:
      assert(false);
  }
}

/**
  * @brief: A function to calculate the in battle hp stat from the given
  * parameters. The formula is as follows:
  * 10 + floor(level / 100 * ((base hp stat * 2) + 2 * IV + EV / 1024)) + level.
  * @param const int &base_hp: The base hp of the Pokemon.
  * @param const int &level: The level of the Pokemon.
  * @param const Ev &ev_stat: The ev of the hp.
  * @param const Iv &iv_stat: The iv of the hp.
  * @return int: The in battle hp stat.
  */

int CalculateInBattleHpStat(const int &base_hp, const int &level,
                            const Ev &ev_stat, const Iv &iv_stat) {
  return static_cast<int>(10 + floor(static_cast<double>(level) /
      100 * ((base_hp * 2) + 2 * iv_stat.Value() + static_cast<double>(
      ev_stat.Value()) / 1024)) + level);
}

} //namespace

/**
  * @brief: One constructor for the Hp class.
  * @param const SpeciesNames &species_name: The species name of the Pokemon.
  * @param const int &level: The level of the Pokemon.
  * @param const Ev &ev_stat: The ev of the hp.
  * @param const Iv &iv_stat: The iv of the hp.
  */

Hp::Hp(const SpeciesNames &species_name, const int &level, const Ev &ev,
       const Iv &iv) : ev_stat_(ev),
                       iv_stat_(iv),
                       current_hp_(CalculateInBattleHpStat(BaseHp(species_name),
                                                           level,
                                                           ev,
                                                           iv)) {
  max_hp_ = current_hp_;
}

/**
  * @brief: An accessor for the current hp.
  * @return int: The current hp.
  */

int Hp::CurrentHp() const {
  return current_hp_;
}

/**
  * @brief: An accessor for the max hp.
  * @return int: The max hp.
  */

int Hp::MaxHp() const {
  return max_hp_;
}

/**
  * @brief: A fucntion to get the hp as a percent. Used in a GUI function.
  * @return double: The hp as a percent.
  */

double Hp::HpAsPercent() const {
  return 100 * (static_cast<double>(current_hp_) / max_hp_);
}

/**
  * @brief: A function to subtract hp.
  * @param const int &amount: The amount of hp to subtract.
  */

void Hp::SubtractHp(const int &amount) {
  if (current_hp_ - amount < 0) {
    current_hp_ = 0;
    return;
  }

  current_hp_ -= amount;
}

/**
  * @brief: A function to add hp.
  * @param const int &amount: The amount of hp to add.
  */

void Hp::AddHp(const int &amount) {
  if (current_hp_ + amount > max_hp_) {
    current_hp_ = max_hp_;
    return;
  }

  current_hp_ += amount;
}

/**
  * @brief: A function to subtract all hp.
  */

void Hp::SubtractAllHp() {
  current_hp_ -= current_hp_;
}

} //namespace artificialtrainer