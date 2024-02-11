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
  std::string dealer_hand;

  void initial_load();

  char draw_card();
  // Generate random number
  int get_random_number(int lb, int ub);

  int calculate_score(std::string hand);

  void deal_cards();

  bool ask_to_draw();

  int player();

  int dealer();

  char check_winner(int player_score, int dealer_score);

  void print_result(char winner, int player_score, int dealer_score);
  void run_game();

 public:
  void blackjack();

  void game_desciption();

  void card_scores();
};
#endif