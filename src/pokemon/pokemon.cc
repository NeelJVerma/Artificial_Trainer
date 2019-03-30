//
// Created by neel on 1/23/19.
//

#include <cassert>
#include "pokemon.h"
#include "../type/type.h"
#include "../move/pp.h"
#include "../random/randomgenerator.h"

namespace artificialtrainer {
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
}

Pokemon::Pokemon() : species_name_(SpeciesNames::kBulbasaur),
                     normal_stats_container_{},
                     exclusive_in_game_stats_container_{},
                     moves_container_{},
                     type_container_{},
                     move_used_(nullptr),
                     level_(0),
                     is_active_(false) {
}

NormalStatsContainer Pokemon::GetNormalStatsContainer() const {
  return normal_stats_container_;
}

ExclusiveInGameStatsContainer Pokemon::
GetExclusiveInGameStatsContainer() const {
  return exclusive_in_game_stats_container_;
}

MovesContainer Pokemon::GetMovesContainer() const {
  return moves_container_;
}

TypeContainer Pokemon::GetTypeContainer() const {
  return type_container_;
}

SpeciesNames Pokemon::SpeciesName() const {
  return species_name_;
}

int Pokemon::Level() const {
  return level_;
}

bool Pokemon::IsActive() const {
  return is_active_;
}

void Pokemon::SetIsActive(const bool &is_active) {
  is_active_ = is_active;
}

void Pokemon::SetMoveUsed(const int &index) {
  move_used_ = moves_container_[index];
}

void Pokemon::SetMoveUsed(const std::shared_ptr<Move> &move) {
  move_used_ = move;
}

std::shared_ptr<Move> Pokemon::MoveUsed() const {
  return move_used_;
}

void Pokemon::ResetStats() {
  for (int i = 0; i < kNumNormalStats; i++) {
    normal_stats_container_[static_cast<StatNames>(i)]->ResetStat();
  }

  for (int i = kNumNormalStats + 1;
       i <= kNumNormalStats + kNumExclusiveInGameStats; i++) {
    exclusive_in_game_stats_container_[static_cast<StatNames>(i)]->ResetStat();
  }
}

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

void Pokemon::ChangeStat(const StatNames &stat_name,
                         const int &num_stages) {
  num_stages < 0 ? LowerStat(stat_name, num_stages,
                             (flags_.status == StatusNames::kBurned ||
                                 flags_.status == StatusNames::kParalyzed))
                 : RaiseStat(stat_name, num_stages);
}

void Pokemon::UseFocusEnergy() {
  flags_.used_focus_energy = true;
}

bool Pokemon::UsedFocusEnergy() const {
  return flags_.used_focus_energy;
}

void Pokemon::Flinch() {
  flags_.flinched = true;
}

bool Pokemon::IsFlinched() const {
  return flags_.flinched;
}

void Pokemon::Confuse() {
  flags_.confusion.Activate();
}

void Pokemon::DisableMove(const int &disable_index) {
  moves_container_[disable_index]->SetDisabled(true);
  flags_.disable.Activate();
}

bool Pokemon::IsConfused() const {
  return flags_.confusion.IsActive();
}

void Pokemon::DoConfusionDamage(const int &damage_done) {
  SetMoveUsed(std::make_shared<Move>(
      MoveNames::kHitSelf, Pp(MoveNames::kHitSelf)));
  hp_stat_->SubtractHp(damage_done);
}

void Pokemon::UseVanishMove() {
  flags_.vanished = !flags_.vanished;
}

bool Pokemon::IsVanished() const {
  return flags_.vanished;
}

void Pokemon::UseChargeUpMove() {
  flags_.charging_up = !flags_.charging_up;
}

bool Pokemon::IsChargingUp() const {
  return flags_.charging_up;
}

void Pokemon::UseConversion() {
  TypeNames random_type = Type(
      moves_container_[RandomIntDistribution(
          0, moves_container_.EndOfNormalMovesIndex() - 1)]->MoveName());
  type_container_.ResetTypeFromConversion(random_type);
}

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

void Pokemon::ReEnableDisabledMove() {
  for (int i = 0; i < moves_container_.EndOfNormalMovesIndex(); i++) {
    if (moves_container_[i]->IsDisabled()) {
      moves_container_[i]->SetDisabled(false);
    }
  }
}

void Pokemon::HandleDisable() {
  if (!flags_.disable.IsActive()) {
    ReEnableDisabledMove();
  } else {
    flags_.disable.AdvanceOneTurn();
  }
}

bool Pokemon::HasMoveDisabled() const {
  return flags_.disable.IsActive();
}

void Pokemon::AbsorbHp(const int &absorbed) {
  hp_stat_->AddHp(absorbed);
}

void Pokemon::TakeRecoilDamage(const int &recoil) {
  hp_stat_->SubtractHp(recoil);
}

void Pokemon::AutoFaint() {
  hp_stat_->SubtractAllHp();
}

