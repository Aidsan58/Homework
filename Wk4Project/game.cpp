#include "table.h"

void game() {
    bool winCondition = false;
    while (winCondition == false) {
        
    }
}

int main() {

    table gameTable;

    gameTable.addDealer("James Incandenza");
    gameTable.addPlayer("Simon");
    gameTable.addPlayer("Samantha");
    gameTable.addPlayer("Charmaine");
    gameTable.addPlayer("Charlotte");
    gameTable.addPlayer("Aidan");

    std::cout << "Initiating first game..." << std::endl;
    game();
    std::cout << "Do you wish to play again? y or n" << std::endl;
    char response;
    while (true) {
        std::cin >> response;
        if (response == 'n') {
            false;
        }
        else game();
    }
    


    return 0;
}