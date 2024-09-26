// Melody Gatan
// (CECS325-02) 
// Prog 2 - More War (vector)
// Due 10/01/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <vector>
#include <random>
using namespace std;


class Card {
  public:
    char suit;
    char rank;
    int rank_val;

    Card(char suit, char rank) : suit(suit), rank(rank) 
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

    void print() {
      if (rank == 'T') {
        cout << "10" << suit;
      } else {
        cout << rank << suit;
      }
    }

    int compare(Card other) {
      if (this->rank_val > other.rank_val) {
        return 1;
      }
      else if (this->rank_val < other.rank_val) {
        return -1;
      }
      else {
        return 0;
      }
    }
};



class Deck {
  private:
  vector<Card> pile;

  public:
    // constructor which creates a deck of 52 cards
    Deck( ){
      char suits[] = {'C', 'S', 'D', 'H'};
      char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

      for (char suit:suits) {
        for (char rank:ranks) {
          pile.push_back(Card(suit, rank));
        }
      }
    }

    // deal a card if you can – otherwise raise an exception
    Card deal( ) {
      if (isEmpty()) {
        throw runtime_error("Error - Deck is empty");
      }
      Card dealtCard = pile.back();
      pile.pop_back();
      return dealtCard;
    };     

    // show all the cards in the deck
    void print( ) {
      for (int i = 0; i < 52; i++) {
      pile[i].print();
      if ((i + 1) % 13 == 0) {
        cout << endl; 
      } else {
        cout << ",";
      }
  }
    };  

    // shuffle the cards in the deck 
    void shuffle( ) {
      srand(unsigned(time(0)));
      for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        swap(pile[i], pile[j]);
      }
    };  

    // return true if deck is empty
    bool isEmpty() {
      return pile.empty();
    };   
};




int main() {
  Deck myDeck;
  string player1, player2;
  int games;

  cout << "Enter the name of the first player: ";
  cin >> player1;
  cout << "Enter the name of the second player: ";
  cin >> player2;

  cout<<"How many games will they play? ";
  cin >> games;

  // Print the unshuffled deck
  cout << "\n Original Deck:" << endl;
  myDeck.print();

  // Shuffle the deck
  myDeck.shuffle();

  // Print the shuffled deck
  cout << "\n Shuffled Deck:" << endl;
  myDeck.print();

  int results[3] = {0, 0, 0};

  try {
    for (int i = 0; i < games; i++) {
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
            results[0] += 1;
        }
        else if (result == -1)
        {
            cout<< player2<< "=> Winner"<<endl;
            results[1]+= 1;
        }
        else if (result == 0) {
            cout<< "Tie game"<<endl;
            results[2] += 1;
        } 
    } 
  } catch (runtime_error &e) {
        cout<< e.what();
    }
    

    cout<< "\n------Final Stats-------";
    cout<<"\n\t" << player1 << "\tvs.\t" << player2<< endl;
    cout<< "Wins \t" << results[0] << "\t\t" << results[1]<< endl;
    cout<< "Losses \t" << results[1] << "\t\t" << results[0] << endl;
    cout<< "Ties \t" << results[2] << "\t\t" << results[2] << endl;

  return 0;
}