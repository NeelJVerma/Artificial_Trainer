//
// Created by neel on 1/23/19.
//

#include <iostream>
#include <random>
#include <cassert>
#include "pokemon.h"
#include "../clientelements/gui.h"
#include "../type/type.h"
#include "../move/pp.h"

namespace artificialtrainer {
Pokemon::Pokemon(const SpeciesNames &species_name,
                 const NormalStatsContainer &stats_container,
                 const MovesContainer &moves_container, const TypeContainer
                 &type_container, const int &level)
    : species_name_(species_name),
      normal_stats_container_(stats_container),
      exclusive_in_game_stats_container_{},
      moves_container_(moves_container),
      type_container_(type_container),
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
  if (stat_name == StatNames::kEvasion && flags_.under_mist) {
    Gui::DisplayIsUnderMistMessage(species_name_);
    return;
  }

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
  if (!ignore_mist && stat_name != StatNames::kEvasion && flags_.under_mist) {
    Gui::DisplayIsUnderMistMessage(species_name_);
    return;
  }

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
  num_stages < 0 ? LowerStat(stat_name,
                             num_stages,
                             (flags_.status == StatusNames::kBurned ||
                                 flags_.status == StatusNames::kParalyzed)) :
  RaiseStat(stat_name, num_stages);
}

void Pokemon::UseFocusEnergy() {
  flags_.used_focus_energy = true;
}

bool Pokemon::UsedFocusEnergy() const {
  return flags_.used_focus_energy;
}

void Pokemon::Flinch() {
  if (!SubstituteIsActive()) {
    flags_.flinched = true;
  }
}

bool Pokemon::IsFlinched() const {
  return flags_.flinched;
}

void Pokemon::Confuse() {
  if (!flags_.confusion.IsActive() && !SubstituteIsActive()) {
    flags_.confusion.Activate();
  }
}

void Pokemon::DisableMove() {
  if (SubstituteIsActive()) {
    Gui::DisplayMoveFailedMessage();
  } else {
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<>
        distribution(0, EndOfNormalMovesIndex() - 1);
    int random_index = distribution(generator);
    moves_container_[random_index]->SetDisabled(true);
    Gui::DisplayMoveDisabledMessage(moves_container_[random_index]->MoveName());
    flags_.disable.Activate();
  }
}

bool Pokemon::IsConfused() const {
  return flags_.confusion.IsActive();
}

void Pokemon::DoConfusionDamage(const int &damage_done) {
  SetMoveUsed(std::make_shared<Move>(
      MoveNames::kHitSelf, Pp(MoveNames::kHitSelf)));
  normal_stats_container_.HpStat()->SubtractHp(damage_done);
  Gui::DisplayDamageDoneMessage(damage_done);
}

void Pokemon::UseVanishMove() {
  if (!flags_.vanished) {
    flags_.vanished = true;
    Gui::DisplayPokemonVanishedMessage(species_name_);
  } else {
    flags_.vanished = false;
  }
}

bool Pokemon::IsVanished() const {
  return flags_.vanished;
}

int Pokemon::EndOfNormalMovesIndex() const {
  int end_normal_moves_index = 0;

  for (int i = 0; i < moves_container_.Size(); i++) {
    if (moves_container_[i]->MoveName() == MoveNames::kPass) {
      end_normal_moves_index = i;
      break;
    }
  }

  return end_normal_moves_index;
}

void Pokemon::UseConversion() {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<> distribution(0, EndOfNormalMovesIndex() - 1);
  TypeNames random_type = Type(
      moves_container_[distribution(generator)]->MoveName());
  type_container_.ResetTypeFromConversion(random_type);
}

bool Pokemon::HandleConfusion() {
  StatusNames status = flags_.status;

  if (!flags_.confusion.IsActive() || status == StatusNames::kAsleepRest ||
      status == StatusNames::kAsleep || status == StatusNames::kFrozen) {
    return true;
  }

  Gui::DisplayConfusedMessage(species_name_);

  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<> distribution(1, 100);

  if (distribution(generator) <= 50) {
    if (flags_.vanished) {
      flags_.vanished = false;
    }

    Gui::DisplayHitSelfMessage(species_name_);
    flags_.confusion.AdvanceOneTurn();
    return false;
  }

  flags_.confusion.AdvanceOneTurn();
  return true;
}

