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
  ExclusiveInGameStatsContainer &operator=(
      const ExclusiveInGameStatsContainer &stats_container) = default;
  std::shared_ptr<ExclusiveInGameStat> operator[](const StatNames &stat_name);

 private:
  std::shared_ptr<ExclusiveInGameStat>
      exclusive_in_game_stats_[kNumExclusiveInGameStats];

};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_EXCLUSIVEINGAMESTATSCONTAINER_H
