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

int MovesContainer::IndexOfMimic() const {
  for (int i = 0; i < current_moves_.size(); i++) {
    if (current_moves_[i]->MoveName() == MoveNames::kMimic) {
      return i;
    }
  }

  // Will never reach here because of how this function is used.
  return -1;
}

void MovesContainer::ResetMoveAtIndex(const int &index,
                                      const MoveNames &move_name,
                                      const int &move_pp) {
  current_moves_[index]->ResetMove(move_name, move_pp);
}

std::shared_ptr<Move> MovesContainer::operator[](const int &index) const {
  return current_moves_[index];
}

} //namespace artificialtrainer