/**
 * @project Artificial Trainer
 * @brief The BeforeTransformState class.
 *
 * @file beforetransformstate.h
 * @author Neel Verma
 * @date 2/22/19
 */

#ifndef ARTIFICIAL_TRAINER_BEFORETRANSFORMSTATE_H
#define ARTIFICIAL_TRAINER_BEFORETRANSFORMSTATE_H

#include "../stat/normalstatscontainer.h"
#include "../stat/exclusiveingamestatscontainer.h"
#include "../type/typecontainer.h"
#include "../move/movescontainer.h"

namespace artificialtrainer {

/**
 * @brief The BeforeTransformState class. This class caches the state of the
 * Pokemon when it uses transform, so that it can be restored when it either
 * switches out or faints.
 *
 * @author Neel Verma
 * @date 2/22/19
 */

class BeforeTransformState {
 public:
  BeforeTransformState(
      const BeforeTransformState &before_transform_state) = default;
  BeforeTransformState &operator=(
      const BeforeTransformState &before_transform_state) = default;
  BeforeTransformState();
  BeforeTransformState(const NormalStatsContainer &normal_stats_container,
                       const ExclusiveInGameStatsContainer
                       &exclusive_in_game_stats_container,
                       const TypeContainer &type_container,
                       const MovesContainer &moves_container,
                       const SpeciesNames &species_name);
  NormalStatsContainer GetNormalStatsContainer() const;
  ExclusiveInGameStatsContainer GetExclusiveInGameStatsContainer() const;
  TypeContainer GetTypeContainer() const;
  MovesContainer GetMovesContainer() const;
  SpeciesNames SpeciesName() const;
  BeforeTransformState DeepCopy() const;

 private:
  NormalStatsContainer normal_stats_container_;
  ExclusiveInGameStatsContainer exclusive_in_game_stats_container_;
  TypeContainer type_container_;
  MovesContainer moves_container_;
  SpeciesNames species_name_;
  void SetNormalStatsContainer(
      const NormalStatsContainer &normal_stats_container);
  void SetExclusiveInGameStatsContainer(
      const ExclusiveInGameStatsContainer &exclusive_in_game_stats_container);
  void SetMovesContainer(const MovesContainer &moves_container);
  void SetTypeContainer(const TypeContainer &type_container);
  void SetSpeciesName(const SpeciesNames &species_name);
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_BEFORETRANSFORMSTATE_H
