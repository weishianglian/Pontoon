#include <iostream>

#include "Game.h"

using namespace std;

int main() {
    Log log;
    bool playing = true;

    Deck* deck = new Deck();
    Game* game = new Game(deck);
    Bank bank(deck);
    Player player(deck);

    while (playing) {
        game -> startDealing(&player, &bank);
        if (game -> playerOption(&player, &log)) {
            game -> bankAction(&player, &bank, &log);
        }
        player.reset();
        bank.reset();
        if (!game -> playAgain()) {
            cout << endl << "Thanks, bye!" << endl;
            playing = false;
        }
    }
    log.saveLog();
    
    delete(game);

    return 0;
}