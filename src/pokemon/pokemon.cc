//
// Created by neel on 1/23/19.
//

#include <iostream>
#include <random>
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
  num_stages < 0 ? LowerStat(stat_name, num_stages, flags_.burned) :
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
  flags_.confusion.Activate();
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

void Pokemon::SetVanished(const bool &vanished) {
  flags_.vanished = vanished;
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
  // TODO: IF POKEMON IS RECHARGING OR STATUS PREVENTS THEM FROM ATTACKING,
  //  RETURN TRUE
  if (!flags_.confusion.IsActive()) {
    return true;
  }

  Gui::DisplayConfusedMessage(species_name_);

  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<> distribution(1, 100);

  if (distribution(generator) <= 50) {
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
  return flags_.burned;
}

void Pokemon::ApplyBurn() {
  if (!IsType(TypeNames::kFire)) {
    flags_.burned = true;
    flags_.statused = true;
    flags_.old_attack_stat =
        normal_stats_container_[StatNames::kAttack]->InGameStat();
    ChangeStat(StatNames::kAttack, -2);
    Gui::DisplayBurnStartedMessage(species_name_);
  }
}

void Pokemon::ApplyStatus(const StatusNames &status_name) {
  switch (status_name) {
    case StatusNames::kBurned:
      ApplyBurn();
      break;
    default:
      break;
  }
}

bool Pokemon::IsStatused() const {
  return flags_.statused;
}

int Pokemon::DoOneSixteenthStatusDamage() {
  std::shared_ptr<Hp> hp_stat = normal_stats_container_.HpStat();
  int damage_done = hp_stat->MaxHp() >> 4;
  damage_done = !damage_done ? 1 : damage_done;
  hp_stat->SubtractHp(damage_done);
  return damage_done;
}

void Pokemon::DoBurnDamage() {
  Gui::DisplayIsBurnedMessage(species_name_);
  Gui::DisplayTookBurnDamageMessage(species_name_,
                                    DoOneSixteenthStatusDamage());
}

void Pokemon::ApplyLeechSeed() {
  if (IsType(TypeNames::kGrass) || flags_.seeded || SubstituteIsActive()) {
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
  int sapped = DoOneSixteenthStatusDamage();
  Gui::DisplayHadHpSappedMessage(species_name_, sapped);
  return sapped;
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
  flags_.used_focus_energy = false;
  flags_.executed_move = false;
  flags_.under_mist = false;
  flags_.behind_reflect = false;
  flags_.behind_light_screen = false;
}

} //namespace artificialtrainer