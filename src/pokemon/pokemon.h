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

namespace artificialtrainer {
struct InGameFlags {
  bool vanished = false;
  bool used_focus_energy = false;
  bool flinched = false;
  bool used_mimic = false;
  int mimic_index = 0;
  bool under_mist = false;
  bool behind_light_screen = false;
  bool behind_reflect = false;
  bool executed_move = false;
  Confusion confusion{};
  Disable disable{};
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
  void SetUsedFocusEnergy(const bool &used_focus_energy);
  bool UsedFocusEnergy() const;
  void SetFlinched(const bool &flinched);
  bool IsFlinched() const;
  void Confuse();
  bool IsConfused() const;
  void DisableMove();
  bool HasMoveDisabled() const;
  void SetVanished(const bool &vanished);
  bool IsVanished() const;
  bool HandleConfusion();
  void HandleDisable();
  void UseConversion();
  void AbsorbHp(const int &damage_done);
  void TakeRecoilDamage(const int &damage_done);
  void AutoFaint();
  void UseMetronome();
  bool IsTyoe(const TypeNames &type_name) const;
  int EndOfNormalMovesIndex() const;
  void SetUsedMimic(const bool &used_mimic);
  void SetMimicIndex(const int& index_in_move_container);
  void SetExecutedMove(const bool &executed_move);
  bool ExecutedMove() const;
  void SetUnderMist(const bool &under_mist);
  void SetBehindLightScreen(const bool &behind_light_screen);
  bool IsBehindLightScreen() const;
  void SetBehindReflect(const bool &behind_reflect);
  bool IsBehindReflect() const;
  void RecoverHp();
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
