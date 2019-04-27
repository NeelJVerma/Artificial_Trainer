//
// Created by neel on 2/22/19.
//

#ifndef ARTIFICIAL_TRAINER_BIDE_H
#define ARTIFICIAL_TRAINER_BIDE_H

namespace artificialtrainer {
class Bide {
 public:
  Bide(const Bide &bide) = default;
  Bide &operator=(const Bide &bide) = default;
  Bide();
  bool IsActive() const;
  void Activate();
  bool AdvanceOneTurn();
  void SetDamageAdded(const int &damage_added);
  void AddDamage();
  int TotalDamage() const;

 private:
  static const int kMaxTurns = 3;
  int num_turns_active_;
  int damage_added_;
  int total_damage_;
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_BIDE_H