void Pokemon::UseMetronome() {
  MoveNames random_move;

  while (true) {
    random_move = static_cast<MoveNames>(RandomIntDistribution(
        1, static_cast<int>(MoveNames::kPass) - 1));

    if (!moves_container_.SeenMove(random_move) &&
        random_move != MoveNames::kStruggle &&
        random_move != MoveNames::kMetronome) {
      break;
    }
  }

  move_used_ = std::make_shared<Move>(random_move, Pp(random_move));
}

bool Pokemon::IsType(const TypeNames &type_name) const {
  bool matches_first = type_name == type_container_.FirstType() &&
      type_container_.FirstType() != TypeNames::kNoType;
  bool matches_second = type_name == type_container_.SecondType() &&
      type_container_.SecondType() != TypeNames::kNoType;
  return matches_first || matches_second;
}

void Pokemon::UseMimic() {
  flags_.used_mimic = true;
}

void Pokemon::SetMimicIndex(const int &index_in_move_container) {
  flags_.mimic_index = index_in_move_container;
}

void Pokemon::RestoreMimic() {
  if (flags_.used_mimic) {
    std::shared_ptr<Move> move_to_reset = moves_container_[flags_.mimic_index];
    move_to_reset->ResetMove(MoveNames::kMimic, move_to_reset->CurrentPp());
    flags_.used_mimic = false;
  }
}

void Pokemon::SetExecutedMove(const bool &executed_move) {
  flags_.executed_move = executed_move;
}

bool Pokemon::ExecutedMove() const {
  return flags_.executed_move;
}

void Pokemon::UseMist() {
  flags_.under_mist = true;
}

bool Pokemon::IsUnderMist() const {
  return flags_.under_mist;
}

void Pokemon::RecoverHp() {
  hp_stat_->AddHp(hp_stat_->MaxHp() >> 1);
}

void Pokemon::UseLightScreen() {
  flags_.behind_light_screen = true;
}

bool Pokemon::IsBehindLightScreen() const {
  return flags_.behind_light_screen;
}

void Pokemon::UseReflect() {
  flags_.behind_reflect = true;
}

bool Pokemon::IsBehindReflect() const {
  return flags_.behind_reflect;
}

void Pokemon::UseSubstitute() {
  int damage_taken = hp_stat_->MaxHp() >> 2;
  flags_.substitute.Activate(damage_taken);
  hp_stat_->SubtractHp(damage_taken);
}

bool Pokemon::SubstituteIsActive() const {
  return flags_.substitute.IsActive();
}

void Pokemon::DoDamageToSubstitute(const int &damage_done) {
  flags_.substitute.TakeDamage(damage_done);
}

bool Pokemon::IsBurned() const {
  return flags_.status == StatusNames::kBurned;
}

void Pokemon::ApplyBurn() {
  flags_.status = StatusNames::kBurned;
  flags_.old_attack_numerator =
      normal_stats_container_[StatNames::kAttack]->Numerator();
  flags_.old_attack_denominator =
      normal_stats_container_[StatNames::kAttack]->Denominator();
  ChangeStat(StatNames::kAttack, -2);
}

void Pokemon::ApplyFreeze() {
  flags_.status = StatusNames::kFrozen;
}

void Pokemon::ApplyParalysis() {
  flags_.status = StatusNames::kParalyzed;
  flags_.old_speed_numerator =
      normal_stats_container_[StatNames::kSpeed]->Numerator();
  flags_.old_speed_denominator =
      normal_stats_container_[StatNames::kSpeed]->Denominator();
  ChangeStat(StatNames::kSpeed, -6);
}

bool Pokemon::IsParalyzed() const {
  return flags_.status == StatusNames::kParalyzed;
}

bool Pokemon::IsFullyParalyzed() const {
  return RandomIntDistribution(1, 100) <= 25;
}

void Pokemon::ApplyPoison() {
  flags_.status = StatusNames::kPoisoned;
}

void Pokemon::ApplyToxic() {
  flags_.status = StatusNames::kPoisonedToxic;
}

void Pokemon::ApplySleep() {
  flags_.status = StatusNames::kAsleep;
  flags_.turns_asleep = 1;
}

void Pokemon::AdvanceRegularSleepCounter() {
  if (flags_.turns_asleep == RandomIntDistribution(1, 7) ||
      flags_.turns_asleep == 7) {
    flags_.status = StatusNames::kClear;
  }
}

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

void Pokemon::ApplyRestSleep() {
  RestoreStatsFromStatuses();
  flags_.status = StatusNames::kAsleepRest;
  hp_stat_->AddHp(hp_stat_->MaxHp());
}

bool Pokemon::IsAsleep() const {
  return flags_.status == StatusNames::kAsleep;
}

bool Pokemon::IsResting() const {
  return flags_.status == StatusNames::kAsleepRest;
}

void Pokemon::AdvanceRestCounter() {
  if (flags_.rest_counter++ == 3) {
    flags_.rest_counter = 1;
    flags_.status = StatusNames::kClear;
  }
}

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

