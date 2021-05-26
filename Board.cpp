#include "Board.h"
#include "Piece.h"
#include <sstream>

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

void Board::setPosition(const std::vector<std::vector<Piece*>>& pos) {
    this->pos = pos;
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

bool Board::isInCheck() const {
    // find king position
    int kingRow = -1;
    int kingCol = -1;
    for (char row = 0; row < 8; row++) {
        for (char col = 0; col < 8; col++) {
            Piece* p = pos[row][col];
            if (!p) {
                continue;
            }
            if (((color == 'w') && (p->getLabel() == "K")) || ((color == 'b') && (p->getLabel() == "k"))) {
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
            if (kingCol >= 1 && pos[kingRow - 1][kingCol - 1] && (pos[kingRow - 1][kingCol - 1])->getLabel() == "p") {
                return true;
            }
            if (kingCol <= 6 && pos[kingRow - 1][kingCol + 1] && (pos[kingRow - 1][kingCol + 1])->getLabel() == "p") {
                return true;
            }
        }
    } else {
        if (kingRow <= 6) {
            if (kingCol >= 1 && pos[kingRow + 1][kingCol - 1] && (pos[kingRow + 1][kingCol - 1])->getLabel() == "P") {
                return true;
            }
            if (kingCol <= 6 && pos[kingRow + 1][kingCol + 1] && (pos[kingRow + 1][kingCol + 1])->getLabel() == "P") {
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
                Piece* p = pos[kingRow + rowDiff][kingCol + colDiff];
                if (!p) {
                    continue;
                }
                if ((p->getLabel() == "n" && color == 'w') || (p->getLabel() == "N" && color == 'b')) {
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
            Piece* p = pos[row][col];
            row += rowDiff;
            col += colDiff;
            if (!p) {
                continue;
            }
            if (color == 'w' && (p->getLabel() == "q" || p->getLabel() == "b")) {
                return true;
            }
            if (color == 'b' && (p->getLabel() == "Q" || p->getLabel() == "B")) {
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
            Piece* p = pos[row][col];
            row += rowDiff;
            col += colDiff;
            if (!p) {
                continue;
            }
            if (color == 'w' && (p->getLabel() == "q" || p->getLabel() == "r")) {
                return true;
            }
            if (color == 'b' && (p->getLabel() == "Q" || p->getLabel() == "R")) {
                return true;
            }
            break;
        }
    }

    return false;
}

std::string Board::generateFEN() const {
    return "";
}

std::vector<int> Board::findVPos(const std::string &pos) const {
    std::vector<int> posit(2);
    std::string num = pos.substr(1,2);
    std::istringstream g(num);
    int n = 0;
    g >> n;
    posit[0] = n;
    std::string post = pos.substr(0,1);
    if(post == "a"|| post == "A"){
        posit[1] = 0;
    }
    else if(post == "b" || post == "B"){
        posit[1] = 1;
    }
    else if(post == "c" || post == "C"){
        posit[1] = 2;
    }
    else if(post == "d" || post == "D"){
        posit[1] = 3;
    }
    else if(post == "e" || post == "E"){
        posit[1] = 4;
    }
    else if(post == "f" || post == "F"){
        posit[1] = 5;
    }
    else if(post == "g" || post == "G"){
        posit[1] = 6;
    }
    else if(post == "h" || post == "H"){
        posit[1] = 7;
    }
    return posit;
}

Piece* Board::getPieceAt(const std::string &position) const {
    //std::vector<int> vPos = findVPos(position);
    //return pos.at(vPos.at(0)).at(vPos.at(1));
    return pos[56 - position[1]][position[0] - 97]; 
}

void Board::printBoard() const {
    std::cout << "   =====================================" << std::endl;
    int num = 9;
        for(int i = 0; i < pos.size(); i++){     
            std::cout << num-1 << "  ";
            num = num-1;
            std::cout << "|   ";
            for(int j = 0; j < pos.at(i).size(); j++){
                if (pos.at(i).at(j)) {
                    std::cout << pos.at(i).at(j)->getLabel();
                } else {
                    std::cout << " ";
                }
                std::cout << "   ";
            }
            std::cout << "|" << std::endl <<"   |                                   |"<< std::endl;
        }
        std::cout << "   ====================================="<< std::endl;
        std::cout << "       A   B   C   D   E   F   G   H" << std::endl;
}

