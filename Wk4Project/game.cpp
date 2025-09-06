#include "table.h"

void game(table& gameTable, cardDeck& deck) {

    char response;

        deck.shuffleDeck();
        for (player& tablePlayer : gameTable.players) {
            tablePlayer.addCard(deck.dealCard());
            tablePlayer.addCard(deck.dealCard()); // Runs twice so each player gets two cards.
        }
        gameTable.tableDealer.dealerAddCard(deck.dealCard());
        gameTable.tableDealer.dealerAddCard(deck.dealCard()); // Dealer gets two cards.

        for (player& tablePlayer : gameTable.players) { // Each player is asked if they want a card.
            
            while (tablePlayer.canHit == true) {
                std::cout << tablePlayer.name << " do you want another card? y or n" << std::endl;
                std::cin >> response;
                if (response == 'n') {
                    std::cout << "Moving on to next player." << std::endl;
                    break;
                }
                else {
                    tablePlayer.addCard(deck.dealCard());
                }
            }
        }
            while(gameTable.tableDealer.canHit == true) {
                std::cout << gameTable.tableDealer.name << " do you want another card? y or n" << std::endl;
                std::cin >> response;
                if (response == 'n') {
                    break;
                }
                else {
                    gameTable.tableDealer.dealerAddCard(deck.dealCard());
                }
            }

        for (player& tablePlayer : gameTable.players) { // Each player is evaluated for win condition.
            if ((tablePlayer.getHandValue() > gameTable.tableDealer.getHandValue()) && tablePlayer.getHandValue() < 21 ) { // win condition
                std::cout << tablePlayer.name << " has won the game." << std::endl;
            }
            if ((tablePlayer.getHandValue() <= 21) && (gameTable.tableDealer.getHandValue() > 21 )) { // win condition
                std::cout << tablePlayer.name << " has won the game." << std::endl;
            }
            else if ((tablePlayer.getHandValue() > 21) && (gameTable.tableDealer.getHandValue() > 21)) {
                std::cout << tablePlayer.name << " draws." << std::endl;
            }
            else if ((tablePlayer.getHandValue() == gameTable.tableDealer.getHandValue())) {
                std::cout << tablePlayer.name << " draws." << std::endl;
            }
            else if ((gameTable.tableDealer.getHandValue() < 15) && (gameTable.tableDealer.handSize >= 5)) {
                std::cout << tablePlayer.name << " has lost the game." << std::endl;
            }
            else if ((tablePlayer.getHandValue() > 21) && (gameTable.tableDealer.handSize <= 21)) {
                std::cout << tablePlayer.name << " has lost the game." << std::endl;
            }
            else if (((tablePlayer.getHandValue() < 21) && (gameTable.tableDealer.handSize < 21)) && (tablePlayer.getHandValue() < gameTable.tableDealer.getHandValue())) {
                std::cout << tablePlayer.name << " has lost the game." << std::endl;
            }
            
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
    char response;
    while (true) {
        std::cout << "Do you wish to play again? y or n" << std::endl;
        std::cin >> response;
        if (response == 'n') {
            break;
        }
        else {
            gameTable.clearTable();
            game(gameTable, deck);
        }

    }
    return 0;
}