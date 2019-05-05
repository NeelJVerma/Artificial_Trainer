/**
 * @project Artificial Trainer
 * @brief The implementation of the Battle class.
 *
 * @file battle.cc
 * @author Neel Verma
 * @date 1/25/19
 */

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
#include "../random/randomgenerator.h"
#include "../ailogic/pickleadingpokemon.h"
#include "../ailogic/pickforcedswitch.h"
#include "../battlemanager/battlemanager.h"
#include "../ailogic/expectimax.h"

namespace artificialtrainer {
namespace {

/**
  * @brief: This function is responsible for, given a team, picking the
  * Pokemon, moves, stats, etc. for that team.
  * @param Team &team: The team that will be filled.
  */

void PickRandomTeam(Team &team) {
  for (int i = 0; i < Team::kMaxTeamSize; i++) {
    auto pokemon_species = static_cast<SpeciesNames>(
        RandomIntDistribution(1, kNumSpecies) - 1);

    if (team.SeenPokemon(pokemon_species)) {
      i--;
      continue;
    }

    int normal_stats_count = 0;
    std::shared_ptr<NormalStat> stats[kNumNormalStats];
    std::shared_ptr<Hp> hp;

    for (int j = 0; j < kNumNormalStats + 1; j++) {
      auto stat_name = static_cast<StatNames>(j);

      if (stat_name == StatNames::kHp) {
        hp = std::make_shared<Hp>(pokemon_species, Pokemon::kMaxLevel,
                                  Ev(Ev::kMaxEv), Iv(Iv::kMaxIv));
      } else {
        stats[normal_stats_count++] = std::make_shared<NormalStat>
            (pokemon_species,
             Pokemon::kMaxLevel,
             stat_name,
             Ev(Ev::kMaxEv),
             Iv(Iv::kMaxIv));
      }
    }

    std::vector<MoveNames> learnset = Learnset(pokemon_species);
    MovesContainer moves_container{};

    for (int j = 0; j < learnset.size() && j < MovesContainer::kMaxMoves; j++) {
      MoveNames move_name = learnset[RandomIntDistribution(
          0, learnset.size() - 1)];

      if (moves_container.SeenMove(move_name)) {
        j--;
        continue;
      }

      moves_container.AddMove(std::make_shared<Move>(move_name, Pp(move_name)));
    }

    MoveNames pass_move = MoveNames::kPass;
    moves_container.AddMove(std::make_shared<Move>(pass_move, Pp(pass_move)));
    MoveNames struggle_move = MoveNames::kStruggle;
    moves_container.AddMove(std::make_shared<Move>(
        struggle_move, Pp(struggle_move)));

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
                                              Pokemon::kMaxLevel, hp));
  }
}

} //namespace

/**
  * @brief: The default constructor for the Battle class. Initializes two
  * empty teams.
  */

Battle::Battle() {
  human_team_ = Team{};
  ai_team_ = Team{};
  human_team_.SetIsHuman(true);
  ai_team_.SetIsHuman(false);
}

/**
  * @brief: Determines if a battle is over or not.
  * @return bool: Whether or not the battle is over.
  */

bool Battle::BattleOver() const {
  return human_team_.ActiveTeam().empty() || ai_team_.ActiveTeam().empty();
}

/**
  * @brief: Handles a turn sequence in the game.
  */

void Battle::HandleTurn() {
  Gui::DisplayPlayerTeam(human_team_, true);
  Gui::DisplayPlayerTeam(ai_team_, false);
  std::shared_ptr<Pokemon> active_pokemon_human = human_team_.ActiveMember();
  Gui::DisplayActivePokemonData(active_pokemon_human, true);
  std::shared_ptr<Pokemon> active_pokemon_ai = ai_team_.ActiveMember();
  Gui::DisplayActivePokemonData(active_pokemon_ai, false);
  BattleManager::HumanPicksMove(human_team_);
  ai_team_.ActiveMember()->SetMoveUsed(
      ExpectiMax(human_team_, ai_team_).MoveIndex());
  bool human_moves_first = BattleManager::HumanMovesFirst(human_team_,
                                                          ai_team_);
  BattleManager::HandleBothTeamsMoves(human_moves_first, human_team_,
      ai_team_, false);
  BattleManager::HandleFainting(human_moves_first, human_team_, ai_team_,
   false);
  active_pokemon_human->ResetEndOfTurnFlags();
  active_pokemon_ai->ResetEndOfTurnFlags();
}

/**
  * @brief: Starts the battle.
  */

void Battle::StartBattle() {
  Gui::DisplayPlayerTeam(human_team_, true);
  Gui::DisplayPlayerTeam(ai_team_, false);
  Gui::DisplayPickLeadingPokemonMessage(true);
  human_team_.SetActiveMember(
      InputHandler::GetIntInput(1, Team::kMaxTeamSize) - 1);
  PickLeadingPokemon(ai_team_, human_team_);
  Gui::DisplayAiPickedLeadingPokemonMessage(
      ai_team_.ActiveMember()->SpeciesName());
}

/**
  * @brief: Plays the battle in its entirety.
  */

void Battle::Play() {
  Gui::DisplayWelcomeMessage();
  Gui::DisplayPickingTeamMessage(true);
  PickRandomTeam(human_team_);
  Gui::DisplayPickingTeamMessage(false);
  PickRandomTeam(ai_team_);
  StartBattle();
  int num_turns_elapsed = 0;

  while (num_turns_elapsed++ < kMaxNumTurns && !BattleOver()) {
    Gui::DisplayTurnNumber(num_turns_elapsed);
    HandleTurn();
  }

  Gui::DisplayBattleOverMessage();
  Gui::DisplayPlayerTeam(human_team_, true);
  Gui::DisplayPlayerTeam(ai_team_, false);
}

} //namespace artificialtrainer