#include <iostream>
#include <string>
#include <vector>
#include "cardDeck.h"

class player {
    public:
    std::string name;
    static const int HAND_SIZE = 10;
    card hand[HAND_SIZE]; // hand should be an array of card types.
    int handValue = 0;
    bool canHit = true;

    player(const std::string& name);

    void addCard(const card& card);
    int getHandValue();
    void resetHand();


};

void player::addCard(const card& card) {
    if (handValue < HAND_SIZE) {
        hand[handValue++] = card;
        if (getHandValue() > 21) {
            canHit = false;
        }
    }
}