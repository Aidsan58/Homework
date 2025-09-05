#include "cardDeck.h"
#include "dealer.h"
#include <vector>

class table : public dealer {
    std::vector<player> players;
};