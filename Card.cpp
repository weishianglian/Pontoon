#include <iostream>

#include "Card.h"

using namespace std;

const string Card::faces[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

Card::Card(const string& face, int value) {
    setFace(face);
    setValue(value);
}

string Card::getFace() const {
    return face;
}

void Card::setFace(const string& face) {
    this -> face = face;
}

int Card::getValue() const {
    return value;
}

void Card::setValue(int value) {
    if (value >= 1  && value <= 10 ) {
        this -> value = value;
    } else {
        throw invalid_argument("The value of a card must be between 1 and 10.");
    }
}

void Card::printCard() {
    cout << face << endl;
}

ostream& operator<<(ostream& os, Card& card) {
    os << card.getFace() << endl;
    return os;
}
