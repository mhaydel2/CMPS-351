//
// Created by cmps351 on 2/17/21.
//

#include "ConvertCard.h"
#include "Card.h"

//This is the method called if there is an Ace in
//the deck and the sum of the hand is less than 21.
//It assigns 11 to the value of the Ace.
//The method takes the number value from all the cards
//in the vector and assigns it to a new vector that is
//later returned in a different method.
void ConvertCard::Switch() {

    for (Value value: hand_values){
        if (value == jack || value == queen || value == king) {
            hand_numb.push_back(10);}
        else if (value == ace){hand_numb.push_back(11);}
        else {hand_numb.push_back(value);}
    }
}

//This is the method called if there is an Ace in
//the deck and the sum of the hand is more than 21.
//Assigns 1 for the value of Ace.
//The method takes the number value from all the cards
//in the vector and assigns it to a new vector that is
//later returned in a different method.
void ConvertCard::ReplaceAce() {
    for (Value value: hand_values){
        if (value == jack || value == queen || value == king) {
            hand_numb.push_back(10);}
        else if (value == ace){hand_numb.push_back(1);}
        else {hand_numb.push_back(value);}
    }
}

//doesnt matter dealer or player hand
//Finds the value of every card in the Card
//vector and adds it do the hand_values vector.
ConvertCard::ConvertCard(std::vector<Card> hand) {
    for (int i = 0; i<hand.size(); i++){
        hand_values.push_back(hand[i].GetValue());
    }
}

//This Get method returns the new vector filled
//with the integer values. This also accounts for
//whether the Ace needs to be 1 or 11.
std::vector<int> ConvertCard::GetHand() {
    return hand_numb;
}

//This method Finds the sum of all the integers
//in a hand that represent cards and returns the sum.
int ConvertCard::FindSum() {
    for (int i: hand_numb){
        sum = sum + i;
    }
    return sum;
}

