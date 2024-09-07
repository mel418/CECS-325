// Author: Melody Gatan
// CECS325-02 Prog 1
// Due 09/05/2024

#ifndef CARD_H
#define CARD_H

class Card {
  public:
    Card(char suit, char rank); // constructor to create a card, setting the suit and rank
    void print( ); // display the card example: AC, 10S, KD
    int compare(Card other); // return 1 for win, 0 for tie, -1 for lose
  
  private:
    char rank;
    char suit;
};

#endif