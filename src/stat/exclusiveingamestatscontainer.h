//
// Created by neel on 2/6/19.
//

#ifndef ARTIFICIAL_TRAINER_EXCLUSIVEINGAMESTATSCONTAINER_H
#define ARTIFICIAL_TRAINER_EXCLUSIVEINGAMESTATSCONTAINER_H

#include <memory>
#include "exclusiveingamestat.h"
#include "statnames.h"

namespace artificialtrainer {
class ExclusiveInGameStatsContainer {
 public:
  ExclusiveInGameStatsContainer();
  ExclusiveInGameStatsContainer(
      const ExclusiveInGameStatsContainer &stats_container) = default;
  auto operator=(
      const ExclusiveInGameStatsContainer &stats_container)
  -> ExclusiveInGameStatsContainer & = default;
  auto operator[](const StatNames &stat_name)
  -> std::shared_ptr<ExclusiveInGameStat>;

 private:
  std::shared_ptr<ExclusiveInGameStat>
      exclusive_in_game_stats_[kNumExclusiveInGameStats];

};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_EXCLUSIVEINGAMESTATSCONTAINER_H
