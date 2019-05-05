/**
 * @project Artificial Trainer
 * @brief The ExclusiveInGameStatsContainer class.
 *
 * @file exclusiveingamestatscontainer.h
 * @author Neel Verma
 * @date 2/6/19
 */

#ifndef ARTIFICIAL_TRAINER_EXCLUSIVEINGAMESTATSCONTAINER_H
#define ARTIFICIAL_TRAINER_EXCLUSIVEINGAMESTATSCONTAINER_H

#include <memory>
#include "exclusiveingamestat.h"
#include "statnames.h"

namespace artificialtrainer {

/**
 * @brief The ExclusiveInGameStatsContainer class. This class acts as a
 * container for accuracy and evasion.
 *
 * @author Neel Verma
 * @date 2/6/19
 */

class ExclusiveInGameStatsContainer {
 public:
  ExclusiveInGameStatsContainer();
  ExclusiveInGameStatsContainer(
      const ExclusiveInGameStatsContainer &stats_container) = default;
  ExclusiveInGameStatsContainer &operator=(
      const ExclusiveInGameStatsContainer &stats_container) = default;
  std::shared_ptr<ExclusiveInGameStat> operator[](const StatNames &stat_name);
  ExclusiveInGameStatsContainer DeepCopy() const;

 private:
  void AddStat(const ExclusiveInGameStat &stat, const int &index);
  std::shared_ptr<ExclusiveInGameStat>
      exclusive_in_game_stats_[kNumExclusiveInGameStats];

};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_EXCLUSIVEINGAMESTATSCONTAINER_H
