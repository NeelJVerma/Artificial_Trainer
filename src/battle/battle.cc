//
// Created by neel on 1/25/19.
//

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
#include "../random/randomgenerator.h"
#include "../ailogic/pickleadingpokemon.h"
#include "../ailogic/pickforcedswitch.h"

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

  SpeciesNames species_name = active_member->SpeciesName();

  if (active_member->MoveUsed()) {
    MoveNames last_move_name = active_member->MoveUsed()->MoveName();

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

    if (active_member->IsRaging() && selected_move_name != last_move_name) {
      Gui::DisplayMustFinishRagingMessage(species_name);
      return false;
    }

    if (active_member->UsedTrapMove() && selected_move_name != last_move_name) {
      Gui::DisplayMustFinishTrapMessage(species_name);
      return false;
    }
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

  return static_cast<bool>(move->CurrentPp());
}

bool IsValidSwitchChoice(const Team &team, const int &index) {
  return index >= 0 && index < team.ActiveTeam().size();
}

} //namespace

bool Battle::BattleOver() const {
  return human_team_.ActiveTeam().empty() || ai_team_.ActiveTeam().empty();
}

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

void Battle::HumanPicksForcedSwitch() {
  if (human_team_.ActiveTeam().empty()) {
    return;
  }

  Gui::DisplayForceSwitchMessage();
  Gui::DisplayAvailableSwitchOptions(human_team_);
  int switch_choice;

  while (true) {
    switch_choice = InputHandler::GetIntInput(1, static_cast<int>(
        human_team_.ActiveTeam().size()));

    if (IsValidSwitchChoice(human_team_, switch_choice - 1)) {
      break;
    }

    Gui::DisplayInvalidChoiceMessage();
  }

  human_team_.SetActiveMember(switch_choice - 1);
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

bool Battle::HandleMove(Team &attacker, Team &defender) {
  UseMove(attacker, defender);
  std::shared_ptr<Pokemon> active_attacker = attacker.ActiveMember();
  std::shared_ptr<Pokemon> active_defender = defender.ActiveMember();

  if (active_attacker->IsFainted() || !active_defender->IsFainted()) {
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
                                     const std::shared_ptr<Pokemon> &defender) {
  if (!attacker->HpStat()->CurrentHp() || !defender->HpStat()->CurrentHp()) {
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

void Battle::ReplaceMovesWithStruggleIfNeeded() {
  std::shared_ptr<Pokemon> active_pokemon_human = human_team_.ActiveMember();
  std::shared_ptr<Pokemon> active_pokemon_ai = ai_team_.ActiveMember();

  if (active_pokemon_human->MustUseStruggle()) {
    active_pokemon_human->GetMovesContainer().ReplaceAllWithStruggle();
  }

  if (active_pokemon_ai->MustUseStruggle()) {
    active_pokemon_ai->GetMovesContainer().ReplaceAllWithStruggle();
  }
}

bool Battle::HumanMovesFirst() const {
  std::shared_ptr<Pokemon> active_pokemon_human = human_team_.ActiveMember();
  std::shared_ptr<Pokemon> active_pokemon_ai = ai_team_.ActiveMember();

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

void Battle::HandleFainting(const bool &human_moves_first) {
  std::shared_ptr<Pokemon> active_pokemon_human = human_team_.ActiveMember();
  std::shared_ptr<Pokemon> active_pokemon_ai = ai_team_.ActiveMember();

  if (human_moves_first) {
    if (active_pokemon_human->IsFainted()) {
      Gui::DisplayPokemonFaintedMessage(active_pokemon_human->SpeciesName());
      human_team_.FaintActivePokemon();
      HumanPicksForcedSwitch();
    }

    if (active_pokemon_ai->IsFainted()) {
      Gui::DisplayPokemonFaintedMessage(active_pokemon_ai->SpeciesName());
      ai_team_.FaintActivePokemon();
      PickForcedSwitch(ai_team_, active_pokemon_human);
      Gui::DisplayAiForceSwitchMessage(ai_team_.ActiveMember()->SpeciesName());
    }
  } else {
    if (active_pokemon_ai->IsFainted()) {
      Gui::DisplayPokemonFaintedMessage(active_pokemon_ai->SpeciesName());
      ai_team_.FaintActivePokemon();
      PickForcedSwitch(ai_team_, active_pokemon_human);
      Gui::DisplayAiForceSwitchMessage(ai_team_.ActiveMember()->SpeciesName());
    }

    if (active_pokemon_human->IsFainted()) {
      Gui::DisplayPokemonFaintedMessage(active_pokemon_human->SpeciesName());
      human_team_.FaintActivePokemon();
      HumanPicksForcedSwitch();
    }
  }
}

void Battle::HandleBothTeamsMoves(const bool &human_moves_first) {
  std::shared_ptr<Pokemon> active_pokemon_human = human_team_.ActiveMember();
  std::shared_ptr<Pokemon> active_pokemon_ai = ai_team_.ActiveMember();

  if (human_moves_first && HandleMove(human_team_, ai_team_) &&
      HandleMove(ai_team_, human_team_)) {
    HandleEndOfTurnStatuses(active_pokemon_human, active_pokemon_ai);
    HandleEndOfTurnStatuses(active_pokemon_ai, active_pokemon_human);
  } else if (HandleMove(ai_team_, human_team_) &&
      HandleMove(human_team_, ai_team_)) {
    HandleEndOfTurnStatuses(active_pokemon_ai, active_pokemon_human);
    HandleEndOfTurnStatuses(active_pokemon_human, active_pokemon_ai);
  }
}

void Battle::HandleTurn() {
  Gui::DisplayPlayerTeam(human_team_, true);
  Gui::DisplayPlayerTeam(ai_team_, false);
  std::shared_ptr<Pokemon> active_pokemon_human = human_team_.ActiveMember();
  Gui::DisplayActivePokemonData(active_pokemon_human, true);
  std::shared_ptr<Pokemon> active_pokemon_ai = ai_team_.ActiveMember();
  Gui::DisplayActivePokemonData(active_pokemon_ai, false);
  PlayerPicksMove(human_team_, true);
  PlayerPicksMove(ai_team_, false);
  bool human_moves_first = HumanMovesFirst();
  HandleBothTeamsMoves(human_moves_first);
  HandleFainting(human_moves_first);
  active_pokemon_human->ResetEndOfTurnFlags();
  active_pokemon_ai->ResetEndOfTurnFlags();
  ReplaceMovesWithStruggleIfNeeded();
}

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