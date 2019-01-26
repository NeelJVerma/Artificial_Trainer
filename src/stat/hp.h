//
// Created by neel on 1/25/19.
//

#ifndef ARTIFICIAL_TRAINER_HP_H
#define ARTIFICIAL_TRAINER_HP_H

#include "../pokemon/species.h"
#include "statnames.h"
#include "iv.h"
#include "ev.h"

namespace artificialtrainer {
class Hp {
 public:
  Hp(const Hp &hp) = default;
  auto operator=(const Hp &hp) -> Hp& = default;
  Hp() = default;
  Hp(const Species &species, const int &level, const Ev &ev, const Iv &iv);
  Hp(const int &current, const Ev &ev, const Iv &iv, const int &max_hp);
  auto EvStat() const -> Ev;
  auto IvStat() const -> Iv;
  auto CurrentHp() const -> int;
  auto MaxHp() const -> int;
  auto HpAsPercent() const -> double;

 private:
  int max_hp_;
  int current_hp_;
  Ev ev_stat_;
  Iv iv_stat_;
};

auto operator +=(Hp &lhs, const int &rhs) -> Hp&;
auto operator -=(Hp &lhs, const int &rhs) -> Hp&;

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_HP_H
