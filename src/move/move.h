//
// Created by neel on 1/27/19.
//

#ifndef ARTIFICIAL_TRAINER_MOVE_H
#define ARTIFICIAL_TRAINER_MOVE_H

#include "movenames.h"

namespace artificialtrainer {
class Move {
 public:
  Move(const Move &move) = default;
  Move &operator=(const Move &move) = default;
  Move() = default;
  Move(const MoveNames &move_name, const int &current_pp);
  MoveNames MoveName() const;
  int CurrentPp() const;
  void DecrementPp(const int &amount);

 private:
  int current_pp_;
  MoveNames move_name_;
};

bool IsPhysical(const MoveNames &move_name);
bool IsSpecial(const MoveNames &move_name);
bool IsDamaging(const MoveNames &move_name);
bool IsUseless(const MoveNames &move_name);
bool IsSwitch(const MoveNames &move_name);
bool OnlyChangesStat(const MoveNames &move_name);
bool IsOneHitKo(const MoveNames &move_name);
bool HasHighCriticalHitRatio(const MoveNames &move_name);
int VariableEffectChance(const MoveNames &move_name);
bool IsSelfKoMove(const MoveNames &move_name);

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_MOVE_H
