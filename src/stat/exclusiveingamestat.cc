//
// Created by neel on 2/6/19.
//

#include "exclusiveingamestat.h"

namespace artificialtrainer {
ExclusiveInGameStat::ExclusiveInGameStat() : numerator_(kMinFactor),
                                             denominator_(kMinFactor) {
}

void ExclusiveInGameStat::RaiseNumerator(const int &num_stages) {
  numerator_ += num_stages;
}

void ExclusiveInGameStat::RaiseDenominator(const int &num_stages) {
  denominator_ += num_stages;
}

void ExclusiveInGameStat::LowerNumerator(const int &num_stages) {
  numerator_ -= num_stages;
}

void ExclusiveInGameStat::LowerDenominator(const int &num_stages) {
  denominator_ -= num_stages;
}

double ExclusiveInGameStat::CalculatedStat() const {
  return static_cast<double>(numerator_) / denominator_;
}

int ExclusiveInGameStat::Numerator() const {
  return numerator_;
}

int ExclusiveInGameStat::Denominator() const {
  return denominator_;
}

void ExclusiveInGameStat::ResetStat() {
  numerator_ = kMinFactor;
  denominator_ = kMinFactor;
}

} //namespace artificialtrainer