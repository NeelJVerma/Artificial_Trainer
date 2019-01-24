//
// Created by neel on 1/23/19.
//

#include "gui.h"
#include "../pokemon/species.h"

namespace artificialtrainer {
void Gui::DisplayWelcomeMessage() {
  std::cout << "Welcome to Artificial Trainer, a Gen 1 battle simulator/AI!" << std::endl;
}

void Gui::DisplayPickTeamMessage(const bool &player_one) {
  std::cout << "Player " << (player_one ? "one" : "two") << ", select your team" << std::endl;
}

void Gui::DisplayPokemonChoices() {
  std::cout << "Team choices:" << std::endl;

  for (unsigned i = 0; i < kNumSpecies; ++i) {
    switch (static_cast<Species>(i)) {
      case Species::kBulbasaur:
        std::cout << "1. Bulbasaur" << std::endl;
        break;
      case Species::kIvysaur:
        std::cout << "2. Ivysaur" << std::endl;
        break;
      case Species::kVenusaur:
        std::cout << "3. Venusaur" << std::endl;
        break;
      case Species::kCharmander:
        std::cout << "4. Charmander" << std::endl;
        break;
      case Species::kCharmeleon:
        std::cout << "5. Charmeleon" << std::endl;
        break;
      case Species::kCharizard:
        std::cout << "6. Charizard" << std::endl;
        break;
      case Species::kSquirtle:
        std::cout << "7. Squirtle" << std::endl;
        break;
      case Species::kWartortle:
        std::cout << "8. Wartortle" << std::endl;
        break;
      case Species::kBlastoise:
        std::cout << "9. Blastoise" << std::endl;
        break;
      case Species::kCaterpie:
        std::cout << "10. Caterpie" << std::endl;
        break;
      case Species::kMetapod:
        std::cout << "11. Metapod" << std::endl;
        break;
      case Species::kButterfree:
        std::cout << "12. Butterfree" << std::endl;
        break;
      case Species::kWeedle:
        std::cout << "13. Weedle" << std::endl;
        break;
      case Species::kKakuna:
        std::cout << "14. Kakuna" << std::endl;
        break;
      case Species::kBeedrill:
        std::cout << "15. Beedrill" << std::endl;
        break;
      case Species::kPidgey:
        std::cout << "16. Pidgey" << std::endl;
        break;
      case Species::kPidgeotto:
        std::cout << "17. Pidgeotto" << std::endl;
        break;
      case Species::kPidgeot:
        std::cout << "18. Pidgeot" << std::endl;
        break;
      case Species::kRattata:
        std::cout << "19. Rattata" << std::endl;
        break;
      case Species::kRaticate:
        std::cout << "20. Raticate" << std::endl;
        break;
      case Species::kSpearow:
        std::cout << "21. Spearow" << std::endl;
        break;
      case Species::kFearow:
        std::cout << "22. Fearow" << std::endl;
        break;
      case Species::kEkans:
        std::cout << "23. Ekans" << std::endl;
        break;
      case Species::kArbok:
        std::cout << "24. Arbok" << std::endl;
        break;
      case Species::kPikachu:
        std::cout << "25. Pikachu" << std::endl;
        break;
      case Species::kRaichu:
        std::cout << "26. Raichu" << std::endl;
        break;
      case Species::kSandshrew:
        std::cout << "27. Sandshrew" << std::endl;
        break;
      case Species::kSandslash:
        std::cout << "28. Sandslash" << std::endl;
        break;
      case Species::kNidoranF:
        std::cout << "29. Nidoran (female)" << std::endl;
        break;
      case Species::kNidorina:
        std::cout << "30. Nidorina" << std::endl;
        break;
      case Species::kNidoqueen:
        std::cout << "31. Nidoqueen" << std::endl;
        break;
      case Species::kNidoranM:
        std::cout << "32. Nidoran (male)" << std::endl;
        break;
      case Species::kNidorino:
        std::cout << "33. Nidorino" << std::endl;
        break;
      case Species::kNidoking:
        std::cout << "34. Nidoking" << std::endl;
        break;
      case Species::kClefairy:
        std::cout << "35. Clefairy" << std::endl;
        break;
      case Species::kClefable:
        std::cout << "36. Clefable" << std::endl;
        break;
      case Species::kVulpix:
        std::cout << "37. Vulpix" << std::endl;
        break;
      case Species::kNinetales:
        std::cout << "38. Ninetales" << std::endl;
        break;
      case Species::kJigglypuff:
        std::cout << "39. Jigglypuff" << std::endl;
        break;
      case Species::kWigglytuff:
        std::cout << "40. Wigglytuff" << std::endl;
        break;
      case Species::kZubat:
        std::cout << "41. Zubat" << std::endl;
        break;
      case Species::kGolbat:
        std::cout << "42. Golbat" << std::endl;
        break;
      case Species::kOddish:
        std::cout << "43. Oddish" << std::endl;
        break;
      case Species::kGloom:
        std::cout << "44. Gloom" << std::endl;
        break;
      case Species::kVileplume:
        std::cout << "45. Vileplume" << std::endl;
        break;
      case Species::kParas:
        std::cout << "46. Paras" << std::endl;
        break;
      case Species::kParasect:
        std::cout << "47. Parasect" << std::endl;
        break;
      case Species::kVenonat:
        std::cout << "48. Venonat" << std::endl;
        break;
      case Species::kVenomoth:
        std::cout << "49. Venomoth" << std::endl;
        break;
      case Species::kDiglett:
        std::cout << "50. Diglett" << std::endl;
        break;
      case Species::kDugtrio:
        std::cout << "51. Dugtrio" << std::endl;
        break;
      case Species::kMeowth:
        std::cout << "52. Meowth" << std::endl;
        break;
      case Species::kPersian:
        std::cout << "53. Persian" << std::endl;
        break;
      case Species::kPsyduck:
        std::cout << "54. Psyduck" << std::endl;
        break;
      case Species::kGolduck:
        std::cout << "55. Golduck" << std::endl;
        break;
      case Species::kMankey:
        std::cout << "56. Mankey" << std::endl;
        break;
      case Species::kPrimeape:
        std::cout << "57. Primeape" << std::endl;
        break;
      case Species::kGrowlithe:
        std::cout << "58. Growlithe" << std::endl;
        break;
      case Species::kArcanine:
        std::cout << "59. Arcanine" << std::endl;
        break;
      case Species::kPoliwag:
        std::cout << "60. Poliwag" << std::endl;
        break;
      case Species::kPoliwhirl:
        std::cout << "61. Poliwhirl" << std::endl;
        break;
      case Species::kPoliwrath:
        std::cout << "62. Poliwrath" << std::endl;
        break;
      case Species::kAbra:
        std::cout << "63. Abra" << std::endl;
        break;
      case Species::kKadabra:
        std::cout << "64. Kadabra" << std::endl;
        break;
      case Species::kAlakazam:
        std::cout << "65. Alakazam" << std::endl;
        break;
      case Species::kMachop:
        std::cout << "66. Machop" << std::endl;
        break;
      case Species::kMachoke:
        std::cout << "67. Machoke" << std::endl;
        break;
      case Species::kMachamp:
        std::cout << "68. Machamp" << std::endl;
        break;
      case Species::kBellsprout:
        std::cout << "69. Bellsprout" << std::endl;
        break;
      case Species::kWeepinbell:
        std::cout << "70. Weepinbell" << std::endl;
        break;
      case Species::kVictreebel:
        std::cout << "71. Victreebell" << std::endl;
        break;
      case Species::kTentacool:
        std::cout << "72. Tentacool" << std::endl;
        break;
      case Species::kTentacruel:
        std::cout << "73. Tentacruel" << std::endl;
        break;
      case Species::kGeodude:
        std::cout << "74. Geodude" << std::endl;
        break;
      case Species::kGraveler:
        std::cout << "75. Graveler" << std::endl;
        break;
      case Species::kGolem:
        std::cout << "76. Golem" << std::endl;
        break;
      case Species::kPonyta:
        std::cout << "77. Ponyta" << std::endl;
        break;
      case Species::kRapidash:
        std::cout << "78. Rapidash" << std::endl;
        break;
      case Species::kSlowpoke:
        std::cout << "79. Slowpoke" << std::endl;
        break;
      case Species::kSlowbro:
        std::cout << "80. Slowbro" << std::endl;
        break;
      case Species::kMagnemite:
        std::cout << "81. Magnemite" << std::endl;
        break;
      case Species::kMagneton:
        std::cout << "82. Magneton" << std::endl;
        break;
      case Species::kFarfetchd:
        std::cout << "83. Farfetch'd" << std::endl;
        break;
      case Species::kDoduo:
        std::cout << "84. Doduo" << std::endl;
        break;
      case Species::kDodrio:
        std::cout << "85. Dodrio" << std::endl;
        break;
      case Species::kSeel:
        std::cout << "86. Seel" << std::endl;
        break;
      case Species::kDewgong:
        std::cout << "87. Dewgong" << std::endl;
        break;
      case Species::kGrimer:
        std::cout << "88. Grimer" << std::endl;
        break;
      case Species::kMuk:
        std::cout << "89. Muk" << std::endl;
        break;
      case Species::kShellder:
        std::cout << "90. Shellder" << std::endl;
        break;
      case Species::kCloyster:
        std::cout << "91. Cloyster" << std::endl;
        break;
      case Species::kGastly:
        std::cout << "92. Gastly" << std::endl;
        break;
      case Species::kHaunter:
        std::cout << "93. Haunter" << std::endl;
        break;
      case Species::kGengar:
        std::cout << "94. Gengar" << std::endl;
        break;
      case Species::kOnix:
        std::cout << "95. Onix" << std::endl;
        break;
      case Species::kDrowzee:
        std::cout << "96. Drowzee" << std::endl;
        break;
      case Species::kHypno:
        std::cout << "97. Hypno" << std::endl;
        break;
      case Species::kKrabby:
        std::cout << "98. Krabby" << std::endl;
        break;
      case Species::kKingler:
        std::cout << "99. Kingler" << std::endl;
        break;
      case Species::kVoltorb:
        std::cout << "100. Voltorb" << std::endl;
        break;
      case Species::kElectrode:
        std::cout << "101. Electrode" << std::endl;
        break;
      case Species::kExeggcute:
        std::cout << "102. Exeggcute" << std::endl;
        break;
      case Species::kExeggutor:
        std::cout << "103. Exeggutor" << std::endl;
        break;
      case Species::kCubone:
        std::cout << "104. Cubone" << std::endl;
        break;
      case Species::kMarowak:
        std::cout << "105. Marowak" << std::endl;
        break;
      case Species::kHitmonlee:
        std::cout << "106. Hitmonlee" << std::endl;
        break;
      case Species::kHitmonchan:
        std::cout << "107. Hitmonchan" << std::endl;
        break;
      case Species::kLickitung:
        std::cout << "108. Lickitung" << std::endl;
        break;
      case Species::kKoffing:
        std::cout << "109. Koffing" << std::endl;
        break;
      case Species::kWeezing:
        std::cout << "110. Weezing" << std::endl;
        break;
      case Species::kRhyhorn:
        std::cout << "111. Rhyhorn" << std::endl;
        break;
      case Species::kRhydon:
        std::cout << "112. Rhydon" << std::endl;
        break;
      case Species::kChansey:
        std::cout << "113. Chansey" << std::endl;
        break;
      case Species::kTangela:
        std::cout << "114. Tangela" << std::endl;
        break;
      case Species::kKangaskhan:
        std::cout << "115. Kangaskhan" << std::endl;
        break;
      case Species::kHorsea:
        std::cout << "116. Horsea" << std::endl;
        break;
      case Species::kSeadra:
        std::cout << "117. Seadra" << std::endl;
        break;
      case Species::kGoldeen:
        std::cout << "118. Goldeen" << std::endl;
        break;
      case Species::kSeaking:
        std::cout << "119. Seaking" << std::endl;
        break;
      case Species::kStaryu:
        std::cout << "120. Staryu" << std::endl;
        break;
      case Species::kStarmie:
        std::cout << "121. Starmie" << std::endl;
        break;
      case Species::kMrMime:
        std::cout << "122. Mr. Mime" << std::endl;
        break;
      case Species::kScyther:
        std::cout << "123. Scyther" << std::endl;
        break;
      case Species::kJynx:
        std::cout << "124. Jynx" << std::endl;
        break;
      case Species::kElectabuzz:
        std::cout << "125. Electabuzz" << std::endl;
        break;
      case Species::kMagmar:
        std::cout << "126. Magmar" << std::endl;
        break;
      case Species::kPinsir:
        std::cout << "127. Pinsir" << std::endl;
        break;
      case Species::kTauros:
        std::cout << "128. Tauros" << std::endl;
        break;
      case Species::kMagikarp:
        std::cout << "129. Magikarp" << std::endl;
        break;
      case Species::kGyarados:
        std::cout << "130. Gyarados" << std::endl;
        break;
      case Species::kLapras:
        std::cout << "131. Lapras" << std::endl;
        break;
      case Species::kDitto:
        std::cout << "132. Ditto" << std::endl;
        break;
      case Species::kEevee:
        std::cout << "133. Eevee" << std::endl;
        break;
      case Species::kVaporeon:
        std::cout << "134. Vaporeon" << std::endl;
        break;
      case Species::kJolteon:
        std::cout << "135. Jolteon" << std::endl;
        break;
      case Species::kFlareon:
        std::cout << "136. Flareon" << std::endl;
        break;
      case Species::kPorygon:
        std::cout << "137. Porygon" << std::endl;
        break;
      case Species::kOmanyte:
        std::cout << "138. Omanyte" << std::endl;
        break;
      case Species::kOmastar:
        std::cout << "139. Omastar" << std::endl;
        break;
      case Species::kKabuto:
        std::cout << "140. Kabuto" << std::endl;
        break;
      case Species::kKabutops:
        std::cout << "141. Kabutops" << std::endl;
        break;
      case Species::kAerodactyl:
        std::cout << "142. Aerodactyl" << std::endl;
        break;
      case Species::kSnorlax:
        std::cout << "143. Snorlax" << std::endl;
        break;
      case Species::kArticuno:
        std::cout << "144. Articuno" << std::endl;
        break;
      case Species::kZapdos:
        std::cout << "145. Zapdos" << std::endl;
        break;
      case Species::kMoltres:
        std::cout << "146. Moltres" << std::endl;
        break;
      case Species::kDratini:
        std::cout << "147. Dratini" << std::endl;
        break;
      case Species::kDragonair:
        std::cout << "148. Dragonair" << std::endl;
        break;
      case Species::kDragonite:
        std::cout << "149. Dragonite" << std::endl;
        break;
      case Species::kMewtwo:
        std::cout << "150. Mewtwo" << std::endl;
        break;
      case Species::kMew:
        std::cout << "151. Mew" << std::endl;
        break;
      default:
        std::cout << "Pokemon list display error" << std::endl;
        break;
    };
  }
}

void Gui::DisplayPickPokemonMessage(const unsigned &num) {
  std::cout << "Pick Pokemon number " << num << ". Enter a number between 1 and " << kNumSpecies << '.' << std::endl;
}

void Gui::DisplayInvalidChoiceMessage() {
  std::cout << "Invalid choice. Select again." << std::endl;
}

} //namespace artificialtrainer