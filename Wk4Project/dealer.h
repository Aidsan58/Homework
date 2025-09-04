// The dealer is a player
#include <algorithm> // https://cplusplus.com/reference/algorithm/shuffle/
#include <random> // default_random_engine generates pseudo random numbers.
#include <chrono> // adds clock
#include "player.h"
#include "cardDeck.h"

class dealer : public player {
    public:
    bool canHit = true;
    void shuffleDeck();
    cardDeck deck;
    
};

void dealer::shuffleDeck() {
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); // I took this code from cplusplus.com
    std::shuffle (deck.cards, deck.cards + cardDeck::CARDS_LENGTH, std::default_random_engine(seed));

}