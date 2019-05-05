/**
 * @project Artificial Trainer
 * @brief The implementation of the ExclusiveInGameStatsContainer class.
 *
 * @file exclusiveingamestatscontainer.cc
 * @author Neel Verma
 * @date 2/6/19
 */

#include <stdexcept>
#include "exclusiveingamestatscontainer.h"

namespace artificialtrainer {

/**
  * @brief: The default constructor for the ExclusiveInGameStatsContainer class.
  */

ExclusiveInGameStatsContainer::ExclusiveInGameStatsContainer() {
  for (int i = 0; i < kNumExclusiveInGameStats; i++) {
    exclusive_in_game_stats_[i] = std::make_shared<ExclusiveInGameStat>();
  }
}

/**
  * @brief: An operator to access an element of the container.
  * @param const StatNames &stat_name: The name of the stat to return.
  * @return std::shared_ptr<ExclusiveInGameStat>: The stat with the given name.
  */

std::shared_ptr<ExclusiveInGameStat> ExclusiveInGameStatsContainer::operator[](
    const StatNames &stat_name) {
  int loc_stat_name = static_cast<int>(stat_name);

  if (loc_stat_name <= kNumNormalStats ||
      loc_stat_name > kNumExclusiveInGameStats + kNumNormalStats) {
    throw std::out_of_range("In game stat doesn't exist");
  }

  return exclusive_in_game_stats_[loc_stat_name - (kNumNormalStats +
      kNumExclusiveInGameStats - 1)];
}

/**
  * @brief: A function to add a stat to the container. Only used in the deep
  * copy.
  * @param const ExclusiveInGameStat &stat: The stat to add.
  * @param const int &index: The index of the container to place the stat.
  */

void ExclusiveInGameStatsContainer::AddStat(const ExclusiveInGameStat &stat,
                                            const int &index) {
  exclusive_in_game_stats_[index] = std::make_shared<ExclusiveInGameStat>(stat);
}

/**
  * @brief: A function to deep copy the object state.
  * @param ExclusiveInGameStatsContainer: The deep copy.
  */

ExclusiveInGameStatsContainer ExclusiveInGameStatsContainer::DeepCopy() const {
  ExclusiveInGameStatsContainer copy;

  for (int i = kNumNormalStats + 1;
       i <= kNumExclusiveInGameStats + kNumNormalStats; i++) {
    int index = i - kNumNormalStats - 1;
    copy.AddStat(*exclusive_in_game_stats_[index], index);
  }

  return copy;
}

} //namespace artificialtrainer