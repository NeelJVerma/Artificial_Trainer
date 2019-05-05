/**
 * @project Artificial Trainer
 * @brief The implementation of the ExclusiveInGameStat class.
 *
 * @file exclusiveingamestat.cc
 * @author Neel Verma
 * @date 2/6/19
 */

#include "exclusiveingamestat.h"

namespace artificialtrainer {

/**
  * @brief: The default constructor for the ExclusiveInGameStat class.
  */

ExclusiveInGameStat::ExclusiveInGameStat() : numerator_(kMinFactor),
                                             denominator_(kMinFactor) {
}

/**
  * @brief: A function to raise the numerator of the stat.
  * @param const int &num_stages: The number of stages to raise.
  */

void ExclusiveInGameStat::RaiseNumerator(const int &num_stages) {
  numerator_ += num_stages;
}

/**
  * @brief: A function to raise the denominator of the stat.
  * @param const int &num_stages: The number of stages to raise.
  */

void ExclusiveInGameStat::RaiseDenominator(const int &num_stages) {
  denominator_ += num_stages;
}

/**
  * @brief: A function to lower the numerator of the stat.
  * @param const int &num_stages: The number of stages to lower.
  */

void ExclusiveInGameStat::LowerNumerator(const int &num_stages) {
  numerator_ -= num_stages;
}

/**
  * @brief: A function to lower the denominator of the stat.
  * @param const int &num_stages: The number of stages to lower.
  */

void ExclusiveInGameStat::LowerDenominator(const int &num_stages) {
  denominator_ -= num_stages;
}

/**
  * @brief: A function to return the stat as it should be in game.
  * @return double: The in game stat..
  */

double ExclusiveInGameStat::CalculatedStat() const {
  return static_cast<double>(numerator_) / denominator_;
}

/**
  * @brief: An accessor for the numerator.
  * @return int: The numerator.
  */

int ExclusiveInGameStat::Numerator() const {
  return numerator_;
}

/**
  * @brief: An accessor for the denominator.
  * @return int: The denominator.
  */

int ExclusiveInGameStat::Denominator() const {
  return denominator_;
}

/**
  * @brief: A function to reset the stat to its original value.
  */

void ExclusiveInGameStat::ResetStat() {
  numerator_ = kMinFactor;
  denominator_ = kMinFactor;
}

} //namespace artificialtrainer