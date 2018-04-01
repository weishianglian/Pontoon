#ifndef PONTOON_BANK_H_
#define PONTOON_BANK_H_

#include "Hand.h"

class Bank : public Hand {
public:
    Bank(Deck *deck);
    void printHand(std::string role="Banks") override;
    void deal() override;
};

#endif