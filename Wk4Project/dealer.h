// The dealer is a player
#include "player.h"


class dealer : public player {
    public:

    dealer() {
        name = ' ';
        handSize = 0;
        canHit = true;
    }

    dealer(const std::string& name);

    void dealerAddCard(const card& card);

};

dealer::dealer(const std::string& name) : player(name) {
    this->name = name;
    handSize = 0;
    canHit = true;
}

void dealer::dealerAddCard(const card& card) {
    if (handSize < HAND_SIZE) {
        hand[handSize++] = card;
        if (handSize >= 5) {
            if (getHandValue() <= 15) {
            canHit = false;
            }
        }
        if (getHandValue() > 21) {
            canHit = false;
        }
    }
}

