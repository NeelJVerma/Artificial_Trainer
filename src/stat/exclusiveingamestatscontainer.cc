//
// Created by neel on 2/6/19.
//

#include <stdexcept>
#include "exclusiveingamestatscontainer.h"

namespace artificialtrainer {
ExclusiveInGameStatsContainer::ExclusiveInGameStatsContainer() {
  for (int i = 0; i < kNumExclusiveInGameStats; i++) {
    exclusive_in_game_stats_[i] = std::make_shared<ExclusiveInGameStat>();
  }
}

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

void ExclusiveInGameStatsContainer::AddStat(const ExclusiveInGameStat &stat,
                                            const int &index) {
  exclusive_in_game_stats_[index] = std::make_shared<ExclusiveInGameStat>(stat);
}

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