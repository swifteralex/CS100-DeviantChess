#include "Board.h"


Board::Board() : ChessObject('w', "board") {
    pos = {
        { new Rook(this, 'b', "r"), new Knight(this, 'b', "n"), new Bishop(this, 'b', "b"), new Queen(this, 'b', "q"), new King(this, 'b', "k"), new Bishop(this, 'b', "b"), new Knight(this, 'b', "n"), new Rook(this, 'b', "r") },
        { new Pawn(this, 'b', "p"), new Pawn(this, 'b', "p"), new Pawn(this, 'b', "p"), new Pawn(this, 'b', "p"), new Pawn(this, 'b', "p"), new Pawn(this, 'b', "p"), new Pawn(this, 'b', "p"), new Pawn(this, 'b', "p") },
        {  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  },
        {  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  },
        {  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  },
        {  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  },
        { new Pawn(this, 'w', "P"), new Pawn(this, 'w', "P"), new Pawn(this, 'w', "P"), new Pawn(this, 'w', "P"), new Pawn(this, 'w', "P"), new Pawn(this, 'w', "P"), new Pawn(this, 'w', "P"), new Pawn(this, 'w', "P") },
        { new Rook(this, 'w', "R"), new Knight(this, 'w', "N"), new Bishop(this, 'w', "B"), new Queen(this, 'w', "Q"), new King(this, 'w', "K"), new Bishop(this, 'w', "B"), new Knight(this, 'w', "N"), new Rook(this, 'w', "R") }
    };
}

Board::~Board() {
    for (std::vector<Piece*> row : pos) {
        for (Piece* piece : row) {
            if (piece) {
                delete piece;
            }
        }
    }
}

void Board::setPosition(const std::vector<std::vector<char>>& in) {
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (pos[r][c]) {
                delete pos[r][c];
            }
            if (in[r][c] == '0') {
                pos[r][c] = nullptr;
            } else if (in[r][c] == 'r') {
                pos[r][c] = new Rook(this, 'b', "r");
            } else if (in[r][c] == 'n') {
                pos[r][c] = new Knight(this, 'b', "n");
            } else if (in[r][c] == 'b') {
                pos[r][c] = new Bishop(this, 'b', "b");
            } else if (in[r][c] == 'q') {
                pos[r][c] = new Queen(this, 'b', "q");
            } else if (in[r][c] == 'k') {
                pos[r][c] = new King(this, 'b', "k");
            } else if (in[r][c] == 'p') {
                pos[r][c] = new Pawn(this, 'b', "p");
            } else if (in[r][c] == 'R') {
                pos[r][c] = new Rook(this, 'w', "R");
            } else if (in[r][c] == 'N') {
                pos[r][c] = new Knight(this, 'w', "N");
            } else if (in[r][c] == 'B') {
                pos[r][c] = new Bishop(this, 'w', "B");
            } else if (in[r][c] == 'Q') {
                pos[r][c] = new Queen(this, 'w', "Q");
            } else if (in[r][c] == 'K') {
                pos[r][c] = new King(this, 'w', "K");
            } else {
                pos[r][c] = new Pawn(this, 'w', "P");
            }
        }
    }
}

void Board::setPosition(const std::vector<std::vector<Piece*>>& pos) {
	this->pos = pos;
}

bool Board::updateBoard(string& pos1, string& pos2){
    vector<int> pos1v = findVPos(pos1);
    if(pos.at(pos1v.at(0).at(pos1v.at(1) == nullptr){
        cout << "No piece at" << pos1 << endl;
        return false;
    }
    if(pos.at(pos1v.at(0)).at(pos1v.at(1))->playMove(pos2) == true){
        vector<int> pos2v = findVPos(pos2);
        pos[pos2v[0]][pos2v[1]] = pos[pos1v[0]][pos1v[1]];
        pos[pos1v[0]][pos1v[1]] = nullptr;
        return true;
    }
    else{
        cout << "Not a Valid Move"<< endl;
        return false;
    }

    return false;
}

bool Board::isInCheck() const {
    return false;
}

// Board* Board::getInstance() {
//     if (!instance) {
//         instance = new Board();
//     }
//     return instance;
// }

std::string Board::generateFEN() const {
    return "";
}

vector<int> findVPos(std::string &pos){
    vector<int> posit(2);
    string num = pos.substr(1,2);
    sstream g(num);
    int n = 0;
    g >> n;
    posit.at(0) = n;
    string post = pos.substr(0,1);
    if(post == 'a'|| post == 'A'){
        posit.at(1) = 0;
    }
    else(post == "b" || post == "B"){
        posit.at(1) = 1;
    }
    else(post == "c" || post == "C"){
        posit.at(1) = 2;
    }
    else(post == "d" || post == "D"){
        posit.at(1) = 3;
    }
    else(post == "e" || post == "E"){
        posit.at(1) = 4;
    }
    else(post == "f" || post == "F"){
        posit.at(1) = 5;
    }
    else(post == "g" || post == "G"){
        posit.at(1) = 6;
    }
    else(post == "h" || post == "H"){
        posit.at(1) = 7;
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
		    if(pos.at(i).at(j) != nullptr){
                        cout << pos.at(i).at(j)->getLabel() << "   ";
		    }
		    else{
			cout << "0   ";
		    }
                }
            cout << "|" <<endl <<"   |                                   |"<< endl;
            }
            cout << "   ====================================="<< endl;
            cout << "       A   B   C   D   E   F   G   H" << endl;
}
char Board::getColor(){
	return currentTurn;
}
char Board::getLabel(){
	return title;
}
void Board::setLabel(char l){
	title = l;
}
void setColor(char turn){
	currentTurn = turn;
}
