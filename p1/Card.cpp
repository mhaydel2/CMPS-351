//
// Created by cmps351 on 2/17/21.
//

#include "Card.h"

//This constructor was used for a test with
//a set value and suit for a card.
Card::Card() {
    Value card_value = three;
    Suit card_suit = hearts;
}

//This method assigns the value and suit of a
//card with the given values passed through
//the method.
Card::Card(Value value, Suit suit) {
    _value = value;
    _suit = suit;
}

//This Get method returns the Value of the card.
Value Card::GetValue() {
    return _value;
}

//This Get method returns the Suit of the card.
Suit Card::GetSuit() {
    return _suit;
}
