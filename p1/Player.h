//
// Created by cmps351 on 2/17/21.
//

#ifndef TEST3_PLAYER_H
#define TEST3_PLAYER_H
#include <vector>
#include "Deck.h"
#include "Card.h"


class Player {
public:
    Player();
    Deck deck = Deck();
    void HandAdd();
    std::vector<Card> GetHand();

private:
    std::vector<Card> player_hand;
};


#endif //TEST3_PLAYER_H
