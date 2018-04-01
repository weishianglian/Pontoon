#ifndef PONTOON_CARD_H_
#define PONTOON_CARD_H_

#include <string>

class Card {
public:
    static const std::string faces[13];

    Card(const std::string &, int=0);
    std::string getFace() const;
    void setFace(const std::string&);
    int getValue() const;
    void setValue(int);
    virtual void printCard();

private:
    std::string face;
    int value;
};

#endif
