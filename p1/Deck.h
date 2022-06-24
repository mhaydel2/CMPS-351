//
// Created by cmps351 on 2/17/21.
//

#ifndef TEST3_DECK_H
#define TEST3_DECK_H
#include <vector>
#include "Card.h"


class Deck {
public:
    Deck();
    Card DrawCard();

private:
    std::vector<Card> _deck;
};


#endif //TEST3_DECK_H
