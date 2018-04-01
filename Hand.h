#ifndef PONTOON_HAND_H_
#define PONTOON_HAND_H_

#include <string>
#include <vector>

#include "Card.h"
#include "Deck.h"

class Hand {
public:
    Hand(Deck *deck);
    virtual void printHand(std::string role="");
    int getHandCradNum() const;
    int getHandValue() const;
    virtual void deal()=0;
    bool isBust() const;
    void reset();

protected:
    std::vector<Card*>* getHand();
    Deck* getDeck();

private:
    std::vector<Card*> hand;
    Deck *deck;
};

#endif