/**
 * @project Artificial Trainer
 * @brief The Pokemon class.
 *
 * @file pokemon.h
 * @author Neel Verma
 * @date 1/23/19
 */

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

/**
 * @brief The InGameFlags struct. This struct tracks the status of all of the
 * Pokemon's in game attributes.
 *
 * @author Neel Verma
 * @date 1/23/19
 */

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
  bool used_transform = false;
  Confusion confusion{};
  Disable disable{};
  Substitute substitute{};
  BeforeTransformState before_transform_state{};
  Bide bide{};
  StatusNames status = StatusNames::kClear;

  /**
  * @brief: A function makes a deep copy of the object state.
  * @return InGameFlags: The copy.
  */

  InGameFlags DeepCopy() const {
    InGameFlags copy;
    copy.vanished = vanished;
    copy.used_focus_energy = used_focus_energy;
    copy.flinched = flinched;
    copy.used_mimic = used_mimic;
    copy.under_mist = under_mist;
    copy.behind_light_screen = behind_light_screen;
    copy.behind_reflect = behind_reflect;
    copy.executed_move = executed_move;
    copy.seeded = seeded;
    copy.charging_up = charging_up;
    copy.recharging = recharging;
    copy.raging = raging;
    copy.used_trap_move = used_trap_move;
    copy.trapped = trapped;
    copy.num_turns_locked_in = num_turns_locked_in;
    copy.old_attack_numerator = old_attack_numerator;
    copy.old_attack_denominator = old_attack_denominator;
    copy.old_speed_numerator = old_speed_numerator;
    copy.old_speed_denominator = old_speed_denominator;
    copy.mimic_index = mimic_index;
    copy.toxic_n_factor = toxic_n_factor;
    copy.rest_counter = rest_counter;
    copy.turns_asleep = turns_asleep;
    copy.num_turns_trapped = num_turns_trapped;
    copy.used_transform = used_transform;
    copy.confusion = confusion;
    copy.disable = disable;
    copy.substitute = substitute;
    copy.before_transform_state = before_transform_state.DeepCopy();
    copy.bide = bide;
    copy.status = status;
    return copy;
  }
};

/**
 * @brief The Pokemon class. This class serves as a container for a Pokemon,
 * as well as a way to manipulate the Pokemon's attributes in game.
 *
 * @author Neel Verma
 * @date 1/23/19
 */

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
  std::shared_ptr<Hp> HpStat() const;
  NormalStatsContainer GetNormalStatsContainer() const;
  ExclusiveInGameStatsContainer GetExclusiveInGameStatsContainer() const;
  MovesContainer GetMovesContainer() const;
  TypeContainer GetTypeContainer() const;
  std::shared_ptr<Move> MoveUsed() const;
  SpeciesNames SpeciesName() const;
  int Level() const;
  bool IsActive() const;
  void SetMoveUsed(const int &index);
  void SetMoveUsed(const std::shared_ptr<Move> &move);
  void SetIsActive(const bool &is_active);
  void ChangeStat(const StatNames &stat_name, const int &num_stages);
  bool MustUseStruggle() const;
  bool IsVanished() const;
  bool UsedFocusEnergy() const;
  bool IsFlinched() const;
  bool UsedMimic() const;
  bool IsUnderMist() const;
  bool IsBehindLightScreen() const;
  bool IsBehindReflect() const;
  bool ExecutedMove() const;
  bool IsSeeded() const;
  bool IsChargingUp() const;
  bool IsRecharging() const;
  bool IsRaging() const;
  bool UsedTrapMove() const;
  bool IsTrapped() const;
  bool IsUsingLockInMove() const;
  bool IsResting() const;
  bool IsAsleep() const;
  bool IsConfused() const;
  bool HasMoveDisabled() const;
  bool SubstituteIsActive() const;
  bool BideIsActive() const;
  int BideDamage() const;
  bool IsFrozen() const;
  bool IsParalyzed() const;
  bool IsFullyParalyzed() const;
  bool IsPoisoned() const;
  bool IsUnderToxic() const;
  bool IsBurned() const;
  bool HasStatus() const;
  bool CanHaveMoveDisabled() const;
  bool IsFainted() const;
  bool IsType(const TypeNames &type_name) const;
  void UseVanishMove();
  void UseFocusEnergy();
  void Flinch();
  void UseMimic();
  void UseMist();
  void UseLightScreen();
  void UseReflect();
  void SetExecutedMove(const bool &executed_move);
  void ApplyLeechSeed();
  void UseChargeUpMove();
  void SetRecharging(const bool &recharging);
  void UseRage();
  void Trap(const bool &user, const int &random_threshold);
  void UseLockInMove();
  void SetMimicIndex(const int &index_in_move_container);
  void AdvanceToxicFactor();
  void AdvanceRestCounter();
  void AdvanceRegularSleepCounter();
  void Confuse();
  bool HandleConfusion();
  void DoConfusionDamage(const int &damage_done);
  MoveNames DisableMove();
  void HandleDisable();
  void UseSubstitute();
  void DoDamageToSubstitute(const int &damage_done);
  void Transform(const std::shared_ptr<Pokemon> &target);
  void UseBide();
  bool BideWillEnd();
  void ResetBide();
  void SetBideDamage(const int &damage);
  void AddDamageToBide();
  void ApplyStatus(const StatusNames &status_name);
  int DoStatusDamage();
  void UseConversion();
  void AbsorbHp(const int &absorbed);
  void TakeRecoilDamage(const int &recoil);
  void AutoFaint();
  void UseMetronome();
  void RecoverHp();
  void ResetFaintFlags();
  void ResetFlagsFromHaze();
  void ResetSwitchFlags();
  void ResetEndOfTurnFlags();
  void DecrementPpOfMoveUsed(const MoveNames &move_name);
  Pokemon DeepCopy() const;

 private:
  std::shared_ptr<Hp> hp_stat_;
  NormalStatsContainer normal_stats_container_;
  ExclusiveInGameStatsContainer exclusive_in_game_stats_container_;
  MovesContainer moves_container_;
  TypeContainer type_container_;
  std::shared_ptr<Move> move_used_;
  InGameFlags flags_;
  SpeciesNames species_name_;
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
  void SetSpeciesName(const SpeciesNames &species_name);
  void SetLevel(const int &level);
  void SetHpStat(const Hp &hp_stat);
  void SetNormalStatsContainer(
      const NormalStatsContainer &normal_stats_container);
  void SetExclusiveInGameStatsContainer(
      const ExclusiveInGameStatsContainer &exclusive_in_game_stats_container);
  void SetMovesContainer(const MovesContainer &moves_container);
  void SetTypeContainer(const TypeContainer &type_container);
  void SetMoveUsed(const Move &move_used);
  void SetFlags(const InGameFlags &flags);
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_POKEMON_H
