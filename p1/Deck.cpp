//
// Created by cmps351 on 2/17/21.
//

#include "Deck.h"
#include <random>

//This constructor creates the virtual deck to contain
//4 for each family of values from 2 to 10
// and the face cards from Jack to
//Ace just like a real deck of card.
Deck::Deck() {
    for (int value = two; value <= ace; value++) {
        for (int suit = clubs; suit <= spades; suit++){
            Card card = Card(static_cast<Value>(value),
                             static_cast<Suit>(suit));
            _deck.push_back(card);
        }
    }
}

//This method draws a random card from the created deck
//and deletes the card so it cannot be draw twice.
Card Deck::DrawCard() {
    std::random_device rd;
    std::mt19937 gen(rd());
    const int DECK_START = 0;
    std::uniform_int_distribution<int>
            card_distributor(DECK_START,
                              _deck.size());
    int card_index = card_distributor(gen);
    Card card_to_return = _deck[card_index];
    _deck.erase(_deck.begin() + card_index);
    return card_to_return;

}
