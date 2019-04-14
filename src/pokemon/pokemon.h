//
// Created by neel on 1/23/19.
//

#ifndef ARTIFICIAL_TRAINER_POKEMON_H
#define ARTIFICIAL_TRAINER_POKEMON_H

#include "speciesnames.h"
#include "../stat/normalstatscontainer.h"
#include "../move/movescontainer.h"
#include "../type/typecontainer.h"
#include "../stat/exclusiveingamestatscontainer.h"
#include "statusnames.h"
#include "confusion.h"
#include "disable.h"
#include "substitute.h"
#include "beforetransformstate.h"
#include "bide.h"

namespace artificialtrainer {
struct InGameFlags {
  bool vanished = false;
  bool used_focus_energy = false;
  bool flinched = false;
  bool used_mimic = false;
  bool under_mist = false;
  bool behind_light_screen = false;
  bool behind_reflect = false;
  bool executed_move = false;
  bool seeded = false;
  bool charging_up = false;
  bool recharging = false;
  bool raging = false;
  bool used_trap_move = false;
  bool trapped = false;
  int num_turns_locked_in = 0;
  int old_attack_numerator = 0;
  int old_attack_denominator = 0;
  int old_speed_numerator = 0;
  int old_speed_denominator = 0;
  int mimic_index = 0;
  int toxic_n_factor = 1;
  int rest_counter = 1;
  int turns_asleep = 1;
  int num_turns_trapped = 0;
  Confusion confusion{};
  Disable disable{};
  Substitute substitute{};
  BeforeTransformState before_transform_state{};
  Bide bide{};
  StatusNames status = StatusNames::kClear;
};

class Pokemon {
 public:
  static const int kMaxLevel;

  Pokemon(const Pokemon &pokemon) = default;
  Pokemon &operator=(const Pokemon &pokemon) = default;
  Pokemon();
  Pokemon(const SpeciesNames &species_name,
          const NormalStatsContainer &stats_container,
          const MovesContainer &moves_container,
          const TypeContainer &type_container, const int &level,
          const std::shared_ptr<Hp> &hp_stat);
  NormalStatsContainer GetNormalStatsContainer() const;
  ExclusiveInGameStatsContainer GetExclusiveInGameStatsContainer() const;
  MovesContainer GetMovesContainer() const;
  TypeContainer GetTypeContainer() const;
  SpeciesNames SpeciesName() const;
  int Level() const;
  bool IsActive() const;
  void SetIsActive(const bool &is_active);
  void SetMoveUsed(const int &index);
  void SetMoveUsed(const std::shared_ptr<Move> &move);
  std::shared_ptr<Move> MoveUsed() const;
  void ChangeStat(const StatNames &stat_name, const int &num_stages);
  void UseFocusEnergy();
  bool UsedFocusEnergy() const;
  void Flinch();
  bool IsFlinched() const;
  void Confuse();
  bool IsConfused() const;
  void DisableMove(const int &disable_index);
  bool HasMoveDisabled() const;
  void UseVanishMove();
  bool IsVanished() const;
  bool HandleConfusion();
  void DoConfusionDamage(const int &damage_done);
  void HandleDisable();
  void UseConversion();
  void AbsorbHp(const int &absorbed);
  void TakeRecoilDamage(const int &recoil);
  void AutoFaint();
  void UseMetronome();
  bool IsType(const TypeNames &type_name) const;
  void UseMimic();
  void SetMimicIndex(const int &index_in_move_container);
  void SetExecutedMove(const bool &executed_move);
  bool ExecutedMove() const;
  void UseMist();
  bool IsUnderMist() const;
  void UseLightScreen();
  bool IsBehindLightScreen() const;
  void UseReflect();
  bool IsBehindReflect() const;
  void UseSubstitute();
  bool SubstituteIsActive() const;
  void DoDamageToSubstitute(const int &damage_done);
  void RecoverHp();
  bool IsBurned() const;
  void ApplyStatus(const StatusNames &status_name);
  void ApplyLeechSeed();
  bool IsSeeded() const;
  bool IsFrozen() const;
  bool HasStatus() const;
  bool IsParalyzed() const;
  bool IsFullyParalyzed() const;
  bool IsPoisoned() const;
  bool IsUnderToxic() const;
  void AdvanceToxicFactor();
  bool IsAsleep() const;
  bool IsResting() const;
  void AdvanceRestCounter();
  void AdvanceRegularSleepCounter();
  void UseChargeUpMove();
  bool IsChargingUp() const;
  void SetRecharging(const bool &recharging);
  bool IsRecharging() const;
  void UseLockInMove();
  bool IsUsingLockInMove() const;
  void UseRage();
  bool IsRaging() const;
  void Trap(const bool &user, const int &random_threshold);
  bool UsedTrapMove() const;
  bool IsTrapped() const;
  void Transform(const std::shared_ptr<Pokemon> &target);
  std::shared_ptr<Hp> HpStat() const;
  void UseBide();
  bool BideWillEnd();
  bool BideIsActive() const;
  int BideDamage() const;
  void ResetBide();
  void SetBideDamage(const int &damage);
  void AddDamageToBide();
  bool MustUseStruggle() const;
  bool CanHaveMoveDisabled() const;
  bool IsFainted() const;
  void ResetFaintFlags();
  void ResetFlagsFromHaze();
  void ResetSwitchFlags();
  void ResetEndOfTurnFlags();
  int DoStatusDamage();

 private:
  NormalStatsContainer normal_stats_container_;
  std::shared_ptr<Hp> hp_stat_;
  ExclusiveInGameStatsContainer exclusive_in_game_stats_container_;
  MovesContainer moves_container_;
  std::shared_ptr<Move> move_used_;
  TypeContainer type_container_;
  SpeciesNames species_name_;
  InGameFlags flags_;
  int level_;
  bool is_active_;
  void LowerStat(const StatNames &stat_name, const int &num_stages,
                 const bool &ignore_mist);
  void RaiseStat(const StatNames &stat_name, const int &num_stages);
  void ResetStats();
  void ReEnableDisabledMove();
  void RestoreMimic();
  void ApplyBurn();
  void ApplyFreeze();
  void ApplyParalysis();
  void ApplyPoison();
  void ApplyToxic();
  void ApplySleep();
  void ApplyRestSleep();
  void RestoreStatsFromStatuses();
  void RestoreStateFromTransform();
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_POKEMON_H
