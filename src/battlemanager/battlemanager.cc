/**
 * @project Artificial Trainer
 * @brief The implementation of the BattleManager class.
 *
 * @file battlemanager.cc
 * @author Neel Verma
 * @date 4/20/19
 */

#include "battlemanager.h"
#include "../clientelements/gui.h"
#include "../clientelements/inputhandler.h"
#include "../move/priority.h"
#include "../random/randomgenerator.h"
#include "../move/usemove.h"
#include "../ailogic/pickforcedswitch.h"
#include "../stringconverter/stringconverter.h"

namespace artificialtrainer {

/**
  * @brief: This function determines whether or not a given move is valid for
  * the given Pokemon.
  * @param const Team &team: The team that the Pokemon checking is on.
  * @param const std::shared_ptr<Move> &move: The move which is getting its
  * validity checked.
  * @param const bool &is_called_by_ai: Whether or not this function is used
  * in the minimax simulation. The reason this is passed is because there is
  * GUI output in here, which should not be shown when the minimax is
  * simulating the game.
  */

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

/**
  * @brief: This function lets the human pick a move for a given Pokemon.
  * @param Team &team: The team that has the current active human Pokemon.
  */

void BattleManager::HumanPicksMove(Team &team) {
  Gui::DisplayPickInBattleMoveMessage();
  std::shared_ptr<Pokemon> pokemon = team.ActiveMember();
  MovesContainer moves = pokemon->GetMovesContainer();
  int move_choice;

  while (true) {
    move_choice = InputHandler::GetIntInput(1, moves.Size());

    if (IsValidMoveChoice(team, moves[move_choice - 1], false)) {
      break;
    }

    Gui::DisplayInvalidMoveChoiceMessage();
  }

  team.ActiveMember()->SetMoveUsed(
      pokemon->GetMovesContainer()[move_choice - 1]);
}

/**
  * @brief: This function decides whether or not the human will move first.
  * Moving first is based on who has the higher soeed stat. In the case of a
  * speed tie, a random chance happens to see who moves first.
  * @param const Team &human_team: The human's team.
  * @param const Team &ai_team: The ai's team.
  * @return bool: Whether or not the human will move first.
  */

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

/**
  * @brief: This function handles a move for a given attacking and defending
  * Pokemon.
  * @param Team &attacker: The attacking team.
  * @param Team &defender: The defending team.
  * @return bool: If the move was successful. This is used because in order
  * for a Pokemon who has not moved yet, the attacking Pokemon must have
  * finished its move without it or the defending Pokemon fainting.
  */

bool BattleManager::HandleMove(Team &attacker, Team &defender) {
  UseMove(attacker, defender, false);
  std::shared_ptr<Pokemon> active_attacker = attacker.ActiveMember();
  std::shared_ptr<Pokemon> active_defender = defender.ActiveMember();
  return !(active_attacker->IsFainted() || active_defender->IsFainted());
}

/**
  * @brief: This function determines whether or not a switch move is valid for
  * the given team.
  * @param const Team &team: The team that is being checked.
  * @param const int &index: The index of the move from the active Pokemon's
  * moveset.
  * @return bool: Whether or not the move selected is a valid switch.
  */

bool BattleManager::IsValidSwitchChoice(const Team &team, const int &index) {
  return index >= 0 && index < team.ActiveTeam().size();
}

/**
  * @brief: This function lets the human player pick its switch in for when
  * its active Pokemon fainted.
  * @param Team &human_team: The human's team.
  */

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

/**
  * @brief: This function handles all of the statuses that must be handled at
  * the end of a turn sequence.
  * @param const std::shared_ptr<Pokemon> &attacker: The attacking Pokemon.
  * @param const std::shared_ptr<Pokemon> &defender: The defending Pokemon.
  * @param const bool &is_called_by_ai: Whether or not this function is used
  * in the minimax simulation. The reason this is passed is because there is
  * GUI output in here, which should not be shown when the minimax is
  * simulating the game.
  */

void BattleManager::HandleEndOfTurnStatuses(
    const std::shared_ptr<Pokemon> &attacker,
    const std::shared_ptr<Pokemon> &defender,
    const bool &is_called_by_ai) {
  if (attacker->IsFainted() || defender->IsFainted()) {
    return;
  }

  SpeciesNames attacker_species_name = attacker->SpeciesName();

  if (attacker->IsBurned()) {
    int status_damage = attacker->DoStatusDamage();

    if (!is_called_by_ai) {
      Gui::DisplayIsBurnedMessage(attacker_species_name);
      Gui::DisplayTookBurnDamageMessage(attacker_species_name,
                                        status_damage);
    }
  } else if (attacker->IsPoisoned()) {
    int status_damage = attacker->DoStatusDamage();

    if (!is_called_by_ai) {
      Gui::DisplayIsPoisonedMessage(attacker_species_name, false);
      Gui::DisplayTookPoisonDamageMessage(attacker_species_name,
                                          status_damage);
    }
  } else if (attacker->IsUnderToxic()) {
    int status_damage = attacker->DoStatusDamage();

    if (!is_called_by_ai) {
      Gui::DisplayIsPoisonedMessage(attacker_species_name, true);
      Gui::DisplayTookPoisonDamageMessage(attacker_species_name,
                                          status_damage);
    }

    attacker->AdvanceToxicFactor();
  }

  if (attacker->IsSeeded()) {
    int sapped = attacker->DoStatusDamage();
    defender->AbsorbHp(sapped);

    if (!is_called_by_ai) {
      Gui::DisplayIsSeededMessage(attacker_species_name);
      Gui::DisplayHadHpSappedMessage(attacker_species_name, sapped);
      Gui::DisplayHpAbsorbedMessage(defender->SpeciesName(), sapped);
    }
  }
}

/**
  * @brief: This function determines whether or not a given team has the
  * ability to switch Pokemon.
  * @param const Team &team: The team that is being checked.
  * @return bool: Whether or not the given team has the ability to switch.
  */

bool BattleManager::CanSwitch(const Team &team) {
  return team.ActiveTeam().size() > 1;
}

/**
  * @brief: This function handles fainting for both teams.
  * @param const bool &human_moves_first: Whether or not the human moved
  * first in that turn sequence. This is important because whoever moved
  * first faints first in the case when both Pokemon fainted at the same time.
  * @param Team &human_team: The human's team.
  * @param Team &ai_team: The ai's team.
  * @param const bool &is_called_by_ai: Whether or not this function is used
  * in the minimax simulation. The reason this is passed is because there is
  * GUI output in here, which should not be shown when the minimax is
  * simulating the game.
  */

void BattleManager::HandleFainting(const bool &human_moves_first,
                                   Team &human_team, Team &ai_team,
                                   const bool &is_called_by_ai) {
  std::shared_ptr<Pokemon> active_pokemon_human = human_team.ActiveMember();
  std::shared_ptr<Pokemon> active_pokemon_ai = ai_team.ActiveMember();

  if (human_moves_first) {
    if (active_pokemon_human->IsFainted() && CanSwitch(human_team)) {
      if ((active_pokemon_human->IsRaging() || active_pokemon_ai->IsRaging()) &&
          !is_called_by_ai) {
        Gui::DisplayRageEndedMessage();
      }

      active_pokemon_human->ResetFaintFlags();
      active_pokemon_ai->ResetFaintFlags();

      if (!is_called_by_ai) {
        Gui::DisplayPokemonFaintedMessage(active_pokemon_human->SpeciesName());
      }

      human_team.FaintActivePokemon();

      if (is_called_by_ai) {
        PickForcedSwitch(human_team, active_pokemon_ai);
      } else {
        HumanPicksForcedSwitch(human_team);
      }
    }

    if (active_pokemon_ai->IsFainted() && CanSwitch(ai_team)) {
      if ((active_pokemon_human->IsRaging() || active_pokemon_ai->IsRaging()) &&
          !is_called_by_ai) {
        Gui::DisplayRageEndedMessage();
      }

      active_pokemon_human->ResetFaintFlags();
      active_pokemon_ai->ResetFaintFlags();

      if (!is_called_by_ai) {
        Gui::DisplayPokemonFaintedMessage(active_pokemon_ai->SpeciesName());
      }

      ai_team.FaintActivePokemon();
      PickForcedSwitch(ai_team, active_pokemon_human);

      if (!is_called_by_ai) {
        Gui::DisplayAiForceSwitchMessage(ai_team.ActiveMember()->SpeciesName());
      }
    }
  } else {
    if (active_pokemon_ai->IsFainted() && CanSwitch(ai_team)) {
      if ((active_pokemon_human->IsRaging() || active_pokemon_ai->IsRaging()) &&
          !is_called_by_ai) {
        Gui::DisplayRageEndedMessage();
      }

      active_pokemon_human->ResetFaintFlags();
      active_pokemon_ai->ResetFaintFlags();

      if (!is_called_by_ai) {
        Gui::DisplayPokemonFaintedMessage(active_pokemon_ai->SpeciesName());
      }

      ai_team.FaintActivePokemon();
      PickForcedSwitch(ai_team, active_pokemon_human);

      if (!is_called_by_ai) {
        Gui::DisplayAiForceSwitchMessage(ai_team.ActiveMember()->SpeciesName());
      }
    }

    if (active_pokemon_human->IsFainted() && CanSwitch(human_team)) {
      if ((active_pokemon_human->IsRaging() || active_pokemon_ai->IsRaging()) &&
          !is_called_by_ai) {
        Gui::DisplayRageEndedMessage();
      }

      active_pokemon_human->ResetFaintFlags();
      active_pokemon_ai->ResetFaintFlags();

      if (!is_called_by_ai) {
        Gui::DisplayPokemonFaintedMessage(active_pokemon_human->SpeciesName());
      }

      human_team.FaintActivePokemon();

      if (is_called_by_ai) {
        PickForcedSwitch(human_team, active_pokemon_ai);
      } else {
        HumanPicksForcedSwitch(human_team);
      }
    }
  }
}

/**
  * @brief: This function handles moves for both teams.
  * @param const bool &human_moves_first: Whether or not the human moved
  * first in that turn sequence.
  * @param Team &human_team: The human's team.
  * @param Team &ai_team: The ai's team.
  * @param const bool &is_called_by_ai: Whether or not this function is used
  * in the minimax simulation. The reason this is passed is because there is
  * GUI output in here, which should not be shown when the minimax is
  * simulating the game.
  */

void BattleManager::HandleBothTeamsMoves(const bool &human_moves_first,
                                         Team &human_team, Team &ai_team,
                                         const bool &is_called_by_ai) {
  std::shared_ptr<Pokemon> active_pokemon_human = human_team.ActiveMember();
  std::shared_ptr<Pokemon> active_pokemon_ai = ai_team.ActiveMember();

  if (human_moves_first && HandleMove(human_team, ai_team) &&
      HandleMove(ai_team, human_team)) {
    HandleEndOfTurnStatuses(
        active_pokemon_human, active_pokemon_ai, is_called_by_ai);
    HandleEndOfTurnStatuses(
        active_pokemon_ai, active_pokemon_human, is_called_by_ai);
  } else if (HandleMove(ai_team, human_team) &&
      HandleMove(human_team, ai_team)) {
    HandleEndOfTurnStatuses(
        active_pokemon_ai, active_pokemon_human, is_called_by_ai);
    HandleEndOfTurnStatuses(
        active_pokemon_human, active_pokemon_ai, is_called_by_ai);
  }
}

} //namespace artificialtrainer