#include "AIStrategy.h"

AIStrategy::AIStrategy(Board* b) : board(b) {}

Stockfish::Stockfish(Board* b, int level) : AIStrategy(b), level(level) {}

std::string Stockfish::getBestMove() {
    return "";
}

Random::Random(Board* b) : AIStrategy(b) {}

std::string Random::getBestMove() {
    return "";
}
