#include "Board.h"
#include <iostream>

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
    for (int i = 0; i < pos.size(); ++i) {
        for (int j = 0; j < pos[i].size(); ++j) {
            std::cout << pos[i][j]->getPieceName() << ' ';
        }
        std::cout << std::endl;
    }
}

char Board::getColor() const{

}

void Board::setColor(char c) {



}
