/**
 * @project Artificial Trainer
 * @brief The implementation of the MovesContainer class.
 *
 * @file movescontainer.cc
 * @author Neel Verma
 * @date 1/29/19
 */

#include <cassert>
#include "movescontainer.h"
#include "pp.h"

namespace artificialtrainer {

/**
  * @brief: A function to add a move to the container.
  * @param const std::shared_ptr<Move> &move: The move to add.
  */

void MovesContainer::AddMove(const std::shared_ptr<Move> &move) {
  current_moves_.push_back(move);
}

/**
  * @brief: A function to determine whether or not a certain move is in the
  * container.
  * @param const MoveNames &move_name: The name of the move to check.
  * @return: Whether or not the move is in the container.
  */

bool MovesContainer::SeenMove(const MoveNames &move_name) const {
  for (const auto &in_container : current_moves_) {
    if (move_name == in_container->MoveName()) {
      return true;
    }
  }

  return false;
}

/**
  * @brief: An accessor for the size of the container.
  * @return int: The container size.
  */

int MovesContainer::Size() const {
  return static_cast<int>(current_moves_.size());
}

/**
  * @brief: A function to find the index of mimic.
  * @return int: The index of mimic.
  */

int MovesContainer::IndexOfMimic() const {
  for (int i = 0; i < current_moves_.size(); i++) {
    if (current_moves_[i]->MoveName() == MoveNames::kMimic) {
      return i;
    }
  }

  // Will never reach here because of how this function is used.
  assert(false);
}

/**
  * @brief: A function to reset the move at the given index with the given
  * parameters.
  * @param const int &index: The index of the move to reset.
  * @param const MoveNames &move_name: The name of the new move.
  * @param const int &move_pp: The new move pp.
  */

void MovesContainer::ResetMoveAtIndex(const int &index,
                                      const MoveNames &move_name,
                                      const int &move_pp) {
  current_moves_[index]->ResetMove(move_name, move_pp);
}

/**
  * @brief: A function to determine where normal moves end. This maans any
  * move that is not a pass, switch, or struggle.
  * @return int: The index of the last normal move.
  */

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

/**
  * @brief: An operator to index into the container.
  * @param const int &index: The index of the move to return.
  * @return std::shared_ptr<Move>: The move at the given index.
  */

std::shared_ptr<Move> MovesContainer::operator[](const int &index) const {
  return current_moves_[index];
}

/**
  * @brief: A function to add a move to the container. This is only used for
  * the deep copy.
  * @param const Move &move: The move to add.
  */

void MovesContainer::AddMove(const Move &move) {
  current_moves_.push_back(std::make_shared<Move>(move));
}

/**
  * @brief: A function to make a deep copy of the current object state.
  * @return MovesContainer: The copy.
  */

MovesContainer MovesContainer::DeepCopy() const {
  MovesContainer copy;

  for (const auto &move : current_moves_) {
    copy.AddMove(*move);
  }

  return copy;
}

} //namespace artificialtrainer