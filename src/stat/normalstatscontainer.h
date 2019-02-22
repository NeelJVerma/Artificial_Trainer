//
// Created by neel on 1/25/19.
//

#ifndef ARTIFICIAL_TRAINER_STATSCONTAINER_H
#define ARTIFICIAL_TRAINER_STATSCONTAINER_H

#include <memory>
#include "hp.h"
#include "normalstat.h"

namespace artificialtrainer {
class NormalStatsContainer {
 public:
  NormalStatsContainer() = default;
  NormalStatsContainer(
      const std::shared_ptr<NormalStat> stats[kNumNormalStats]);
  NormalStatsContainer(const NormalStatsContainer &stats_container) = default;
  NormalStatsContainer &operator=(
      const NormalStatsContainer &stats_container) = default;
  std::shared_ptr<NormalStat> operator[](const StatNames &stat_name) const;

 private:
  std::shared_ptr<NormalStat> normal_stats_[kNumNormalStats];
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_STATSCONTAINER_H
