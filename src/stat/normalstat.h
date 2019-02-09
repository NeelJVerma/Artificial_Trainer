//
// Created by neel on 1/24/19.
//

#ifndef ARTIFICIAL_TRAINER_STAT_H
#define ARTIFICIAL_TRAINER_STAT_H

#include "statnames.h"
#include "ev.h"
#include "iv.h"
#include "../pokemon/speciesnames.h"

namespace artificialtrainer {
class NormalStat {
 public:
  static const int kMaxFactor = 8;
  static const int kMinFactor = 2;
  NormalStat(const NormalStat &stat) = default;
  auto operator=(const NormalStat &stat) -> NormalStat & = default;
  NormalStat() = default;
  NormalStat(const SpeciesNames &species_name, const int &level,
             const StatNames &stat_name, const Ev &ev, const Iv &iv);
  auto EvStat() const -> Ev;
  auto IvStat() const -> Iv;
  auto BaseStat() const -> int;
  auto RaiseNumerator(const int &num_stages) -> void;
  auto RaiseDenominator(const int &num_stages) -> void;
  auto LowerNumerator(const int &num_stages) -> void;
  auto LowerDenominator(const int &num_stages) -> void;
  auto Numerator() const -> int;
  auto Denominator() const -> int;
  auto InGameStat() const -> int;
  auto ResetStat() -> void;

 private:
  int base_stat_;
  int numerator_;
  int denominator_;
  int level_;
  Ev ev_stat_;
  Iv iv_stat_;
};

} //nammespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_STAT_H
