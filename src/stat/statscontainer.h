//
// Created by neel on 1/25/19.
//

#ifndef ARTIFICIAL_TRAINER_STATSCONTAINER_H
#define ARTIFICIAL_TRAINER_STATSCONTAINER_H

#include "hp.h"
#include "stat.h"

namespace artificialtrainer {
class StatsContainer {
 public:
  StatsContainer() = default;
  StatsContainer(const Species &species, const Hp &hp_stat, const Stat
  stats[kNumNormalStats]);
  auto HpStat() -> Hp&;
  auto EvasionStat() const -> double;
  auto AccuracyStat() const -> double;
  auto operator [](const StatNames &stat_name) -> Stat&;

 private:
  Hp hp_stat_;
  Stat normal_stats_[kNumNormalStats];
  double evasion_stat_;
  double accuracy_stat_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_STATSCONTAINER_H
