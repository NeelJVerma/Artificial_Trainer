//
// Created by neel on 1/25/19.
//

#include <cmath>
#include <iostream>
#include <memory>
#include "hp.h"

namespace artificialtrainer {
namespace {
auto GetBaseHp(const Species &species) -> int {
  switch (species) {
    //Gen 1
    case Species::kBulbasaur: return 45;
    case Species::kIvysaur: return 60;
    case Species::kVenusaur: return 80;
    case Species::kCharmander: return 39;
    case Species::kCharmeleon: return 58;
    case Species::kCharizard: return 78;
    case Species::kSquirtle: return 44;
    case Species::kWartortle: return 59;
    case Species::kBlastoise: return 79;
    case Species::kCaterpie: return 45;
    case Species::kMetapod: return 50;
    case Species::kButterfree: return 60;
    case Species::kWeedle: return 40;
    case Species::kKakuna: return 45;
    case Species::kBeedrill: return 65;
    case Species::kPidgey: return 40;
    case Species::kPidgeotto: return 63;
    case Species::kPidgeot: return 83;
    case Species::kRattata: return 30;
    case Species::kRaticate: return 55;
    case Species::kSpearow: return 40;
    case Species::kFearow: return 65;
    case Species::kEkans: return 35;
    case Species::kArbok: return 60;
    case Species::kPikachu: return 35;
    case Species::kRaichu: return 60;
    case Species::kSandshrew: return 50;
    case Species::kSandslash: return 75;
    case Species::kNidoranF: return 55;
    case Species::kNidorina: return 70;
    case Species::kNidoqueen: return 90;
    case Species::kNidoranM: return 46;
    case Species::kNidorino: return 61;
    case Species::kNidoking: return 81;
    case Species::kClefairy: return 70;
    case Species::kClefable: return 95;
    case Species::kVulpix: return 38;
    case Species::kNinetales: return 73;
    case Species::kJigglypuff: return 115;
    case Species::kWigglytuff: return 140;
    case Species::kZubat: return 40;
    case Species::kGolbat: return 75;
    case Species::kOddish: return 45;
    case Species::kGloom: return 60;
    case Species::kVileplume: return 75;
    case Species::kParas: return 35;
    case Species::kParasect: return 60;
    case Species::kVenonat: return 60;
    case Species::kVenomoth: return 70;
    case Species::kDiglett: return 10;
    case Species::kDugtrio: return 35;
    case Species::kMeowth: return 40;
    case Species::kPersian: return 65;
    case Species::kPsyduck: return 50;
    case Species::kGolduck: return 80;
    case Species::kMankey: return 40;
    case Species::kPrimeape: return 65;
    case Species::kGrowlithe: return 55;
    case Species::kArcanine: return 90;
    case Species::kPoliwag: return 40;
    case Species::kPoliwhirl: return 65;
    case Species::kPoliwrath: return 90;
    case Species::kAbra: return 25;
    case Species::kKadabra: return 40;
    case Species::kAlakazam: return 55;
    case Species::kMachop: return 70;
    case Species::kMachoke: return 80;
    case Species::kMachamp: return 90;
    case Species::kBellsprout: return 50;
    case Species::kWeepinbell: return 65;
    case Species::kVictreebel: return 80;
    case Species::kTentacool: return 40;
    case Species::kTentacruel: return 80;
    case Species::kGeodude: return 40;
    case Species::kGraveler: return 55;
    case Species::kGolem: return 80;
    case Species::kPonyta: return 50;
    case Species::kRapidash: return 65;
    case Species::kSlowpoke: return 90;
    case Species::kSlowbro: return 95;
    case Species::kMagnemite: return 25;
    case Species::kMagneton: return 50;
    case Species::kFarfetchd: return 52;
    case Species::kDoduo: return 35;
    case Species::kDodrio: return 60;
    case Species::kSeel: return 65;
    case Species::kDewgong: return 90;
    case Species::kGrimer: return 80;
    case Species::kMuk: return 105;
    case Species::kShellder: return 30;
    case Species::kCloyster: return 50;
    case Species::kGastly: return 30;
    case Species::kHaunter: return 45;
    case Species::kGengar: return 60;
    case Species::kOnix: return 35;
    case Species::kDrowzee: return 60;
    case Species::kHypno: return 85;
    case Species::kKrabby: return 30;
    case Species::kKingler: return 55;
    case Species::kVoltorb: return 40;
    case Species::kElectrode: return 60;
    case Species::kExeggcute: return 60;
    case Species::kExeggutor: return 95;
    case Species::kCubone: return 50;
    case Species::kMarowak: return 60;
    case Species::kHitmonlee: return 50;
    case Species::kHitmonchan: return 50;
    case Species::kLickitung: return 90;
    case Species::kKoffing: return 40;
    case Species::kWeezing: return 65;
    case Species::kRhyhorn: return 80;
    case Species::kRhydon: return 105;
    case Species::kChansey: return 250;
    case Species::kTangela: return 65;
    case Species::kKangaskhan: return 105;
    case Species::kHorsea: return 30;
    case Species::kSeadra: return 55;
    case Species::kGoldeen: return 45;
    case Species::kSeaking: return 80;
    case Species::kStaryu: return 30;
    case Species::kStarmie: return 60;
    case Species::kMrMime: return 40;
    case Species::kScyther: return 70;
    case Species::kJynx: return 65;
    case Species::kElectabuzz: return 65;
    case Species::kMagmar: return 65;
    case Species::kPinsir: return 65;
    case Species::kTauros: return 75;
    case Species::kMagikarp: return 20;
    case Species::kGyarados: return 95;
    case Species::kLapras: return 130;
    case Species::kDitto: return 48;
    case Species::kEevee: return 55;
    case Species::kVaporeon: return 130;
    case Species::kJolteon: return 65;
    case Species::kFlareon: return 65;
    case Species::kPorygon: return 65;
    case Species::kOmanyte: return 35;
    case Species::kOmastar: return 70;
    case Species::kKabuto: return 30;
    case Species::kKabutops: return 60;
    case Species::kAerodactyl: return 80;
    case Species::kSnorlax: return 160;
    case Species::kArticuno: return 90;
    case Species::kZapdos: return 90;
    case Species::kMoltres: return 90;
    case Species::kDratini: return 41;
    case Species::kDragonair: return 61;
    case Species::kDragonite: return 91;
    case Species::kMewtwo: return 106;
    case Species::kMew: return 100;
  };
}

auto CalculateActualHpStat(const int &base_hp, const int &level,
    const Ev &ev_stat, const Iv &iv_stat) -> int {
  return static_cast<int>(10 + floor(static_cast<double>(level / 100 * (
      (base_hp * 2) + 2 * iv_stat.Value() + ev_stat.Value() / 1024))) + level);
}

} //namespace

Hp::Hp(const Species &species, const int &level, const Ev &ev, const Iv
&iv) : ev_stat_(ev), iv_stat_(iv), current_hp_(CalculateActualHpStat
(GetBaseHp(species), level, ev, iv)) {
  max_hp_ = current_hp_;
}

Hp::Hp(const int &current, const Ev &ev, const Iv &iv, const int &max_hp) :
current_hp_(current), ev_stat_(ev), iv_stat_(iv), max_hp_(max_hp) {
}

auto Hp::EvStat() const -> Ev {
  return ev_stat_;
}

auto Hp::IvStat() const -> Iv {
  return iv_stat_;
}

auto Hp::CurrentHp() const -> int {
  return current_hp_;
}

auto Hp::MaxHp() const -> int {
  return max_hp_;
}

auto Hp::operator=(const Hp &hp) -> Hp& {
  current_hp_ = hp.CurrentHp();
  max_hp_ = hp.MaxHp();
  ev_stat_ = hp.EvStat();
  iv_stat_ = hp.IvStat();
}

auto operator +=(Hp &lhs, const int &rhs) -> Hp& {
  return lhs = Hp(lhs.CurrentHp() + rhs, lhs.EvStat(), lhs.IvStat(), lhs
  .MaxHp());
}

auto operator -=(Hp &lhs, const int &rhs) -> Hp& {
  return lhs = Hp(lhs.CurrentHp() - rhs, lhs.EvStat(), lhs.IvStat(), lhs
  .MaxHp());
}

} //namespace artificialtrainer