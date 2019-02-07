//
// Created by neel on 2/6/19.
//

#include "exclusiveingamestat.h"

namespace artificialtrainer {
ExclusiveInGameStat::ExclusiveInGameStat() : numerator_(3), denominator_(3) {
}


auto ExclusiveInGameStat::RaiseNumerator(const int &num_stages) -> void {
  numerator_ += num_stages;
}

auto ExclusiveInGameStat::RaiseDenominator(const int &num_stages) -> void {
  denominator_ += num_stages;
}

auto ExclusiveInGameStat::LowerNumerator(const int &num_stages) -> void {
  numerator_ -= num_stages;
}

auto ExclusiveInGameStat::LowerDenominator(const int &num_stages) -> void {
  denominator_ -= num_stages;
}

auto ExclusiveInGameStat::CalculatedModifier() const -> double {
  return static_cast<double>(numerator_) / denominator_;
}

auto ExclusiveInGameStat::Numerator() const -> int {
  return numerator_;
}

auto ExclusiveInGameStat::Denominator() const -> int {
  return denominator_;
}

} //namespace artificialtrainer