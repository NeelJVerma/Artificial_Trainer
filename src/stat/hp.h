//
// Created by neel on 1/25/19.
//

#ifndef ARTIFICIAL_TRAINER_HP_H
#define ARTIFICIAL_TRAINER_HP_H

#include "../pokemon/speciesnames.h"
#include "statnames.h"
#include "iv.h"
#include "ev.h"

namespace artificialtrainer {
class Hp {
 public:
  Hp(const Hp &hp) = default;
  Hp &operator=(const Hp &hp) = default;
  Hp() = default;
  Hp(const SpeciesNames &species_name, const int &level, const Ev &ev,
     const Iv &iv);
  int CurrentHp() const;
  int MaxHp() const;
  double HpAsPercent() const;
  void SubtractHp(const int &amount);
  void AddHp(const int &amount);

 private:
  int max_hp_;
  int current_hp_;
  Ev ev_stat_;
  Iv iv_stat_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_HP_H
