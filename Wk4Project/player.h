#include <iostream>
#include <string>

class player {
    public:
    std::string name;
    static const int HAND_SIZE = 10;
    int hand[HAND_SIZE];
    private:
    int handValue = 0;
    bool canHit = true;


};