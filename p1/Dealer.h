//
// Created by cmps351 on 2/17/21.
//

#ifndef TEST3_DEALER_H
#define TEST3_DEALER_H
#include <vector>
#include "Card.h"
#include "Deck.h"


class Dealer {
public:
    Dealer();
    Deck deck = Deck();

    void DHandAdd();
    void PHandAdd();
    std::vector<Card> GetDHand();
    std::vector<Card> GetPHand();

private:
    std::vector<Card> dealer_hand;
    std::vector<Card> player_hand;

};


#endif //TEST3_DEALER_H
