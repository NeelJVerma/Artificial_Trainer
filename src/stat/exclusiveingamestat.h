//
// Created by neel on 2/6/19.
//

#ifndef ARTIFICIAL_TRAINER_EXCLUSIVEINGAMESTAT_H
#define ARTIFICIAL_TRAINER_EXCLUSIVEINGAMESTAT_H

namespace artificialtrainer {
class ExclusiveInGameStat {
 public:
  static const int kMaxFactor = 9;
  static const int kMinFactor = 3;
  ExclusiveInGameStat(const ExclusiveInGameStat &stat) = default;
  auto operator=(
      const ExclusiveInGameStat &stat) -> ExclusiveInGameStat & = default;
  ExclusiveInGameStat();
  auto RaiseNumerator(const int &num_stages) -> void;
  auto RaiseDenominator(const int &num_stages) -> void;
  auto LowerNumerator(const int &num_stages) -> void;
  auto LowerDenominator(const int &num_stages) -> void;
  auto CalculatedStat() const -> double;
  auto Numerator() const -> int;
  auto Denominator() const -> int;
  auto ResetStat() -> void;

 private:
  int numerator_;
  int denominator_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_EXCLUSIVEINGAMESTAT_H
