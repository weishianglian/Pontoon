#ifndef PONTOON_LOG_H_
#define PONTOON_LOG_H_

#include <string>
#include <vector>


class Log {
public:
    Log();
    void setRoundResult(int);
    void saveLog();
    
    enum gameResults {WIN=1, LOSE=2, DRAW=3};

private:
    std::string fileName;
    std::string startTime;
    std::vector<int> rounds;

    std::string getTimeStr(char []) const;
    std::string getFileName() const;
    std::string getGameTime() const;

};

#endif