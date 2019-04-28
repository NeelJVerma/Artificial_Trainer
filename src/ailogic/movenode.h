//
// Created by neel on 4/3/19.
//

#ifndef ARTIFICIAL_TRAINER_MOVENODE_H
#define ARTIFICIAL_TRAINER_MOVENODE_H

namespace artificialtrainer {
class MoveNode {
 public:
  MoveNode() = default;
  MoveNode(const MoveNode &move_node) = default;
  MoveNode &operator=(const MoveNode &move_node) = default;
  explicit MoveNode(const int &move_index);
  void SetHeuristicValue(const double &heuristic_value);
  int MoveIndex() const;
  double HeuristicValue() const;

 private:
  int move_index_;
  double heuristic_value_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_MOVENODE_H