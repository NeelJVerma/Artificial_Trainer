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
  ExclusiveInGameStat &operator=(const ExclusiveInGameStat &stat) = default;
  ExclusiveInGameStat();
  void RaiseNumerator(const int &num_stages);
  void RaiseDenominator(const int &num_stages);
  void LowerNumerator(const int &num_stages);
  void LowerDenominator(const int &num_stages);
  double CalculatedStat() const;
  int Numerator() const;
  int Denominator() const;
  void ResetStat();

 private:
  int numerator_;
  int denominator_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_EXCLUSIVEINGAMESTAT_H
