//
// Created by neel on 1/25/19.
//

#include "battle.h"
#include "../clientelements/gui.h"
#include "../clientelements/inputhandler.h"
#include "../stat/ev.h"
#include "../stat/iv.h"
#include "../stringconversions/stringconverter.h"

namespace artificialtrainer {
namespace {
auto SelectTeam(Team &team, const bool &team_one) -> void {
  Gui::DisplayPokemonChoices();
  Gui::DisplayPickTeamMessage(team_one);

  for (int i = 0; i < Team::kMaxTeamSize; i++) {
    Gui::DisplayPickPokemonMessage(i + 1);
    int pokemon_selection = InputHandler::GetIntInput(1, kNumSpecies);
    auto pokemon_species = static_cast<Species>(pokemon_selection - 1);

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
        stats[normal_stats_count++] = stat(pokemon_species, stat_name,
            Ev(ev_selection), Iv(iv_selection);
      }
    }

    team.AddPokemon(std::make_shared<Pokemon>(pokemon_species,
        StatsContainer(pokemon_species, hp, stats), level_selection));
  }
}

} //namespace

auto Battle::BattleOver() const -> bool {
  return !team_one_.TeamSize() || !team_two_.TeamSize();
}

auto Battle::Play() -> void {
  Gui::DisplayWelcomeMessage();
  SelectTeam(team_one_, true);
  SelectTeam(team_two_, false);

  while (!BattleOver()) {
    break;
  }
}

} //namespace artificialtrainer