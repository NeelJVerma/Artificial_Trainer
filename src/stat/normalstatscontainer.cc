//
// Created by neel on 1/25/19.
//

#include <stdexcept>
#include "normalstatscontainer.h"

namespace artificialtrainer {
NormalStatsContainer::NormalStatsContainer(
    const SpeciesNames &species_name,
    const Hp &hp_stat,
    const NormalStat stats[kNumNormalStats])
    : hp_stat_(hp_stat) {
  for (int i = 0; i < kNumNormalStats; i++) {
    normal_stats_[i] = stats[i];
  }
}

auto NormalStatsContainer::HpStat() -> Hp & {
  return hp_stat_;
}

auto NormalStatsContainer::operator[](
    const StatNames &stat_name) -> NormalStat & {
  int loc_stat_name = static_cast<int>(stat_name);

  if (loc_stat_name < 0 || loc_stat_name >= kNumNormalStats) {
    throw std::out_of_range("Normal stat doesn't exist");
  }

  return normal_stats_[loc_stat_name];
}

} //namespace artificialtrainer