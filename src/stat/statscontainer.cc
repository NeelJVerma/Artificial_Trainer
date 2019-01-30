//
// Created by neel on 1/25/19.
//

#include <stdexcept>
#include "statscontainer.h"

namespace artificialtrainer {
StatsContainer::StatsContainer(const SpeciesNames &species_name,
                               const Hp &hp_stat,
                               const Stat stats[kNumNormalStats])
    : hp_stat_(hp_stat),
      evasion_stat_(1),
      accuracy_stat_(1) {
  for (int i = 0; i < kNumNormalStats; i++) {
    normal_stats_[i] = stats[i];
  }
}

auto StatsContainer::HpStat() -> Hp & {
  return hp_stat_;
}

auto StatsContainer::AccuracyStat() const -> double {
  return accuracy_stat_;
}

auto StatsContainer::EvasionStat() const -> double {
  return evasion_stat_;
}

auto StatsContainer::operator[](const StatNames &stat_name) -> Stat & {
  int loc_stat_name = static_cast<int>(stat_name);

  if (loc_stat_name < 0 || loc_stat_name >= kNumNormalStats) {
    throw std::out_of_range("Stat doesn't exist");
  }

  return normal_stats_[loc_stat_name];
}

} //namespace artificialtrainer