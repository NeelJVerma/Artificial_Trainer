/**
 * @project Artificial Trainer
 * @brief The Substitute class.
 *
 * @file substitute.h
 * @author Neel Verma
 * @date 2/19/19
 */

#ifndef ARTIFICIAL_TRAINER_SUBSTITUTE_H
#define ARTIFICIAL_TRAINER_SUBSTITUTE_H

namespace artificialtrainer {

/**
 * @brief The Substitute class. This class is responsible for keeping track of
 * the state of a Pokemon's substitute, if it is active.
 *
 * @author Neel Verma
 * @date 2/19/19
 */

class Substitute {
 public:
  Substitute(const Substitute &substitute) = default;
  Substitute &operator=(const Substitute &substitute) = default;
  Substitute();
  void Activate(const int &current_hp);
  bool IsActive() const;
  void TakeDamage(const int &damage_done);

 private:
  int current_hp_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_SUBSTITUTE_H
