#include <iostream>
#include <string>
#include "card.h"

class cardDeck {
    public:
    static const int CARDS_LENGTH = 52;
    card cards[CARDS_LENGTH];
    
    void deckEnumeration();
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