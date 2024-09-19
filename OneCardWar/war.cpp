// Melody Gatan
// (CECS325-02) 
// Prog 1 - WAR (array)
// Due 09/19/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include "Deck.h"
#include "Card.h"
using namespace std;


int main() {
    Deck myDeck;
    string player1, player2;

    cout << "Enter the name of the first player: ";
    cin >> player1;
    cout << "Enter the name of the second player: ";
    cin >> player2;

    // Print the unshuffled deck
    cout << "\n Original Deck:" << endl;
    myDeck.print();

    // Shuffle the deck
    myDeck.shuffle();

    // Print the shuffled deck
    cout << "\n Shuffled Deck:" << endl;
    myDeck.print();

    for (int i = 0; i < 26; i++) {
        Card card1 = myDeck.deal();
        Card card2 = myDeck.deal();

        cout << "\nGame " << (i+1) << "\n--------\n\t" << player1 << "=>";
        card1.print();
        cout << "\n\t" << player2 << "=>";
        card2.print();
        cout << "\n";

        int result = card1.compare(card2);
        if (result == 1) {
            cout<< player1<< "=> Winner"<<endl;
        }
        else if (result == -1)
        {
            cout<< player2<< "=> Winner"<<endl;
        }
        else {
            cout<< "Tie game"<<endl;
        } 
    } 

    return 0;
}