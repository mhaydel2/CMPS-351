#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Card.h"
#include "Dealer.h"
#include "ConvertCard.h"

//Returns the string version of the Card
//from the passed Card Value. For any value
//other than a Face Card, that value will
//be returned.
std::string ValueToString(Value value){
    switch (value) {
        case jack:
            return "J";
        case queen:
            return "Q";
        case king:
            return "K";
        case ace:
            return "A";
        default:
            return std::to_string(value);
    }
}

//Returns the string type for the Suit of
//of the card it belongs to for the print
//statements to later use.
std:: string SuitToString(Suit suit){
    switch (suit) {
        case clubs:
            return "C";
        case diamonds:
            return "D";
        case hearts:
            return "H";
        case spades:
            return "S";
        default:
            std::cout << "Invalid suit" << std::endl;
            return "";
    }
}

//This method checks if the cards in the dealer
//or player's hand that is passed by converting
//the hand of cards to a values only vector,
//and using the count algorithm to search for
//the value 11 as the Ace. If an Ace is found in
//the hand then an int returns. Depending on the
//return value will determine if a One or Eleven
//is counted for the Ace.
int AceCheck (std::vector<Card> hand) {
    ConvertCard converted = ConvertCard(hand);
    converted.Switch();
    int hand_sum = converted.FindSum();
    std::vector<int> card_values = converted.GetHand();
    if(hand_sum > 21 && (std::count(card_values.begin(), card_values.end(), 11))){
        return 1;}
    else {return 11;}

}

//This converts the Value and Suit of cards in the
//hand of vectors to strings in order to be used
//in a print statement.
std::string HandToString(std::vector<Card> hand, int i){
    return ValueToString(hand[i].GetValue()) +
        SuitToString(hand[i].GetSuit());
}

//Prints the cards from the vector holding the
//hand passed. The Value and Suit of each card
//in the vector is printed by calling the HandToString
//method that returns the Value and Suit of a card.
void PrintHand(std::vector<Card> hand){
    for (int i = 0; i<hand.size(); i++){
        std::cout<<HandToString(hand, i)<<" ";
    }
    std::cout<<""<<std::endl;
}

//This method Prints the hand for the dealer
//before the hidden card is revealed.
void FirstPrint(std::vector<Card> hand){
    std::cout<<HandToString(hand, 0)<<" (hidden card)"<<std::endl;
}


