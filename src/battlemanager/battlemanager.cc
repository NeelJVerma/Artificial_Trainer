//
// Created by neel on 4/20/19.
//

#include "battlemanager.h"
#include "../clientelements/gui.h"
#include "../clientelements/inputhandler.h"
#include "../move/priority.h"
#include "../random/randomgenerator.h"
#include "../move/usemove.h"
#include "../ailogic/pickforcedswitch.h"

namespace artificialtrainer {
namespace {

} //namespace

bool BattleManager::IsValidMoveChoice(const Team &team,
                                      const std::shared_ptr<Move> &move,
                                      const bool &is_called_by_ai) {
  std::shared_ptr<Pokemon> active_member = team.ActiveMember();
  MoveNames selected_move_name = move->MoveName();

  if (IsSwitch(selected_move_name)) {
    int switch_beg = static_cast<int>(MoveNames::kSwitch1);
    int selected = static_cast<int>(selected_move_name);

    if (team.ActiveTeam().size() <= 1 ||
        selected >= switch_beg + team.ActiveTeam().size() ||
        selected - static_cast<int>(MoveNames::kPass) - 1 ==
            team.IndexOfActiveMember()) {
      return false;
    }
  }

  SpeciesNames species_name = active_member->SpeciesName();

  if (is_called_by_ai) {
    if (active_member->MoveUsed()) {
      MoveNames last_move_name = active_member->MoveUsed()->MoveName();

      if ((active_member->IsVanished() &&
          selected_move_name != last_move_name) ||
          (active_member->IsChargingUp() &&
              selected_move_name != last_move_name) ||
          (active_member->IsUsingLockInMove() &&
              selected_move_name != last_move_name) ||
          (active_member->IsRaging() && selected_move_name != last_move_name) ||
          (active_member->UsedTrapMove() &&
              selected_move_name != last_move_name)) {
        return false;
      }
    }

    if ((!active_member->MustUseStruggle() &&
        selected_move_name == MoveNames::kStruggle) ||
        (active_member->IsTrapped() &&
            selected_move_name != MoveNames::kPass) ||
        (active_member->BideIsActive() &&
            selected_move_name != MoveNames::kPass) ||
        (active_member->IsRecharging() &&
            selected_move_name != MoveNames::kPass) ||
        (selected_move_name == MoveNames::kPass &&
            !active_member->IsRecharging() && !active_member->IsTrapped() &&
            !active_member->BideIsActive()) || (move->IsDisabled())) {
      return false;
    }
  } else {
    if (active_member->MoveUsed()) {
      MoveNames last_move_name = active_member->MoveUsed()->MoveName();

      if (active_member->IsVanished() && selected_move_name != last_move_name) {
        Gui::DisplayMustFinishVanishMessage(species_name);
        return false;
      }

      if (active_member->IsChargingUp()
          && selected_move_name != last_move_name) {
        Gui::DisplayMustFinishChargingUpMessage(species_name);
        return false;
      }

      if (active_member->IsUsingLockInMove() &&
          selected_move_name != last_move_name) {
        Gui::DisplayMustFinishLockInMessage(species_name);
        return false;
      }

      if (active_member->IsRaging() && selected_move_name != last_move_name) {
        Gui::DisplayMustFinishRagingMessage(species_name);
        return false;
      }

      if (active_member->UsedTrapMove()
          && selected_move_name != last_move_name) {
        Gui::DisplayMustFinishTrapMessage(species_name);
        return false;
      }
    }

    if (!active_member->MustUseStruggle() &&
        selected_move_name == MoveNames::kStruggle) {
      Gui::DisplayCantUseStruggleMessage(species_name);
      return false;
    }

    if (active_member->IsTrapped() && selected_move_name != MoveNames::kPass) {
      Gui::DisplayMustRemainTrappedMessage(species_name);
      return false;
    }

    if (active_member->BideIsActive()
        && selected_move_name != MoveNames::kPass) {
      Gui::DisplayMustFinishBideMessage(species_name);
      return false;
    }

    if (active_member->IsRecharging()
        && selected_move_name != MoveNames::kPass) {
      Gui::DisplayMustRechargeMessage(active_member->SpeciesName());
      return false;
    }

    if (selected_move_name == MoveNames::kPass &&
        !active_member->IsRecharging() && !active_member->IsTrapped() &&
        !active_member->BideIsActive()) {
      Gui::DisplayCantPassMessage(species_name);
      return false;
    }

    if (move->IsDisabled()) {
      Gui::DisplayMoveDisabledMessage(selected_move_name);
      return false;
    }
  }

  return static_cast<bool>(move->CurrentPp());
}

void BattleManager::HumanPicksMove(Team &team) {
  Gui::DisplayPickInBattleMoveMessage();
  std::shared_ptr<Pokemon> pokemon = team.ActiveMember();
  MovesContainer moves = team.ActiveMember()->GetMovesContainer();
  int move_choice;

  while (true) {
    move_choice = InputHandler::GetIntInput(1, moves.Size());

    if (IsValidMoveChoice(team, moves[move_choice - 1], false)) {
      break;
    }

    Gui::DisplayInvalidMoveChoiceMessage();
  }

  pokemon->SetMoveUsed(move_choice - 1);
}

bool BattleManager::HumanMovesFirst(const Team &human_team,
                                    const Team &ai_team) {
  std::shared_ptr<Pokemon> active_pokemon_human = human_team.ActiveMember();
  std::shared_ptr<Pokemon> active_pokemon_ai = ai_team.ActiveMember();

  bool human_moves_first = false;
  std::shared_ptr<Move> human_move = active_pokemon_human->MoveUsed();
  std::shared_ptr<Move> ai_move = active_pokemon_ai->MoveUsed();
  int human_move_priority = Priority(human_move->MoveName());
  int ai_move_priority = Priority(ai_move->MoveName());
  int human_speed =
      active_pokemon_human->GetNormalStatsContainer()[
          StatNames::kSpeed]->InGameStat();
  int ai_speed =
      active_pokemon_ai->GetNormalStatsContainer()[
          StatNames::kSpeed]->InGameStat();

  if (human_move_priority == ai_move_priority) {
    if (human_speed > ai_speed) {
      human_moves_first = true;
    } else if (human_speed == ai_speed) {
      if (RandomIntDistribution(0, 1) & 1) {
        human_moves_first = true;
      }
    }
  } else if (human_move_priority > ai_move_priority) {
    human_moves_first = true;
  }

  return human_moves_first;
}

bool BattleManager::HandleMove(Team &attacker, Team &defender) {
  UseMove(attacker, defender);
  std::shared_ptr<Pokemon> active_attacker = attacker.ActiveMember();
  std::shared_ptr<Pokemon> active_defender = defender.ActiveMember();

  if (active_attacker->IsFainted() || active_defender->IsFainted()) {
    if (active_attacker->IsRaging() || active_defender->IsRaging()) {
      Gui::DisplayRageEndedMessage();
    }

    active_attacker->ResetFaintFlags();
    active_defender->ResetFaintFlags();
    return false;
  }

  return true;
}

bool BattleManager::IsValidSwitchChoice(const Team &team, const int &index) {
  return index >= 0 && index < team.ActiveTeam().size();
}

void BattleManager::HumanPicksForcedSwitch(Team &human_team) {
  if (human_team.ActiveTeam().empty()) {
    return;
  }

  Gui::DisplayForceSwitchMessage();
  Gui::DisplayAvailableSwitchOptions(human_team);
  int switch_choice;

  while (true) {
    switch_choice = InputHandler::GetIntInput(1, static_cast<int>(
        human_team.ActiveTeam().size()));

    if (IsValidSwitchChoice(human_team, switch_choice - 1)) {
      break;
    }

    Gui::DisplayInvalidChoiceMessage();
  }

  human_team.SetActiveMember(switch_choice - 1);
}

void BattleManager::HandleEndOfTurnStatuses(
    const std::shared_ptr<Pokemon> &attacker,
    const std::shared_ptr<Pokemon> &defender) {
  if (attacker->IsFainted() || defender->IsFainted()) {
    return;
  }

  SpeciesNames attacker_species_name = attacker->SpeciesName();

  if (attacker->IsBurned()) {
    Gui::DisplayIsBurnedMessage(attacker_species_name);
    Gui::DisplayTookBurnDamageMessage(attacker_species_name,
                                      attacker->DoStatusDamage());
  } else if (attacker->IsPoisoned()) {
    Gui::DisplayIsPoisonedMessage(attacker_species_name, false);
    Gui::DisplayTookPoisonDamageMessage(attacker_species_name,
                                        attacker->DoStatusDamage());
  } else if (attacker->IsUnderToxic()) {
    Gui::DisplayIsPoisonedMessage(attacker_species_name, true);
    Gui::DisplayTookPoisonDamageMessage(attacker_species_name,
                                        attacker->DoStatusDamage());
    attacker->AdvanceToxicFactor();
  }

  if (attacker->IsSeeded()) {
    Gui::DisplayIsSeededMessage(attacker_species_name);
    int sapped = attacker->DoStatusDamage();
    Gui::DisplayHadHpSappedMessage(attacker_species_name, sapped);
    defender->AbsorbHp(sapped);
    Gui::DisplayHpAbsorbedMessage(defender->SpeciesName(), sapped);
  }
}

void BattleManager::HandleFainting(const bool &human_moves_first,
                                   Team &human_team, Team &ai_team) {
  std::shared_ptr<Pokemon> active_pokemon_human = human_team.ActiveMember();
  std::shared_ptr<Pokemon> active_pokemon_ai = ai_team.ActiveMember();

  if (human_moves_first) {
    if (active_pokemon_human->IsFainted()) {
      Gui::DisplayPokemonFaintedMessage(active_pokemon_human->SpeciesName());
      human_team.FaintActivePokemon();
      HumanPicksForcedSwitch(human_team);
    }

    if (active_pokemon_ai->IsFainted()) {
      Gui::DisplayPokemonFaintedMessage(active_pokemon_ai->SpeciesName());
      ai_team.FaintActivePokemon();
      PickForcedSwitch(ai_team, active_pokemon_human);
      Gui::DisplayAiForceSwitchMessage(ai_team.ActiveMember()->SpeciesName());
    }
  } else {
    if (active_pokemon_ai->IsFainted()) {
      Gui::DisplayPokemonFaintedMessage(active_pokemon_ai->SpeciesName());
      ai_team.FaintActivePokemon();
      PickForcedSwitch(ai_team, active_pokemon_human);
      Gui::DisplayAiForceSwitchMessage(ai_team.ActiveMember()->SpeciesName());
    }

    if (active_pokemon_human->IsFainted()) {
      Gui::DisplayPokemonFaintedMessage(active_pokemon_human->SpeciesName());
      human_team.FaintActivePokemon();
      HumanPicksForcedSwitch(human_team);
    }
  }
}

void BattleManager::HandleBothTeamsMoves(const bool &human_moves_first,
                                         Team &human_team, Team &ai_team) {
  std::shared_ptr<Pokemon> active_pokemon_human = human_team.ActiveMember();
  std::shared_ptr<Pokemon> active_pokemon_ai = ai_team.ActiveMember();

  if (human_moves_first && HandleMove(human_team, ai_team) &&
      HandleMove(ai_team, human_team)) {
    HandleEndOfTurnStatuses(active_pokemon_human, active_pokemon_ai);
    HandleEndOfTurnStatuses(active_pokemon_ai, active_pokemon_human);
  } else if (HandleMove(ai_team, human_team) &&
      HandleMove(human_team, ai_team)) {
    HandleEndOfTurnStatuses(active_pokemon_ai, active_pokemon_human);
    HandleEndOfTurnStatuses(active_pokemon_human, active_pokemon_ai);
  }
}

} //namespace artificialtrainer