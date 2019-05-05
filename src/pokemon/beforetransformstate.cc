/**
 * @project Artificial Trainer
 * @brief The implementation of the BeforeTransformState class.
 *
 * @file beforetransformstate.cc
 * @author Neel Verma
 * @date 2/22/19
 */

#include "beforetransformstate.h"

namespace artificialtrainer {

/**
  * @brief: The default constructor for the BeforeTransformState class. We
  * can't use the compiler generated default constructor because we have to
  * initialize this enum type. Although, it shouldn't really matter because of
  * how this class is used (the state only matters when the Pokemon uses
  * transform and the other constructor below is called), it's just for
  * cleanliness sake.
  */

BeforeTransformState::BeforeTransformState() :
    species_name_(SpeciesNames::kBulbasaur) {
}

/**
  * @brief: Another constructor for the BeforeTransformState class.
  * @param const NormalStatsContainer &normal_stats_container: The normal
  * stats of the Pokemon before using transform.
  * @param const ExclusiveInGameStatsContainer
  * &exclusive_in_game_stats_container: The exclusive in game stats container
  * of the Pokemon before using Transform.
  * @param const TypeContainer &type_container: The types of the Pokemon
  * before using transform.
  * @param const MovesContainer &moves_container: The moves of the Pokemon
  * before using transform.
  * @param const SpeciesNames &species_name: The species of the Pokemon
  * before using transform.
  */

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

/**
  * @brief: An accessor the normal stats container.
  * @return NormalStatsContainer: The normal stats container.
  */

NormalStatsContainer BeforeTransformState::GetNormalStatsContainer() const {
  return normal_stats_container_;
}

/**
  * @brief: An accessor the exclusive in game stats container.
  * @return ExclusiveInGameStatsContainer: The exclusive in game stats
  * container.
  */

ExclusiveInGameStatsContainer BeforeTransformState::
GetExclusiveInGameStatsContainer() const {
  return exclusive_in_game_stats_container_;
}

/**
  * @brief: An accessor the type container.
  * @return TypeContainer: The type container.
  */

TypeContainer BeforeTransformState::GetTypeContainer() const {
  return type_container_;
}

/**
  * @brief: An accessor the moves container.
  * @return MovesContainer: The moves container.
  */

MovesContainer BeforeTransformState::GetMovesContainer() const {
  return moves_container_;
}

/**
  * @brief: An accessor the species name.
  * @return SpeciesName: The species name.
  */

SpeciesNames BeforeTransformState::SpeciesName() const {
  return species_name_;
}

/**
  * @brief: A mutator for the normal stats container. Only used in the deep
  * copy.
  * @param const NormalStatsContainer &normal_stats_container: The normal
  * stats container to set.
  */

void BeforeTransformState::SetNormalStatsContainer(
    const NormalStatsContainer &normal_stats_container) {
  normal_stats_container_ = normal_stats_container;
}

/**
  * @brief: A mutator for the exclusive in game stats container. Only used in
  * the deep copy.
  * @param const ExclusiveInGameStatsContainer
  * &exclusive_in_game_stats_container: The exclusive in game stats container
  * to set.
  */

void BeforeTransformState::SetExclusiveInGameStatsContainer(
    const ExclusiveInGameStatsContainer &exclusive_in_game_stats_container) {
  exclusive_in_game_stats_container_ =
      exclusive_in_game_stats_container.DeepCopy();
}

/**
  * @brief: A mutator for the moves container. Only used in the deep copy.
  * @param const MovesContainer &moves_container: The moves container to set.
  */

void BeforeTransformState::SetMovesContainer(
    const MovesContainer &moves_container) {
  moves_container_ = moves_container.DeepCopy();
}

/**
  * @brief: A mutator for the type container. Only used in the deep copy.
  * @param const TypeContainer &type_container: The type container to set.
  */

void BeforeTransformState::SetTypeContainer(
    const TypeContainer &type_container) {
  type_container_ = type_container;
}

/**
  * @brief: A mutator for the species name. Only used in the deep copy.
  * @param const SpeciesNames &species_name: The species name to set.
  */

void BeforeTransformState::SetSpeciesName(const SpeciesNames &species_name) {
  species_name_ = species_name;
}

/**
  * @brief: A function to deep copy the state of the object.
  * @return BeforeTransformState: The copy.
  */

BeforeTransformState BeforeTransformState::DeepCopy() const {
  BeforeTransformState copy;
  copy.SetNormalStatsContainer(normal_stats_container_.DeepCopy());
  copy.SetExclusiveInGameStatsContainer(
      exclusive_in_game_stats_container_.DeepCopy());
  copy.SetMovesContainer(moves_container_.DeepCopy());
  copy.SetTypeContainer(type_container_);
  copy.SetSpeciesName(species_name_);
  return copy;
}

} //namespace artificialtrainer