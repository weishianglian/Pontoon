#include <iostream>

#include "Hand.h"

using namespace std;

Hand::Hand(Deck *deck) {
    this -> deck = deck;
}

void Hand::printHand(string role) {
    cout << endl << role << " hand is : " << endl << endl;
    for (size_t i=0; i < hand.size(); i++) {
        hand[i] -> printCard();
    }
    cout << "value = " << getHandValue() << endl;
}

int Hand::getHandCradNum() const {
    return hand.size();
}

int Hand::getHandValue() const {
    int sum = 0;
    for (size_t i=0; i < hand.size(); i++) {
        sum += hand[i] -> getValue();
    }
    return sum;
}

bool Hand::isBust() const {
    return getHandValue() > 21;
}

void Hand::reset() {
    hand.clear();
}

vector<Card*>* Hand::getHand() {
    return &hand;
}

Deck* Hand::getDeck() {
    return deck;
}