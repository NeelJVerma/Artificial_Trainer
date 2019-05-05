/**
 * @project Artificial Trainer
 * @brief The MoveNode class.
 *
 * @file movenode.h
 * @author Neel Verma
 * @date 4/3/19
 */

#ifndef ARTIFICIAL_TRAINER_MOVENODE_H
#define ARTIFICIAL_TRAINER_MOVENODE_H

namespace artificialtrainer {

/**
 * @brief The MoveNode class. This class defines a node in the minimax game
 * tree. It is also used to store the index of a move in the ai's moveset, so
 * that it can then select that move if it is the best.
 *
 * @author Neel Verma
 * @date 4/3/19
 */

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