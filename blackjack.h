#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include <random>
#include <string>
/*
cardsPtr -> deck
handPtr -> hand
dealerHandPtr -> dealerHand
*/
class Hungarian21 {
private:
  std::string deck;
  std::string hand;
  std::string dealerHand;

  void initial_load();

  char draw_card();
  int get_random_number(int lb, int ub);

  int calculate_score(std::string hand);

  void deal_cards();

  bool ask_to_draw();

  int player();

  int dealer();

  char check_winner(int playerScore, int dealerScore);

  void print_result(char winner, int playerScore, int dealerScore);

  void run_game();

public:
  void blackjack();

  void game_desciption();

  void card_scores();
};
#endif