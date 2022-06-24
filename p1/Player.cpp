//
// Created by cmps351 on 2/17/21.
//

#include "Player.h"
#include <vector>
#include "Deck.h"

Player::Player() {
    player_hand.push_back(deck.DrawCard());
    player_hand.push_back(deck.DrawCard());
}

void Player::HandAdd() {
    player_hand.push_back(deck.DrawCard());
}

std::vector<Card> Player::GetHand() {
    return player_hand;
}

