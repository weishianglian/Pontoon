#include "Player.h"

using namespace std;

Player::Player(Deck *deck) : Bank(deck) {}

void Player::printHand(string role) {
    Bank::printHand(role);
}