void Pokemon::ReEnableDisabledMove() {
  for (int i = 0; i < EndOfNormalMovesIndex(); i++) {
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

void Pokemon::AbsorbHp(const int &damage_done) {
  int absored = damage_done >> 1;
  absored = !absored ? 1 : absored;
  normal_stats_container_.HpStat()->AddHp(absored);
  Gui::DisplayHpAbsorbedMessage(species_name_, absored);
}

void Pokemon::TakeRecoilDamage(const int &damage_done) {
  int recoil_damage = damage_done >> 2;
  recoil_damage = !recoil_damage ? 1 : recoil_damage;
  normal_stats_container_.HpStat()->SubtractHp(recoil_damage);
  Gui::DisplayRecoilDamageMessage(species_name_, recoil_damage);
}

void Pokemon::AutoFaint() {
  normal_stats_container_.HpStat()->SubtractAllHp();
}

void Pokemon::UseMetronome() {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<> distribution(1, static_cast<int>(
      MoveNames::kPass) - 1);
  MoveNames random_move;

  while (true) {
    random_move = static_cast<MoveNames>(distribution(generator));

    if (!moves_container_.SeenMove(random_move) &&
        random_move != MoveNames::kStruggle &&
        random_move != MoveNames::kMetronome) {
      break;
    }
  }

  move_used_ = std::make_shared<Move>(random_move, Pp(random_move));
  Gui::DisplayPokemonUsedMoveMessage(species_name_, random_move);
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
  if (flags_.under_mist) {
    Gui::DisplayMoveFailedMessage();
  } else {
    flags_.under_mist = true;
    Gui::DisplayMistStartedMessage(species_name_);
  }
}

void Pokemon::RecoverHp() {
  std::shared_ptr<Hp> hp = normal_stats_container_.HpStat();
  int max_minus_current = hp->MaxHp() - hp->CurrentHp();

  if (max_minus_current == 255 || max_minus_current == 511 ||
      hp->CurrentHp() == hp->MaxHp()) {
    Gui::DisplayMoveFailedMessage();
  } else {
    hp->AddHp(hp->MaxHp() >> 1);
  }
}

void Pokemon::UseLightScreen() {
  if (flags_.behind_light_screen) {
    Gui::DisplayMoveFailedMessage();
  } else {
    flags_.behind_light_screen = true;
  }
}

bool Pokemon::IsBehindLightScreen() const {
  return flags_.behind_light_screen;
}

void Pokemon::UseReflect() {
  if (flags_.behind_reflect) {
    Gui::DisplayMoveFailedMessage();
  } else {
    flags_.behind_reflect = true;
  }
}

bool Pokemon::IsBehindReflect() const {
  return flags_.behind_reflect;
}

void Pokemon::UseSubstitute() {
  std::shared_ptr<Hp> hp_stat = normal_stats_container_.HpStat();

  if (flags_.substitute.IsActive() || hp_stat->HpAsPercent() <= 25.0) {
    Gui::DisplayMoveFailedMessage();
  } else {
    int damage_taken = hp_stat->MaxHp() >> 2;
    flags_.substitute.Activate(damage_taken);
    hp_stat->SubtractHp(damage_taken);
    Gui::DisplayIsBehindSubstituteMessage(species_name_);
  }
}

bool Pokemon::SubstituteIsActive() const {
  return flags_.substitute.IsActive();
}

void Pokemon::DoDamageToSubstitute(const int &damage_done) {
  int sub_current_hp = flags_.substitute.CurrentHp();
  Gui::DisplaySubstituteTooKDamageMessage(damage_done);

  if (sub_current_hp - damage_done <= 0) {
    flags_.substitute.TakeDamage(sub_current_hp);
    Gui::DisplaySubstituteFadedMessage(species_name_);
  } else {
    flags_.substitute.TakeDamage(damage_done);
  }
}

bool Pokemon::IsBurned() const {
  return flags_.status == StatusNames::kBurned;
}

void Pokemon::ApplyBurn() {
  if (!IsType(TypeNames::kFire)) {
    flags_.status = StatusNames::kBurned;
    flags_.old_attack_numerator =
        normal_stats_container_[StatNames::kAttack]->Numerator();
    flags_.old_attack_denominator =
        normal_stats_container_[StatNames::kAttack]->Denominator();
    ChangeStat(StatNames::kAttack, -2);
    Gui::DisplayBurnStartedMessage(species_name_);
  }
}

void Pokemon::ApplyFreeze() {
  if (!IsType(TypeNames::kIce)) {
    flags_.status = StatusNames::kFrozen;
    Gui::DisplayFreezeStartedMessage(species_name_);
  }
}

void Pokemon::ApplyParalysis() {
  if (!IsType(TypeNames::kElectric)) {
    flags_.status = StatusNames::kParalyzed;
    flags_.old_speed_numerator =
        normal_stats_container_[StatNames::kSpeed]->Numerator();
    flags_.old_speed_denominator =
        normal_stats_container_[StatNames::kSpeed]->Denominator();
    ChangeStat(StatNames::kSpeed, -6);
    Gui::DisplayParalysisStartedMessage(species_name_);
  }
}

bool Pokemon::IsParalyzed() const {
  return flags_.status == StatusNames::kParalyzed;
}

bool Pokemon::IsFullyParalyzed() const {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<> distribution(1, 100);
  return distribution(generator) <= 25;
}

void Pokemon::ApplyPoison() {
  if (!IsType(TypeNames::kPoison)) {
    flags_.status = StatusNames::kPoisoned;
    Gui::DisplayPoisonStartedMessage(species_name_, false);
  }
}

void Pokemon::ApplyToxic() {
  if (!IsType(TypeNames::kPoison)) {
    flags_.status = StatusNames::kPoisonedToxic;
    Gui::DisplayPoisonStartedMessage(species_name_, true);
  }
}

void Pokemon::ApplySleep() {
  flags_.status = StatusNames::kAsleep;
  flags_.turns_asleep = 1;
  Gui::DisplaySleepStartedMessage(species_name_);
}

void Pokemon::AdvanceRegularSleepCounter() {
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<> distribution(1, 7);

  if (flags_.turns_asleep == distribution(generator) ||
      flags_.turns_asleep == 7) {
    Gui::DisplayWokeUpMessage(species_name_);
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
  std::shared_ptr<Hp> hp = normal_stats_container_.HpStat();
  int max_minus_current = hp->MaxHp() - hp->CurrentHp();

  if (max_minus_current == 255 || max_minus_current == 511 ||
      hp->CurrentHp() == hp->MaxHp()) {
    Gui::DisplayMoveFailedMessage();
  } else {
    RestoreStatsFromStatuses();
    flags_.status = StatusNames::kAsleepRest;
    hp->AddHp(hp->MaxHp());
    Gui::DisplaySleepStartedMessage(species_name_);
    Gui::DisplayRecoveredAllHpMessage(species_name_);
  }
}

bool Pokemon::IsAsleep() const {
  return flags_.status == StatusNames::kAsleep;
}

bool Pokemon::IsResting() const {
  return flags_.status == StatusNames::kAsleepRest;
}

void Pokemon::AdvanceRestCounter() {
  if (flags_.rest_counter++ == 3) {
    Gui::DisplayWokeUpMessage(species_name_);
    flags_.rest_counter = 1;
    flags_.status = StatusNames::kClear;
  }
}

void Pokemon::ApplyStatus(const StatusNames &status_name) {
  if (flags_.status != StatusNames::kClear || SubstituteIsActive()) {
    return;
  }

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
  std::shared_ptr<Hp> hp_stat = normal_stats_container_.HpStat();
  int damage_done = hp_stat->MaxHp() >> 4;
  damage_done = !damage_done ? 1 : damage_done;
  damage_done = flags_.status == StatusNames::kPoisonedToxic ?
                flags_.toxic_n_factor * damage_done : damage_done;
  hp_stat->SubtractHp(damage_done);
  return damage_done;
}

void Pokemon::DoBurnDamage() {
  Gui::DisplayIsBurnedMessage(species_name_);
  Gui::DisplayTookBurnDamageMessage(species_name_,
                                    DoStatusDamage());
}

void Pokemon::ApplyLeechSeed() {
  if (IsType(TypeNames::kGrass) || flags_.seeded || SubstituteIsActive() ||
      flags_.seeded) {
    Gui::DisplayMoveFailedMessage();
  } else {
    flags_.seeded = true;
    Gui::DisplayLeechSeedStartedMessage(species_name_);
  }
}

bool Pokemon::IsSeeded() const {
  return flags_.seeded;
}

int Pokemon::DoLeechSeedDamage() {
  Gui::DisplayIsSeededMessage(species_name_);
  int sapped = DoStatusDamage();
  Gui::DisplayHadHpSappedMessage(species_name_, sapped);
  return sapped;
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

void Pokemon::DoPoisonDamage() {
  Gui::DisplayIsPoisonedMessage(species_name_, false);
  Gui::DisplayTookPoisonDamageMessage(species_name_,
                                      DoStatusDamage());
}

bool Pokemon::IsUnderToxic() const {
  return flags_.status == StatusNames::kPoisonedToxic;
}

void Pokemon::DoToxicDamage() {
  Gui::DisplayIsPoisonedMessage(species_name_, true);
  Gui::DisplayTookPoisonDamageMessage(species_name_,
                                      DoStatusDamage());
  flags_.toxic_n_factor++;
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