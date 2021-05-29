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

// void Board::setPosition(const std::vector<std::vector<ChessObject*>>& pos) {
//     this->pos = pos;
// }

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

bool Board::updateBoard(std::string pos1, std::string pos2c){
    std::string pos2 = pos2c.substr(0,2);
    std::vector<int> pos1v = findVPos(pos1); //vector location
    //checks if there is a piece at the said location.
    if(pos[pos1v[0]][pos1v[1]] == nullptr){
        // std::cout << "No piece at: " << pos1 << std::endl;
        return false;
    }
    std::vector<int> pos2v = findVPos(pos2); // second piece vector location
    Piece* prev; //stores the move location in case of a revert move. 
    bool moved = false; // checks if move is valid. 
    Piece* currentPiece = pos[pos1v[0]][pos1v[1]]; // stores a pointer to the piece needing to be moved. 
    //special case for pawn movement. 
    if(currentPiece->getLabel() == "p" || currentPiece->getLabel() == "P"){
        if(pos2v[0] == pos1v[0]){
            if(pos[pos2v[0]][pos2v[1]] != nullptr){
                // std::cout << "Invalide Pawn Placement" << std::endl;
                return false;
            }
        }
    }
    std::vector<std::string> move = currentPiece->getLegalMoves(); //string of all possible moves
    std::vector<std::string> moves;
    for(int i = 0; i < move.size();i++){
        moves.push_back(move[i].substr(2,2));
    }
    
    //king and queen slide. 
    if(currentPiece->getLabel() == "k" || currentPiece->getLabel() == "K"){
        // if(castlingPrivileges == "-"){
        //     if(pos1 == "e1" && pos2 == "g1" || pos1 == "e8" && pos2 == "g8"){
        //         std::cout << "Castling KingSide not allowed" << std::endl;
        //         return false;
        //     }
        // }
        //this portion swaps. if the slide is part of legal moves.
        for(int i = 0; i < move.size(); i++){
            if(move[i] == "e1g1" && move[i].substr(2,4) == pos2){
                swap(pos1v, pos2v);
                std::string h1 = "h1";
                std::string f1 = "f1";
                std::vector<int> h = findVPos(h1);
                std::vector<int> f = findVPos(f1);
                swap(h, f);
                moved = true;
            }
            else if(move[i] == "e1c1" && move[i].substr(2,4) == pos2){
                swap(pos1v, pos2v);
                std::string a1 = "a1";
                std::string d1 = "d1";
                std::vector<int> a = findVPos(a1);
                std::vector<int> d = findVPos(d1);

                swap(a, d);
                moved = true;
            }
            else if(move[i] == "e8g8" && move[i].substr(2,4) == pos2){
                swap(pos1v, pos2v);
                std::string h = "h8";
                std::string f = "f8";
                std::vector<int> h1 = findVPos(h);
                std::vector<int> f1 = findVPos(f);

                swap(h1, f1);
                moved = true;
            }
            else if(move[i] == "e8c8" && move[i].substr(2,4) == pos2){
                swap(pos1v, pos2v);
                std::string a1 = "a8";
                std::string d1 = "d8";
                std::vector<int> a = findVPos(a1);
                std::vector<int> d = findVPos(d1);

                swap(a, d);
                moved = true;
            }
        }
    }
    // if the piece is not the currentTurn's piece it doesnt move. 
    if(currentPiece->getColor() != color){
        // std::cout << "Cannot Move Enemy Pieces. " << std::endl;
        return false;
    }
    
    
    //this moves if the piece is a legal move. 
    // std::cout << moves.size();
    for(int i = 0; i < moves.size(); i++){
        // std::cout << "hey" << std::endl;
        if(moves[i] == pos2 && moved == false){
            if(pos[pos2v[0]][pos2v[1]] == nullptr){//empty space
                //swaps pieces.
                prev = pos[pos2v[0]][pos2v[1]];
                //std::cout <<  "this works" << std::endl;
                swap(pos1v, pos2v);
                pos[pos1v[0]][pos1v[1]] = nullptr;
                // std::cout << "Move Successful" << std::endl;
                moved = true;
            }
            else {
                // if(pos[pos2v[0]][pos2v[1]]->getColor() != color){ //only moves if the space is filled with a different colored piece. i.e. 
                    prev = pos[pos2v[0]][pos2v[1]];
                    swap(pos1v, pos2v);
                    pos[pos1v[0]][pos1v[1]] = nullptr;
                    //std::cout <<  "this works" << std::endl;
                    // std::cout << "Move Successful" << std::endl;
                    moved = true;
                //}
                // else{
                //    moved = false;
                // }
            }
        }
    }
    //invalid move. returns false
    if(!moved){
        // std::cout << "Invalid Move" << std::endl;
        return false;
    }
    //pawn promotion
    std::vector<std::string> legalPromo;
    for(int i = 0; i < move.size(); i++){
        if(move[i].length() == 5){
            legalPromo.push_back(move[i].substr(4,5));
        }
    }
    bool promo = false;
    // std::cout << pos2c.substr(2,3) << std::endl;
    if( currentPiece->getLabel() == "p"  && pos2v[0] == 7){
        for(int i = 0; i < legalPromo.size(); i++){
            // std::cout << pos2c.substr(1,3) << std::endl;
            if(legalPromo[i] == pos2c.substr(2,3)){
                if(legalPromo[i] == "b"){
                    pos[pos2v[0]][pos2v[1]] = new Bishop(this, 'b', "b");
                }
                else if(legalPromo[i]== "q"){
                    pos[pos2v[0]][pos2v[1]] = new Queen(this, 'b', "q");
                }
                else if(legalPromo[i] == "n"){
                    pos[pos2v[0]][pos2v[1]] = new Knight(this, 'b', "n");
                }
                else if(legalPromo[i] == "r"){
                    pos[pos2v[0]][pos2v[1]] = new Rook(this, 'b', "r");
                }
                promo = true;
            }
        }
    }
    else if(currentPiece->getLabel() == "P" && pos2v[0] == 0){
        for(int i = 0; i < legalPromo.size(); i++){
            //std::cout << pos2c.substr(2,3) << std::endl;
            if(legalPromo[i] == pos2c.substr(2,3)){
                if(legalPromo[i] == "b"){
                    pos[pos2v[0]][pos2v[1]] = new Bishop(this, 'w', "B");
                    
                }
                else if(legalPromo[i]== "q"){
                    pos[pos2v[0]][pos2v[1]] = new Queen(this, 'w', "Q");
                    
                }
                else if(legalPromo[i] == "n"){
                    pos[pos2v[0]][pos2v[1]] = new Knight(this, 'w', "N");
                    
                }
                else if(legalPromo[i] == "r"){
                    pos[pos2v[0]][pos2v[1]] = new Rook(this, 'w', "R");
                    
                }
                promo = true;
            }
        }
    }
    if(promo == false && currentPiece->getLabel() == "p"){
        if(pos2v[0] == 7){
            pos[pos1v[0]][pos1v[1]] = new Pawn(this, 'b', "p");
            pos[pos2v[0]][pos2v[1]] = prev;
            // std::cout << "King is in Check. Invalid Move" << std::endl;
            return false;
        }
    }
    else if(promo == false && currentPiece->getLabel() == "P"){
        if(pos2v[0] == 0){
            pos[pos1v[0]][pos1v[1]] = new Pawn(this, 'w', "P");
            pos[pos2v[0]][pos2v[1]] = prev;
            // std::cout << "King is in Check. Invalid Move" << std::endl;
            return false;
        }
    }
    //just checks if king is in check... THIS IS A FAILSAFE IN CASE GETLEGALMOVES DOESNT CATCH IT. 
    if(isInCheck() == false){
        return true;
    }
    //if after move the player's  king is in check, reverts the board. 
    else if(isInCheck() == true){
        pos[pos1v[0]][pos1v[1]] = pos[pos2v[0]][pos2v[1]];
        pos[pos2v[0]][pos2v[1]] = prev;
        // std::cout << "King is in Check. Invalid Move" << std::endl;
        return false;
    }
    //just here b/c otherwise i have an error. 
    return false;
}


