// Author: Melody Gatan
// CECS325-02 Prog 1
// Due 09/05/2024

#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {
  public:
    Deck();         // constructor which creates a deck of 52 cards
    Card deal();    // deal a card
    void print();   // show all the cards in the deck
    void shuffle(); // shuffle the cards in the deck
  
  private:
    
};

#endif