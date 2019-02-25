//
// Created by neel on 2/22/19.
//

#include "beforetransformstate.h"

namespace artificialtrainer {
// We can't use the compiler generated default constructor because we have to
// initialize this enum type. Although, it shouldn't really matter because of
// how this class is used, it's just for cleanliness sake.

BeforeTransformState::BeforeTransformState() :
    species_name_(SpeciesNames::kBulbasaur) {
}

BeforeTransformState::BeforeTransformState(
    const NormalStatsContainer &normal_stats_container,
    const ExclusiveInGameStatsContainer &exclusive_in_game_stats_container,
    const TypeContainer &type_container,
    const MovesContainer &moves_container,
    const SpeciesNames &species_name) :
    normal_stats_container_(normal_stats_container),
    exclusive_in_game_stats_container_(exclusive_in_game_stats_container),
    type_container_(type_container),
    moves_container_(moves_container),
    species_name_(species_name) {
}

NormalStatsContainer BeforeTransformState::GetNormalStatsContainer() const {
  return normal_stats_container_;
}

ExclusiveInGameStatsContainer BeforeTransformState::
GetExclusiveInGameStatsContainer() const {
  return exclusive_in_game_stats_container_;
}

TypeContainer BeforeTransformState::GetTypeContainer() const {
  return type_container_;
}

MovesContainer BeforeTransformState::GetMovesContainer() const {
  return moves_container_;
}

SpeciesNames BeforeTransformState::SpeciesName() const {
  return species_name_;
}

} //namespace artificialtrainer