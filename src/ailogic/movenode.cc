/**
 * @project Artificial Trainer
 * @brief The implementation of the MoveNode class.
 *
 * @file movenode.cc
 * @author Neel Verma
 * @date 4/3/19
 */

#include "movenode.h"

namespace artificialtrainer {

/**
  * @brief: One constructor for the MoveNode class.
  * @param const int &move_index: The index of the move in a Pokemon's moveset.
  */

MoveNode::MoveNode(const int &move_index) : move_index_(move_index),
                                            heuristic_value_(0) {
}

/**
  * @brief: A mutator for the heuristic value of the move node.
  * @param const double &heuristic_value: The heuristic value of the move node.
  */

void MoveNode::SetHeuristicValue(const double &heuristic_value) {
  heuristic_value_ = heuristic_value;
}

/**
  * @brief: An accessor for the move index.
  * @return int: The move index for the move node.
  */

int MoveNode::MoveIndex() const {
  return move_index_;
}

/**
  * @brief: An accessor for the heuristic value.
  * @return double: The heuristic value of the move node.
  */

double MoveNode::HeuristicValue() const {
  return heuristic_value_;
}

} //namespace artificialtrainer