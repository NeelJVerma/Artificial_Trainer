//
// Created by neel on 1/24/19.
//

#include <cstdlib>
#include <iostream>
#include "stat.h"
#include "../stringconversions/stringconverter.h"

namespace artificialtrainer {
namespace {
auto GetAttackFromSpecies(const Species &species) -> int {
  switch (species) {
    case Species::kBulbasaur: return 49;
    case Species::kIvysaur: return 62;
    case Species::kVenusaur: return 82;
    case Species::kCharmander: return 52;
    case Species::kCharmeleon: return 64;
    case Species::kCharizard: return 84;
    case Species::kSquirtle: return 48;
    case Species::kWartortle: return 63;
    case Species::kBlastoise: return 83;
    case Species::kCaterpie: return 30;
    case Species::kMetapod: return 20;
    case Species::kButterfree: return 45;
    case Species::kWeedle: return 35;
    case Species::kKakuna: return 25;
    case Species::kBeedrill: return 80;
    case Species::kPidgey: return 45;
    case Species::kPidgeotto: return 60;
    case Species::kPidgeot: return 80;
    case Species::kRattata: return 56;
    case Species::kRaticate: return 81;
    case Species::kSpearow: return 60;
    case Species::kFearow: return 90;
    case Species::kEkans: return 60;
    case Species::kArbok: return 85;
    case Species::kPikachu: return 55;
    case Species::kRaichu: return 90;
    case Species::kSandshrew: return 75;
    case Species::kSandslash: return 100;
    case Species::kNidoranF: return 47;
    case Species::kNidorina: return 62;
    case Species::kNidoqueen: return 82;
    case Species::kNidoranM: return 57;
    case Species::kNidorino: return 72;
    case Species::kNidoking: return 92;
    case Species::kClefairy: return 45;
    case Species::kClefable: return 70;
    case Species::kVulpix: return 41;
    case Species::kNinetales: return 76;
    case Species::kJigglypuff: return 45;
    case Species::kWigglytuff: return 70;
    case Species::kZubat: return 45;
    case Species::kGolbat: return 80;
    case Species::kOddish: return 50;
    case Species::kGloom: return 65;
    case Species::kVileplume: return 80;
    case Species::kParas: return 70;
    case Species::kParasect: return 95;
    case Species::kVenonat: return 55;
    case Species::kVenomoth: return 65;
    case Species::kDiglett: return 55;
    case Species::kDugtrio: return 80;
    case Species::kMeowth: return 45;
    case Species::kPersian: return 70;
    case Species::kPsyduck: return 52;
    case Species::kGolduck: return 82;
    case Species::kMankey: return 80;
    case Species::kPrimeape: return 105;
    case Species::kGrowlithe: return 70;
    case Species::kArcanine: return 110;
    case Species::kPoliwag: return 50;
    case Species::kPoliwhirl: return 65;
    case Species::kPoliwrath: return 85;
    case Species::kAbra: return 20;
    case Species::kKadabra: return 35;
    case Species::kAlakazam: return 50;
    case Species::kMachop: return 80;
    case Species::kMachoke: return 100;
    case Species::kMachamp: return 130;
    case Species::kBellsprout: return 75;
    case Species::kWeepinbell: return 90;
    case Species::kVictreebel: return 105;
    case Species::kTentacool: return 40;
    case Species::kTentacruel: return 70;
    case Species::kGeodude: return 80;
    case Species::kGraveler: return 95;
    case Species::kGolem: return 110;
    case Species::kPonyta: return 85;
    case Species::kRapidash: return 100;
    case Species::kSlowpoke: return 65;
    case Species::kSlowbro: return 75;
    case Species::kMagnemite: return 35;
    case Species::kMagneton: return 60;
    case Species::kFarfetchd: return 65;
    case Species::kDoduo: return 85;
    case Species::kDodrio: return 110;
    case Species::kSeel: return 45;
    case Species::kDewgong: return 70;
    case Species::kGrimer: return 80;
    case Species::kMuk: return 105;
    case Species::kShellder: return 65;
    case Species::kCloyster: return 95;
    case Species::kGastly: return 35;
    case Species::kHaunter: return 50;
    case Species::kGengar: return 65;
    case Species::kOnix: return 45;
    case Species::kDrowzee: return 48;
    case Species::kHypno: return 73;
    case Species::kKrabby: return 105;
    case Species::kKingler: return 130;
    case Species::kVoltorb: return 30;
    case Species::kElectrode: return 50;
    case Species::kExeggcute: return 40;
    case Species::kExeggutor: return 95;
    case Species::kCubone: return 50;
    case Species::kMarowak: return 80;
    case Species::kHitmonlee: return 120;
    case Species::kHitmonchan: return 105;
    case Species::kLickitung: return 55;
    case Species::kKoffing: return 65;
    case Species::kWeezing: return 90;
    case Species::kRhyhorn: return 85;
    case Species::kRhydon: return 130;
    case Species::kChansey: return 5;
    case Species::kTangela: return 55;
    case Species::kKangaskhan: return 95;
    case Species::kHorsea: return 40;
    case Species::kSeadra: return 65;
    case Species::kGoldeen: return 67;
    case Species::kSeaking: return 92;
    case Species::kStaryu: return 45;
    case Species::kStarmie: return 75;
    case Species::kMrMime: return 45;
    case Species::kScyther: return 110;
    case Species::kJynx: return 50;
    case Species::kElectabuzz: return 83;
    case Species::kMagmar: return 95;
    case Species::kPinsir: return 125;
    case Species::kTauros: return 100;
    case Species::kMagikarp: return 10;
    case Species::kGyarados: return 125;
    case Species::kLapras: return 85;
    case Species::kDitto: return 48;
    case Species::kEevee: return 55;
    case Species::kVaporeon: return 65;
    case Species::kJolteon: return 65;
    case Species::kFlareon: return 130;
    case Species::kPorygon: return 60;
    case Species::kOmanyte: return 40;
    case Species::kOmastar: return 60;
    case Species::kKabuto: return 80;
    case Species::kKabutops: return 115;
    case Species::kAerodactyl: return 105;
    case Species::kSnorlax: return 110;
    case Species::kArticuno: return 85;
    case Species::kZapdos: return 90;
    case Species::kMoltres: return 100;
    case Species::kDratini: return 64;
    case Species::kDragonair: return 84;
    case Species::kDragonite: return 134;
    case Species::kMewtwo: return 110;
    case Species::kMew: return 100;
    default: break;
  };
}

auto GetDefenseFromSpecies(const Species &species) -> int {
  switch (species) {
    //Gen 1
    case Species::kBulbasaur: return 49;
    case Species::kIvysaur: return 63;
    case Species::kVenusaur: return 83;
    case Species::kCharmander: return 43;
    case Species::kCharmeleon: return 58;
    case Species::kCharizard: return 78;
    case Species::kSquirtle: return 65;
    case Species::kWartortle: return 80;
    case Species::kBlastoise: return 100;
    case Species::kCaterpie: return 35;
    case Species::kMetapod: return 55;
    case Species::kButterfree: return 50;
    case Species::kWeedle: return 30;
    case Species::kKakuna: return 50;
    case Species::kBeedrill: return 40;
    case Species::kPidgey: return 40;
    case Species::kPidgeotto: return 55;
    case Species::kPidgeot: return 75;
    case Species::kRattata: return 35;
    case Species::kRaticate: return 60;
    case Species::kSpearow: return 30;
    case Species::kFearow: return 65;
    case Species::kEkans: return 44;
    case Species::kArbok: return 69;
    case Species::kPikachu: return 30;
    case Species::kRaichu: return 55;
    case Species::kSandshrew: return 85;
    case Species::kSandslash: return 110;
    case Species::kNidoranF: return 52;
    case Species::kNidorina: return 67;
    case Species::kNidoqueen: return 87;
    case Species::kNidoranM: return 40;
    case Species::kNidorino: return 57;
    case Species::kNidoking: return 77;
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

auto GetSpecialFromSpecies(const Species &species) -> int {
  switch (species) {
    //Gen 1
    case Species::kBulbasaur: return 65;
    case Species::kIvysaur: return 80;
    case Species::kVenusaur: return 100;
    case Species::kCharmander: return 50;
    case Species::kCharmeleon: return 65;
    case Species::kCharizard: return 85;
    case Species::kSquirtle: return 50;
    case Species::kWartortle: return 65;
    case Species::kBlastoise: return 85;
    case Species::kCaterpie: return 20;
    case Species::kMetapod: return 25;
    case Species::kButterfree: return 80;
    case Species::kWeedle: return 20;
    case Species::kKakuna: return 25;
    case Species::kBeedrill: return 45;
    case Species::kPidgey: return 35;
    case Species::kPidgeotto: return 50;
    case Species::kPidgeot: return 70;
    case Species::kRattata: return 25;
    case Species::kRaticate: return 50;
    case Species::kSpearow: return 31;
    case Species::kFearow: return 61;
    case Species::kEkans: return 40;
    case Species::kArbok: return 65;
    case Species::kPikachu: return 50;
    case Species::kRaichu: return 90;
    case Species::kSandshrew: return 30;
    case Species::kSandslash: return 55;
    case Species::kNidoranF: return 40;
    case Species::kNidorina: return 55;
    case Species::kNidoqueen: return 75;
    case Species::kNidoranM: return 40;
    case Species::kNidorino: return 55;
    case Species::kNidoking: return 75;
    case Species::kClefairy: return 60;
    case Species::kClefable: return 85;
    case Species::kVulpix: return 65;
    case Species::kNinetales: return 100;
    case Species::kJigglypuff: return 25;
    case Species::kWigglytuff: return 50;
    case Species::kZubat: return 40;
    case Species::kGolbat: return 75;
    case Species::kOddish: return 75;
    case Species::kGloom: return 85;
    case Species::kVileplume: return 100;
    case Species::kParas: return 55;
    case Species::kParasect: return 80;
    case Species::kVenonat: return 40;
    case Species::kVenomoth: return 90;
    case Species::kDiglett: return 45;
    case Species::kDugtrio: return 70;
    case Species::kMeowth: return 40;
    case Species::kPersian: return 65;
    case Species::kPsyduck: return 50;
    case Species::kGolduck: return 80;
    case Species::kMankey: return 35;
    case Species::kPrimeape: return 60;
    case Species::kGrowlithe: return 50;
    case Species::kArcanine: return 80;
    case Species::kPoliwag: return 40;
    case Species::kPoliwhirl: return 50;
    case Species::kPoliwrath: return 70;
    case Species::kAbra: return 105;
    case Species::kKadabra: return 120;
    case Species::kAlakazam: return 135;
    case Species::kMachop: return 35;
    case Species::kMachoke: return 50;
    case Species::kMachamp: return 65;
    case Species::kBellsprout: return 70;
    case Species::kWeepinbell: return 85;
    case Species::kVictreebel: return 100;
    case Species::kTentacool: return 100;
    case Species::kTentacruel: return 120;
    case Species::kGeodude: return 30;
    case Species::kGraveler: return 45;
    case Species::kGolem: return 55;
    case Species::kPonyta: return 65;
    case Species::kRapidash: return 80;
    case Species::kSlowpoke: return 40;
    case Species::kSlowbro: return 80;
    case Species::kMagnemite: return 95;
    case Species::kMagneton: return 120;
    case Species::kFarfetchd: return 58;
    case Species::kDoduo: return 35;
    case Species::kDodrio: return 60;
    case Species::kSeel: return 70;
    case Species::kDewgong: return 95;
    case Species::kGrimer: return 40;
    case Species::kMuk: return 65;
    case Species::kShellder: return 45;
    case Species::kCloyster: return 85;
    case Species::kGastly: return 100;
    case Species::kHaunter: return 115;
    case Species::kGengar: return 130;
    case Species::kOnix: return 30;
    case Species::kDrowzee: return 90;
    case Species::kHypno: return 115;
    case Species::kKrabby: return 25;
    case Species::kKingler: return 50;
    case Species::kVoltorb: return 55;
    case Species::kElectrode: return 80;
    case Species::kExeggcute: return 60;
    case Species::kExeggutor: return 125;
    case Species::kCubone: return 40;
    case Species::kMarowak: return 50;
    case Species::kHitmonlee: return 35;
    case Species::kHitmonchan: return 35;
    case Species::kLickitung: return 60;
    case Species::kKoffing: return 60;
    case Species::kWeezing: return 85;
    case Species::kRhyhorn: return 30;
    case Species::kRhydon: return 45;
    case Species::kChansey: return 105;
    case Species::kTangela: return 100;
    case Species::kKangaskhan: return 40;
    case Species::kHorsea: return 70;
    case Species::kSeadra: return 95;
    case Species::kGoldeen: return 50;
    case Species::kSeaking: return 80;
    case Species::kStaryu: return 70;
    case Species::kStarmie: return 100;
    case Species::kMrMime: return 100;
    case Species::kScyther: return 55;
    case Species::kJynx: return 95;
    case Species::kElectabuzz: return 85;
    case Species::kMagmar: return 85;
    case Species::kPinsir: return 55;
    case Species::kTauros: return 70;
    case Species::kMagikarp: return 20;
    case Species::kGyarados: return 100;
    case Species::kLapras: return 95;
    case Species::kDitto: return 48;
    case Species::kEevee: return 65;
    case Species::kVaporeon: return 110;
    case Species::kJolteon: return 110;
    case Species::kFlareon: return 110;
    case Species::kPorygon: return 75;
    case Species::kOmanyte: return 90;
    case Species::kOmastar: return 115;
    case Species::kKabuto: return 45;
    case Species::kKabutops: return 70;
    case Species::kAerodactyl: return 60;
    case Species::kSnorlax: return 65;
    case Species::kArticuno: return 125;
    case Species::kZapdos: return 125;
    case Species::kMoltres: return 125;
    case Species::kDratini: return 50;
    case Species::kDragonair: return 70;
    case Species::kDragonite: return 100;
    case Species::kMewtwo: return 154;
    case Species::kMew: return 100;
    default: break;
  };
}

auto GetSpeedFromSpecies(const Species &species) -> int {
  switch (species) {
    //Gen 1
    case Species::kBulbasaur: return 45;
    case Species::kIvysaur: return 60;
    case Species::kVenusaur: return 80;
    case Species::kCharmander: return 60;
    case Species::kCharmeleon: return 80;
    case Species::kCharizard: return 100;
    case Species::kSquirtle: return 43;
    case Species::kWartortle: return 58;
    case Species::kBlastoise: return 78;
    case Species::kCaterpie: return 45;
    case Species::kMetapod: return 30;
    case Species::kButterfree: return 70;
    case Species::kWeedle: return 50;
    case Species::kKakuna: return 35;
    case Species::kBeedrill: return 75;
    case Species::kPidgey: return 56;
    case Species::kPidgeotto: return 71;
    case Species::kPidgeot: return 91;
    case Species::kRattata: return 72;
    case Species::kRaticate: return 97;
    case Species::kSpearow: return 70;
    case Species::kFearow: return 100;
    case Species::kEkans: return 55;
    case Species::kArbok: return 80;
    case Species::kPikachu: return 90;
    case Species::kRaichu: return 100;
    case Species::kSandshrew: return 40;
    case Species::kSandslash: return 65;
    case Species::kNidoranF: return 41;
    case Species::kNidorina: return 56;
    case Species::kNidoqueen: return 76;
    case Species::kNidoranM: return 50;
    case Species::kNidorino: return 65;
    case Species::kNidoking: return 85;
    case Species::kClefairy: return 35;
    case Species::kClefable: return 60;
    case Species::kVulpix: return 65;
    case Species::kNinetales: return 100;
    case Species::kJigglypuff: return 20;
    case Species::kWigglytuff: return 45;
    case Species::kZubat: return 55;
    case Species::kGolbat: return 90;
    case Species::kOddish: return 30;
    case Species::kGloom: return 40;
    case Species::kVileplume: return 50;
    case Species::kParas: return 25;
    case Species::kParasect: return 30;
    case Species::kVenonat: return 45;
    case Species::kVenomoth: return 90;
    case Species::kDiglett: return 95;
    case Species::kDugtrio: return 120;
    case Species::kMeowth: return 90;
    case Species::kPersian: return 115;
    case Species::kPsyduck: return 55;
    case Species::kGolduck: return 85;
    case Species::kMankey: return 70;
    case Species::kPrimeape: return 95;
    case Species::kGrowlithe: return 60;
    case Species::kArcanine: return 95;
    case Species::kPoliwag: return 90;
    case Species::kPoliwhirl: return 90;
    case Species::kPoliwrath: return 70;
    case Species::kAbra: return 90;
    case Species::kKadabra: return 105;
    case Species::kAlakazam: return 120;
    case Species::kMachop: return 35;
    case Species::kMachoke: return 45;
    case Species::kMachamp: return 55;
    case Species::kBellsprout: return 40;
    case Species::kWeepinbell: return 55;
    case Species::kVictreebel: return 70;
    case Species::kTentacool: return 70;
    case Species::kTentacruel: return 100;
    case Species::kGeodude: return 20;
    case Species::kGraveler: return 35;
    case Species::kGolem: return 45;
    case Species::kPonyta: return 90;
    case Species::kRapidash: return 105;
    case Species::kSlowpoke: return 15;
    case Species::kSlowbro: return 30;
    case Species::kMagnemite: return 45;
    case Species::kMagneton: return 70;
    case Species::kFarfetchd: return 60;
    case Species::kDoduo: return 75;
    case Species::kDodrio: return 100;
    case Species::kSeel: return 45;
    case Species::kDewgong: return 70;
    case Species::kGrimer: return 25;
    case Species::kMuk: return 50;
    case Species::kShellder: return 40;
    case Species::kCloyster: return 70;
    case Species::kGastly: return 80;
    case Species::kHaunter: return 95;
    case Species::kGengar: return 110;
    case Species::kOnix: return 70;
    case Species::kDrowzee: return 42;
    case Species::kHypno: return 67;
    case Species::kKrabby: return 50;
    case Species::kKingler: return 75;
    case Species::kVoltorb: return 100;
    case Species::kElectrode: return 140;
    case Species::kExeggcute: return 40;
    case Species::kExeggutor: return 55;
    case Species::kCubone: return 35;
    case Species::kMarowak: return 45;
    case Species::kHitmonlee: return 87;
    case Species::kHitmonchan: return 76;
    case Species::kLickitung: return 30;
    case Species::kKoffing: return 35;
    case Species::kWeezing: return 60;
    case Species::kRhyhorn: return 25;
    case Species::kRhydon: return 40;
    case Species::kChansey: return 50;
    case Species::kTangela: return 60;
    case Species::kKangaskhan: return 90;
    case Species::kHorsea: return 60;
    case Species::kSeadra: return 85;
    case Species::kGoldeen: return 63;
    case Species::kSeaking: return 68;
    case Species::kStaryu: return 85;
    case Species::kStarmie: return 115;
    case Species::kMrMime: return 90;
    case Species::kScyther: return 105;
    case Species::kJynx: return 95;
    case Species::kElectabuzz: return 105;
    case Species::kMagmar: return 93;
    case Species::kPinsir: return 85;
    case Species::kTauros: return 110;
    case Species::kMagikarp: return 80;
    case Species::kGyarados: return 81;
    case Species::kLapras: return 60;
    case Species::kDitto: return 48;
    case Species::kEevee: return 55;
    case Species::kVaporeon: return 65;
    case Species::kJolteon: return 130;
    case Species::kFlareon: return 65;
    case Species::kPorygon: return 40;
    case Species::kOmanyte: return 35;
    case Species::kOmastar: return 55;
    case Species::kKabuto: return 55;
    case Species::kKabutops: return 80;
    case Species::kAerodactyl: return 130;
    case Species::kSnorlax: return 30;
    case Species::kArticuno: return 85;
    case Species::kZapdos: return 100;
    case Species::kMoltres: return 90;
    case Species::kDratini: return 50;
    case Species::kDragonair: return 70;
    case Species::kDragonite: return 80;
    case Species::kMewtwo: return 130;
    case Species::kMew: return 100;
    default: break;
  };
}

auto GetBase(const Species &species, const StatNames &stat_name) -> int {
  switch (stat_name) {
    case StatNames::kAttack: return GetAttackFromSpecies(species);
    case StatNames::kDefense: return GetDefenseFromSpecies(species);
    case StatNames::kSpecial: return GetSpecialFromSpecies(species);
    case StatNames::kSpeed: return GetSpeedFromSpecies(species);
    default: break;
  };
}

} //namespace

Stat::Stat(const Species &species, const StatNames &stat_name, const Ev &ev,
    const Iv &iv) : base_stat_(GetBase(species, stat_name)), ev_stat_(ev),
                    iv_stat_(iv) {
}

auto Stat::EvStat() const -> Ev {
  return ev_stat_;
}

auto Stat::IvStat() const -> Iv {
  return iv_stat_;
}

auto Stat::BaseStat() const -> int {
  return base_stat_;
}

} //nammespace artificialtrainer