/**
 * @project Artificial Trainer
 * @brief The NormalStatsContainer class.
 *
 * @file normalstatscontainer.h
 * @author Neel Verma
 * @date 1/25/19
 */

#ifndef ARTIFICIAL_TRAINER_STATSCONTAINER_H
#define ARTIFICIAL_TRAINER_STATSCONTAINER_H

#include <memory>
#include "hp.h"
#include "normalstat.h"

namespace artificialtrainer {

/**
 * @brief The NormalStatsContainer class. This class acts as a container for
 * attack, defense, special, and speed.
 *
 * @author Neel Verma
 * @date 1/25/19
 */

class NormalStatsContainer {
 public:
  NormalStatsContainer() = default;
  explicit NormalStatsContainer(
      const std::shared_ptr<NormalStat> stats[kNumNormalStats]);
  NormalStatsContainer(const NormalStatsContainer &stats_container) = default;
  NormalStatsContainer &operator=(
      const NormalStatsContainer &stats_container) = default;
  std::shared_ptr<NormalStat> operator[](const StatNames &stat_name) const;
  NormalStatsContainer DeepCopy() const;

 private:
  void AddStat(const NormalStat &stat, const int &index);
  std::shared_ptr<NormalStat> normal_stats_[kNumNormalStats];
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_STATSCONTAINER_H
