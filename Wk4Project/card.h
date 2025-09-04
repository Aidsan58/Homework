#include <iostream>
#include <string>

    // enum-key attr (optional) enum-head-name (optional) enum-base (optional)
    // { enumerator-list (optional) }
    enum faces { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, KING, QUEEN, FACES_COUNT };
    enum suits { DIAMONDS, HEARTS, CLUBS, SPADES, SUITS_COUNT };

class card {
    public:
    suits suit;
    faces face;
    int value;
};