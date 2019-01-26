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
auto Battle::BattleOver() const -> bool {
  return !team_one_.TeamSize() || !team_two_.TeamSize();
}

auto Battle::Play() -> void {
  Gui::DisplayWelcomeMessage();
  SelectTeam(true);
  SelectTeam(false);

  while (!BattleOver()) {
    break;
  }
}

auto Battle::SelectTeam(const bool &team_one) -> void {
  Gui::DisplayPokemonChoices();
  Gui::DisplayPickTeamMessage(team_one);

  for (int i = 0; i < Team::kMaxTeamSize; i++) {
    Gui::DisplayPickPokemonMessage(i + 1);
    int pokemon_selection = InputHandler::GetIntInput(1, kNumSpecies);
    Species pokemon_species = static_cast<Species>(pokemon_selection - 1);
    Gui::DisplayPickLevelMessage();
    int level_selection = InputHandler::GetIntInput(1, Pokemon::kMaxLevel);
    int normal_stats_count = 0;
    Stat stats[kNumNormalStats];
    Hp hp;

    for (int i = 0; i < kNumNormalStats + 1; i++) {
      StatNames stat_name = static_cast<StatNames>(i);
      Gui::DisplayPickEvMessage(stat_name);
      int ev_selection = InputHandler::GetIntInput(1, Ev::kMaxEv);
      Gui::DisplayPickIvMessage(stat_name);
      int iv_selection = InputHandler::GetIntInput(1, Iv::kMaxIv);

      if (static_cast<StatNames>(i) == StatNames::kHp) {
        hp = Hp(pokemon_species, level_selection, Ev(ev_selection), Iv
            (iv_selection));
      } else {
        Stat stat(pokemon_species, stat_name, Ev(ev_selection), Iv
            (iv_selection));
        stats[normal_stats_count++] = stat;
      }
    }

    std::shared_ptr<Pokemon> pokemon = std::make_shared<Pokemon>
        (pokemon_species, StatsContainer(pokemon_species, hp, stats),
            level_selection);

    if (team_one) {
      team_one_.AddPokemon(pokemon);
    } else {
      team_two_.AddPokemon(pokemon);
    }
  }
}

} //namespace artificialtrainer