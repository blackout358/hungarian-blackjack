#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

std::string* cardsPtr = NULL;
std::string* handPtr = NULL;
std::string* dealerHandPtr = NULL;

void initial_load() {
  cardsPtr = new std::string("777788889999aaaaAAAAFFFFKKKKSSSS");
  // cardsPtr = cards;
  handPtr = new std::string("");
  dealerHandPtr = new std::string("");
}

void deallocate() {
  if (cardsPtr) {
    delete cardsPtr;
    cardsPtr = NULL;
  }
  if (handPtr) {
    delete handPtr;
    handPtr = NULL;
  }
  if (dealerHandPtr) {
    delete dealerHandPtr;
    dealerHandPtr = NULL;
  }
}

int get_random_number(int lb, int ub) {
  std::random_device rd;   // Obtain a random number from hardware
  std::mt19937 eng(rd());  // Seed the generator
  srand((unsigned)time(NULL));
  std::uniform_int_distribution<> distr(lb, ub);  // Define the range
  int randomNumber = distr(eng);
  return randomNumber;
}

char draw_card() {
  // Random select a num, and get index of that num in cards string mem
  std::string localDeck = *cardsPtr;
  int deck_size = localDeck.length();
  // size_t deck_size = *cardsPtr.length();
  //   std::cout << deck_size;
  int card_draw = get_random_number(1, deck_size - 1);

  char draw = localDeck[card_draw];
  std::cout << "Drawing this card: " << localDeck[card_draw] << std::endl;

  localDeck.erase(card_draw, 1);
  // localDeck.swap("" card_draw);
  // cardsPtr*.;
  cardsPtr->assign(localDeck);
  // cardsPtr = new std::
  // std::cout << *cardsPtr << std::endl;

  return draw;

  // Remove the selected num from the cards string
}

int calculate_score(std::string hand) {
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

void deal_cards() {
  //
  // std::string local_hand = *handPtr;
  // std::string local_dealer_hand = *dealer_hand_Ptr;
  for (int i = 0; i < 2; i++) {
    char draw = draw_card();
    // std::cout << draw;
    *handPtr += draw;
    draw = draw_card();
    // std::cout << draw;
    *dealerHandPtr += draw;
  }

  // std::cout << *dealer_hand_Ptr << std::endl;
  // std::cout << *cardsPtr << std::endl;
}

bool ask_to_draw() {
  std::string move;
  std::cout << "Hit or Stand? [ h / s ]: " << std::endl;
  std::cin >> move;

  if (move == "h") {
    return true;
  } else {
    return false;
  }
}

int player() {
  int score = calculate_score(*handPtr);
  while (score < 22) {
    std::cout << std::endl << *handPtr << std::endl;
    std::cout << score << std::endl;
    if (ask_to_draw()) {
      char draw = draw_card();
      *handPtr += draw;
      std::cout << draw << std::endl;
      score = calculate_score(*handPtr);
    } else {
      break;
    }
  }
  return score;
}

int dealer() {
  int score = calculate_score(*dealerHandPtr);

  while (score < 17) {
    // *dealer_hand_Ptr += draw_card();
    (*dealerHandPtr) += (draw_card());
    score = calculate_score(*dealerHandPtr);
  }
  return score;
}

char check_winner(int playerScore, int dealerScore) {
  if (dealerScore == 21)
    return 'd';
  else if (playerScore < 22 && dealerScore > 21)
    return 'p';
  else if (playerScore > 21 && dealerScore > 21)
    return 'n';
  else if ((playerScore < 22 && dealerScore < 22) && playerScore > dealerScore)
    return 'p';
  else
    return 'd';
}

void print_result(char winner, int playerScore, int dealerScore) {
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

  std::printf("\nPlayer Cards: %s - %d\nDealer Cards: %s - %d\n",
              handPtr->c_str(), playerScore, dealerHandPtr->c_str(),
              dealerScore);

  // std::cout << std::endl
  //           << "Player Cards: " << *handPtr << " - " << playerScore
  //           << std::endl
  //           << "Dealer Cards: " << *dealerHandPtr << " - " << dealerScore
  //           << std::endl;

  // Deal Cards
  // char draw = draw_card();
}

void debug_values() {}

void run_game() {
  // std::cout << *cardsPtr << std::endl;
  deal_cards();
  int playerScore = player();
  int dealerScore = dealer();
  char winner = check_winner(playerScore, dealerScore);
  print_result(winner, playerScore, dealerScore);
}

int main() {
  initial_load();
  run_game();
  deallocate();
  return 0;
}

/*
789aAFKS

a = 10
A = Also
F = Felso
K = Kiraly
S = Asz
*/