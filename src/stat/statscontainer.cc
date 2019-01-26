//
// Created by neel on 1/25/19.
//

#include "statscontainer.h"
#include <map>

namespace artificialtrainer {
StatsContainer::StatsContainer(const Species &species, const Hp &hp_stat,
    const Stat stats[kNumNormalStats]) : hp_stat_(hp_stat), evasion_stat_(1),
    accuracy_stat_(1), normal_stats_{stats[0], stats[1], stats[2],stats[3]} {
}

auto StatsContainer::HpStat() -> Hp& {
  return hp_stat_;
}

auto StatsContainer::AccuracyStat() const -> double {
  return accuracy_stat_;
}

auto StatsContainer::EvasionStat() const -> double {
  return evasion_stat_;
}

auto StatsContainer::operator[](const StatNames &stat_name) -> Stat& {
  return normal_stats_[static_cast<int>(stat_name)];
}

} //namespace artificialtrainer