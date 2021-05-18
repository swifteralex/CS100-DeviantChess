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
	cout << "=====================================" << endl;
        for(int i = 0; i < pos.size(); i++){
		cout << "|   ";
                for(int j = 0; j < pos.at(i).size(); j++){
                	cout << pos.at(i).at(j) << "   ";
                }
            	cout << "|" <<endl <<"|                                   |"<< endl;
        }
        cout << "=====================================";
}

