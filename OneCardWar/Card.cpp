// Melody Gatan
// (CECS325-02) 
// Prog 1 - WAR (array)
// Due 09/19/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include "Card.h"
#include <iostream>

using namespace std;

Card::Card() {}

Card::Card(char suit, char rank) : suit(suit), rank(rank) 
{
  switch (rank)
  {
  case ('A'):
    rank_val = 1;
    break;
  case ('T'):
    rank_val = 10;
    break;
  case ('J'):
    rank_val = 11;
    break;
  case ('Q'):
    rank_val = 12;
    break;
  case ('K'):
    rank_val = 13;
    break;
  
  default:
    rank_val = rank - '0';
    break;
  }
}

void Card::print() {
  if (rank == 'T') {
    cout << "10" << suit;
  } else {cout << rank << suit;}
}

int Card::compare(Card other) {
    if (this->rank_val > other.rank_val) {
      return 1;
    }
    else if (this->rank_val < other.rank_val) {
      return -1;
    }
    else {
      return 0;
    }
};