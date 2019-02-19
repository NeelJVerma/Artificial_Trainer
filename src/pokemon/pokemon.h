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
  bool burned = false;
  bool statused = false;
  int old_attack_stat = 0;
  int mimic_index = 0;
  Confusion confusion{};
  Disable disable{};
  Substitute substitute{};
};

class Pokemon {
 public:
  static const int kMaxLevel = 100;

  Pokemon(const Pokemon &pokemon) = default;
  Pokemon &operator=(const Pokemon &pokemon) = default;
  Pokemon();
  Pokemon(const SpeciesNames &species_name,
          const NormalStatsContainer &stats_container,
          const MovesContainer &moves_container,
          const TypeContainer &type_container, const int &level);
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
  void DisableMove();
  void SetVanished(const bool &vanished);
  bool IsVanished() const;
  bool HandleConfusion();
  void DoConfusionDamage(const int &damage_done);
  void HandleDisable();
  void UseConversion();
  void AbsorbHp(const int &damage_done);
  void TakeRecoilDamage(const int &damage_done);
  void AutoFaint();
  void UseMetronome();
  bool IsType(const TypeNames &type_name) const;
  int EndOfNormalMovesIndex() const;
  void UseMimic();
  void SetMimicIndex(const int& index_in_move_container);
  void SetExecutedMove(const bool &executed_move);
  bool ExecutedMove() const;
  void UseMist();
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
  bool IsStatused() const;
  void DoBurnDamage();
  void ResetSwitchFlags();
  void ResetEndOfTurnFlags();

 private:
  NormalStatsContainer normal_stats_container_;
  ExclusiveInGameStatsContainer exclusive_in_game_stats_container_;
  MovesContainer moves_container_;
  std::shared_ptr<Move> move_used_;
  TypeContainer type_container_;
  SpeciesNames species_name_;
  InGameFlags flags_;
  int level_;
  bool is_active_;
  void LowerStat(const StatNames &stat_name, const int &num_stages);
  void RaiseStat(const StatNames &stat_name, const int &num_stages);
  void ResetStats();
  void ReEnableDisabledMove();
  void RestoreMimic();
};

} //namespace artificialtrainer

#endif //ARTIFICIAL_TRAINER_POKEMON_H
