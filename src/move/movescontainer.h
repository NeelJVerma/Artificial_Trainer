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
  MovesContainer &operator=(const MovesContainer &moves_container) = default;
  void AddMove(const std::shared_ptr<Move> &move);
  bool SeenMove(const MoveNames &move_name) const;
  int Size() const;
  int IndexOfMimic() const;
  void ResetMoveAtIndex(const int &index, const MoveNames &move_name,
                        const int &move_pp);
  std::shared_ptr<Move> operator[](const int &index) const;

 private:
  std::vector<std::shared_ptr<Move>> current_moves_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_MOVESCONTAINER_H
