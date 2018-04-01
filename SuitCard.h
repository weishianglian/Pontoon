#ifndef PONTOON_SUITCARD_H_
#define PONTOON_SUITCARD_H_

#include <string>

#include "Card.h"

class SuitCard : public Card {
public:
    static const std::string suits[4];

    SuitCard(const std::string &, const std::string &, int=0);
    std::string getSuit() const;
    void setSuit(const std::string&);
    void printCard() override;

private:
    std::string suit;
};

#endif
