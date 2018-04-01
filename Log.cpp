#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

#include "Log.h"

using namespace std;

Log::Log() {
    fileName = getFileName();
    startTime = getGameTime();
}

std::string Log::getTimeStr(char fmt[]) const {
    time_t t = time(0);
    tm *ltm = localtime(&t);
    stringstream ss;
    ss << put_time(ltm, fmt);
    return ss.str();
}

string Log::getFileName() const {
    char fmt[] = "%y%m%d_%H%M";
    return getTimeStr(fmt) + ".txt";
}

string Log::getGameTime() const {
    char fmt[] = "%H:%M %d-%b-%Y";
    return getTimeStr(fmt);   
}

void Log::setRoundResult(int result) {
    rounds.push_back(result);
}

void Log::saveLog() {
    string gameStarted = "Game started at: " + startTime;
    string gameFinished = "Game finished at: " + getGameTime();
    
    int roundsNum = rounds.size();
    int winNum = 0, loseNum = 0, drawNum = 0;
    stringstream roundRecords;
    for (size_t i = 0; i < rounds.size(); i++) {
        roundRecords << "Round " << to_string(i) << ": ";
        if (rounds[i] == WIN) {
            winNum++;
            roundRecords << "won." << endl;
        } else if (rounds[i] == LOSE) {
            loseNum++;
            roundRecords << "lost." << endl;
        } else {
            drawNum++;
            roundRecords << "draw." << endl;
        }
    }
    string gameRounds = "Rounds: " + to_string(roundsNum);
    string gameWon = "Won: " + to_string(winNum);
    string gameLost = "Lost: " + to_string(loseNum);

    ofstream logFile;
    try {
        logFile.open(getFileName());
        logFile << gameStarted << endl << gameFinished << endl;
        logFile << gameRounds << endl << gameWon << endl << gameLost << endl;
        logFile << "--" << endl << roundRecords.str() << endl;
        logFile.close();
    } catch(ofstream::failure) {
        cerr << "File IO Error!" << endl;
        cerr << gameStarted << endl << gameFinished << endl;
    }
}