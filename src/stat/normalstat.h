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
  NormalStat &operator=(const NormalStat &stat) = default;
  NormalStat() = default;
  NormalStat(const SpeciesNames &species_name, const int &level,
             const StatNames &stat_name, const Ev &ev, const Iv &iv);
  int BaseStat() const;
  void RaiseNumerator(const int &num_stages);
  void RaiseDenominator(const int &num_stages);
  void LowerNumerator(const int &num_stages);
  void LowerDenominator(const int &num_stages);
  double CalculatedStat() const;
  int Numerator() const;
  int Denominator() const;
  int InGameStat() const;
  void ResetStat();
  void ResetStat(const int &new_numerator, const int &new_denominator);
  int InitialStat();

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
