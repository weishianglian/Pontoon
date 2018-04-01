#ifndef PONTOON_DECK_H_
#define PONTOON_DECK_H_

#include <vector>
#include <stack>

#include "SuitCard.h"

class Deck {
public:
    Deck();
    void shuffleDeck();
    bool isEmpty() const;
    Card* deal();

private:
    std::vector<SuitCard> deckSource;
    std::stack<Card*> deckStack;

    void createDeckSource();
    void buildDeckStack();
};

#endif