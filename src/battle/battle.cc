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
                                              NormalStatsContainer(
                                                  pokemon_species,
                                                  hp,
                                                  stats),
                                              moves_container,
                                              TypeContainer(pokemon_species),
                                              level_selection));
  }
}

bool IsValidMoveChoice(const Team &team, const std::shared_ptr<Move> &move) {
  if (IsSwitch(move->MoveName())) {
    int switch_beg = static_cast<int>(MoveNames::kSwitch1);
    int selected = static_cast<int>(move->MoveName());

    // TODO: ADD CHECKS FOR DIGGING/FLYING/RECHARGING FLAGS
    if (team.ActiveTeam().size() <= 1 ||
        selected >= switch_beg + team.ActiveTeam().size()) {
      return false;
    }

    if (selected - static_cast<int>(MoveNames::kPass) - 1 ==
        team.IndexOfActiveMember()) {
      return false;
    }
  }

  if (move->IsDisabled()) {
    return false;
  }

  // TODO: ADD CHECKS FOR PASSING AS WELL

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

  while (true) {
    move_choice = InputHandler::GetIntInput(1, moves.Size());

    if (IsValidMoveChoice(team, moves[move_choice - 1])) {
      break;
    }

    Gui::DisplayInvalidMoveChoiceMessage();
  }

  pokemon->SetMoveUsed(move_choice - 1);
}

bool Battle::DoPokemonActiveCheck(const std::shared_ptr<Pokemon> &pokemon,
                                  Team &team) {
  if (!pokemon->GetNormalStatsContainer().HpStat()->CurrentHp()) {
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

  return DoPokemonActiveCheck(active_attacker, attacker) ||
      DoPokemonActiveCheck(active_defender, defender);
}

void Battle::HandleEndOfTurnStatuses(const std::shared_ptr<Pokemon> &pokemon,
                                     Team &team) {
  if (pokemon->IsBurned()) {
    pokemon->DoBurnDamage();
  }

  DoPokemonActiveCheck(pokemon, team);
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

  // TODO: burn/toxic/leech seed/other end of turn statuses: put in function
  if (one_moves_first && HandleMove(team_one_, team_two_)) {
    HandleMove(team_two_, team_one_);
    HandleEndOfTurnStatuses(active_pokemon_one, team_one_);
    HandleEndOfTurnStatuses(active_pokemon_two, team_two_);
  } else if (!one_moves_first && HandleMove(team_two_, team_one_)) {
    HandleMove(team_one_, team_two_);
    HandleEndOfTurnStatuses(active_pokemon_two, team_two_);
    HandleEndOfTurnStatuses(active_pokemon_one, team_one_);
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