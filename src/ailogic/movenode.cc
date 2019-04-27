//
// Created by neel on 4/3/19.
//

#include "movenode.h"

namespace artificialtrainer {
MoveNode::MoveNode(const int &move_index) : move_index_(move_index),
                                            heuristic_value_(0) {
}

void MoveNode::SetHeuristicValue(const double &heuristic_value) {
  heuristic_value_ = heuristic_value;
}

int MoveNode::MoveIndex() const {
  return move_index_;
}

double MoveNode::HeuristicValue() const {
  return heuristic_value_;
}

} //namespace artificialtrainer