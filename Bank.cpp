#include "Bank.h"

using namespace std;

Bank::Bank(Deck *deck) : Hand(deck) {}

void Bank::printHand(string role) {
    Hand::printHand(role);
}

void Bank::deal() {
    getHand() -> push_back(getDeck() -> deal());
}