#include <iostream>
#include <string>
#include <algorithm> // https://cplusplus.com/reference/algorithm/shuffle/
#include <random> // default_random_engine generates pseudo random numbers.
#include <chrono> // adds clock
#include "card.h"

class cardDeck {
    public:
    static const int CARDS_LENGTH = 52;
    card cards[CARDS_LENGTH];
    int index = 0;
    
    void deckEnumeration();
    void shuffleDeck();
    card dealCard();
};

void cardDeck::deckEnumeration() {
    int i = 0;

    for (int j = 0; j < FACES_COUNT; j++) {
        for (int k = 0; k < SUITS_COUNT; k++) {
            // static_cast<target-type>(expression)		
            cards[i].face = static_cast<faces>(j);
            cards[i].suit = static_cast<suits>(k);
            if ((j == 10) || (j == 11) || (j == 12)) { // Jack King and Queen should all have values of 10 for blackjack.
                cards[i].value = 10;
            }
            else {
                cards[i].value = j + 1; // since j represents the index of the face, j + 1 will return the correct value of the face. We will have to modify ACE values to implement blackjack.
            } // Ace has a value of 1 by default.
            i++;
        }
    }
}

void cardDeck::shuffleDeck() {
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); // I took this code from cplusplus.com
    std::shuffle (cards, cards + cardDeck::CARDS_LENGTH, std::default_random_engine(seed));
    index = 0;
}



card cardDeck::dealCard() {
    if (index >= CARDS_LENGTH) {
        shuffleDeck();
    }
    return cards[index++];
}