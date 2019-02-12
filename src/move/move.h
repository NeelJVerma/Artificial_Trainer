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
  auto operator=(const Move &move) -> Move & = default;
  Move() = default;
  Move(const MoveNames &move_name, const int &current_pp);
  auto MoveName() const -> MoveNames;
  auto CurrentPp() const -> int;
  auto DecrementPp(const int &amount) -> void;

 private:
  int current_pp_;
  MoveNames move_name_;
};

auto IsPhysical(const MoveNames &move_name) -> bool;
auto IsSpecial(const MoveNames &move_name) -> bool;
auto IsDamaging(const MoveNames &move_name) -> bool;
auto IsUseless(const MoveNames &move_name) -> bool;
auto IsSwitch(const MoveNames &move_name) -> bool;
auto OnlyChangesStat(const MoveNames &move_name) -> bool;
auto IsOneHitKo(const MoveNames &move_name) -> bool;
auto HasHighCriticalHitRatio(const MoveNames &move_name) -> bool;
auto VariableEffectChance(const MoveNames &move_name) -> int;
auto IsSelfKoMove(const MoveNames &move_name) -> bool;

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_MOVE_H
