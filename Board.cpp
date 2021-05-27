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

//makes the move.
bool Board::updateBoard(std::string& pos1, std::string& pos2c){
    std::string pos2 = pos2c.substr(0,2);
    std::vector<int> pos1v = findVPos(pos1); //vector location
    //checks if there is a piece at the said location.
    if(pos[pos1v[0]][pos1v[1]] == nullptr){
        std::cout << "No piece at: " << pos1 << std::endl;
        return false;
    }
    std::vector<int> pos2v = findVPos(pos2); // second piece vector location
    Piece* prev; //stores the move location in case of a revert move. 
    bool moved = false; // checks if move is valid. 
    Piece* currentPiece = pos[pos1v[0]][pos1v[1]]; // stores a pointer to the piece needing to be moved. 
    //special case for pawn movement. 
    if(currentPiece->getLabel() == 'p' || currentPiece->getLabel() == 'P'){
        if(pos2v[0] == pos1v[0]){
            if(pos[pos2v[0]][pos2v[1]] != nullptr){
                std::cout << "Invalide Pawn Placement" << std::endl;
                return false;
            }
        }
    }
    std::vector<std::string> move = currentPiece->getLegalMoves(); //string of all possible moves
    std::vector<std::string> moves;
    for(int i = 0; i < move.size();i++){
        moves.push_back(move[i].substr(2,4));
    }
    
    //king and queen slide. 
    if(currentPiece->getLabel() == 'k' || currentPiece->getLabel() == 'K'){
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
                std::vector<int> h = findVPos("h1");
                std::vector<int> f = findVPos("f1");
                swap(h, f);
                moved = true;
            }
            else if(move[i] == "e1c1" && move[i].substr(2,4) == pos2){
                swap(pos1v, pos2v);
                std::vector<int> a = findVPos("a1");
                std::vector<int> d = findVPos("d1");

                swap(a, d);
                moved = true;
            }
            else if(move[i] == "e8g8" && move[i].substr(2,4) == pos2){
                swap(pos1v, pos2v);
                std::vector<int> h = findVPos("h8");
                std::vector<int> f = findVPos("f8");

                swap(h, f);
                moved = true;
            }
            else if(move[i] == "e8c8" && move[i].substr(2,4) == pos2){
                swap(pos1v, pos2v);
                std::vector<int> a = findVPos("a8");
                std::vector<int> d = findVPos("d8");

                swap(a, d);
                moved = true;
            }
        }
    }
    // if the piece is not the currentTurn's piece it doesnt move. 
    if(currentPiece->getColor() != currentTurn){
        std::cout << "Cannot Move Enemy Pieces. " << std::endl;
        return false;
    }
    
    
    //this moves if the piece is a legal move. 
    for(int i = 0; i < moves.size(); i++){
        if(moves[i] == pos2 && moved == false){
            if(pos[pos2v[0]][pos2v[1]] == nullptr){//empty space
                //swaps pieces.
                prev = pos[pos2v[0]][pos2v[1]];
                
                swap(pos1v, pos2v);
                std::cout << "Move Successful" << std::endl;
                moved = true;
            }
            else {
                if(pos[pos2v[0]][pos2v[1]]->getColor() != currentTurn){ //only moves if the space is filled with a different colored piece. i.e. 
                    prev = pos[pos2v[0]][pos2v[1]];
                    swap(pos1v, pos2v);
                    pos[pos1v[0]][pos1v[1]] = nullptr;
                    std::cout << "Move Successful" << std::endl;
                    moved = true;
                }
                else{
                    moved = false;
                }
            }
        }
    }
    //invalid move. returns false
    if(!moved){
        std::cout << "Invalid Move" << std::endl;
        return false;
    }
    //pawn promotion
    std::vector<std::string> legalPromo;
    for(int i = 0; i < move.size(); i++){
        if(move[i].length() == 5){
            legalPromo.push_back(move[i].substr(4,5));
        }
    }
    if(currentPiece->getLabel() == 'p' && pos2v[0] == 7){
        for(int i = 0; i < legalPromo.size(); i++){
            if(legalPromo[i] == pos2c.substr(2,3)){
                if(legalPromo[i] == "b"){
                    pos[pos2v[0]][pos2v[1]] = new Bishop(this, 'b', 'b');
                }
                else if(legalPromo[i]== "q"){
                    pos[pos2v[0]][pos2v[1]] = new Queen(this, 'b', 'q');
                }
                else if(legalPromo[i] == "n"){
                    pos[pos2v[0]][pos2v[1]] = new Knight(this, 'b', 'n');
                }
                else if(legalPromo[i] == "r"){
                    pos[pos2v[0]][pos2v[1]] = new Rook(this, 'b', 'r');
                }
            }
        }
    }
    if(currentPiece->getLabel() == 'P' && pos2v[0] == 0){
        for(int i = 0; i < legalPromo.size(); i++){
            if(legalPromo[i] == pos2c.substr(2,3)){
                if(legalPromo[i] == "b"){
                    pos[pos2v[0]][pos2v[1]] = new Bishop(this, 'w', 'B');
                }
                else if(legalPromo[i]== "q"){
                    pos[pos2v[0]][pos2v[1]] = new Queen(this, 'w', 'Q');
                }
                else if(legalPromo[i] == "n"){
                    pos[pos2v[0]][pos2v[1]] = new Knight(this, 'w', 'N');
                }
                else if(legalPromo[i] == "r"){
                    pos[pos2v[0]][pos2v[1]] = new Rook(this, 'w', 'R');
                }
            }
        }
    }
    //just checks if king is in check... THIS IS A FAILSAFE IN CASE GETLEGALMOVES DOESNT CATCH IT. 
    if(isInCheck() == false){
        return true;
    }
    //if after move the player's  king is in check, reverts the board. 
    if(isInCheck() == true){
        pos[pos1v[0]][pos1v[1]] = pos[pos2v[0]][pos2v[1]];
        pos[pos2v[0]][pos2v[1]] = prev;
        std::cout << "King is in Check. Invalid Move" << std::endl;
        return false;
    }
    //just here b/c otherwise i have an error. 
    return false;
}

bool Board::isCheckmated(){

    //this whole part finds the current turns king
    Piece* king;
    if(currentTurn == 'w'){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(pos[i][j]->getLabel() == 'K'){
                    king = pos[i][j];
                    break;
                }
            }
        }
    }
    else if(currentTurn == 'b'){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(pos[i][j]->getLabel() == 'k'){
                    king = pos[i][j];
                    break;
                }
            }
        }
    }
    std::vector<std::string> legalMoves = king->getLegalMoves();
    int r;
    int c;
    while(r<9 && c < 9){
        Piece p = pos[r][c];
        if(p != nullptr){
            if(p->getColor() == currentTurn){
                std::vector<std::string> lm = p->getLegalMoves();
                for(int i = 0; i < lm.size(); i++){
                    legalMoves.push_back(lm[i]);
                }
            }
        }
    }
    //if in check check if any possible moves. else no.
    if(isInCheck()){
        if(legalMoves.size() == 0){
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}

bool Board::isStalemated() {
    bool check = false;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (pos[i][j] != nullptr) {
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

void Board::swap(std::vector<int> pos1, std::vector<int> pos2){
    Piece* prev = pos[pos2[0]][pos2[1]];
    pos[pos2v[0]][pos2v[1]] = pos[pos1[0]][pos1[1]];
    pos[pos1[0]][pos1[1]] = prev;
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
    posit.at(0) = 8-n;
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
