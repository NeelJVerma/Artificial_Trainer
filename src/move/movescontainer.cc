//
// Created by neel on 1/29/19.
//

#include <cassert>
#include "movescontainer.h"
#include "pp.h"

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
  assert(false);
}

void MovesContainer::ResetMoveAtIndex(const int &index,
                                      const MoveNames &move_name,
                                      const int &move_pp) {
  current_moves_[index]->ResetMove(move_name, move_pp);
}

int MovesContainer::EndOfNormalMovesIndex() const {
  int end_normal_moves_index = 0;

  for (int i = 0; i < current_moves_.size(); i++) {
    if (current_moves_[i]->MoveName() == MoveNames::kPass) {
      end_normal_moves_index = i;
      break;
    }
  }

  return end_normal_moves_index;
}

std::shared_ptr<Move> MovesContainer::operator[](const int &index) const {
  return current_moves_[index];
}

void MovesContainer::AddMove(const Move &move) {
  current_moves_.push_back(std::make_shared<Move>(move));
}

MovesContainer MovesContainer::DeepCopy() const {
  MovesContainer copy;

  for (const auto &move : current_moves_) {
    copy.AddMove(*move);
  }

  return copy;
}

} //namespace artificialtrainer