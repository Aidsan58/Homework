#include <iostream>
#include <string>
#include <vector>
#include "cardDeck.h"

class player {
    public:
    std::string name;
    static const int HAND_SIZE = 10;
    card hand[HAND_SIZE]; // hand should be an array of card types.
    int handSize;
    bool canHit;

    player() {
        name = ' ';
        handSize = 0;
        canHit = true;
    }

    player(const std::string& name);

    void addCard(const card& card);
    int getHandValue();
    void resetHand();



};

player::player(const std::string& name) {
    this->name = name;
    handSize = 0;
    canHit = true;
}


int player::getHandValue() {

    int total = 0;
    int aces = 0;
    for (int i = 0; i < handSize; ++i) {
        total += hand[i].value;
        
        // Ace case. Ace should be 1 or 11 depending on if including ace will bring the player to 21.
        if (hand[i].face == ACE) {
            aces++;
        }
        while (((total + 10) <= 21) && (aces > 0)) {
            total += 10; // Ace is now valued at 11.
            aces--;
            
        }
    }
    return total;
}


void player::addCard(const card& card) {
    if (handSize < HAND_SIZE) {
        hand[handSize++] = card;
        if (getHandValue() > 21) {
            canHit = false;
        }
    }
}

void player::resetHand() {
    handSize = 0;
    canHit = true;
}