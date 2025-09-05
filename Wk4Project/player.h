#include <iostream>
#include <string>
#include <vector>

class player {
    public:
    std::string name;
    static const int HAND_SIZE = 10;
    int hand[HAND_SIZE];
    int handValue = 0;
    bool canHit = true;

    player(const std::string& name);

    void addCard(const card& card)


};

