//
// Created by neel on 1/25/19.
//

#include <stdexcept>
#include "normalstatscontainer.h"

namespace artificialtrainer {
NormalStatsContainer::NormalStatsContainer(
    const std::shared_ptr<NormalStat> stats[kNumNormalStats]) {
  for (int i = 0; i < kNumNormalStats; i++) {
    normal_stats_[i] = stats[i];
  }
}

std::shared_ptr<NormalStat> NormalStatsContainer::operator[](
    const StatNames &stat_name) const {
  int loc_stat_name = static_cast<int>(stat_name);

  if (loc_stat_name < 0 || loc_stat_name >= kNumNormalStats) {
    throw std::out_of_range("Normal stat doesn't exist");
  }

  return normal_stats_[loc_stat_name];
}

} //namespace artificialtrainer