//
// Created by neel on 2/6/19.
//

#ifndef ARTIFICIAL_TRAINER_EXCLUSIVEINGAMESTAT_H
#define ARTIFICIAL_TRAINER_EXCLUSIVEINGAMESTAT_H

namespace artificialtrainer {
class ExclusiveInGameStat {
 public:
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

 private:
  int numerator_;
  int denominator_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_EXCLUSIVEINGAMESTAT_H
