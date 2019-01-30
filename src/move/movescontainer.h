//
// Created by neel on 1/29/19.
//

#ifndef ARTIFICIAL_TRAINER_MOVESCONTAINER_H
#define ARTIFICIAL_TRAINER_MOVESCONTAINER_H

#include <vector>
#include "movenames.h"
#include "move.h"

namespace artificialtrainer {
class MovesContainer {
 public:
  static const int kMaxMoves = 4;

  MovesContainer() = default;
  MovesContainer(const MovesContainer &moves_container) = default;
  auto operator=(const MovesContainer &moves_container) -> MovesContainer &
  = default;
  auto AddMove(const Move &move) -> void;
  auto GetCurrentMoves() const -> std::vector<Move>;
  auto SeenMove(const MoveNames &move) -> bool;
  auto Size() const -> int;
  auto operator[](const int &index) -> Move &;

 private:
  std::vector<Move> current_moves_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_MOVESCONTAINER_H