void Board::swap(std::vector<int> pos1, std::vector<int> pos2){
    Piece* prev = pos[pos2[0]][pos2[1]];
    pos[pos2[0]][pos2[1]] = pos[pos1[0]][pos1[1]];
    pos[pos1[0]][pos1[1]] = prev;
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

    // check if enemy king is attacking king (used for move legality checking)
    for (int i = 0; i < 9; i++) {
        if (i == 4) {
            continue;
        }
        int rowDiff = (i / 3) - 1;
        int colDiff = (i % 3) - 1;
        int r = kingRow + rowDiff;
        int c = kingCol + colDiff;
        if (r >= 0 && r <= 7 && c >= 0 && c <= 7) {
            if (pos[r][c] && pos[r][c]->getColor() != color && (pos[r][c]->getLabel() == "k" || pos[r][c]->getLabel() == "K")) {
                return true;
            }
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
    int n = 0;
    n = std::stoi(num);
    posit.at(0) = 8-n;
    std::string post = pos.substr(0,1);
    if(post == "a"|| post == "A"){
        posit.at(1) = 0;
    }
    else if(post == "b" || post == "B"){
        posit.at(1) = 1;
    }
    else if(post == "c" || post == "C"){
        posit.at(1) = 2;
    }
    else if(post == "d" || post == "D"){
        posit.at(1) = 3;
    }
    else if(post == "e" || post == "E"){
        posit.at(1) = 4;
    }
    else if(post == "f" || post == "F"){
        posit.at(1) = 5;
    }
    else if(post == "g" || post == "G"){
        posit.at(1) = 6;
    }
    else if(post == "h" || post == "H"){
        posit.at(1) = 7;
    }
    return posit;
}

Piece* Board::getPieceAt(const std::string &position) const {
    //std::vector<int> vPos = findVPos(position);
    //return pos.at(vPos.at(0)).at(vPos.at(1));
    char lowercase = position[0] | 32;
    return pos[56 - position[1]][lowercase - 97]; 
}

std::string Board::printBoard() const {
    std::string output;
    output += "   =====================================\n";
    int num = 9;
        for(int i = 0; i < pos.size(); i++){     
            output += std::to_string(num-1) + "  ";
            num = num-1;
            output += "|   ";
            for(int j = 0; j < pos.at(i).size(); j++){
                if (pos.at(i).at(j)) {
                    output += pos.at(i).at(j)->getLabel();
                } else {
                    output += "0";
                }
                output += "   ";
            }
            output += "|\n   |                                   |\n";
        }
        output += "   =====================================\n";
        output += "       A   B   C   D   E   F   G   H\n";
    return output;
}

bool Board::isCheckmated() {
    if (isInCheck()) {
        int kingRow = -1;
        int kingCol = -1;
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
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
        Piece* kingPosition = pos[kingRow][kingCol];
        if ((kingPosition->getLegalMoves()).size() == 0) {
            return true;
        }
    }
    return false;
}

bool Board::isStalemated() {
    bool check = false;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (pos[i][j] != nullptr && (this->getColor() == pos[i][j]->getColor())) {
                Piece* temp = pos[i][j];
                if ((temp->getLegalMoves()).size() == 0) {
                    check = true;
                }
                else {
                    return false;
                }
            }
        }
    }
    if (!isInCheck() && check){
        return true;
    }
    return false;
}
