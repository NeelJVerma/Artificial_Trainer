//
// Created by neel on 1/25/19.
//

#include <random>
#include <ctime>
#include "battle.h"
#include "../clientelements/gui.h"
#include "../clientelements/inputhandler.h"
#include "../stat/ev.h"
#include "../stat/iv.h"
#include "../move/movenames.h"
#include "../pokemon/learnset.h"
#include "../move/movescontainer.h"
#include "../move/pp.h"
#include "../stringconverter/stringconverter.h"
#include "../move/priority.h"
#include "../move/usemove.h"

namespace artificialtrainer {
namespace {
bool MoveInLearnset(const std::vector<MoveNames> &learnset,
                    const MoveNames &move_selected) {
  for (MoveNames learned_move : learnset) {
    if (move_selected == learned_move) {
      return true;
    }
  }

  return false;
}

void SelectTeam(Team &team, const bool &team_one) {
  Gui::DisplayPokemonChoices();
  Gui::DisplayPickTeamMessage(team_one);

  // TODO: CHANGE BACK TO ACTUAL TEAM SIZE WHEN DONE TESTING
  for (int i = 0; i < Team::kMaxTeamSize - 5; i++) {
    Gui::DisplayPickPokemonMessage(i + 1);
    int pokemon_selection = InputHandler::GetIntInput(1, kNumSpecies);
    auto pokemon_species = static_cast<SpeciesNames>(pokemon_selection - 1);

    if (team.SeenPokemon(pokemon_species)) {
      Gui::DisplayInvalidChoiceMessage();
      i--;
      continue;
    }

    Gui::DisplayPickLevelMessage();
    int level_selection = InputHandler::GetIntInput(1, Pokemon::kMaxLevel);
    int normal_stats_count = 0;
    std::shared_ptr<NormalStat> stats[kNumNormalStats];
    std::shared_ptr<Hp> hp;

    for (int j = 0; j < kNumNormalStats + 1; j++) {
      auto stat_name = static_cast<StatNames>(j);
      Gui::DisplayPickEvMessage(stat_name);
      int ev_selection = InputHandler::GetIntInput(1, Ev::kMaxEv);
      Gui::DisplayPickIvMessage(stat_name);
      int iv_selection = InputHandler::GetIntInput(1, Iv::kMaxIv);

      if (stat_name == StatNames::kHp) {
        hp = std::make_shared<Hp>(pokemon_species, level_selection,
                                  Ev(ev_selection), Iv(iv_selection));
      } else {
        stats[normal_stats_count++] = std::make_shared<NormalStat>
            (pokemon_species,
             level_selection,
             stat_name,
             Ev(ev_selection),
             Iv(iv_selection));
      }
    }

    std::vector<MoveNames> learnset = Learnset(pokemon_species);
    Gui::DisplayPokemonLearnset(learnset);
    MovesContainer moves_container{};

    for (int j = 0; j < learnset.size() && j < MovesContainer::kMaxMoves; j++) {
      Gui::DisplayPickMoveMessage(j + 1);
      int move_selection = InputHandler::GetIntInput(1, kNumMoves);
      auto move_name = static_cast<MoveNames>(move_selection);

      if (!MoveInLearnset(learnset, move_name) ||
          moves_container.SeenMove(move_name)) {
        Gui::DisplayInvalidChoiceMessage();
        j--;
        continue;
      }

      moves_container.AddMove(std::make_shared<Move>(move_name, Pp(move_name)));
    }

    MoveNames pass_move = MoveNames::kPass;
    moves_container.AddMove(std::make_shared<Move>(pass_move, Pp(pass_move)));

    for (int j = static_cast<int>(MoveNames::kSwitch1);
         j <= static_cast<int>(MoveNames::kSwitch6); j++) {
      auto switch_move = static_cast<MoveNames>(j);
      moves_container.AddMove(
          std::make_shared<Move>(switch_move, Pp(switch_move)));
    }

    team.AddPokemon(std::make_shared<Pokemon>(pokemon_species,
                                              NormalStatsContainer(stats),
                                              moves_container,
                                              TypeContainer(pokemon_species),
                                              level_selection, hp));
  }
}

bool IsValidMoveChoice(const Team &team, const std::shared_ptr<Move> &move) {
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

  MoveNames last_move_name = active_member->MoveUsed()->MoveName();
  SpeciesNames species_name = active_member->SpeciesName();

  if (active_member->IsVanished() && selected_move_name != last_move_name) {
    Gui::DisplayMustFinishVanishMessage(species_name);
    return false;
  }

  if (active_member->IsChargingUp() && selected_move_name != last_move_name) {
    Gui::DisplayMustFinishChargingUpMessage(species_name);
    return false;
  }

  if (active_member->IsUsingLockInMove() &&
      selected_move_name != last_move_name) {
    Gui::DisplayMustFinishLockInMessage(species_name);
    return false;
  }

  if (active_member->IsTrapped() && selected_move_name != MoveNames::kPass) {
    Gui::DisplayMustRemainTrappedMessage(species_name);
    return false;
  }

  if (active_member->BideIsActive() && selected_move_name != MoveNames::kPass) {
    Gui::DisplayMustFinishBideMessage(species_name);
    return false;
  }

  if (active_member->IsRecharging() && selected_move_name != MoveNames::kPass) {
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

  if (active_member->IsRaging() && selected_move_name != last_move_name) {
    Gui::DisplayMustFinishRagingMessage(species_name);
    return false;
  }

  if (active_member->UsedTrapMove() && selected_move_name != last_move_name) {
    Gui::DisplayMustFinishTrapMessage(species_name);
    return false;
  }

  return static_cast<bool>(move->CurrentPp());
}

bool IsValidSwitchChoice(const Team &team, const int &index) {
  return index >= 0 && index < team.ActiveTeam().size();
}

} //namespace

bool Battle::BattleOver() const {
  return team_one_.ActiveTeam().empty() || team_two_.ActiveTeam().empty();
}

void Battle::StartBattle() {
  Gui::DisplayPlayerTeam(team_one_, true);
  Gui::DisplayPlayerTeam(team_two_, false);
  Gui::DisplayPickLeadingPokemonMessage(true);
  team_one_.SetActiveMember(
      InputHandler::GetIntInput(1, Team::kMaxTeamSize) - 1);
  Gui::DisplayPickLeadingPokemonMessage(false);
  team_two_.SetActiveMember(
      InputHandler::GetIntInput(1, Team::kMaxTeamSize) - 1);
}

void Battle::PlayerPicksForcedSwitch(Team &team) {
  if (team.ActiveTeam().empty()) {
    return;
  }

  Gui::DisplayForceSwitchMessage();
  Gui::DisplayAvailableSwitchOptions(team);
  int switch_choice;

  while (true) {
    switch_choice = InputHandler::GetIntInput(1, static_cast<int>(
        team.ActiveTeam().size()));

    if (IsValidSwitchChoice(team, switch_choice - 1)) {
      break;
    }

    Gui::DisplayInvalidChoiceMessage();
  }

  team.SwitchAction(switch_choice - 1);
}

void Battle::PlayerPicksMove(Team &team, const bool &team_one) {
  Gui::DisplayPickInBattleMoveMessage(team_one);
  std::shared_ptr<Pokemon> pokemon = team.ActiveMember();
  MovesContainer moves = team.ActiveMember()->GetMovesContainer();
  int move_choice;

  if (pokemon->MustUseStruggle()) {
    moves.ReplaceAllWithStruggle();
  }

  while (true) {
    move_choice = InputHandler::GetIntInput(1, moves.Size());

    if (IsValidMoveChoice(team, moves[move_choice - 1])) {
      break;
    }

    Gui::DisplayInvalidMoveChoiceMessage();
  }

  pokemon->SetMoveUsed(move_choice - 1);
}

bool Battle::CheckIfActivePokemonIsStillAlive(
    const std::shared_ptr<Pokemon> &pokemon, Team &team) {
  if (!pokemon->HpStat()->CurrentHp()) {
    Gui::DisplayPokemonFaintedMessage(pokemon->SpeciesName());
    team.FaintActivePokemon();
    PlayerPicksForcedSwitch(team);
    return false;
  }

  return true;
}

bool Battle::HandleMove(Team &attacker, Team &defender) {
  UseMove(attacker, defender);
  std::shared_ptr<Pokemon> active_attacker = attacker.ActiveMember();
  std::shared_ptr<Pokemon> active_defender = defender.ActiveMember();

  if (!CheckIfActivePokemonIsStillAlive(active_attacker, attacker) ||
      !CheckIfActivePokemonIsStillAlive(active_defender, defender)) {
    if (active_attacker->IsRaging() || active_defender->IsRaging()) {
      Gui::DisplayRageEndedMessage();
    }

    active_attacker->ResetFaintFlags();
    active_defender->ResetFaintFlags();
    return false;
  }

  return true;
}

void Battle::HandleEndOfTurnStatuses(const std::shared_ptr<Pokemon> &attacker,
                                     const std::shared_ptr<Pokemon> &defender,
                                     Team &team) {
  if (!attacker->HpStat()->CurrentHp() || !defender->HpStat()->CurrentHp()) {
    return;
  }

  if (attacker->IsBurned()) {
    attacker->DoBurnDamage();
  } else if (attacker->IsPoisoned()) {
    attacker->DoPoisonDamage();
  } else if (attacker->IsUnderToxic()) {
    attacker->DoToxicDamage();
  }

  if (attacker->IsSeeded()) {
    defender->AbsorbHp(attacker->DoLeechSeedDamage());
  }

  CheckIfActivePokemonIsStillAlive(attacker, team);
}

void Battle::HandleTurn() {
  Gui::DisplayPlayerTeam(team_one_, true);
  Gui::DisplayPlayerTeam(team_two_, false);
  std::shared_ptr<Pokemon> active_pokemon_one = team_one_.ActiveMember();
  Gui::DisplayActivePokemonData(active_pokemon_one, true);
  std::shared_ptr<Pokemon> active_pokemon_two = team_two_.ActiveMember();
  Gui::DisplayActivePokemonData(active_pokemon_two, false);
  PlayerPicksMove(team_one_, true);
  PlayerPicksMove(team_two_, false);
  bool one_moves_first = false;
  NormalStatsContainer normal_active_stats_one =
      active_pokemon_one->GetNormalStatsContainer();
  NormalStatsContainer normal_active_stats_two =
      active_pokemon_two->GetNormalStatsContainer();
  std::shared_ptr<Move> move_one = active_pokemon_one->MoveUsed();
  std::shared_ptr<Move> move_two = active_pokemon_two->MoveUsed();

  if (Priority(move_one->MoveName()) ==
      Priority(move_two->MoveName())) {
    if (normal_active_stats_one[StatNames::kSpeed]->InGameStat() >
        normal_active_stats_two[StatNames::kSpeed]->InGameStat()) {
      one_moves_first = true;
    } else if (normal_active_stats_one[StatNames::kSpeed]->InGameStat() ==
        normal_active_stats_two[StatNames::kSpeed]->InGameStat()) {
      std::random_device device;
      std::mt19937 generator(device());
      std::uniform_int_distribution<> distribution(0, 1);

      if (distribution(generator) & 1) {
        one_moves_first = true;
      }
    }
  } else if (Priority(move_one->MoveName()) > Priority(move_two->MoveName())) {
    one_moves_first = true;
  }

  if (one_moves_first && HandleMove(team_one_, team_two_) &&
      HandleMove(team_two_, team_one_)) {
    HandleEndOfTurnStatuses(active_pokemon_one,
                            active_pokemon_two,
                            team_one_);
    HandleEndOfTurnStatuses(active_pokemon_two,
                            active_pokemon_one,
                            team_two_);
  } else if (!one_moves_first && HandleMove(team_two_, team_one_) &&
      HandleMove(team_one_, team_two_)) {
    HandleEndOfTurnStatuses(active_pokemon_two,
                            active_pokemon_one,
                            team_two_);
    HandleEndOfTurnStatuses(active_pokemon_one,
                            active_pokemon_two,
                            team_one_);
  }

  active_pokemon_one->ResetEndOfTurnFlags();
  active_pokemon_two->ResetEndOfTurnFlags();
}

void Battle::Play() {
  Gui::DisplayWelcomeMessage();
  SelectTeam(team_one_, true);
  SelectTeam(team_two_, false);
  StartBattle();
  int num_turns_elapsed = 0;

  while (num_turns_elapsed++ < kMaxNumTurns && !BattleOver()) {
    Gui::DisplayTurnNumber(num_turns_elapsed);
    HandleTurn();
  }

  Gui::DisplayBattleOverMessage();
  Gui::DisplayPlayerTeam(team_one_, true);
  Gui::DisplayPlayerTeam(team_two_, false);
}

} //namespace artificialtrainer