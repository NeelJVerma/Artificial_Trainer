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
  auto operator=(const Hp &hp) -> Hp & = default;
  Hp() = default;
  Hp(const SpeciesNames &species_name, const int &level, const Ev &ev,
     const Iv &iv);
  auto EvStat() const -> Ev;
  auto IvStat() const -> Iv;
  auto CurrentHp() const -> int;
  auto MaxHp() const -> int;
  auto HpAsPercent() const -> double;
  auto SubtractHp(const int &amount) -> void;
  auto AddHp(const int &amount) -> void;

 private:
  int max_hp_;
  int current_hp_;
  Ev ev_stat_;
  Iv iv_stat_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_HP_H
