//
// Created by neel on 1/27/19.
//

#ifndef ARTIFICIAL_TRAINER_MOVE_H
#define ARTIFICIAL_TRAINER_MOVE_H

#include "moves.h"

namespace artificialtrainer {
class Move {
 public:
  Move(const Move &move) = default;
  auto operator=(const Move &move) -> Move & = default;
  Move() = default;
  Move(const Moves &move_name, const int &current_pp);
  auto MoveName() const -> Moves;
  auto CurrentPp() const -> int;
  auto DecrementPp(const int &amount) -> void;

 private:
  int current_pp_;
  Moves move_name_;
};

auto IsPhysical(Moves &move_name) -> bool;
auto IsSpecial(const Moves &move_name) -> bool;
auto IsDamaging(const Moves &move_name) -> bool;
auto IsUseless(const Moves &move_name) -> bool;

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_MOVE_H