//All scenarios of A game of BlackJack are executed
//in this method/
int main() {

    Dealer hand = Dealer();
    std::vector<Card> dealer_hand = hand.GetDHand();
    std::vector<Card> player_hand = hand.GetPHand();

    std::cout<<"The dealer's hand: ";
    FirstPrint(dealer_hand);
    std::cout<<"The player's hand: ";
    PrintHand(player_hand);

    ConvertCard P_Converted = ConvertCard(player_hand);
    int key = AceCheck(player_hand);
    if (key == 11){P_Converted.Switch();}
    else {P_Converted.ReplaceAce();}
    int P_Sum = P_Converted.FindSum();

    ConvertCard D_Converted = ConvertCard(dealer_hand);
    int keyD = AceCheck(dealer_hand);
    if (keyD == 11){D_Converted.Switch();}
    else {D_Converted.ReplaceAce();}
    int D_Sum = D_Converted.FindSum();
    std::vector<int> dealer_values = D_Converted.GetHand();

    //the if for all 3 scenarios starts here
    if (P_Sum == 21 && D_Sum == 21){
        std::cout<<"Tie!"<<std::endl;
        std::cout<<"The dealer's hand: ";
        PrintHand(dealer_hand);
        std::cout<<"The player's hand: ";
        PrintHand(player_hand);
    }
    else if(P_Sum == 21){
        std::cout<<"The Player Wins!"<<std::endl;
        std::cout<<"The dealer's hand: ";
        PrintHand(dealer_hand);
        std::cout<<"The player's hand: ";
        PrintHand(player_hand);
    }
    else if (D_Sum == 21 && std::count(dealer_values.begin(),
                                       dealer_values.end(), 11)){
        std::cout<<"The Dealer Wins!"<<std::endl;
        std::cout<<"The dealer's hand: ";
        PrintHand(dealer_hand);
        std::cout<<"The player's hand: ";
        PrintHand(player_hand);
    }

    //else starts here
    else {
        std::cout << "Current Total: " << P_Sum << std::endl;
        std::string answer;
        std::cout << "Hit or Stand? (Enter H or S): ";
        std::cin >> answer;
        std::cout << "" << std::endl;

        if (answer == "H") {
            hand.PHandAdd();
            player_hand = hand.GetPHand();
            std::cout<<"The player's hand: ";
            PrintHand(player_hand);

            P_Converted = ConvertCard(player_hand);
            key = AceCheck(player_hand);
            if (key == 11) { P_Converted.Switch(); }
            else { P_Converted.ReplaceAce(); }
            P_Sum = P_Converted.FindSum();
            std::cout << "Current Total: " << P_Sum << std::endl;

            if (P_Sum < 21) {
                std::cout << "Hit or Stand? (Enter H or S): ";
                std::cin >> answer;
                std::cout << "" << std::endl;
                while (P_Sum < 21 && answer == "H") {
                    hand.PHandAdd();
                    player_hand = hand.GetPHand();
                    std::cout<<"The player's hand: ";
                    PrintHand(player_hand);

                    P_Converted = ConvertCard(player_hand);
                    key = AceCheck(player_hand);
                    if (key == 11) { P_Converted.Switch(); }
                    else { P_Converted.ReplaceAce(); }
                    P_Sum = P_Converted.FindSum();
                    std::cout << "Current Total: " << P_Sum << std::endl;
                    if (P_Sum < 21) {
                        std::cout << "Hit or Stand? (Enter H or S): ";
                        std::cin >> answer;
                        std::cout << "" << std::endl;
                    }
                }

                //dealer's turn
                if (P_Sum < 21 && answer == "S") {
                    D_Converted = ConvertCard(dealer_hand);
                    keyD = AceCheck(dealer_hand);
                    if (keyD == 11) { D_Converted.Switch(); }
                    else { D_Converted.ReplaceAce(); }
                    D_Sum = D_Converted.FindSum();
                    std::cout << "Current Sum: " << D_Sum << std::endl;
                    while (D_Sum <= 17) {
                        hand.DHandAdd();
                        dealer_hand = hand.GetDHand();
                        D_Converted = ConvertCard(dealer_hand);
                        std::cout<<"The dealer's hand: ";
                        PrintHand(dealer_hand);
                        keyD = AceCheck(dealer_hand);
                        if (keyD == 11) { D_Converted.Switch(); }
                        else { D_Converted.ReplaceAce(); }
                        D_Sum = D_Converted.FindSum();
                        std::cout << "Current Tot: " << D_Sum << std::endl;

                    }

                    if (D_Sum < 21) {
                        if (D_Sum > P_Sum) {
                            std::cout << "The Dealer Wins!" << std::endl;
                            std::cout << "The dealer's hand: ";
                            PrintHand(dealer_hand);
                            std::cout << "The player's hand: ";
                            PrintHand(player_hand);
                        } else if (P_Sum > D_Sum) {
                            std::cout << "The Player Wins!" << std::endl;
                            std::cout << "The dealer's hand: ";
                            PrintHand(dealer_hand);
                            std::cout << "The player's hand: ";
                            PrintHand(player_hand);
                        }
                        else if (D_Sum == P_Sum){
                            std::cout << "Tie!" << std::endl;
                            std::cout << "The dealer's hand: ";
                            PrintHand(dealer_hand);
                            std::cout << "The player's hand: ";
                            PrintHand(player_hand);
                        }
                    } else if (D_Sum == 21) {
                        std::cout << "The Dealer Wins!" << std::endl;
                        std::cout << "The dealer's hand: ";
                        PrintHand(dealer_hand);
                        std::cout << "The player's hand: ";
                        PrintHand(player_hand);
                    } else {
                        std::cout << "Dealer Busted! Player Wins!" << std::endl;
                        std::cout << "The dealer's hand: ";
                        PrintHand(dealer_hand);
                        std::cout << "The player's hand: ";
                        PrintHand(player_hand);
                    }
                } else if (P_Sum > 21) {
                    std::cout << "Player Busted! Dealer Wins!" << std::endl;
                    std::cout << "The dealer's hand: ";
                    PrintHand(dealer_hand);
                    std::cout << "The player's hand: ";
                    PrintHand(player_hand);
                } else if (P_Sum == 21) {
                    std::cout << "Player Wins!" << std::endl;
                    std::cout << "The dealer's hand: ";
                    PrintHand(dealer_hand);
                    std::cout << "The player's hand: ";
                    PrintHand(player_hand);
                }
            }
            else if (P_Sum == 21) {
                std::cout << "Player Wins!" << std::endl;
                std::cout << "The dealer's hand: ";
                PrintHand(dealer_hand);
                std::cout << "The player's hand: ";
                PrintHand(player_hand);
            }
            else {
                std::cout << "Player Busted! Dealer Wins!" << std::endl;
                std::cout << "The dealer's hand: ";
                PrintHand(dealer_hand);
                std::cout << "The player's hand: ";
                PrintHand(player_hand);
            }

            //dealer's turn
        } else {
            while (D_Sum <= 17) {
                hand.DHandAdd();
                std::cout << "Dealer Hits!"<< std::endl;
                dealer_hand = hand.GetDHand();
                D_Converted = ConvertCard(dealer_hand);
                std::cout<<"The Dealer's hand: ";
                PrintHand(dealer_hand);
                keyD = AceCheck(dealer_hand);
                if (keyD == 11) { D_Converted.Switch(); }
                else { D_Converted.ReplaceAce(); }
                D_Sum = D_Converted.FindSum();
                std::cout << "Current Total: " << D_Sum << std::endl;

            }

            if (D_Sum < 21) {
                if (D_Sum > P_Sum) {
                    std::cout << "The Dealer Wins!" << std::endl;
                    std::cout << "The dealer's hand: ";
                    PrintHand(dealer_hand);
                    std::cout << "The player's hand: ";
                    PrintHand(player_hand);
                } else if (P_Sum > D_Sum) {
                    std::cout << "The Player Wins!" << std::endl;
                    std::cout << "The dealer's hand: ";
                    PrintHand(dealer_hand);
                    std::cout << "The player's hand: ";
                    PrintHand(player_hand);
                }
                else if(D_Sum == P_Sum) {
                    std::cout << "Tie!" << std::endl;
                    std::cout << "The dealer's hand: ";
                    PrintHand(dealer_hand);
                    std::cout << "The player's hand: ";
                    PrintHand(player_hand);
                }
            } else if (D_Sum == 21) {
                std::cout << "The Dealer Wins!" << std::endl;
                std::cout << "The dealer's hand: ";
                PrintHand(dealer_hand);
                std::cout << "The player's hand: ";
                PrintHand(player_hand);
            } else {
                std::cout << "Dealer Busted! Player Wins!" << std::endl;
                std::cout << "The dealer's hand: ";
                PrintHand(dealer_hand);
                std::cout << "The player's hand: ";
                PrintHand(player_hand);
            }
        }
    }
    //else ends here on this line
    return 0;
}
