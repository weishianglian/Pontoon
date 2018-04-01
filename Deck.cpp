#include <random>
#include <iostream>

#include "Deck.h"

using namespace std;

Deck::Deck() {
    createDeckSource();
    buildDeckStack();
}

template<typename T>
void swapRef(T &e1, T &e2) {
    T tmp = e1;
    e1 = e2;
    e2 = tmp;
}

void Deck::shuffleDeck() {
    // STL Shuffle Function
    // shuffle(deckSource.begin(), deckSource.end(), default_random_engine {});
    
    // Implement of Fisher–Yates Shuffle
    srand(unsigned(time(0)));
    int num = deckSource.size();
    for (size_t i = num-1; i > 0; i--) {
        int j = rand() % i;
        swapRef(deckSource[i], deckSource[j]);
    }
    buildDeckStack();
}

bool Deck::isEmpty() const {
    return deckStack.size() == 0;
}

Card* Deck::deal() {
    Card* topCard = deckStack.top();
    deckStack.pop();

    if (isEmpty()) {
        cout << "This deck is empty now. Refill the deck!" << endl;
        shuffleDeck();
        buildDeckStack();
    }
    return topCard;
}

void Deck::buildDeckStack() {
    while (!deckStack.empty())
        deckStack.pop();
    
    // shuffleDeck();
    for (size_t i = 0; i < 52; i++) {
        deckStack.push(&deckSource[i]);
    }
}

void Deck::createDeckSource() {
    for (size_t i = 0; i < 13; i++) {
        int value = (i+1 < 10) ? i+1 : 10; // The value of face cards(the Jack, Queen and King) have a value of 10  
        for (size_t j = 0; j < 4; j++) {
            SuitCard c(Card::faces[i], SuitCard::suits[j], value);
            deckSource.push_back(c);
        }
    }
}