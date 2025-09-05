#include "table.h"

void game(table gameTable, cardDeck deck) {
    bool winCondition = false;
    while (winCondition == false) {
        deck.shuffleDeck();
        for (player& tablePlayer : gameTable.players) {
            tablePlayer.addCard(deck.dealCard());
            tablePlayer.addCard(deck.dealCard()); // Runs twice so each player gets two cards.
        }
        gameTable.tableDealer.addCard(deck.dealCard());
        gameTable.tableDealer.addCard(deck.dealCard()); // Dealer gets two cards.


    }
}

int main() {

    table gameTable;
    cardDeck deck;

    deck.deckEnumeration();

    gameTable.addDealer("James Incandenza");
    gameTable.addPlayer("Simon");
    gameTable.addPlayer("Samantha");
    gameTable.addPlayer("Charmaine");
    gameTable.addPlayer("Charlotte");
    gameTable.addPlayer("Aidan");

    std::cout << "Initiating first game..." << std::endl;
    game(gameTable, deck);
    std::cout << "Do you wish to play again? y or n" << std::endl;
    char response;
    while (true) {
        std::cin >> response;
        if (response == 'n') {
            break;
        }
        else game(gameTable, deck);
    }
    


    return 0;
}