int Pokemon::DoStatusDamage() {
  int damage_done = hp_stat_->MaxHp() >> 4;
  damage_done = !damage_done ? 1 : damage_done;
  damage_done = flags_.status == StatusNames::kPoisonedToxic ?
                flags_.toxic_n_factor * damage_done : damage_done;
  hp_stat_->SubtractHp(damage_done);
  return damage_done;
}

void Pokemon::ApplyLeechSeed() {
  flags_.seeded = true;
}

bool Pokemon::IsSeeded() const {
  return flags_.seeded;
}

bool Pokemon::IsFrozen() const {
  return flags_.status == StatusNames::kFrozen;
}

bool Pokemon::HasStatus() const {
  return flags_.status != StatusNames::kClear;
}

bool Pokemon::IsPoisoned() const {
  return flags_.status == StatusNames::kPoisoned;
}

bool Pokemon::IsUnderToxic() const {
  return flags_.status == StatusNames::kPoisonedToxic;
}

void Pokemon::AdvanceToxicFactor() {
  flags_.toxic_n_factor++;
}

void Pokemon::SetRecharging(const bool &recharging) {
  flags_.recharging = recharging;
}

bool Pokemon::IsRecharging() const {
  return flags_.recharging;
}

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

bool Pokemon::IsUsingLockInMove() const {
  return static_cast<bool>(flags_.num_turns_locked_in);
}

void Pokemon::UseRage() {
  flags_.raging = true;
}

bool Pokemon::IsRaging() const {
  return flags_.raging;
}

void Pokemon::Trap(const bool &user, const int &random_threshold) {
  if (!flags_.num_turns_trapped) {
    if (user) {
      flags_.used_trap_move = true;
    } else {
      flags_.trapped = true;
    }

    flags_.num_turns_trapped = 1;
  }

  if (flags_.num_turns_trapped == random_threshold ||
      flags_.num_turns_trapped == 5) {
    flags_.trapped = false;
    flags_.used_trap_move = false;
    flags_.num_turns_trapped = 0;
  } else {
    flags_.num_turns_trapped++;
  }
}

bool Pokemon::UsedTrapMove() const {
  return flags_.used_trap_move;
}

bool Pokemon::IsTrapped() const {
  return flags_.trapped;
}

std::shared_ptr<Hp> Pokemon::HpStat() const {
  return hp_stat_;
}

void Pokemon::RestoreStateFromTransform() {
  normal_stats_container_ =
      flags_.before_transform_state.GetNormalStatsContainer();
  exclusive_in_game_stats_container_ =
      flags_.before_transform_state.GetExclusiveInGameStatsContainer();
  type_container_ = flags_.before_transform_state.GetTypeContainer();
  moves_container_ = flags_.before_transform_state.GetMovesContainer();
  species_name_ = flags_.before_transform_state.SpeciesName();
}

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
}

void Pokemon::UseBide() {
  flags_.bide.Activate();
}

bool Pokemon::BideWillEnd() {
  return flags_.bide.IsActive() && flags_.bide.AdvanceOneTurn();
}

bool Pokemon::BideIsActive() const {
  return flags_.bide.IsActive();
}

int Pokemon::BideDamage() const {
  return flags_.bide.TotalDamage();
}

void Pokemon::ResetBide() {
  flags_.bide = Bide{};
}

void Pokemon::SetBideDamage(const int &damage) {
  flags_.bide.SetDamageAdded(damage);
}

void Pokemon::AddDamageToBide() {
  flags_.bide.AddDamage();
}

bool Pokemon::MustUseStruggle() const {
  for (int i = 0; i < moves_container_.Size(); i++) {
    if (moves_container_[i]->CurrentPp()) {
      return false;
    }
  }

  return true;
}

bool Pokemon::CanHaveMoveDisabled() const {
  int num_valid_moves = 0;

  for (int i = 0; i < moves_container_.Size(); i++) {
    if (!moves_container_[i]->IsDisabled() &&
        moves_container_[i]->CurrentPp()) {
      num_valid_moves++;
    }
  }

  return num_valid_moves > 1;
}

void Pokemon::ResetFaintFlags() {
  RestoreStateFromTransform();
  flags_.num_turns_trapped = 0;
  flags_.trapped = false;
  flags_.used_trap_move = false;
  flags_.vanished = false;
  flags_.raging = false;
}

void Pokemon::ResetFlagsFromHaze() {
  ResetStats();
  flags_.status = StatusNames::kClear;
  flags_.seeded = false;
  flags_.behind_light_screen = false;
  flags_.behind_reflect = false;
  flags_.confusion = Confusion{};
  flags_.toxic_n_factor = 1;
}

void Pokemon::ResetEndOfTurnFlags() {
  flags_.flinched = false;
  move_used_->SetDamageDone(0);
}

void Pokemon::ResetSwitchFlags() {
  ResetStats();
  RestoreMimic();
  RestoreStateFromTransform();
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

} //namespace artificialtrainer