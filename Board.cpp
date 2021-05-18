#include "Board.h"

void Board::setPosition(const std::vector<std::vector<ChessObject*>>& pos) {
	this->pos = pos;
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

vector<int> findVPos(string &pos){
    vector<int> posit(2);
    string num = pos.substr(1,2);
    sstream g(num);
    int n = 0;
    g >> n;
    posit(0) = n;
    string post = pos.substr(0,1);
    if(post == 'a'|| post == 'A'){
        posit[1] = 0;
    }
    else(post == "b" || post == "B"){
        posit[1] = 1;
    }
    else(post == "c" || post == "C"){
        posit[1] = 2;
    }
    else(post == "d" || post == "D"){
        posit[1] = 3;
    }
    else(post == "e" || post == "E"){
        posit[1] = 4;
    }
    else(post == "f" || post == "F"){
        posit[1] = 5;
    }
    else(post == "g" || post == "G"){
        posit[1] = 6;
    }
    else(post == "h" || post == "H"){
        posit[1] = 7;
    }
    return posit;
}
Piece Board::getPieceAt(string &position){
    vector<int> vPos = findVPos(position);
    return pos.at(vPos.at(0)).at(vPos.at(1));
}

void Board::printBoard() const {
	cout << "   =====================================" << endl;
            int num = 9;
            for(int i = 0; i < pos.size(); i++){
                
                cout << num-1 << "  ";
                num = num-1;
                cout << "|   ";
                for(int j = 0; j < pos.at(i).size(); j++){
                    cout << pos.at(i).at(j)->getLabel() << "   ";
                }
            cout << "|" <<endl <<"   |                                   |"<< endl;
            }
            cout << "   ====================================="<< endl;
            cout << "       A   B   C   D   E   F   G   H" << endl;
}
char Board::getColor(){
	return currentTurn;
}

void setColor(char turn){
	currentTurn = turn;
}
