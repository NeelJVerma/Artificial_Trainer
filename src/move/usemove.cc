//
// Created by neel on 2/6/19.
//

#include <cmath>
#include <cassert>
#include "usemove.h"
#include "../stringconverter/stringconverter.h"
#include "baseaccuracy.h"
#include "basepower.h"
#include "../clientelements/gui.h"
#include "../type/effectiveness.h"
#include "pp.h"
#include "../random/randomgenerator.h"

namespace artificialtrainer {
namespace {
double ChanceToHit(const std::shared_ptr<Pokemon> &attacker,
                   const std::shared_ptr<Pokemon> &defender) {
  std::shared_ptr<Move> move_used = attacker->MoveUsed();

  if (BaseAccuracy(move_used->MoveName()) == kNeverMiss) {
    return (move_used->MoveName() == MoveNames::kSwift ? (255.0 / 256) * 100 :
            100.0);
  }

  ExclusiveInGameStatsContainer attacker_stats =
      attacker->GetExclusiveInGameStatsContainer();
  ExclusiveInGameStatsContainer defender_stats =
      defender->GetExclusiveInGameStatsContainer();
  double chance = static_cast<double>(BaseAccuracy(move_used->MoveName())) *
      (attacker_stats[StatNames::kAccuracy]->CalculatedStat() /
          defender_stats[StatNames::kEvasion]->CalculatedStat());

  return chance > 100.0 ? 100.0 : chance;
}

double TypeProduct(const std::shared_ptr<Move> &move_used,
                   const std::shared_ptr<Pokemon> &defender) {
  TypeNames move_type = Type(move_used->MoveName());
  TypeContainer defender_types = defender->GetTypeContainer();
  return Effectiveness(move_type, defender_types.FirstType()) *
      Effectiveness(move_type, defender_types.SecondType()) * 10;
}

bool MoveCrit(const double &crit_chance) {
  return RandomRealDistribution(0.0, 1.0) <= crit_chance;
}

bool MoveHit(const double &chance_to_hit) {
  return RandomRealDistribution(1.0, 100.0) <= chance_to_hit;
}

bool VariableEffectActivates(const MoveNames &move_name) {
  return RandomIntDistribution(1, 100) <= VariableEffectChance(move_name);
}

int DamageRandomFactor() {
  return RandomIntDistribution(217, 255);
}

double StabBonus(const std::shared_ptr<Pokemon> &attacker) {
  return ((attacker->GetTypeContainer().MoveMatchesType(
      attacker->MoveUsed()->MoveName())) ? 1.5 : 1.0);
}

double CriticalHitChance(const std::shared_ptr<Pokemon> &attacker) {
  MoveNames move_used_name = attacker->MoveUsed()->MoveName();
  double attacker_base_speed = static_cast<double>(
      attacker->GetNormalStatsContainer()[StatNames::kSpeed]->BaseStat());

  if (HasHighCriticalHitRatio(move_used_name) && attacker->UsedFocusEnergy()) {
    return attacker_base_speed / 256;
  }

  if (HasHighCriticalHitRatio(move_used_name)) {
    return attacker_base_speed / 64;
  }

  if (attacker->UsedFocusEnergy()) {
    return attacker_base_speed / 2048;
  }

  return attacker_base_speed / 512;
}

std::pair<int, int> AttackAndDefenseUsed(
    const std::shared_ptr<Pokemon> &attacker,
    const std::shared_ptr<Pokemon> &defender,
    const bool &move_crit) {
  MoveNames move_used_name = attacker->MoveUsed()->MoveName();
  NormalStatsContainer attacker_stats = attacker->GetNormalStatsContainer();
  NormalStatsContainer defender_stats = defender->GetNormalStatsContainer();
  std::shared_ptr<NormalStat> attack;
  std::shared_ptr<NormalStat> defense;

  if (IsPhysical(move_used_name)) {
    attack = attacker_stats[StatNames::kAttack];
    defense = defender_stats[StatNames::kDefense];
  } else {
    attack = attacker_stats[StatNames::kSpecial];
    defense = defender_stats[StatNames::kSpecial];
  }

  if (move_crit) {
    return std::make_pair(attack->InitialStat(), defense->InitialStat());
  }

  return std::make_pair(attack->InGameStat(), defense->InGameStat());
}

int DamageDone(const std::shared_ptr<Pokemon> &attacker,
               const std::shared_ptr<Pokemon> &defender,
               const bool &self_ko_move, const bool &move_hit,
               const bool &confusion_damage, const bool &is_called_by_ai) {
  std::shared_ptr<Move> move_used = attacker->MoveUsed();

  if (!move_hit ||
      (defender->IsVanished() && move_used->MoveName() != MoveNames::kSwift) ||
      !BasePower(move_used->MoveName())) {
    return 0;
  }

  double type_product = confusion_damage ? 10.0 : TypeProduct(move_used,
                                                              defender);

  if (!static_cast<int>(type_product) ||
      (move_used->MoveName() == MoveNames::kLick &&
          defender->IsType(TypeNames::kPsychic)) ||
      (move_used->MoveName() == MoveNames::kDreamEater &&
          !defender->IsAsleep())) {
    if (!is_called_by_ai) {
      Gui::DisplayMoveHadNoEffectMessage();
    }

    return 0;
  }

  if (type_product < 10.0 && !is_called_by_ai) {
    Gui::DisplayNotVeryEffectiveMessage();
  } else if (type_product > 10.0 && !is_called_by_ai) {
    Gui::DisplaySuperEffectiveMessage();
  }

  bool move_crit = IsDamaging(move_used->MoveName()) ?
                   MoveCrit(CriticalHitChance(attacker)) : false;
  std::pair<int, int> used_stats = AttackAndDefenseUsed(attacker, defender,
                                                        confusion_damage ?
                                                        move_crit : false);

  if (move_crit && !confusion_damage && !is_called_by_ai) {
    Gui::DisplayMoveCritMessage();
  }

  int damage_done = static_cast<int>(floor(((((((((2.0 * (move_crit ? 2 : 1) *
      attacker->Level() / 5 + 2) * used_stats.first * BasePower(
      move_used->MoveName()) * (self_ko_move ? 2 : 1) / used_stats.second) /
      50) + 2) * StabBonus(attacker)) * type_product / 10) *
      DamageRandomFactor()) / 255)));

  if (((defender->IsBehindReflect() && IsPhysical(move_used->MoveName())) ||
      (defender->IsBehindLightScreen() && IsSpecial(move_used->MoveName()))) &&
      !move_crit) {
    damage_done >>= 1;
  }

  return !damage_done ? 1 : damage_done;
}

void UseCounter(const std::shared_ptr<Pokemon> &attacker,
                const std::shared_ptr<Pokemon> &defender,
                const bool &is_called_by_ai) {
  if (!defender->MoveUsed() ||
      !static_cast<int>(TypeProduct(attacker->MoveUsed(), defender))) {
    if (!is_called_by_ai) {
      Gui::DisplayMoveHadNoEffectMessage();
    }

    return;
  }

  MoveNames defender_move_name = defender->MoveUsed()->MoveName();
  TypeNames defender_move_type = Type(defender_move_name);

  if (!IsPhysical(defender_move_name) || !IsDamaging(defender_move_name) ||
      (defender_move_type != TypeNames::kNormal &&
          defender_move_type != TypeNames::kFighting)) {
    if (!is_called_by_ai) {
      Gui::DisplayMoveFailedMessage();
    }

    return;
  }

  int damage_done = defender->MoveUsed()->DamageDone() << 1;
  defender->HpStat()->SubtractHp(damage_done);

  if (!is_called_by_ai) {
    Gui::DisplayDamageDoneMessage(damage_done);
  }
}

void UseOneHitKoMove(const std::shared_ptr<Pokemon> &attacker,
                     const std::shared_ptr<Pokemon> &defender,
                     const bool &is_called_by_ai) {
  // In this case, damage done is damage that would have been done. If it's
  // 0, the move didn't affect the target.
  int attacker_speed =
      attacker->GetNormalStatsContainer()[StatNames::kSpeed]->InGameStat();
  int defender_speed =
      defender->GetNormalStatsContainer()[StatNames::kSpeed]->InGameStat();

  if (attacker->Level() < defender->Level() ||
      attacker_speed < defender_speed) {
    if (!is_called_by_ai) {
      Gui::DisplayMoveFailedMessage();
    }

    return;
  }

  if (defender->SubstituteIsActive()) {
    if (!is_called_by_ai) {
      Gui::DisplaySubstituteTookDamageMessage(defender->HpStat()->MaxHp());
    }

    defender->DoDamageToSubstitute(defender->HpStat()->MaxHp());

    if (!defender->SubstituteIsActive() && !is_called_by_ai) {
      Gui::DisplaySubstituteFadedMessage(defender->SpeciesName());
    }
  } else {
    defender->AutoFaint();
  }

  if (!is_called_by_ai) {
    Gui::DisplayOneHitKoMoveLandedMessage();
  }
}

bool MimicWillSucceed(const std::shared_ptr<Pokemon> &attacker,
                      const std::shared_ptr<Pokemon> &defender) {
  if (attacker->UsedMimic()) {
    return false;
  }

  MovesContainer defender_moves = defender->GetMovesContainer();

  for (int i = 0; i < defender_moves.EndOfNormalMovesIndex(); i++) {
    if (!attacker->GetMovesContainer().SeenMove(
        defender_moves[i]->MoveName())) {
      return true;
    }
  }

  return false;
}

MoveNames MoveFromMimic(const std::shared_ptr<Pokemon> &attacker,
                        const std::shared_ptr<Pokemon> &defender) {
  MoveNames random_move;

  while (true) {
    random_move =
        defender->GetMovesContainer()[RandomIntDistribution(
            0, defender->GetMovesContainer().EndOfNormalMovesIndex()
                - 1)]->MoveName();

    if (random_move != MoveNames::kStruggle &&
        random_move != MoveNames::kMimic &&
        !attacker->GetMovesContainer().SeenMove(random_move)) {
      break;
    }
  }

  return random_move;
}

void UseMimic(const std::shared_ptr<Pokemon> &attacker,
              const std::shared_ptr<Pokemon> &defender,
              const bool &is_called_by_ai) {
  MoveNames random_move = MoveFromMimic(attacker, defender);
  MovesContainer attacker_moves = attacker->GetMovesContainer();
  int index_of_mimic = attacker_moves.IndexOfMimic();
  int mimic_pp = attacker_moves[index_of_mimic]->CurrentPp();
  attacker_moves.ResetMoveAtIndex(index_of_mimic, random_move, mimic_pp);
  attacker->SetMimicIndex(index_of_mimic);
  attacker->UseMimic();

  if (!is_called_by_ai) {
    Gui::DisplayPokemonCopiedMoveMessage(attacker->SpeciesName(), random_move);
  }
}

void DoConditionalDamage(const std::shared_ptr<Pokemon> &defender,
                         const MoveNames &attacker_move,
                         const int &damage_done,
                         const bool &is_called_by_ai) {
  if (defender->SubstituteIsActive()) {
    if (!is_called_by_ai) {
      Gui::DisplaySubstituteTookDamageMessage(damage_done);
    }

    defender->DoDamageToSubstitute(damage_done);

    if (!defender->SubstituteIsActive() && !is_called_by_ai) {
      Gui::DisplaySubstituteFadedMessage(defender->SpeciesName());
    }
  } else {
    if (defender->IsRaging()) {
      defender->ChangeStat(StatNames::kAttack, 1);

      if (!is_called_by_ai) {
        Gui::DisplayStatChangeMessage(defender->SpeciesName(),
                                      StatNames::kAttack, 1);
      }
    }

    defender->HpStat()->SubtractHp(damage_done);

    if (!is_called_by_ai) {
      Gui::DisplayDamageDoneMessage(damage_done);
    }
  }

  if (defender->BideIsActive() && !defender->BideDamage()) {
    defender->SetBideDamage(damage_done);
    defender->AddDamageToBide();
  }
}

void DoDirectDamage(const std::shared_ptr<Pokemon> &defender,
                    const int &damage_done,
                    const bool &is_called_by_ai) {
  if (defender->SubstituteIsActive()) {
    if (!is_called_by_ai) {
      Gui::DisplaySubstituteTookDamageMessage(damage_done);
    }

    defender->DoDamageToSubstitute(damage_done);

    if (!defender->SubstituteIsActive() && !is_called_by_ai) {
      Gui::DisplaySubstituteFadedMessage(defender->SpeciesName());
    }
  } else {
    if (defender->IsRaging()) {
      defender->ChangeStat(StatNames::kAttack, 1);

      if (!is_called_by_ai) {
        Gui::DisplayStatChangeMessage(defender->SpeciesName(),
                                      StatNames::kAttack, 1);
      }
    }

    defender->HpStat()->SubtractHp(damage_done);

    if (!is_called_by_ai) {
      Gui::DisplayDamageDoneMessage(damage_done);
    }
  }

  if (defender->BideIsActive() && !defender->BideDamage()) {
    defender->SetBideDamage(damage_done);
    defender->AddDamageToBide();
  }
}

void DoDamageEqualToAttackerLevel(const std::shared_ptr<Pokemon> &attacker,
                                  const std::shared_ptr<Pokemon> &defender,
                                  const bool &is_called_by_ai) {
  if (defender->BideIsActive() && !defender->BideDamage()) {
    defender->SetBideDamage(attacker->Level());
    defender->AddDamageToBide();
  }

  DoDirectDamage(defender, attacker->Level(), is_called_by_ai);
}

void UsePsywave(const std::shared_ptr<Pokemon> &attacker,
                const std::shared_ptr<Pokemon> &defender,
                const bool &is_called_by_ai) {
  DoDirectDamage(defender, RandomIntDistribution(1, static_cast<int>(
      1.5 * attacker->Level())), is_called_by_ai);
}

void UseSuperFang(const std::shared_ptr<Pokemon> &attacker,
                  const std::shared_ptr<Pokemon> &defender,
                  const bool &is_called_by_ai) {
  if (!static_cast<int>(TypeProduct(attacker->MoveUsed(), defender)) &&
      !is_called_by_ai) {
    Gui::DisplayMoveHadNoEffectMessage();
  } else {
    DoDirectDamage(
        defender, defender->HpStat()->CurrentHp() >> 1, is_called_by_ai);
  }
}

void HazeField(const std::shared_ptr<Pokemon> &attacker,
               const std::shared_ptr<Pokemon> &defender) {
  attacker->ResetFlagsFromHaze();
  defender->ResetFlagsFromHaze();
  Gui::DisplayHazeResetMessage();
}

void DoSideEffect(const std::shared_ptr<Pokemon> &attacker,
                  const std::shared_ptr<Pokemon> &defender,
                  const int &damage_done, const bool &move_hit,
                  const bool &is_charge_or_vanish,
                  const bool &is_called_by_ai) {
  MoveNames move_name = attacker->MoveUsed()->MoveName();

  if (!HasSideEffectIfMissed(move_name) && !move_hit) {
    return;
  }

  if (IsDamaging(move_name) && !damage_done && !is_charge_or_vanish) {
    return;
  }

  switch (move_name) {
    case MoveNames::kAbsorb:
    case MoveNames::kMegaDrain:
    case MoveNames::kLeechLife: {
      int absorbed = !(damage_done >> 1) ? 1 : damage_done >> 1;
      attacker->AbsorbHp(absorbed);

      if (!is_called_by_ai) {
        Gui::DisplayHpAbsorbedMessage(attacker->SpeciesName(), absorbed);
      }

      break;
    }
    case MoveNames::kAcid:
    case MoveNames::kPsychic:
      if (VariableEffectActivates(move_name) &&
          !defender->SubstituteIsActive() && !defender->IsUnderMist()) {
        defender->ChangeStat(StatNames::kSpecial, -1);

        if (!is_called_by_ai) {
          Gui::DisplayStatChangeMessage(defender->SpeciesName(),
                                        StatNames::kSpecial, -1);
        }
      }

      break;
    case MoveNames::kBarrier:
    case MoveNames::kAcidArmor:
      attacker->ChangeStat(StatNames::kDefense, 2);

      if (!is_called_by_ai) {
        Gui::DisplayStatChangeMessage(attacker->SpeciesName(),
                                      StatNames::kDefense, 2);
      }

      break;
    case MoveNames::kAgility:
      attacker->ChangeStat(StatNames::kSpeed, 2);

      if (!is_called_by_ai) {
        Gui::DisplayStatChangeMessage(attacker->SpeciesName(),
                                      StatNames::kSpeed, 2);
      }

      break;
    case MoveNames::kBite:
    case MoveNames::kBoneClub:
    case MoveNames::kHeadbutt:
    case MoveNames::kHyperFang:
    case MoveNames::kLowKick:
    case MoveNames::kRollingKick:
    case MoveNames::kStomp:
      if (VariableEffectActivates(move_name) &&
          !defender->SubstituteIsActive()) {
        defender->Flinch();
      }

      break;
    case MoveNames::kAmnesia:
      attacker->ChangeStat(StatNames::kSpecial, 2);

      if (!is_called_by_ai) {
        Gui::DisplayStatChangeMessage(attacker->SpeciesName(),
                                      StatNames::kSpecial, 2);
      }

      break;
    case MoveNames::kAuroraBeam:
      if (VariableEffectActivates(move_name) &&
          !defender->SubstituteIsActive() && !defender->IsUnderMist()) {
        defender->ChangeStat(StatNames::kAttack, -1);

        if (!is_called_by_ai) {
          Gui::DisplayStatChangeMessage(defender->SpeciesName(),
                                        StatNames::kAttack, -1);
        }
      }

      break;
    case MoveNames::kBide:
      attacker->UseBide();

      if (!is_called_by_ai) {
        Gui::DisplayIsBidingMessage(attacker->SpeciesName());
      }

      break;
    case MoveNames::kBind:
    case MoveNames::kClamp:
    case MoveNames::kFireSpin:
    case MoveNames::kWrap: {
      if (!attacker->UsedTrapMove() && !is_called_by_ai) {
        Gui::DisplayUsedTrapMoveMessage(attacker->SpeciesName());
        Gui::DisplayIsTrappedMessage(defender->SpeciesName());
      }

      int random_threshold = RandomIntDistribution(2, 5);
      attacker->Trap(true, random_threshold);
      defender->Trap(false, random_threshold);

      if ((!attacker->UsedTrapMove() || !defender->IsTrapped()) &&
          !is_called_by_ai) {
        Gui::DisplayTrapEndedMessage(attacker->SpeciesName());
        Gui::DisplayTrapEndedMessage(defender->SpeciesName());
      }

      break;
    }
    case MoveNames::kBlizzard:
    case MoveNames::kIcePunch:
    case MoveNames::kIceBeam:
      if (VariableEffectActivates(move_name) &&
          !defender->IsType(TypeNames::kIce) &&
          !defender->SubstituteIsActive() && !defender->HasStatus()) {
        defender->ApplyStatus(StatusNames::kFrozen);

        if (!is_called_by_ai) {
          Gui::DisplayFreezeStartedMessage(defender->SpeciesName());
        }
      }

      break;
    case MoveNames::kBodySlam:
    case MoveNames::kLick:
    case MoveNames::kThunder:
    case MoveNames::kThunderbolt:
    case MoveNames::kThunderShock:
      if (VariableEffectActivates(move_name) &&
          !defender->IsType(TypeNames::kElectric) &&
          !defender->SubstituteIsActive()) {
        defender->ApplyStatus(StatusNames::kParalyzed);

        if (!is_called_by_ai) {
          Gui::DisplayParalysisStartedMessage(defender->SpeciesName());
        }
      }

      break;
    case MoveNames::kBubble:
    case MoveNames::kBubbleBeam:
    case MoveNames::kConstrict:
      if (VariableEffectActivates(move_name) &&
          !defender->SubstituteIsActive() && !defender->IsUnderMist()) {
        defender->ChangeStat(StatNames::kSpeed, -1);

        if (!is_called_by_ai) {
          Gui::DisplayStatChangeMessage(defender->SpeciesName(),
                                        StatNames::kSpeed, -1);
        }
      }

      break;
    case MoveNames::kConfuseRay:
    case MoveNames::kSupersonic:
      if (defender->IsConfused() || defender->SubstituteIsActive()) {
        if (!is_called_by_ai) {
          Gui::DisplayMoveFailedMessage();
        }
      } else {
        defender->Confuse();

        if (!is_called_by_ai) {
          Gui::DisplayConfusionStartedMessage(defender->SpeciesName());
        }
      }

      break;
    case MoveNames::kConfusion:
    case MoveNames::kPsybeam:
      if (VariableEffectActivates(move_name) && !defender->IsConfused()) {
        defender->Confuse();

        if (!is_called_by_ai) {
          Gui::DisplayConfusionStartedMessage(defender->SpeciesName());
        }
      }

      break;
    case MoveNames::kConversion:
      attacker->UseConversion();
      break;
    case MoveNames::kCounter:
      UseCounter(attacker, defender, is_called_by_ai);
      break;
    case MoveNames::kDefenseCurl:
    case MoveNames::kHarden:
    case MoveNames::kWithdraw:
      attacker->ChangeStat(StatNames::kDefense, 1);

      if (!is_called_by_ai) {
        Gui::DisplayStatChangeMessage(attacker->SpeciesName(),
                                      StatNames::kDefense, 1);
      }

      break;
    case MoveNames::kDig:
    case MoveNames::kFly:
      if (!attacker->IsVanished() && !is_called_by_ai) {
        Gui::DisplayPokemonVanishedMessage(attacker->SpeciesName());
      }

      attacker->UseVanishMove();
      break;
    case MoveNames::kDisable:
      if (!is_called_by_ai) {
        if (defender->SubstituteIsActive() ||
            !defender->CanHaveMoveDisabled() || defender->HasMoveDisabled()) {
          Gui::DisplayMoveFailedMessage();
        } else {
          Gui::DisplayMoveDisabledMessage(defender->DisableMove());
        }
      }

      break;
    case MoveNames::kDoubleTeam:
    case MoveNames::kMinimize:
      attacker->ChangeStat(StatNames::kEvasion, -1);

      if (!is_called_by_ai) {
        Gui::DisplayStatChangeMessage(attacker->SpeciesName(),
                                      StatNames::kEvasion, 1);
      }

      break;
    case MoveNames::kDoubleEdge:
    case MoveNames::kTakeDown:
    case MoveNames::kSubmission:
    case MoveNames::kStruggle: {
      int recoil_damage = !(damage_done >> 2) ? 1 : damage_done >> 2;
      attacker->TakeRecoilDamage(recoil_damage);

      if (!is_called_by_ai) {
        Gui::DisplayRecoilDamageMessage(attacker->SpeciesName(), recoil_damage);
      }

      break;
    }
    case MoveNames::kDragonRage:
      DoDirectDamage(defender, 40, is_called_by_ai);
      break;
    case MoveNames::kDreamEater: {
      if (defender->IsAsleep() || defender->IsResting()) {
        int absorbed = !(damage_done >> 1) ? 1 : damage_done >> 1;
        attacker->AbsorbHp(absorbed);

        if (!is_called_by_ai) {
          Gui::DisplayHpAbsorbedMessage(attacker->SpeciesName(), absorbed);
        }
      }

      break;
    }
    case MoveNames::kExplosion:
    case MoveNames::kSelfDestruct:
      attacker->AutoFaint();
      break;
    case MoveNames::kEmber:
    case MoveNames::kFireBlast:
    case MoveNames::kFirePunch:
    case MoveNames::kFlamethrower:
      if (VariableEffectActivates(move_name) &&
          !defender->IsType(TypeNames::kFire) &&
          !defender->SubstituteIsActive() && !defender->HasStatus()) {
        defender->ApplyStatus(StatusNames::kBurned);

        if (!is_called_by_ai) {
          Gui::DisplayBurnStartedMessage(defender->SpeciesName());
        }
      }

      break;
    case MoveNames::kFissure:
    case MoveNames::kGuillotine:
    case MoveNames::kHornDrill:
      UseOneHitKoMove(attacker, defender, is_called_by_ai);
      break;
    case MoveNames::kFlash:
    case MoveNames::kKinesis:
    case MoveNames::kSmokescreen:
    case MoveNames::kSandAttack:
      if (defender->SubstituteIsActive()) {
        if (!is_called_by_ai) {
          Gui::DisplayIsBehindSubstituteMessage(defender->SpeciesName());
        }
      } else if (defender->IsUnderMist()) {
        if (!is_called_by_ai) {
          Gui::DisplayIsUnderMistMessage(defender->SpeciesName());
        }
      } else {
        defender->ChangeStat(StatNames::kAccuracy, -1);

        if (!is_called_by_ai) {
          Gui::DisplayStatChangeMessage(defender->SpeciesName(),
                                        StatNames::kAccuracy, -1);
        }
      }

      break;
    case MoveNames::kFocusEnergy:
      attacker->UseFocusEnergy();
      break;
    case MoveNames::kGlare:
      if (defender->HasStatus() || defender->SubstituteIsActive() ||
          defender->IsType(TypeNames::kElectric)) {
        if (!is_called_by_ai) {
          Gui::DisplayMoveFailedMessage();
        }
      } else {
        defender->ApplyStatus(StatusNames::kParalyzed);

        if (!is_called_by_ai) {
          Gui::DisplayParalysisStartedMessage(defender->SpeciesName());
        }
      }

      break;
    case MoveNames::kStunSpore:
      if (defender->HasStatus() || defender->SubstituteIsActive() ||
          defender->IsType(TypeNames::kGrass) ||
          defender->IsType(TypeNames::kElectric)) {
        if (!is_called_by_ai) {
          Gui::DisplayMoveFailedMessage();
        }
      } else {
        defender->ApplyStatus(StatusNames::kParalyzed);

        if (!is_called_by_ai) {
          Gui::DisplayParalysisStartedMessage(defender->SpeciesName());
        }
      }

      break;
    case MoveNames::kThunderWave:
      if (defender->HasStatus() || defender->SubstituteIsActive() ||
          defender->IsType(TypeNames::kElectric) ||
          defender->IsType(TypeNames::kGround)) {
        if (!is_called_by_ai) {
          Gui::DisplayMoveFailedMessage();
        }
      } else {
        defender->ApplyStatus(StatusNames::kParalyzed);

        if (!is_called_by_ai) {
          Gui::DisplayParalysisStartedMessage(defender->SpeciesName());
        }
      }

      break;
    case MoveNames::kGrowl:
      if (defender->SubstituteIsActive()) {
        if (!is_called_by_ai) {
          Gui::DisplayIsBehindSubstituteMessage(defender->SpeciesName());
        }
      } else if (defender->IsUnderMist()) {
        if (!is_called_by_ai) {
          Gui::DisplayIsUnderMistMessage(defender->SpeciesName());
        }
      } else {
        defender->ChangeStat(StatNames::kAttack, -1);

        if (!is_called_by_ai) {
          Gui::DisplayStatChangeMessage(defender->SpeciesName(),
                                        StatNames::kAttack, -1);
        }
      }

      break;
    case MoveNames::kGrowth:
      attacker->ChangeStat(StatNames::kSpecial, 1);

      if (!is_called_by_ai) {
        Gui::DisplayStatChangeMessage(attacker->SpeciesName(),
                                      StatNames::kSpecial, 1);
      }

      break;
    case MoveNames::kHaze:
      HazeField(attacker, defender);
      break;
    case MoveNames::kHighJumpKick:
    case MoveNames::kJumpKick:
      if (!move_hit || !damage_done) {
        attacker->TakeRecoilDamage(1);

        if (!is_called_by_ai) {
          Gui::DisplayRecoilDamageMessage(attacker->SpeciesName(), 1);
        }
      }

      break;
    case MoveNames::kHyperBeam:
      attacker->SetRecharging(true);
      break;
    case MoveNames::kHypnosis:
    case MoveNames::kLovelyKiss:
    case MoveNames::kSing:
      if (defender->SubstituteIsActive() || defender->HasStatus()) {
        if (!is_called_by_ai) {
          Gui::DisplayMoveFailedMessage();
        }
      } else {
        defender->ApplyStatus(StatusNames::kAsleep);

        if (!is_called_by_ai) {
          Gui::DisplaySleepStartedMessage(defender->SpeciesName());
        }
      }

      break;
    case MoveNames::kSleepPowder:
    case MoveNames::kSpore:
      if (defender->SubstituteIsActive() ||
          defender->HasStatus() || defender->IsType(TypeNames::kGrass)) {
        if (!is_called_by_ai) {
          Gui::DisplayMoveFailedMessage();
        }
      } else {
        defender->ApplyStatus(StatusNames::kAsleep);

        if (!is_called_by_ai) {
          Gui::DisplaySleepStartedMessage(defender->SpeciesName());
        }
      }

      break;
    case MoveNames::kLeechSeed:
      if (defender->IsType(TypeNames::kGrass) || defender->IsSeeded() ||
          defender->SubstituteIsActive()) {
        if (!is_called_by_ai) {
          Gui::DisplayMoveFailedMessage();
        }
      } else {
        defender->ApplyLeechSeed();

        if (!is_called_by_ai) {
          Gui::DisplayLeechSeedStartedMessage(defender->SpeciesName());
        }
      }
      break;
    case MoveNames::kLeer:
    case MoveNames::kTailWhip:
      if (defender->SubstituteIsActive()) {
        if (!is_called_by_ai) {
          Gui::DisplayIsBehindSubstituteMessage(defender->SpeciesName());
        }
      } else if (defender->IsUnderMist()) {
        if (!is_called_by_ai) {
          Gui::DisplayIsUnderMistMessage(defender->SpeciesName());
        }
      } else {
        defender->ChangeStat(StatNames::kDefense, -1);

        if (!is_called_by_ai) {
          Gui::DisplayStatChangeMessage(defender->SpeciesName(),
                                        StatNames::kDefense, -1);
        }
      }

      break;
    case MoveNames::kLightScreen:
      if (attacker->IsBehindLightScreen()) {
        if (!is_called_by_ai) {
          Gui::DisplayMoveFailedMessage();
        }
      } else {
        attacker->UseLightScreen();
      }

      break;
    case MoveNames::kMeditate:
    case MoveNames::kSharpen:
      attacker->ChangeStat(StatNames::kAttack, 1);

      if (!is_called_by_ai) {
        Gui::DisplayStatChangeMessage(attacker->SpeciesName(),
                                      StatNames::kAttack, 1);
      }

      break;
    case MoveNames::kMimic:
      if (!MimicWillSucceed(attacker, defender)) {
        if (!is_called_by_ai) {
          Gui::DisplayMoveFailedMessage();
        }
      } else {
        UseMimic(attacker, defender, is_called_by_ai);
      }

      break;
    case MoveNames::kMist:
      if (attacker->IsUnderMist()) {
        if (!is_called_by_ai) {
          Gui::DisplayMoveFailedMessage();
        }
      } else {
        attacker->UseMist();

        if (!is_called_by_ai) {
          Gui::DisplayMistStartedMessage(attacker->SpeciesName());
        }
      }

      break;
    case MoveNames::kNightShade:
    case MoveNames::kSeismicToss:
      DoDamageEqualToAttackerLevel(attacker, defender, is_called_by_ai);
      break;
    case MoveNames::kRage:
      if (!attacker->IsRaging() && !is_called_by_ai) {
        Gui::DisplayIsRagingMessage(attacker->SpeciesName());
      }

      attacker->UseRage();
      break;
    case MoveNames::kPetalDance:
    case MoveNames::kThrash:
      if (!attacker->IsUsingLockInMove() && !is_called_by_ai) {
        Gui::DisplayIsLockedInMessage(attacker->SpeciesName());
      }

      attacker->UseLockInMove();

      if (!attacker->IsUsingLockInMove() && !is_called_by_ai) {
        Gui::DisplayLockInEndedMessage(attacker->SpeciesName());
        Gui::DisplayConfusionStartedMessage(attacker->SpeciesName());
      }

      break;
    case MoveNames::kPoisonGas:
    case MoveNames::kPoisonPowder:
      if (defender->SubstituteIsActive() ||
          defender->IsType(TypeNames::kPoison) || defender->HasStatus()) {
        if (!is_called_by_ai) {
          Gui::DisplayMoveFailedMessage();
        }
      } else {
        defender->ApplyStatus(StatusNames::kPoisoned);

        if (!is_called_by_ai) {
          Gui::DisplayPoisonStartedMessage(defender->SpeciesName(), false);
        }
      }

      break;
    case MoveNames::kPoisonSting:
    case MoveNames::kSludge:
    case MoveNames::kSmog:
    case MoveNames::kTwineedle:
      if (VariableEffectActivates(move_name) &&
          !defender->IsType(TypeNames::kPoison) &&
          !defender->SubstituteIsActive()) {
        defender->ApplyStatus(StatusNames::kPoisoned);

        if (!is_called_by_ai) {
          Gui::DisplayPoisonStartedMessage(defender->SpeciesName(), false);
        }
      }

      break;
    case MoveNames::kPsywave:
      UsePsywave(attacker, defender, is_called_by_ai);
      break;
    case MoveNames::kRazorWind:
    case MoveNames::kSkullBash:
    case MoveNames::kSkyAttack:
    case MoveNames::kSolarBeam:
      if (!attacker->IsChargingUp() && !is_called_by_ai) {
        Gui::DisplayChargingUpMessage(attacker->SpeciesName());
      }

      attacker->UseChargeUpMove();
      break;
    case MoveNames::kRecover:
    case MoveNames::kSoftBoiled: {
      int max_minus_current =
          attacker->HpStat()->MaxHp() - attacker->HpStat()->CurrentHp();

      if (max_minus_current == 255 || max_minus_current == 511 ||
          attacker->HpStat()->CurrentHp() == attacker->HpStat()->MaxHp()) {
        if (!is_called_by_ai) {
          Gui::DisplayMoveFailedMessage();
        }
      } else {
        attacker->RecoverHp();
      }

      break;
    }
    case MoveNames::kReflect:
      if (attacker->IsBehindReflect()) {
        if (!is_called_by_ai) {
          Gui::DisplayMoveFailedMessage();
        }
      } else {
        attacker->UseReflect();
      }

      break;
    case MoveNames::kRest: {
      int max_minus_current =
          attacker->HpStat()->MaxHp() - attacker->HpStat()->CurrentHp();

      if (max_minus_current == 255 || max_minus_current == 511 ||
          attacker->HpStat()->CurrentHp() == attacker->HpStat()->MaxHp()) {
        if (!is_called_by_ai) {
          Gui::DisplayMoveFailedMessage();
        }
      } else {
        attacker->ApplyStatus(StatusNames::kAsleepRest);

        if (!is_called_by_ai) {
          Gui::DisplaySleepStartedMessage(defender->SpeciesName());
          Gui::DisplayRecoveredAllHpMessage(defender->SpeciesName());
        }
      }

      break;
    }
    case MoveNames::kScreech:
      if (defender->SubstituteIsActive()) {
        if (!is_called_by_ai) {
          Gui::DisplayIsBehindSubstituteMessage(defender->SpeciesName());
        }
      } else if (defender->IsUnderMist()) {
        if (!is_called_by_ai) {
          Gui::DisplayIsUnderMistMessage(defender->SpeciesName());
        }
      } else {
        defender->ChangeStat(StatNames::kDefense, -2);

        if (!is_called_by_ai) {
          Gui::DisplayStatChangeMessage(defender->SpeciesName(),
                                        StatNames::kDefense, -2);
        }
      }

      break;
    case MoveNames::kSonicBoom:
      DoDirectDamage(defender, 20, is_called_by_ai);
      break;
    case MoveNames::kStringShot:
      if (defender->SubstituteIsActive()) {
        if (!is_called_by_ai) {
          Gui::DisplayIsBehindSubstituteMessage(defender->SpeciesName());
        }
      } else if (defender->IsUnderMist()) {
        if (!is_called_by_ai) {
          Gui::DisplayIsUnderMistMessage(defender->SpeciesName());
        }
      } else {
        defender->ChangeStat(StatNames::kSpeed, -1);

        if (!is_called_by_ai) {
          Gui::DisplayStatChangeMessage(defender->SpeciesName(),
                                        StatNames::kSpeed, -1);
        }
      }

      break;
    case MoveNames::kSubstitute:
      if (attacker->SubstituteIsActive() ||
          attacker->HpStat()->HpAsPercent() <= 25.0) {
        if (!is_called_by_ai) {
          Gui::DisplayMoveFailedMessage();
        }
      } else {
        attacker->UseSubstitute();

        if (!is_called_by_ai) {
          Gui::DisplaySubstituteStartedMessage(attacker->SpeciesName());
        }
      }

      break;
    case MoveNames::kSuperFang:
      UseSuperFang(attacker, defender, is_called_by_ai);
      break;
    case MoveNames::kSwordsDance:
      attacker->ChangeStat(StatNames::kAttack, 2);

      if (!is_called_by_ai) {
        Gui::DisplayStatChangeMessage(attacker->SpeciesName(),
                                      StatNames::kAttack, 2);
      }

      break;
    case MoveNames::kToxic:
      if (defender->SubstituteIsActive() ||
          defender->IsType(TypeNames::kPoison) || defender->HasStatus()) {
        if (!is_called_by_ai) {
          Gui::DisplayMoveFailedMessage();
        }
      } else {
        defender->ApplyStatus(StatusNames::kPoisonedToxic);

        if (!is_called_by_ai) {
          Gui::DisplayPoisonStartedMessage(defender->SpeciesName(), true);
        }
      }

      break;
    case MoveNames::kTransform:
      attacker->Transform(defender);

      if (!is_called_by_ai) {
        Gui::DisplayTransformMessage(attacker->SpeciesName(),
                                     defender->SpeciesName());
      }

      break;
    default:
      break;
  }
}

bool IsGoodToMove(const std::shared_ptr<Pokemon> &attacker,
                  const std::shared_ptr<Pokemon> &defender,
                  const bool &is_called_by_ai) {
  if (attacker->IsFainted() || defender->IsFainted()) {
    return false;
  }

  if (attacker->IsAsleep()) {
    if (!is_called_by_ai) {
      Gui::DisplayIsAsleepMessage(attacker->SpeciesName());
    }

    attacker->AdvanceRegularSleepCounter();

    if (!attacker->HasStatus() && !is_called_by_ai) {
      Gui::DisplayWokeUpMessage(attacker->SpeciesName());
    }

    return false;
  }

  if (attacker->IsResting()) {
    if (!is_called_by_ai) {
      Gui::DisplayIsAsleepMessage(attacker->SpeciesName());
    }

    attacker->AdvanceRestCounter();

    if (!attacker->HasStatus() && !is_called_by_ai) {
      Gui::DisplayWokeUpMessage(attacker->SpeciesName());
    }

    return false;
  }

  if (attacker->IsFrozen()) {
    if (!is_called_by_ai) {
      Gui::DisplayIsFrozenMessage(attacker->SpeciesName());
    }

    return false;
  }

  if (attacker->IsFlinched()) {
    if (!is_called_by_ai) {
      Gui::DisplayFlinchedMessage(attacker->SpeciesName());
    }

    return false;
  }

  if (attacker->IsParalyzed() && attacker->IsFullyParalyzed()) {
    if (!is_called_by_ai) {
      Gui::DisplayFullyParalyzedMessage(attacker->SpeciesName());
    }

    return false;
  }

  if (attacker->IsConfused() && !attacker->IsAsleep() &&
      !attacker->IsFrozen() && !attacker->IsResting()) {
    if (!is_called_by_ai) {
      Gui::DisplayConfusedMessage(attacker->SpeciesName());
    }

    if (!attacker->HandleConfusion()) {
      if (!is_called_by_ai) {
        Gui::DisplayHitSelfMessage(attacker->SpeciesName());
      }

      attacker->SetMoveUsed(std::make_shared<Move>(MoveNames::kHitSelf,
                                                   Pp(MoveNames::kHitSelf)));
      int damage_done = DamageDone(
          attacker, attacker, false, true, true, is_called_by_ai);
      attacker->DoConfusionDamage(damage_done);

      if (!is_called_by_ai) {
        Gui::DisplayDamageDoneMessage(damage_done);
      }

      if (!attacker->IsConfused() && !is_called_by_ai) {
        Gui::DisplayConfusionEndedMessage(attacker->SpeciesName());
      }

      return false;
    }
  }

  if (attacker->IsTrapped()) {
    if (!is_called_by_ai) {
      Gui::DisplayIsTrappedMessage(attacker->SpeciesName());
    }

    return false;
  }

  if (attacker->MoveUsed()->IsDisabled()) {
    if (!is_called_by_ai) {
      Gui::DisplayMoveDisabledMessage(attacker->MoveUsed()->MoveName());
    }

    return false;
  }

  return true;
}

void HardSwitch(Team &attacker, const bool &is_called_by_ai) {
  std::shared_ptr<Pokemon> old_active_member = attacker.ActiveMember();
  attacker.HardSwitch();

  if (!is_called_by_ai) {
    Gui::DisplaySwitchMessage(old_active_member->SpeciesName(),
                              attacker.ActiveMember()->SpeciesName());
  }
}

bool MirrorMoveWillFail(const MoveNames &defender_move) {
  return !(defender_move != MoveNames::kStruggle && !IsLockIn(defender_move) &&
      !IsChargeUp(defender_move) && !IsVanish(defender_move) &&
      !IsBinding(defender_move) && defender_move != MoveNames::kMimic);
}

void UseMirrorMove(const std::shared_ptr<Pokemon> &attacker,
                   const std::shared_ptr<Pokemon> &defender,
                   const bool &is_called_by_ai) {
  if (!defender->ExecutedMove() ||
      (defender->MoveUsed() &&
          MirrorMoveWillFail(defender->MoveUsed()->MoveName()))) {
    if (!is_called_by_ai) {
      Gui::DisplayMoveFailedMessage();
    }
  } else {
    MoveNames defender_move_name = defender->MoveUsed()->MoveName();
    std::shared_ptr<Move> move_used = std::make_shared<Move>(
        defender_move_name, Pp(defender_move_name));
    attacker->SetMoveUsed(defender->MoveUsed());

    if (!is_called_by_ai) {
      Gui::DisplayPokemonUsedMoveMessage(attacker->SpeciesName(),
                                         defender_move_name);
    }
  }
}

void ExecuteMove(const std::shared_ptr<Pokemon> &attacker,
                 const std::shared_ptr<Pokemon> &defender,
                 const bool &move_hit, const bool &is_called_by_ai) {
  std::shared_ptr<Move> move_used = attacker->MoveUsed();
  int damage_done;
  bool is_charge_or_vanish = false;

  if ((IsVanish(move_used->MoveName()) && !attacker->IsVanished()) ||
      (IsChargeUp(move_used->MoveName()) && !attacker->IsChargingUp())) {
    is_charge_or_vanish = true;
    damage_done = 0;
  } else {
    damage_done = IsSelfKo(move_used->MoveName()) ?
                  DamageDone(attacker,
                             defender,
                             true,
                             move_hit,
                             false,
                             is_called_by_ai) :
                  DamageDone(attacker,
                             defender,
                             false,
                             move_hit,
                             false,
                             is_called_by_ai);
  }

  if (damage_done && move_hit) {
    move_used->SetDamageDone(damage_done);
    DoConditionalDamage(defender, attacker->MoveUsed()->MoveName(),
                        damage_done, is_called_by_ai);
  }

  DoSideEffect(attacker, defender, damage_done, move_hit, is_charge_or_vanish,
               is_called_by_ai);
}

void UseMoveThatAlwaysHitsTwice(const std::shared_ptr<Pokemon> &attacker,
                                const std::shared_ptr<Pokemon> &defender,
                                const bool &move_hit,
                                const bool &is_called_by_ai) {
  ExecuteMove(attacker, defender, move_hit, is_called_by_ai);
  ExecuteMove(attacker, defender, move_hit, is_called_by_ai);
}

void UseMoveThatHitsTwoToFiveTimes(const std::shared_ptr<Pokemon> &attacker,
                                   const std::shared_ptr<Pokemon> &defender,
                                   const bool &move_hit,
                                   const bool &is_called_by_ai) {
  for (int i = 0; i < 5; i++) {
    switch (i) {
      case 0:
      case 1:
        ExecuteMove(attacker, defender, move_hit, is_called_by_ai);
        break;
      case 2:
        if (RandomRealDistribution(0.0, 100.0) > 37.5) {
          return;
        }

        ExecuteMove(attacker, defender, move_hit, is_called_by_ai);
        break;
      case 3:
      case 4:
        if (RandomRealDistribution(0.0, 100.0) > 12.5) {
          return;
        }

        ExecuteMove(attacker, defender, move_hit, is_called_by_ai);
        break;
      default:
        assert(false);
    }
  }
}

} //namespace

void UseMove(Team &attacker, Team &defender, const bool &is_called_by_ai) {
  std::shared_ptr<Pokemon> attacking_member = attacker.ActiveMember();
  std::shared_ptr<Pokemon> defending_member = defender.ActiveMember();
  std::shared_ptr<Move> move_used = attacking_member->MoveUsed();

  if (IsSwitch(attacking_member->MoveUsed()->MoveName())) {
    HardSwitch(attacker, is_called_by_ai);
    return;
  }

  if (!IsGoodToMove(attacking_member, defending_member, is_called_by_ai)) {
    return;
  }

  MoveNames move_used_name = move_used->MoveName();

  if (attacking_member->HasMoveDisabled()) {
    attacking_member->HandleDisable();

    if (!attacking_member->HasMoveDisabled() && !is_called_by_ai) {
      Gui::DisplayDisableEndedMessage(attacking_member->SpeciesName());
    }
  }

  if (defending_member->HasMoveDisabled()) {
    defending_member->HandleDisable();

    if (!defending_member->HasMoveDisabled() && !is_called_by_ai) {
      Gui::DisplayDisableEndedMessage(defending_member->SpeciesName());
    }
  }

  if (!is_called_by_ai) {
    Gui::DisplayPokemonUsedMoveMessage(attacking_member->SpeciesName(),
                                       move_used->MoveName());
  }

  if (move_used_name == MoveNames::kPass && !attacking_member->BideIsActive()) {
    attacking_member->SetRecharging(false);
    return;
  }

  if ((defending_member->SubstituteIsActive() &&
      (move_used_name == MoveNames::kSuperFang || IsBinding(move_used_name) ||
          IsDraining(move_used_name))) ||
      (defending_member->IsVanished() && !WorksIfDefenderIsVanished(
          move_used_name))) {
    if (!is_called_by_ai) {
      Gui::DisplayMoveFailedMessage();
    }

    return;
  }

  bool move_hit = MoveHit(ChanceToHit(attacking_member, defending_member));

  if (!move_hit && !is_called_by_ai) {
    Gui::DisplayMoveMissedMessage();
  }

  // Metronome has to be handled separately because it makes the attacker
  // call a random move. This needs to be set as attacker->MoveUsed(), and
  // then they have to call that move with the side effect and damage. See
  // Pokemon->UseMetronome() for a reference.
  if (move_used->MoveName() == MoveNames::kMetronome) {
    attacking_member->UseMetronome();

    if (!is_called_by_ai) {
      Gui::DisplayPokemonUsedMoveMessage(
          attacking_member->SpeciesName(),
          attacking_member->MoveUsed()->MoveName());
    }
  }

  // Mirror move must be handled separately for the same reason. The attacker
  // essentially is going to be executing two moves.
  if (move_used->MoveName() == MoveNames::kMirrorMove) {
    UseMirrorMove(attacking_member, defending_member, is_called_by_ai);
  }

  if (AlwaysHitsTwice(move_used->MoveName())) {
    UseMoveThatAlwaysHitsTwice(attacking_member,
                               defending_member,
                               move_hit,
                               is_called_by_ai);
  } else if (HitsTwoToFiveTimes(move_used->MoveName())) {
    UseMoveThatHitsTwoToFiveTimes(attacking_member,
                                  defending_member,
                                  move_hit,
                                  is_called_by_ai);
  } else {
    ExecuteMove(attacking_member, defending_member, move_hit, is_called_by_ai);
  }

  if (attacking_member->BideWillEnd()) {
    if (!is_called_by_ai) {
      Gui::DisplayBideEndedMessage(attacking_member->SpeciesName());
    }

    DoDirectDamage(defending_member,
                   attacking_member->BideDamage() << 1,
                   is_called_by_ai);
    attacking_member->ResetBide();
  }

  attacking_member->SetExecutedMove(true);

  if (!attacking_member->IsVanished() && !attacking_member->IsChargingUp() &&
      move_used_name != MoveNames::kStruggle) {
    move_used->DecrementPp(1);
  }
}

} //namespace artificialtrainer