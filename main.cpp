#include "Board.h"
Board* Board::instance = nullptr;

int main() {
    Board* board = board->getInstance();

    board->printBoard();

    return 0;
}