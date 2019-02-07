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
  NormalStatsContainer(const SpeciesNames &species_name,
                       const std::shared_ptr<Hp> &hp_stat,
                       const std::shared_ptr<NormalStat>
                       stats[kNumNormalStats]);
  NormalStatsContainer(const NormalStatsContainer &stats_container) = default;
  auto operator=(
      const NormalStatsContainer &stats_container)
  -> NormalStatsContainer & = default;
  auto HpStat() -> std::shared_ptr<Hp>;
  auto operator[](const StatNames &stat_name) -> std::shared_ptr<NormalStat>;

 private:
  std::shared_ptr<Hp> hp_stat_;
  std::shared_ptr<NormalStat> normal_stats_[kNumNormalStats];
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_STATSCONTAINER_H
