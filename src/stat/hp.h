/**
 * @project Artificial Trainer
 * @brief The Hp class.
 *
 * @file hp.h
 * @author Neel Verma
 * @date 1/25/19
 */

#ifndef ARTIFICIAL_TRAINER_HP_H
#define ARTIFICIAL_TRAINER_HP_H

#include "../pokemon/speciesnames.h"
#include "statnames.h"
#include "iv.h"
#include "ev.h"

namespace artificialtrainer {

/**
 * @brief The Hp class. This class acts as a container for a Pokemon's hp stat.
 *
 * @author Neel Verma
 * @date 1/25/19
 */

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
  void SubtractAllHp();

 private:
  int max_hp_;
  int current_hp_;
  Ev ev_stat_;
  Iv iv_stat_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_HP_H
