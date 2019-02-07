//
// Created by neel on 1/29/19.
//

#include "movescontainer.h"

namespace artificialtrainer {
auto MovesContainer::AddMove(const std::shared_ptr<Move> &move) -> void {
  current_moves_.push_back(move);
}

auto MovesContainer::CurrentMoves() const
-> std::vector<std::shared_ptr<Move>> {
  return current_moves_;
}

auto MovesContainer::SeenMove(const MoveNames &move_name) -> bool {
  for (const auto &in_container : current_moves_) {
    if (move_name == in_container->MoveName()) {
      return true;
    }
  }

  return false;
}

auto MovesContainer::Size() const -> int {
  return static_cast<int>(current_moves_.size());
}

auto MovesContainer::operator[](const int &index) -> std::shared_ptr<Move> {
  return current_moves_[index];
}

} //namespace artificialtrainer