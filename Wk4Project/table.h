//#include "cardDeck.h"
#include "dealer.h"
#include <vector>

class table {
    public:
    std::vector<player> players;
    dealer tableDealer;

    void addPlayer(const std::string& name);
    void addDealer(const std::string& name);
    void clearTable();

    table();

};

void table::addPlayer(const std::string& name) {

    if (players.size() >= 5) { // There shuold be 5 or fewer players in the game.
        std::cout << "There are already too many players in the game." << std::endl;
        return;
    }
    else players.push_back(player(name));
    //players.push_back("Simon")
}

void table::addDealer(const std::string& name) {
    tableDealer = dealer(name);
}

void table::clearTable() {
    for (player& tablePlayer : players) {
        tablePlayer.resetHand();
    }
}

table::table() {
    //empty
}