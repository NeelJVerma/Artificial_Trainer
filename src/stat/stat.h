//
// Created by neel on 1/24/19.
//

#ifndef ARTIFICIAL_TRAINER_STAT_H
#define ARTIFICIAL_TRAINER_STAT_H

#include "../pokemon/species.h"
#include "statnames.h"
#include "ev.h"
#include "iv.h"

namespace artificialtrainer {
class Stat {
 public:
  Stat(const Stat &stat) = default;
  auto operator=(const Stat &stat) -> Stat& = default;
  Stat() = default;
  Stat(const Species &species, const StatNames &stat_name, const Ev &ev,
       const Iv &iv);
  auto EvStat() const -> Ev;
  auto IvStat() const -> Iv;
  auto BaseStat() const -> int;

 private:
  int actual_stat_;
  int base_stat_;
  Ev ev_stat_;
  Iv iv_stat_;
};

} //nammespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_STAT_H
