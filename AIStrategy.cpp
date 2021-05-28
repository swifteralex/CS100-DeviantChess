#include "AIStrategy.h"
#include <random>
#include <ctime>

AIStrategy::AIStrategy(Board* b) : board(b) {}

Stockfish::Stockfish(Board* b, int level) : AIStrategy(b), level(level) {}

std::string Stockfish::getBestMove() {
    return "";
}

Random::Random(Board* b) : AIStrategy(b) {}

std::string Random::getBestMove() {
    std::vector<std::string> moves;
    for (char r = '1'; r < '9'; r++) {
        for (char c = 'a'; c < 'i'; c++) {
            std::string square;
            square.push_back(c);
            square.push_back(r);
            Piece* piece = board->getPieceAt(square);
            if (piece && piece->getColor() == board->getColor()) {
                std::vector<std::string>* ret = piece->getLegalMoves();
                for (int i = 0; i < ret->size(); i++) {
                    moves.push_back(ret->at(i));
                }
                delete ret;
            }
        }
    }
    srand(time(0));
    int random_move = rand() % moves.size();
    return moves[random_move];
}
