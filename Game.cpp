#include <iostream>

#include "Game.h"

using namespace std;

Game::Game(Deck* deck) : deck(deck) {
    shuffleDeck(deck);
}

Game::~Game() {
    delete(deck);
}

void Game::shuffleDeck(Deck *deck) {
    deck -> shuffleDeck();
}

void Game::startDealing(Player *player , Bank *bank) {
    bank -> deal();
    bank -> deal();
    player -> deal();
    player -> deal();
    player -> printHand();
}

bool Game::playerOption(Player *player, Log *log) const {
    char option;
    string input = "";
    bool playing = true;
    bool continued = true;
    while (continued) {
        if (player -> isBust()) {
            playing = false;
            continued = false;
            log -> setRoundResult(Log::LOSE);
            cout << bustStr << endl << endl << loseStr << endl << endl; 
        } else if (player -> getHandCradNum() == 5) {
            playing = true;
            continued = false;
        } else {
            while (true) {
                cout << endl << optionStr;
                getline(cin, input);
                cout << endl;
                if (input.length() == 1 && (input == "s" || input == "t")) {
                    option = input[0];
                    break;
                }
            }
            if (option == 's') {
                continued = false;
            } else {
                player -> deal();
                player -> printHand();
            }
        }
    }
    return playing;
}

void Game::bankAction(Player *player, Bank *bank, Log *log) {
    bool continued = true;
    bank -> printHand();
    while (continued) {
        if (bank -> isBust()) {
            continued = false;
            log -> setRoundResult(Log::WIN);
            cout << bustStr << endl << endl << wonStr << endl << endl;
        } else if (bank -> getHandValue() > player -> getHandValue()) {
            continued = false;
            log -> setRoundResult(Log::LOSE);
            cout << endl << loseStr << endl << endl;
        } else if (bank -> getHandValue() == player -> getHandValue()) {
            if (bank -> getHandCradNum() > player -> getHandCradNum()) {
                continued = false;
                log -> setRoundResult(Log::LOSE);
                cout << endl << loseStr << endl << endl;
            } else if (bank -> getHandCradNum() <= player -> getHandCradNum()) {
                continued = false;
                log -> setRoundResult(Log::DRAW);
                cout << endl << drawStr << endl << endl;
            } 
        } else if (bank -> getHandCradNum() == 5) {
            if (bank -> getHandValue() > player -> getHandValue()) {
                continued = false;
                log -> setRoundResult(Log::LOSE);
                cout << loseStr << endl << endl;
            } else if (bank -> getHandValue() < player -> getHandValue()) {
                continued = false;
                log -> setRoundResult(Log::WIN);
                cout << endl << wonStr << endl << endl;
            } else {
                continued = false;
                log -> setRoundResult(Log::DRAW);
                cout << endl << drawStr << endl << endl;
            }
        } else {
            cout << endl << drawCardStr << endl;
            bank -> deal();
            bank -> printHand();
        }
    }
}

bool Game::playAgain() const {
    char option;
    string input = "";
    while (true) {
        cout << againStr;
        getline(cin, input);
        if (input.length() == 1 && (input == "y" || input == "n")) {
            option = input[0];
            break;
        }
    }
    return option == 'y';
}