//
// Created by neel on 1/29/19.
//

#ifndef ARTIFICIAL_TRAINER_MOVESCONTAINER_H
#define ARTIFICIAL_TRAINER_MOVESCONTAINER_H

#include <vector>
#include <memory>
#include "movenames.h"
#include "move.h"

namespace artificialtrainer {
class MovesContainer {
 public:
  static const int kMaxMoves = 4;

  MovesContainer() = default;
  MovesContainer(const MovesContainer &moves_container) = default;
  auto operator=(
      const MovesContainer &moves_container) -> MovesContainer & = default;
  auto AddMove(const std::shared_ptr<Move> &move) -> void;
  auto CurrentMoves() const -> std::vector<std::shared_ptr<Move>>;
  auto SeenMove(const MoveNames &move_name) -> bool;
  auto Size() const -> int;
  auto operator[](const int &index) -> std::shared_ptr<Move>;

 private:
  std::vector<std::shared_ptr<Move>> current_moves_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_MOVESCONTAINER_H
