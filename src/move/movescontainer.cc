//
// Created by neel on 1/29/19.
//

#include "movescontainer.h"

namespace artificialtrainer {
void MovesContainer::AddMove(const std::shared_ptr<Move> &move) {
  current_moves_.push_back(move);
}

bool MovesContainer::SeenMove(const MoveNames &move_name) const {
  for (const auto &in_container : current_moves_) {
    if (move_name == in_container->MoveName()) {
      return true;
    }
  }

  return false;
}

int MovesContainer::Size() const {
  return static_cast<int>(current_moves_.size());
}

std::shared_ptr<Move> MovesContainer::operator[](const int &index) const {
  return current_moves_[index];
}

} //namespace artificialtrainer