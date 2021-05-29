#ifndef _AISTRATEGY_HPP_
#define _AISTRATEGY_HPP_

#include "Board.h"

class Board;

class AIStrategy {
protected:
    Board* board;
public:
    AIStrategy(Board*);
    virtual std::string getBestMove() = 0;
};

class Stockfish : public AIStrategy {
private:
    int level;
public:
    Stockfish(Board*, int);
    std::string getBestMove();
};

class Random : public AIStrategy {
public:
    Random(Board*);
    std::string getBestMove();
};

#endif
