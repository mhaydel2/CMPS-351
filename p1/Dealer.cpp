//
// Created by cmps351 on 2/17/21.
//
#include <vector>
#include "Dealer.h"
#include "Deck.h"

//This constructor draws two random cards for both the
//player and the dealer.
Dealer::Dealer() {
    dealer_hand.push_back(deck.DrawCard());
    dealer_hand.push_back(deck.DrawCard());
    player_hand.push_back(deck.DrawCard());
    player_hand.push_back(deck.DrawCard());
}

//This method adds a random card to the dealer's hand.
void Dealer::DHandAdd() {
    dealer_hand.push_back(deck.DrawCard());
}


//This method adds a random card to the Player's hand.
void Dealer::PHandAdd() {
    player_hand.push_back(deck.DrawCard());
}

//This Get method returns the Dealer's hand.
std::vector<Card> Dealer::GetDHand() {
    return dealer_hand;
}

//This Get method returns the Player's hand.
std::vector<Card> Dealer::GetPHand() {
    return player_hand;
}

