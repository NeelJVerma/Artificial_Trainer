//
// Created by neel on 1/25/19.
//

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

namespace artificialtrainer {
namespace {
auto PokemonLearnsMove(const std::vector<MoveNames> &learnset,
                       const MoveNames &move_selected) -> bool {
  for (MoveNames learned_move : learnset) {
    if (move_selected == learned_move) {
      return true;
    }
  }

  return false;
}

auto SelectTeam(Team &team, const bool &team_one) -> void {
  Gui::DisplayPokemonChoices();
  Gui::DisplayPickTeamMessage(team_one);

  // TODO: CHANGE LOOP VARIABLE AFTER TESTING
  for (int i = 0; i < 2; i++) {
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
    Stat stats[kNumNormalStats];
    Hp hp{};

    for (int j = 0; j < kNumNormalStats + 1; j++) {
      auto stat_name = static_cast<StatNames>(j);
      Gui::DisplayPickEvMessage(stat_name);
      int ev_selection = InputHandler::GetIntInput(1, Ev::kMaxEv);
      Gui::DisplayPickIvMessage(stat_name);
      int iv_selection = InputHandler::GetIntInput(1, Iv::kMaxIv);

      if (stat_name == StatNames::kHp) {
        hp = Hp(pokemon_species, level_selection, Ev(ev_selection),
                Iv(iv_selection));
      } else {
        stats[normal_stats_count++] = Stat(pokemon_species, stat_name,
                                           Ev(ev_selection), Iv(iv_selection));
      }
    }

    std::vector<MoveNames> learnset = Learnset(pokemon_species);
    Gui::DisplayPokemonLearnset(learnset);
    MovesContainer moves_container{};

    for (int j = 0; j < learnset.size() && j < MovesContainer::kMaxMoves; j++) {
      Gui::DisplayPickMoveMessage(j + 1);
      int move_selection = InputHandler::GetIntInput(1, kNumMoves);
      auto move_name = static_cast<MoveNames>(move_selection);

      if (!PokemonLearnsMove(learnset, move_name) ||
          moves_container.SeenMove(move_name)) {
        Gui::DisplayInvalidChoiceMessage();
        j--;
        continue;
      }

      moves_container.AddMove(Move(move_name, Pp(move_name)));
    }

    team.AddPokemon(Pokemon(pokemon_species,
                            StatsContainer(pokemon_species,
                                           hp, stats),
                            moves_container,
                            TypeContainer(pokemon_species),
                            level_selection));
  }
}

} //namespace

auto Battle::BattleOver() const -> bool {
  return !team_one_.ActiveTeamSize() || !team_two_.ActiveTeamSize();
}

auto Battle::StartBattle() -> void {
  Gui::DisplayPlayerTeam(team_one_, true);
  Gui::DisplayPlayerTeam(team_two_, false);
  Gui::DisplayPickLeadingPokemonMessage(true);
  int ones_leading_index = InputHandler::GetIntInput(1, Team::kMaxTeamSize);
  team_one_.SetActiveMember(ones_leading_index - 1);
  Gui::DisplayPickLeadingPokemonMessage(false);
  int twos_leading_index = InputHandler::GetIntInput(1, Team::kMaxTeamSize);
  team_two_.SetActiveMember(twos_leading_index - 1);
}

auto Battle::HandleTurn() -> void {
  Gui::DisplayPlayerTeam(team_one_, true);
  Gui::DisplayPlayerTeam(team_two_, false);
  Gui::DisplayActivePokemonData(team_one_.FindActiveMember(), true);
  Gui::DisplayActivePokemonData(team_two_.FindActiveMember(), false);
}

auto Battle::Play() -> void {
  Gui::DisplayWelcomeMessage();
  SelectTeam(team_one_, true);
  SelectTeam(team_two_, false);
  StartBattle();
  int num_turns_elapsed = 1;

  while (num_turns_elapsed++ < kMaxNumTurns && !BattleOver()) {
    HandleTurn();
    break;
  }
}

} //namespace artificialtrainer