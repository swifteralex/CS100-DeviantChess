#include "Board.h"

void Board::setPosition(const std::vector<std::vector<char>>& pos) {

}

std::vector<std::string>* Board::getLegalMoves() const {
    return new std::vector<std::string>();
}

bool Board::isInCheck() const {
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

char Board::getColor() {

}

void Board::setColor(char c) {



}
