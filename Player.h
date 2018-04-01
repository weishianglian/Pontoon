#ifndef PONTOON_PLAYER_H_
#define PONTOON_PLAYER_H_

#include "Bank.h"

class Player : public Bank {
public:
    Player(Deck *deck);
    void printHand(std::string role="Your") override;
};

#endif