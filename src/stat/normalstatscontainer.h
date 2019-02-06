//
// Created by neel on 1/25/19.
//

#ifndef ARTIFICIAL_TRAINER_STATSCONTAINER_H
#define ARTIFICIAL_TRAINER_STATSCONTAINER_H

#include "hp.h"
#include "normalstat.h"

namespace artificialtrainer {
class NormalStatsContainer {
 public:
  NormalStatsContainer() = default;
  NormalStatsContainer(const SpeciesNames &species_name, const Hp &hp_stat,
                       const NormalStat stats[kNumNormalStats]);
  NormalStatsContainer(const NormalStatsContainer &stats_container) = default;
  auto operator=(
      const NormalStatsContainer &stats_container)
          -> NormalStatsContainer & = default;
  auto HpStat() -> Hp &;
  auto operator[](const StatNames &stat_name) -> NormalStat &;

 private:
  Hp hp_stat_;
  NormalStat normal_stats_[kNumNormalStats];
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_STATSCONTAINER_H
