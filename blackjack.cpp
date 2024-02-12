#include "blackjack.h"

#include <iostream>
#include <random>
#include <string>

/*
cardsPtr -> deck
handPtr -> hand
dealerHandPtr -> dealerHand
*/

void Hungarian21::initial_load() {
  deck = std::string("777788889999aaaaAAAAFFFFKKKKSSSS");
  // cardsPtr = cards;
  hand = std::string("");
  dealerHand = std::string("");
}

char Hungarian21::draw_card() {
  // Random select a num, and get index of that num in cards string mem
  // std::string local_deck = deck;
  int deckSize = deck.length();
  // size_t deckSize = *cardsPtr.length();
  //   std::cout << deckSize;
  int cardDraw = get_random_number(1, deckSize - 1);

  char draw = deck[cardDraw];
  // std::cout << "Drawing this card: " << deck[cardDraw] << std::endl;

  deck.erase(cardDraw, 1);
  // deck.swap("" cardDraw);
  // cardsPtr*.;
  // deck->assign(deck);
  // cardsPtr = new std::
  // std::cout << *cardsPtr << std::endl;

  return draw;

  // Remove the selected num from the cards string
}
// Generate random number
int Hungarian21::get_random_number(int lb, int ub) {
  std::random_device rd;   // Obtain a random number from hardware
  std::mt19937 eng(rd());  // Seed the generator
  srand((unsigned)time(NULL));
  std::uniform_int_distribution<> distr(lb, ub);  // Define the range
  int randomNumber = distr(eng);
  return randomNumber;
}

int Hungarian21::calculate_score(std::string hand) {
  int score = 0;
  if (hand == "SS") {
    return 21;
  }
  for (int i = 0; i < hand.length(); i++) {
    switch (hand[i]) {
      case '7':
        /* code */
        score += 7;
        break;
      case '8':
        score += 8;
        break;
      case '9':
        score += 9;
        break;
      case 'a':
        score += 10;
        break;
      case 'A':
        score += 2;
        break;
      case 'F':
        score += 3;
        break;
      case 'K':
        score += 4;
        break;
      case 'S':
        score += 11;
        break;
      default:
        break;
    }
  }
  return score;
}

void Hungarian21::deal_cards() {
  //
  // std::string local_hand = hand;
  // std::string local_dealer_hand = dealerHand;
  for (int i = 0; i < 2; i++) {
    char draw = draw_card();
    // std::cout << draw;
    hand += draw;
    draw = draw_card();
    // std::cout << draw;
    dealerHand += draw;
  }

  // std::cout << dealerHand << std::endl;
  // std::cout << *cardsPtr << std::endl;
}

bool Hungarian21::ask_to_draw() {
  std::string move;
  std::cout << "Hit or Stand? [ h / s ]: " << std::endl;
  std::cin >> move;

  if (move == "h") {
    return true;
  } else {
    return false;
  }
}

int Hungarian21::player() {
  int score = calculate_score(hand);
  while (score < 22) {
    std::cout << std::endl << hand << std::endl;
    std::cout << score << std::endl;
    if (ask_to_draw()) {
      char draw = draw_card();
      hand += draw;
      std::cout << draw << std::endl;
      score = calculate_score(hand);
    } else {
      break;
    }
  }
  return score;
}

int Hungarian21::dealer() {
  int score = calculate_score(dealerHand);

  while (score < 17) {
    // dealerHand += draw_card();
    (dealerHand) += (draw_card());
    score = calculate_score(dealerHand);
  }
  return score;
}

char Hungarian21::check_winner(int playerScore, int dealerScore) {
  if (dealerScore == 21)
    return 'd';
  else if (playerScore < 22 && dealerScore > 21)
    return 'p';
  else if (playerScore > 21 && dealerScore > 21)
    return 'd';
  else if ((playerScore < 22 && dealerScore < 22) && playerScore > dealerScore)
    return 'p';
  else
    return 'd';
}

void Hungarian21::print_result(char winner, int playerScore, int dealerScore) {
  switch (winner) {
    case 'd':
      std::cout << std::endl << "Dealer Wins";
      break;
    case 'p':
      std::cout << std::endl << "Player Wins";
      break;
    case 'b':
      std::cout << std::endl << "Draw";
      break;
    default:
      std::cout << std::endl << "?";
      break;
  }

  // std::printf("\nPlayer Cards: %s - %d\nDealer Cards: %s - %d\n", hand,
  //             playerScore, dealerHand, dealerScore);

  std::cout << std::endl
            << "Player Cards: " << hand << " - " << playerScore << std::endl
            << "Dealer Cards: " << dealerHand << " - " << dealerScore
            << std::endl;

  // Deal Cards
  // char draw = draw_card();
}

void Hungarian21::run_game() {
  // std::cout << *cardsPtr << std::endl;
  deal_cards();
  int playerScore = player();
  int dealerScore = dealer();
  char winner = check_winner(playerScore, dealerScore);
  print_result(winner, playerScore, dealerScore);
}
void Hungarian21::blackjack() {
  initial_load();
  run_game();
  // deallocate();
}

void Hungarian21::game_desciption() {
  // std::cout << std::endl << "Blackjack played with Hungarian cards" << st
  printf("\nBlackjack played with Hungarian cards\n");
}

void Hungarian21::card_scores() {
  printf(
      "\nCard\t-\tValue"
      "\n7\t-\t7"
      "\n8\t-\t8"
      "\n9\t-\t9"
      "\na\t-\t10"
      "\nA\t-\t2 -> Alsó"
      "\nF\t-\t3 -> Felső"
      "\nK\t-\t4 -> Király"
      "\nS\t-\t11 -> Ász\n");
}
