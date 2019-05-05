/**
 * @project Artificial Trainer
 * @brief The implementation of the Pokemon class.
 *
 * @file pokemon.cc
 * @author Neel Verma
 * @date 1/23/19
 */

#include <cassert>
#include <iostream>
#include "pokemon.h"
#include "../type/type.h"
#include "../move/pp.h"
#include "../random/randomgenerator.h"
#include "../stringconverter/stringconverter.h"

namespace artificialtrainer {
const int Pokemon::kMaxLevel = 100;

/**
  * @brief: One constructor for the Pokemon class.
  * @param const SpeciesNames &species_name: The species name of the Pokemon.
  * @param const NormalStatsContainer &stats_container: The stats for the
  * Pokemon.
  * @param const MovesContainer &moves_container: The moves for the Pokemon.
  * @param const TypeContainer &type_container: The types of the Pokemon.
  * @param const int &level: The level of the Pokemon.
  * @param const sdt::shared_ptr<Hp> &hp_stat: The hp of the Pokemon.
  */

Pokemon::Pokemon(const SpeciesNames &species_name,
                 const NormalStatsContainer &stats_container,
                 const MovesContainer &moves_container,
                 const TypeContainer &type_container, const int &level,
                 const std::shared_ptr<Hp> &hp_stat)
    : species_name_(species_name),
      normal_stats_container_(stats_container),
      exclusive_in_game_stats_container_{},
      moves_container_(moves_container),
      type_container_(type_container),
      hp_stat_(hp_stat),
      move_used_(nullptr),
      level_(level),
      is_active_(false) {
  flags_.before_transform_state = BeforeTransformState
      (normal_stats_container_, exclusive_in_game_stats_container_,
       type_container_, moves_container_, species_name_);
}

/**
  * @brief: The default constructor for the Pokemon class.
  */

Pokemon::Pokemon() : species_name_(SpeciesNames::kBulbasaur),
                     normal_stats_container_{},
                     exclusive_in_game_stats_container_{},
                     moves_container_{},
                     type_container_{},
                     move_used_(nullptr),
                     level_(0),
                     is_active_(false) {
}

/**
  * @brief: An accessor for the hp stat.
  * @return std::shared_ptr<Hp>: The hp stat.
  */

std::shared_ptr<Hp> Pokemon::HpStat() const {
  return hp_stat_;
}

/**
  * @brief: An accessor for the normal stats container.
  * @return NormalStatsContainer: The normal stats container.
  */

NormalStatsContainer Pokemon::GetNormalStatsContainer() const {
  return normal_stats_container_;
}

/**
  * @brief: An accessor for the exclusive in game stats container.
  * @return ExclusiveInGameStatsContainer: The exclusive in game stats
  * container.
  */

ExclusiveInGameStatsContainer Pokemon::
GetExclusiveInGameStatsContainer() const {
  return exclusive_in_game_stats_container_;
}

/**
  * @brief: An accessor for the moves container.
  * @return MovesContainer: The moves container.
  */

MovesContainer Pokemon::GetMovesContainer() const {
  return moves_container_;
}

/**
  * @brief: An accessor for the type container.
  * @return TypeContainer: The type container.
  */

TypeContainer Pokemon::GetTypeContainer() const {
  return type_container_;
}

/**
  * @brief: An accessor for the move used.
  * @return std::shared_ptr<Move>: The move used.
  */

std::shared_ptr<Move> Pokemon::MoveUsed() const {
  return move_used_;
}

/**
  * @brief: An accessor for the species name.
  * @return SpeciesNames: The species name.
  */

SpeciesNames Pokemon::SpeciesName() const {
  return species_name_;
}

/**
  * @brief: An accessor for the Pokemon's level.
  * @return int: The Pokemon's level.
  */

int Pokemon::Level() const {
  return level_;
}

/**
  * @brief: An accessor for is active.
  * @return bool: Whether or not the Pokemon is active.
  */

bool Pokemon::IsActive() const {
  return is_active_;
}

/**
  * @brief: A mutator for the move used.
  * @param const int &index: The index of the move to set.
  */

void Pokemon::SetMoveUsed(const int &index) {
  move_used_ = moves_container_[index];
}

/**
  * @brief: A mutator for the move used.
  * @param const std::shared_ptr<Move> &move: The move to set.
  */

void Pokemon::SetMoveUsed(const std::shared_ptr<Move> &move) {
  move_used_ = move;
}

/**
  * @brief: A mutator for the move used. Only used in the deep copy.
  * @param const Move &move_used: The move to set.
  */

void Pokemon::SetMoveUsed(const Move &move_used) {
  move_used_ = std::make_shared<Move>(move_used);
}

/**
  * @brief: A mutator for is active
  * @param const bool &is_active: The boolean to set.
  */

void Pokemon::SetIsActive(const bool &is_active) {
  is_active_ = is_active;
}

/**
  * @brief: A function that lowers a Pokemon's stat.
  * @param const StatNames &stat_name: The stat to lower.
  * @param const int &num_stages: The number of stages to lower.
  * @param const bool &ignore_mist: Whether or not to ignore mist.
  */

void Pokemon::LowerStat(const StatNames &stat_name,
                        const int &num_stages, const bool &ignore_mist) {
  if (stat_name != StatNames::kAccuracy && stat_name != StatNames::kEvasion) {
    std::shared_ptr<NormalStat> stat_to_lower =
        normal_stats_container_[stat_name];

    for (int i = 0; i > num_stages; i--) {
      if (stat_to_lower->Denominator() == NormalStat::kMaxFactor) {
        return;
      }

      if (stat_to_lower->CalculatedStat() > 1.0) {
        stat_to_lower->LowerNumerator(1);
      } else {
        stat_to_lower->RaiseDenominator(1);
      }
    }
  } else {
    std::shared_ptr<ExclusiveInGameStat> stat_to_lower =
        exclusive_in_game_stats_container_[stat_name];

    for (int i = 0; i > num_stages; i--) {
      if (stat_to_lower->Denominator() == ExclusiveInGameStat::kMaxFactor) {
        return;
      }

      if (stat_to_lower->CalculatedStat() > 1.0) {
        stat_to_lower->LowerNumerator(1);
      } else {
        stat_to_lower->RaiseDenominator(1);
      }
    }
  }
}

/**
  * @brief: A function that raises a Pokemon's stat.
  * @param const StatNames &stat_name: The stat to lower.
  * @param const int &num_stages: The number of stages to raise.
  */

void Pokemon::RaiseStat(const StatNames &stat_name,
                        const int &num_stages) {
  if (stat_name != StatNames::kAccuracy && stat_name != StatNames::kEvasion) {
    std::shared_ptr<NormalStat> stat_to_boost =
        normal_stats_container_[stat_name];

    for (int i = 0; i < num_stages; i++) {
      if (stat_to_boost->Numerator() == NormalStat::kMaxFactor) {
        return;
      }

      if (stat_to_boost->CalculatedStat() < 1.0) {
        stat_to_boost->LowerDenominator(1);
      } else {
        stat_to_boost->RaiseNumerator(1);
      }
    }
  } else {
    std::shared_ptr<ExclusiveInGameStat> stat_to_boost =
        exclusive_in_game_stats_container_[stat_name];

    for (int i = 0; i < num_stages; i++) {
      if (stat_to_boost->Numerator() == ExclusiveInGameStat::kMaxFactor) {
        return;
      }

      if (stat_to_boost->CalculatedStat() < 1.0) {
        stat_to_boost->LowerDenominator(1);
      } else {
        stat_to_boost->RaiseNumerator(1);
      }
    }
  }
}

/**
  * @brief: A function that changes a Pokemon's stat.
  * @param const StatNames &stat_name: The stat to lower.
  * @param const int &num_stages: The number of stages to change the stat.
  */

void Pokemon::ChangeStat(const StatNames &stat_name,
                         const int &num_stages) {
  num_stages < 0 ? LowerStat(stat_name, num_stages,
                             (flags_.status == StatusNames::kBurned ||
                                 flags_.status == StatusNames::kParalyzed))
                 : RaiseStat(stat_name, num_stages);
}

/**
  * @brief: A function that determines whether or not the Pokemon needs to
  * use struggle.
  * @return bool: Whether or not the Pokemon must use struggle.
  */

bool Pokemon::MustUseStruggle() const {
  for (int i = 0; i < moves_container_.EndOfNormalMovesIndex(); i++) {
    if (moves_container_[i]->CurrentPp() &&
        !moves_container_[i]->IsDisabled()) {
      return false;
    }
  }

  return true;
}

/**
  * @brief: A function that determines whether or not the Pokemon is vanished.
  * @return bool: Whether or not the Pokemon is vanished.
  */

bool Pokemon::IsVanished() const {
  return flags_.vanished;
}

/**
  * @brief: A function that determines whether or not the Pokemon used focus
  * energy.
  * @return bool: Whether or not the Pokemon used focus energy.
  */

bool Pokemon::UsedFocusEnergy() const {
  return flags_.used_focus_energy;
}

/**
  * @brief: A function that determines whether or not the Pokemon is flinched.
  * @return bool: Whether or not the Pokemon is flinched.
  */

bool Pokemon::IsFlinched() const {
  return flags_.flinched;
}

/**
  * @brief: A function that determines whether or not the Pokemon used mimic.
  * @return bool: Whether or not the Pokemon used mimc.
  */

bool Pokemon::UsedMimic() const {
  return flags_.used_mimic;
}

/**
  * @brief: A function that determines whether or not the Pokemon is under mist.
  * @return bool: Whether or not the Pokemon is under mist.
  */

bool Pokemon::IsUnderMist() const {
  return flags_.under_mist;
}

/**
  * @brief: A function that determines whether or not the Pokemon is behind
  * light screen.
  * @return bool: Whether or not the Pokemon is behind light screen.
  */

bool Pokemon::IsBehindLightScreen() const {
  return flags_.behind_light_screen;
}

/**
  * @brief: A function that determines whether or not the Pokemon is behind
  * reflect.
  * @return bool: Whether or not the Pokemon is behind reflect.
  */

bool Pokemon::IsBehindReflect() const {
  return flags_.behind_reflect;
}

/**
  * @brief: A function that determines whether or not the Pokemon executed a
  * move.
  * @return bool: Whether or not the Pokemon executed a move.
  */

bool Pokemon::ExecutedMove() const {
  return flags_.executed_move;
}

/**
  * @brief: A function that determines whether or not the Pokemon is seeded.
  * @return bool: Whether or not the Pokemon is seeded.
  */

bool Pokemon::IsSeeded() const {
  return flags_.seeded;
}

/**
  * @brief: A function that determines whether or not the Pokemon is charging
  * up.
  * @return bool: Whether or not the Pokemon is charging up.
  */

bool Pokemon::IsChargingUp() const {
  return flags_.charging_up;
}

/**
  * @brief: A function that determines whether or not the Pokemon is recharging.
  * @return bool: Whether or not the Pokemon is recharging.
  */

bool Pokemon::IsRecharging() const {
  return flags_.recharging;
}

/**
  * @brief: A function that determines whether or not the Pokemon is raging.
  * @return bool: Whether or not the Pokemon is raging.
  */

bool Pokemon::IsRaging() const {
  return flags_.raging;
}

/**
  * @brief: A function that determines whether or not the Pokemon used a trap
  * move.
  * @return bool: Whether or not the Pokemon used a trap move.
  */

bool Pokemon::UsedTrapMove() const {
  return flags_.used_trap_move;
}

/**
  * @brief: A function that determines whether or not the Pokemon is trapped.
  * @return bool: Whether or not the Pokemon is trapped.
  */

bool Pokemon::IsTrapped() const {
  return flags_.trapped;
}

/**
  * @brief: A function that determines whether or not the Pokemon is using a
  * lock in move.
  * @return bool: Whether or not the Pokemon is using a lock in move.
  */

bool Pokemon::IsUsingLockInMove() const {
  return static_cast<bool>(flags_.num_turns_locked_in);
}

/**
  * @brief: A function that determines whether or not the Pokemon is resting.
  * @return bool: Whether or not the Pokemon is resting.
  */

bool Pokemon::IsResting() const {
  return flags_.status == StatusNames::kAsleepRest;
}

/**
  * @brief: A function that determines whether or not the Pokemon is asleep.
  * @return bool: Whether or not the Pokemon is asleep.
  */

bool Pokemon::IsAsleep() const {
  return flags_.status == StatusNames::kAsleep;
}

/**
  * @brief: A function that determines whether or not the Pokemon is confused.
  * @return bool: Whether or not the Pokemon is confused.
  */

bool Pokemon::IsConfused() const {
  return flags_.confusion.IsActive();
}

/**
  * @brief: A function that determines whether or not the Pokemon has a move
  * disabled.
  * @return bool: Whether or not the Pokemon has a move disabled.
  */

bool Pokemon::HasMoveDisabled() const {
  return flags_.disable.IsActive();
}

/**
  * @brief: A function that determines whether or not the Pokemon has a
  * substitute active.
  * @return bool: Whether or not the Pokemon has a substitute active.
  */

bool Pokemon::SubstituteIsActive() const {
  return flags_.substitute.IsActive();
}

/**
  * @brief: A function that determines whether or not the Pokemon is biding.
  * @return bool: Whether or not the Pokemon is biding.
  */

bool Pokemon::BideIsActive() const {
  return flags_.bide.IsActive();
}

/**
  * @brief: A function that returns the damage collected by bide.
  * @return int: The bide damage.
  */

int Pokemon::BideDamage() const {
  return flags_.bide.TotalDamage();
}

/**
  * @brief: A function that determines whether or not the Pokemon is frozen.
  * @return bool: Whether or not the Pokemon is frozen.
  */

bool Pokemon::IsFrozen() const {
  return flags_.status == StatusNames::kFrozen;
}

/**
  * @brief: A function that determines whether or not the Pokemon is paralyzed.
  * @return bool: Whether or not the Pokemon is paralyzed.
  */

bool Pokemon::IsParalyzed() const {
  return flags_.status == StatusNames::kParalyzed;
}

/**
  * @brief: A function that determines whether or not the Pokemon is fully
  * paralyzed.
  * @return bool: Whether or not the Pokemon is fully paralyzed.
  */

bool Pokemon::IsFullyParalyzed() const {
  return RandomIntDistribution(1, 100) <= 25;
}

/**
  * @brief: A function that determines whether or not the Pokemon is poisoned.
  * @return bool: Whether or not the Pokemon is poisoned.
  */

bool Pokemon::IsPoisoned() const {
  return flags_.status == StatusNames::kPoisoned;
}

/**
  * @brief: A function that determines whether or not the Pokemon is under
  * toxic.
  * @return bool: Whether or not the Pokemon is under toxic.
  */

bool Pokemon::IsUnderToxic() const {
  return flags_.status == StatusNames::kPoisonedToxic;
}

/**
  * @brief: A function that determines whether or not the Pokemon is burned.
  * @return bool: Whether or not the Pokemon is burned.
  */

bool Pokemon::IsBurned() const {
  return flags_.status == StatusNames::kBurned;
}

/**
  * @brief: A function that determines whether or not the Pokemon has a status.
  * @return bool: Whether or not the Pokemon has a status.
  */

bool Pokemon::HasStatus() const {
  return flags_.status != StatusNames::kClear;
}

/**
  * @brief: A function that determines whether or not the Pokemon can have a
  * move disabled.
  * @return bool: Whether or not the Pokemon can have a move disabled.
  */

bool Pokemon::CanHaveMoveDisabled() const {
  int num_valid_moves = 0;

  for (int i = 0; i < moves_container_.EndOfNormalMovesIndex(); i++) {
    if (!moves_container_[i]->IsDisabled() &&
        moves_container_[i]->CurrentPp()) {
      num_valid_moves++;
    }
  }

  return num_valid_moves > 1;
}

/**
  * @brief: A function that determines whether or not the Pokemon is fainted.
  * @return bool: Whether or not the Pokemon is fainted.
  */

bool Pokemon::IsFainted() const {
  return !static_cast<bool>(hp_stat_->CurrentHp());
}

/**
  * @brief: A function that determines whether or not the Pokemon is a given
  * type.
  * @param const TypeNames &type_name: The type to check.
  * @return bool: Whether or not the Pokemon is a given type.
  */

bool Pokemon::IsType(const TypeNames &type_name) const {
  return (type_name == type_container_.FirstType() &&
      type_container_.FirstType() != TypeNames::kNoType) ||
      (type_name == type_container_.SecondType() &&
          type_container_.SecondType() != TypeNames::kNoType);
}

/**
  * @brief: A function that makes the Pokemon use a vanish move.
  */

void Pokemon::UseVanishMove() {
  flags_.vanished = !flags_.vanished;
}

/**
  * @brief: A function that makes the Pokemon use focus energy.
  */

void Pokemon::UseFocusEnergy() {
  flags_.used_focus_energy = true;
}

/**
  * @brief: A function that makes the Pokemon flinch.
  */

void Pokemon::Flinch() {
  flags_.flinched = true;
}

/**
  * @brief: A function that makes the Pokemon use mimic.
  */

void Pokemon::UseMimic() {
  flags_.used_mimic = true;
}

/**
  * @brief: A function that makes the Pokemon use mimic.
  */

void Pokemon::UseMist() {
  flags_.under_mist = true;
}

/**
  * @brief: A function that makes the Pokemon use light screen.
  */

void Pokemon::UseLightScreen() {
  flags_.behind_light_screen = true;
}

/**
  * @brief: A function that makes the Pokemon use reflect.
  */

void Pokemon::UseReflect() {
  flags_.behind_reflect = true;
}

/**
  * @brief: A function that sets whether or not the Pokemon executed a move
  * successfully.
  * @param const bool &executed_move: The boolean to set.
  */

void Pokemon::SetExecutedMove(const bool &executed_move) {
  flags_.executed_move = executed_move;
}

/**
  * @brief: A function that applies leech seed to the Pokemon.
  */

void Pokemon::ApplyLeechSeed() {
  flags_.seeded = true;
}

/**
  * @brief: A function that makes the Pokemon use charge up move.
  */

void Pokemon::UseChargeUpMove() {
  flags_.charging_up = !flags_.charging_up;
}

/**
  * @brief: A function that sets whether or not the Pokemon is recharging.
  * @param const bool &recharging: The boolean to set.
  */

void Pokemon::SetRecharging(const bool &recharging) {
  flags_.recharging = recharging;
}

/**
  * @brief: A function that makes the Pokemon use rage.
  */

void Pokemon::UseRage() {
  flags_.raging = true;
}

/**
  * @brief: A function that makes the Pokemon use a trap move or get trapped.
  * @param const bool &user: Whether or not the Pokemon was the user of the
  * move.
  * @param const int &random_threshold: The random number of turns both
  * Pokemon are trapped for.
  */

void Pokemon::Trap(const bool &user, const int &random_threshold) {
  if (!flags_.num_turns_trapped) {
    if (user) {
      flags_.used_trap_move = true;
    } else {
      flags_.trapped = true;
      flags_.charging_up = false;
      flags_.raging = false;
      flags_.bide = Bide{};
    }

    flags_.num_turns_trapped = 1;
  } else if (flags_.num_turns_trapped == random_threshold ||
      flags_.num_turns_trapped == 5) {
    flags_.trapped = false;
    flags_.used_trap_move = false;
    flags_.num_turns_trapped = 0;
  } else {
    flags_.num_turns_trapped++;
  }
}

/**
  * @brief: A function that makes the Pokemon use a lock in move.
  */

void Pokemon::UseLockInMove() {
  if (!flags_.num_turns_locked_in) {
    flags_.num_turns_locked_in = 1;
  }

  if (flags_.num_turns_locked_in == RandomIntDistribution(2, 3) ||
      flags_.num_turns_locked_in == 3) {
    Confuse();
    flags_.num_turns_locked_in = 0;
  } else {
    flags_.num_turns_locked_in++;
  }
}

/**
  * @brief: A function that sets the index of mimic in the Pokemon's move
  * container.
  * @param const int &index_in_move_container: The index of mimic.
  */

void Pokemon::SetMimicIndex(const int &index_in_move_container) {
  flags_.mimic_index = index_in_move_container;
}

/**
  * @brief: A function that advances the toxic n factor.
  */

void Pokemon::AdvanceToxicFactor() {
  flags_.toxic_n_factor++;
}

/**
  * @brief: A function that advances the rest counter.
  */

void Pokemon::AdvanceRestCounter() {
  if (flags_.rest_counter++ == 3) {
    flags_.rest_counter = 1;
    flags_.status = StatusNames::kClear;
  }
}

/**
  * @brief: A function that advances the regular sleep counter.
  */

void Pokemon::AdvanceRegularSleepCounter() {
  if (flags_.turns_asleep++ == RandomIntDistribution(1, 7) ||
      flags_.turns_asleep == 7) {
    flags_.status = StatusNames::kClear;
  }
}

/**
  * @brief: A function that makes the Pokemon confused.
  */

void Pokemon::Confuse() {
  flags_.confusion.Activate();
}

/**
  * @brief: A function that handles the Pokemon's confusion.
  * @return bool: If the Pokemon will hit itself in confusion, it will return
  * false, otherwise it will return true.
  */

bool Pokemon::HandleConfusion() {
  if (RandomIntDistribution(1, 100) <= 50) {
    if (flags_.vanished) {
      flags_.vanished = false;
    }

    flags_.confusion.AdvanceOneTurn();
    return false;
  }

  flags_.confusion.AdvanceOneTurn();
  return true;
}

/**
  * @brief: A function that does confusion damage to the Pokemon.
  * @param const int &damage_done: The damage done.
  */

void Pokemon::DoConfusionDamage(const int &damage_done) {
  hp_stat_->SubtractHp(damage_done);
}

/**
  * @brief: A function that disables one of the Pokemon's moves.
  * @return MoveNames: The name of the disabled move. Used in a GUI function.
  */

MoveNames Pokemon::DisableMove() {
  std::shared_ptr<Move> disabled_move = moves_container_[RandomIntDistribution(
      0, moves_container_.EndOfNormalMovesIndex() - 1)];
  disabled_move->SetDisabled(true);
  flags_.disable.Activate();
  return disabled_move->MoveName();
}

/**
  * @brief: A function that handles the Pokemon's disable.
  */

void Pokemon::HandleDisable() {
  if (!flags_.disable.IsActive()) {
    ReEnableDisabledMove();
  } else {
    flags_.disable.AdvanceOneTurn();
  }
}

/**
  * @brief: A function that makes the Pokemon use a substitute.
  */

void Pokemon::UseSubstitute() {
  int damage_taken = hp_stat_->MaxHp() >> 2;
  flags_.substitute.Activate(damage_taken);
  hp_stat_->SubtractHp(damage_taken);
}

/**
  * @brief: A function that does damage to the Pokemon's substitute.
  * @param const int &damage_done: The damage done.
  */

void Pokemon::DoDamageToSubstitute(const int &damage_done) {
  flags_.substitute.TakeDamage(damage_done);
}

/**
  * @brief: A function that makes the Pokemon use transform.
  * @const std::shared_ptr<Pokemon> &target: The Pokemon that the current
  * Pokemon is transforming into.
  */

void Pokemon::Transform(const std::shared_ptr<Pokemon> &target) {
  flags_.before_transform_state = BeforeTransformState
      (normal_stats_container_, exclusive_in_game_stats_container_,
       type_container_, moves_container_, species_name_);
  normal_stats_container_ = target->GetNormalStatsContainer();
  exclusive_in_game_stats_container_ =
      target->GetExclusiveInGameStatsContainer();
  type_container_ = target->GetTypeContainer();
  moves_container_ = target->GetMovesContainer();
  species_name_ = target->SpeciesName();
  flags_.used_transform = true;
}

/**
  * @brief: A function that makes the Pokemon use bide.
  */

void Pokemon::UseBide() {
  flags_.bide.Activate();
}

/**
  * @brief: A function that determines whether or not bide will end.
  * @return bool: Whether or not bide will end.
  */

bool Pokemon::BideWillEnd() {
  return flags_.bide.IsActive() && flags_.bide.AdvanceOneTurn();
}

/**
  * @brief: A function that resets the Pokemon's bide.
  */

void Pokemon::ResetBide() {
  flags_.bide = Bide{};
}

/**
  * @brief: A function that sets the bide damage.
  * @param const int &damage: The damage to set.
  */

void Pokemon::SetBideDamage(const int &damage) {
  flags_.bide.SetDamageAdded(damage);
}

/**
  * @brief: A function that adds damage to bide.
  */

void Pokemon::AddDamageToBide() {
  flags_.bide.AddDamage();
}

/**
  * @brief: A function that burns the Pokemon.
  */

void Pokemon::ApplyBurn() {
  flags_.status = StatusNames::kBurned;
  flags_.old_attack_numerator =
      normal_stats_container_[StatNames::kAttack]->Numerator();
  flags_.old_attack_denominator =
      normal_stats_container_[StatNames::kAttack]->Denominator();
  ChangeStat(StatNames::kAttack, -2);
}

/**
  * @brief: A function that freezes the Pokemon.
  */

void Pokemon::ApplyFreeze() {
  flags_.status = StatusNames::kFrozen;
}

/**
  * @brief: A function that paralyzes the Pokemon.
  */

void Pokemon::ApplyParalysis() {
  flags_.status = StatusNames::kParalyzed;
  flags_.old_speed_numerator =
      normal_stats_container_[StatNames::kSpeed]->Numerator();
  flags_.old_speed_denominator =
      normal_stats_container_[StatNames::kSpeed]->Denominator();
  ChangeStat(StatNames::kSpeed, -6);
}

/**
  * @brief: A function that poisons the Pokemon.
  */

void Pokemon::ApplyPoison() {
  flags_.status = StatusNames::kPoisoned;
}

/**
  * @brief: A function that toxic poisons the Pokemon.
  */

void Pokemon::ApplyToxic() {
  flags_.status = StatusNames::kPoisonedToxic;
}

/**
  * @brief: A function that makes the Pokemon go to sleep.
  */

void Pokemon::ApplySleep() {
  flags_.status = StatusNames::kAsleep;
  flags_.turns_asleep = 1;
}

/**
  * @brief: A function that makes the Pokemon rest.
  */

void Pokemon::ApplyRestSleep() {
  RestoreStatsFromStatuses();
  flags_.status = StatusNames::kAsleepRest;
  hp_stat_->AddHp(hp_stat_->MaxHp());
}

/**
  * @brief: A function that makes the applies a status on the Pokemon.
  * @param const StatusNames &status_name: The status to apply.
  */

void Pokemon::ApplyStatus(const StatusNames &status_name) {
  switch (status_name) {
    case StatusNames::kBurned:
      ApplyBurn();
      break;
    case StatusNames::kFrozen:
      ApplyFreeze();
      break;
    case StatusNames::kParalyzed:
      ApplyParalysis();
      break;
    case StatusNames::kPoisoned:
      ApplyPoison();
      break;
    case StatusNames::kPoisonedToxic:
      ApplyToxic();
      break;
    case StatusNames::kAsleep:
      ApplySleep();
      break;
    case StatusNames::kAsleepRest:
      ApplyRestSleep();
      break;
    default:
      assert(false);
  }
}

/**
  * @brief: A function that does status damage to the Pokemon.
  * @return int: The damage done.
  */

int Pokemon::DoStatusDamage() {
  int damage_done = hp_stat_->MaxHp() >> 4;
  damage_done = !damage_done ? 1 : damage_done;
  damage_done = flags_.status == StatusNames::kPoisonedToxic ?
                flags_.toxic_n_factor * damage_done : damage_done;
  hp_stat_->SubtractHp(damage_done);
  return damage_done;
}

/**
  * @brief: A function that makes the Pokemon use conversion.
  */

void Pokemon::UseConversion() {
  TypeNames random_type = Type(
      moves_container_[RandomIntDistribution(
          0, moves_container_.EndOfNormalMovesIndex() - 1)]->MoveName());
  type_container_.ResetTypeFromConversion(random_type);
}

/**
  * @brief: A function that makes the Pokemon absorb hp.
  * @param const int &absorbed: The amount of hp absorbed.
  */

void Pokemon::AbsorbHp(const int &absorbed) {
  hp_stat_->AddHp(absorbed);
}

/**
  * @brief: A function that makes the Pokemon take recoil damage.
  * @param const int &recoil: The damage taken from recoil.
  */

void Pokemon::TakeRecoilDamage(const int &recoil) {
  hp_stat_->SubtractHp(recoil);
}

/**
  * @brief: A function that makes the Pokemon faint.
  */

void Pokemon::AutoFaint() {
  hp_stat_->SubtractAllHp();
}

/**
  * @brief: A function that makes the Pokemon use a metronome.
  */

void Pokemon::UseMetronome() {
  MoveNames random_move;

  while (true) {
    random_move = static_cast<MoveNames>(RandomIntDistribution(
        1, static_cast<int>(MoveNames::kPass) - 1));

    if (!moves_container_.SeenMove(random_move) &&
        random_move != MoveNames::kStruggle &&
        random_move != MoveNames::kMetronome && !IsLockIn(random_move) &&
        !IsChargeUp(random_move) && !IsVanish(random_move) &&
        !IsBinding(random_move) && random_move != MoveNames::kMimic) {
      break;
    }
  }

  move_used_ = std::make_shared<Move>(random_move, Pp(random_move));
}

/**
  * @brief: A function that makes the Pokemon recover half of its max hp.
  */

void Pokemon::RecoverHp() {
  hp_stat_->AddHp(hp_stat_->MaxHp() >> 1);
}

/**
  * @brief: A function that resets the Pokemon's necessary flags upon fainting.
  */

void Pokemon::ResetFaintFlags() {
  if (flags_.used_transform) {
    RestoreStateFromTransform();
  }

  flags_.used_transform = false;
  flags_.num_turns_trapped = 0;
  flags_.trapped = false;
  flags_.used_trap_move = false;
  flags_.vanished = false;
  flags_.raging = false;
}

/**
  * @brief: A function that resets the Pokemon's necessary flags upon hazing.
  */

void Pokemon::ResetFlagsFromHaze() {
  ResetStats();
  flags_.status = StatusNames::kClear;
  flags_.seeded = false;
  flags_.behind_light_screen = false;
  flags_.behind_reflect = false;
  flags_.confusion = Confusion{};
  flags_.toxic_n_factor = 1;
}

/**
  * @brief: A function that resets the Pokemon's necessary flags upon switching.
  */

void Pokemon::ResetSwitchFlags() {
  ResetStats();
  RestoreMimic();

  if (flags_.used_transform) {
    RestoreStateFromTransform();
  }

  flags_.used_transform = false;
  flags_.confusion = Confusion{};
  flags_.disable = Disable{};
  flags_.substitute = Substitute{};
  type_container_ = TypeContainer(species_name_);
  move_used_ = nullptr;
  flags_.used_focus_energy = false;
  flags_.executed_move = false;
  flags_.under_mist = false;
  flags_.behind_reflect = false;
  flags_.behind_light_screen = false;
  flags_.seeded = false;
  flags_.toxic_n_factor = 1;
}

/**
  * @brief: A function that resets the Pokemon's necessary flags upon end of
  * turn.
  */

void Pokemon::ResetEndOfTurnFlags() {
  flags_.flinched = false;

  if (move_used_) {
    move_used_->SetDamageDone(0);
  }
}

/**
  * @brief: A function that decrements the pp of the move used.
  * @param const MoveNames &move_name: The name of the move used.
  */

void Pokemon::DecrementPpOfMoveUsed(const MoveNames &move_name) {
  for (int i = 0; i < moves_container_.Size(); i++) {
    if (moves_container_[i]->MoveName() == move_name) {
      moves_container_[i]->DecrementPp(1);
    }
  }
}

/**
  * @brief: A function that sets the level of the Pokemon. Only used in the
  * deep copy.
  * @param const int &level: The level to set.
  */

void Pokemon::SetLevel(const int &level) {
  level_ = level;
}

/**
  * @brief: A function that sets the species name of the Pokemon. Only used in
  * the  deep copy.
  * @param const SpeciesNames &species_name: The species name to set.
  */

void Pokemon::SetSpeciesName(const SpeciesNames &species_name) {
  species_name_ = species_name;
}

/**
  * @brief: A function that sets the hp stat of the Pokemon. Only used in the
  * deep copy.
  * @param const Hp &hp_stat: The hp stat to set.
  */

void Pokemon::SetHpStat(const Hp &hp_stat) {
  hp_stat_ = std::make_shared<Hp>(hp_stat);
}

/**
  * @brief: A function that sets the normal stats container of the Pokemon.
  * Only used in the deep copy.
  * @param const NormalStatsContainer &normal_stats_container: The normal
  * stats container to set.
  */

void Pokemon::SetNormalStatsContainer(
    const NormalStatsContainer &normal_stats_container) {
  normal_stats_container_ = normal_stats_container;
}

/**
  * @brief: A function that sets the exclusive in game stats container of the
  * Pokemon. Only used in the deep copy.
  * @param const ExclusiveInGameStatsContainer
  * &exclusive_in_game_stats_container: The exclusive in game stats container
  * to set.
  */

void Pokemon::SetExclusiveInGameStatsContainer(
    const ExclusiveInGameStatsContainer &exclusive_in_game_stats_container) {
  exclusive_in_game_stats_container_ = exclusive_in_game_stats_container;
}

/**
  * @brief: A function that sets the moves container of the Pokemon. Only
  * used in the deep copy.
  * @param const MovesContainer &moves_container: The moves container to set.
  */

void Pokemon::SetMovesContainer(const MovesContainer &moves_container) {
  moves_container_ = moves_container;
}

/**
  * @brief: A function that sets the type container of the Pokemon. Only
  * used in the deep copy.
  * @param const TypeContainer &type_container: The type container to set.
  */

void Pokemon::SetTypeContainer(const TypeContainer &type_container) {
  type_container_ = type_container;
}

/**
  * @brief: A function that sets the flags of the Pokemon.  Only used in the
  * deep copy.
  * @param const InGameFlags &flags: The flags to set.
  */

void Pokemon::SetFlags(const InGameFlags &flags) {
  flags_ = flags.DeepCopy();
}

/**
  * @brief: A function that makes a deep copy of the object state.
  * @return Pokemon: The deep copy.
  */

Pokemon Pokemon::DeepCopy() const {
  Pokemon copy;
  copy.SetIsActive(is_active_);
  copy.SetLevel(level_);
  copy.SetSpeciesName(species_name_);
  copy.SetHpStat(*hp_stat_);

  if (move_used_) {
    copy.SetMoveUsed(*move_used_);
  } else {
    copy.SetMoveUsed(nullptr);
  }

  copy.SetNormalStatsContainer(normal_stats_container_.DeepCopy());
  copy.SetExclusiveInGameStatsContainer(
      exclusive_in_game_stats_container_.DeepCopy());
  copy.SetMovesContainer(moves_container_.DeepCopy());
  copy.SetTypeContainer(type_container_);
  copy.SetFlags(flags_.DeepCopy());
  return copy;
}

/**
  * @brief: A function that resets the stats of the Pokemon.
  */

void Pokemon::ResetStats() {
  for (int i = 0; i < kNumNormalStats; i++) {
    normal_stats_container_[static_cast<StatNames>(i)]->ResetStat();
  }

  for (int i = kNumNormalStats + 1;
       i <= kNumNormalStats + kNumExclusiveInGameStats; i++) {
    exclusive_in_game_stats_container_[static_cast<StatNames>(i)]->ResetStat();
  }
}

/**
  * @brief: A function that re-enables the move that was disabled.
  */

void Pokemon::ReEnableDisabledMove() {
  for (int i = 0; i < moves_container_.EndOfNormalMovesIndex(); i++) {
    if (moves_container_[i]->IsDisabled()) {
      moves_container_[i]->SetDisabled(false);
    }
  }
}

/**
  * @brief: A function that resets the state of mimic.
  */

void Pokemon::RestoreMimic() {
  if (flags_.used_mimic) {
    std::shared_ptr<Move> move_to_reset = moves_container_[flags_.mimic_index];
    move_to_reset->ResetMove(MoveNames::kMimic, move_to_reset->CurrentPp());
    flags_.used_mimic = false;
  }
}

/**
  * @brief: A function that restores the state before the Pokemon transformed.
  */

void Pokemon::RestoreStateFromTransform() {
  normal_stats_container_ =
      flags_.before_transform_state.GetNormalStatsContainer();
  exclusive_in_game_stats_container_ =
      flags_.before_transform_state.GetExclusiveInGameStatsContainer();
  type_container_ = flags_.before_transform_state.GetTypeContainer();
  moves_container_ = flags_.before_transform_state.GetMovesContainer();
  species_name_ = flags_.before_transform_state.SpeciesName();
}

/**
  * @brief: A function that restores the stats from statuses (burn and
  * paralysis).
  */

void Pokemon::RestoreStatsFromStatuses() {
  if (flags_.status == StatusNames::kBurned) {
    normal_stats_container_[
        StatNames::kAttack]->ResetStat(flags_.old_attack_numerator,
                                       flags_.old_attack_denominator);
  } else if (flags_.status == StatusNames::kParalyzed) {
    normal_stats_container_[
        StatNames::kSpeed]->ResetStat(flags_.old_speed_numerator,
                                      flags_.old_speed_denominator);
  }
}

} //namespace artificialtrainer