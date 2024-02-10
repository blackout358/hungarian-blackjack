#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

std::string* cardsPtr = NULL;
std::string* handPtr = NULL;
std::string* dealer_hand_Ptr = NULL;

void initial_load() {
  cardsPtr = new std::string("777788889999aaaaAAAAFFFFKKKKSSSS");
  // cardsPtr = cards;
  handPtr = new std::string("");
  dealer_hand_Ptr = new std::string("");
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
  if (dealer_hand_Ptr) {
    delete dealer_hand_Ptr;
    dealer_hand_Ptr = NULL;
  }
}

int get_random_number(int lb, int ub) {
  std::random_device rd;   // Obtain a random number from hardware
  std::mt19937 eng(rd());  // Seed the generator
  srand((unsigned)time(NULL));
  std::uniform_int_distribution<> distr(lb, ub);  // Define the range
  int random_number = distr(eng);
  return random_number;
}

char drawCard() {
  // Random select a num, and get index of that num in cards string mem
  std::string local_deck = *cardsPtr;
  int deck_size = local_deck.length();
  // size_t deck_size = *cardsPtr.length();
  //   std::cout << deck_size;
  int card_draw = get_random_number(1, deck_size - 1);

  char draw = local_deck[card_draw];
  std::cout << "Drawing this card: " << local_deck[card_draw] << std::endl;

  local_deck.erase(card_draw, 1);
  // local_deck.swap("" card_draw);
  // cardsPtr*.;
  cardsPtr->assign(local_deck);
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
    char draw = drawCard();
    // std::cout << draw;
    *handPtr += draw;
    draw = drawCard();
    // std::cout << draw;
    *dealer_hand_Ptr += draw;
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
      char draw = drawCard();
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
  int score = calculate_score(*dealer_hand_Ptr);

  while (score < 17) {
    // *dealer_hand_Ptr += drawCard();
    (*dealer_hand_Ptr) += (drawCard());
    score = calculate_score(*dealer_hand_Ptr);
  }
  return score;
}

char check_winner(int player_score, int dealer_score) {
  if (dealer_score == 21)
    return 'd';
  else if (player_score < 22 && dealer_score > 21)
    return 'p';
  else if (player_score > 21 && dealer_score > 21)
    return 'n';
  else if ((player_score < 22 && dealer_score < 22) &&
           player_score > dealer_score)
    return 'p';
  else
    return 'd';
}

void print_result(char winner, int player_score, int dealer_score) {
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
              handPtr->c_str(), player_score, dealer_hand_Ptr->c_str(),
              dealer_score);

  // std::cout << std::endl
  //           << "Player Cards: " << *handPtr << " - " << player_score
  //           << std::endl
  //           << "Dealer Cards: " << *dealer_hand_Ptr << " - " << dealer_score
  //           << std::endl;

  // Deal Cards
  // char draw = drawCard();
}

void debug_values() {}

void run_game() {
  // std::cout << *cardsPtr << std::endl;
  deal_cards();
  int player_score = player();
  int dealer_score = dealer();
  char winner = check_winner(player_score, dealer_score);
  print_result(winner, player_score, dealer_score);
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