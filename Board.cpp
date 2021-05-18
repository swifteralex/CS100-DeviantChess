#include "Board.h"

void Board::setPosition(const std::vector<std::vector<char>>& pos) {

}

std::vector<std::string>* Board::getLegalMoves() const {
    return new std::vector<std::string>();
}

bool Board::isInCheck() const {
    // find king position
    int kingRow = -1;
    int kingCol = -1;
    for (char row = 0; row < 8; row++) {
        for (char col = 0; col < 8; col++) {
            ChessObject* p = pos[row][col];
            if (!p) {
                continue;
            }
            if (((color == 'w') && (p->getLabel() == 'K')) || ((color == 'b') && (p->getLabel() == 'k'))) {
                kingRow = row;
                kingCol = col;
                break;
            }
        }
        if (kingRow != -1) {
            break;
        }
    }

    // check if enemy pawn is attacking king
    if (color == 'w') {
        if (kingRow >= 1) {
            if (kingCol >= 1 && pos[kingRow - 1][kingCol - 1] && (pos[kingRow - 1][kingCol - 1])->getLabel() == 'p') {
                return true;
            }
            if (kingCol <= 6 && pos[kingRow - 1][kingCol + 1] && (pos[kingRow - 1][kingCol + 1])->getLabel() == 'p') {
                return true;
            }
        }
    } else {
        if (kingRow <= 6) {
            if (kingCol >= 1 && pos[kingRow + 1][kingCol - 1] && (pos[kingRow + 1][kingCol - 1])->getLabel() == 'P') {
                return true;
            }
            if (kingCol <= 6 && pos[kingRow + 1][kingCol + 1] && (pos[kingRow + 1][kingCol + 1])->getLabel() == 'P') {
                return true;
            }
        }
    }


    // check if enemy knight is attacking king
    for (int rowDiff = -2; rowDiff < 3; rowDiff++) {
        for (int colDiff = -2; colDiff < 3; colDiff++) {
            if (rowDiff == 0 || colDiff == 0 || abs(colDiff) == abs(rowDiff)) {
                continue;
            }
            if (kingRow + rowDiff >= 0 && kingRow + rowDiff <= 7 && kingCol + colDiff >= 0 && kingCol + colDiff <= 7) {
                ChessObject* p = pos[kingRow + rowDiff][kingCol + colDiff];
                if (!p) {
                    continue;
                }
                if ((p->getLabel() == 'n' && color == 'w') || (p->getLabel() == 'N' && color == 'b')) {
                    return true;
                }
            }
        }
    }

    // check if enemy bishop or queen is attacking king diagonally
    for (int i = 0; i < 4; i++) {
        int rowDiff = 1 + ((-i / 2) * 2);
        int colDiff = 1 + ((i % 2) * -2);
        int row = kingRow + rowDiff;
        int col = kingCol + colDiff;
        while (row >= 0 && row <= 7 && col >= 0 && col <= 7) {
            ChessObject* p = pos[row][col];
            row += rowDiff;
            col += colDiff;
            if (!p) {
                continue;
            }
            if (color == 'w' && (p->getLabel() == 'q' || p->getLabel() == 'b')) {
                return true;
            }
            if (color == 'b' && (p->getLabel() == 'Q' || p->getLabel() == 'B')) {
                return true;
            }
            break;
        }
    }

    // check if enemy rook or queen is attacking king orthogonally
    for (int i = 0; i < 4; i++) {
        int rowDiff = (1 - 2 * (i == 3)) * (i > 1);
        int colDiff = (1 - 2 * (i == 0)) * (i < 2);
        int row = kingRow + rowDiff;
        int col = kingCol + colDiff;
        while (row >= 0 && row <= 7 && col >= 0 && col <= 7) {
            ChessObject* p = pos[row][col];
            row += rowDiff;
            col += colDiff;
            if (!p) {
                continue;
            }
            if (color == 'w' && (p->getLabel() == 'q' || p->getLabel() == 'r')) {
                return true;
            }
            if (color == 'b' && (p->getLabel() == 'Q' || p->getLabel() == 'R')) {
                return true;
            }
            break;
        }
    }

    return false;
}

Board* Board::getInstance() {
    if (!instance) {
        instance = new Board();
    }
    return instance;
}

std::string Board::generateFEN() const {
    return "";
}

bool Board::playMove(const std::string& move) {
    return false;
}

void Board::printBoard() const {
}

