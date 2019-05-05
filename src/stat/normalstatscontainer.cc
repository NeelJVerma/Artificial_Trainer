/**
 * @project Artificial Trainer
 * @brief The implementation of the NormalStatsContainer class.
 *
 * @file normalstatscontainer.cc
 * @author Neel Verma
 * @date 1/25/19
 */

#include <stdexcept>
#include "normalstatscontainer.h"

namespace artificialtrainer {

/**
  * @brief: A constructor for the NormalStatsContainer class.
  * @param const std::shared_ptr<NormalStats> stats[kNumNormalStats]: An
  * array of the stats to set.
  */

NormalStatsContainer::NormalStatsContainer(
    const std::shared_ptr<NormalStat> stats[kNumNormalStats]) {
  for (int i = 0; i < kNumNormalStats; i++) {
    normal_stats_[i] = stats[i];
  }
}

/**
  * @brief: An operator to access an element of the container.
  * @param const StatNames &stat_name: The name of the stat to return.
  * @return std::shared_ptr<NormalStat>: The stat with the given name.
  */

std::shared_ptr<NormalStat> NormalStatsContainer::operator[](
    const StatNames &stat_name) const {
  int loc_stat_name = static_cast<int>(stat_name);

  if (loc_stat_name < 0 || loc_stat_name >= kNumNormalStats) {
    throw std::out_of_range("Normal stat doesn't exist");
  }

  return normal_stats_[loc_stat_name];
}

/**
  * @brief: A function to add a stat to the container. Only used in the deep
  * copy.
  * @param const NormalStat &stat: The stat to add.
  * @param const int &index: The index of the container to place the stat.
  */

void NormalStatsContainer::AddStat(const NormalStat &stat, const int &index) {
  normal_stats_[index] = std::make_shared<NormalStat>(stat);
}

/**
  * @brief: A function to deep copy the object state.
  * @param NormalStatsContainer: The deep copy.
  */

NormalStatsContainer NormalStatsContainer::DeepCopy() const {
  NormalStatsContainer copy;

  for (int i = 0; i < kNumNormalStats; i++) {
    copy.AddStat(*normal_stats_[i], i);
  }

  return copy;
}

} //namespace artificialtrainer