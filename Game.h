#ifndef PONTOON_GAEM_H_
#define PONTOON_GAEM_H_

#include "Log.h"
#include "Player.h"

class Game {
public:
    Game(Deck*);
    ~Game();
    void shuffleDeck(Deck*);
    void startDealing(Player*, Bank*);
    bool playerOption(Player*, Log*) const;
    void bankAction(Player*, Bank*, Log*);
    bool playAgain() const;

private:
    Deck* deck;
    std::string wonStr = "Well done, you won!!!";
    std::string loseStr = "Bad luck, the bank won.";
    std::string bustStr = "BUST!!!";
    std::string optionStr = "[s]tick or [t]wist? ";
    std::string drawStr = "Draw";
    std::string drawCardStr = "The bank draws a card...";
    std::string againStr = "Do you want to play again ([y]es/[n]o)?";
};

#endif