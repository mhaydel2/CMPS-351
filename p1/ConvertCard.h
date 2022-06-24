//
// Created by cmps351 on 2/17/21.
//

#ifndef TEST3_CONVERTCARD_H
#define TEST3_CONVERTCARD_H
#include <vector>
#include "Card.h"
#include "Dealer.h"
#include "Player.h"


class ConvertCard {
public:
    ConvertCard(std::vector<Card> hand);
    std::vector<int> GetHand();

    int FindSum();
    void Switch();
    void ReplaceAce();


private:
    std::vector<Value> hand_values;
    std::vector<int> hand_numb;
    int sum = 0;

};


#endif //TEST3_CONVERTCARD_H
