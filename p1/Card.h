//
// Created by cmps351 on 2/17/21.
//

#ifndef TEST3_CARD_H
#define TEST3_CARD_H

enum Value {two = 2, three, four, five,
        six, seven, eight, nine, ten,
        jack, queen, king, ace};
enum Suit {clubs, diamonds, hearts, spades};
class Card {
public:
    Card();
    Card(Value value, Suit suit);
    Value GetValue();
    Suit GetSuit();

private:
    Value _value;
    Suit _suit;
};


#endif //TEST3_CARD_H
