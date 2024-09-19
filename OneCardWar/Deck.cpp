// Melody Gatan
// (CECS325-02) 
// Prog 1 - WAR (array)
// Due 09/19/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <cstdlib>
using namespace std;


Deck::Deck() {
  char suits[] = {'C', 'S', 'D', 'H'};
  char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
  int index = 0;

  for (char suit : suits) {
    for (char rank : ranks) {
      pile[index] = Card(suit, rank);
      index++;
    }
  }
  topCard = 52;
}

Card Deck::deal() {
  return pile[--topCard];
}

void Deck::print() {
  for (int i = 0; i < 52; i++) {
    pile[i].print();
    if ((i + 1) % 13 == 0) {
      cout << endl; 
    } else {
      cout << ",";
    }
  }
}


void Deck::shuffle() {
  srand(unsigned(time(0)));
  for (int i = 0; i < 52; i++) {
    int j = rand() % 52;
    swap(pile[i], pile[j]);
  }
}

