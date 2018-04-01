#include <iostream>

#include "SuitCard.h"

using namespace std;

const string SuitCard::suits[4] = {"Spade", "Heart", "Diamond", "Club"};

SuitCard::SuitCard(const string &face, const string &suit, int value) : Card(face, value) {
    setSuit(suit);
}

string SuitCard::getSuit() const {
    return suit;
}

void SuitCard::setSuit(const string& suit) {
    if (suit == "Spade" || suit == "Heart" || suit == "Diamond" || suit == "Club") {
        this -> suit = suit;
    } else {
        throw invalid_argument("The suit must be either hearts, spades, clubs, or diamonds.");
    }
}

void SuitCard::printCard() {
    cout << getFace() << " of " << getSuit() << endl;
}

ostream& operator<<(ostream& os, SuitCard& card) {
    os << card.getFace() << " of " << card.getSuit() << endl;
    return os;
}
