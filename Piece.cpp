#include "Piece.h"

Piece::Piece(Board* b, char c, const std::string& l) : ChessObject(c, l), chessBoard(b) {}

Pawn::Pawn(Board* b, char c, const std::string& l) : Piece(b, c, l) {}

std::vector<std::string>* Pawn::getLegalMoves() {
    std::vector<std::string>* moves = new std::vector<std::string>();
    int row = -1;
    int col = -1;
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (chessBoard->pos[r][c] == this) {
                row = r;
                col = c;
                break;
            }
        }
        if (row != -1) {
            break;
        }
    }
    
    if (color == 'w') {
        if (row > 0 && col > 0 && ((chessBoard->pos[row - 1][col - 1] && chessBoard->pos[row - 1][col - 1]->getColor() == 'b') || (chessBoard->enPassantSquare[0] == col + 96 && chessBoard->enPassantSquare[1] == 57 - row))) {
            std::string new_move;
            new_move.push_back(col + 96);
            new_move.push_back(57 - row);
            moves->push_back(new_move);
        }
        if (row > 0 && col < 7 && ((chessBoard->pos[row - 1][col + 1] && chessBoard->pos[row - 1][col + 1]->getColor() == 'b') || (chessBoard->enPassantSquare[0] == col + 98 && chessBoard->enPassantSquare[1] == 57 - row))) {
            std::string new_move;
            new_move.push_back(col + 98);
            new_move.push_back(57 - row);
            moves->push_back(new_move);
        }
        if (row > 0 && chessBoard->pos[row - 1][col] == nullptr) {
            std::string new_move;
            new_move.push_back(col + 97);
            new_move.push_back(57 - row);
            moves->push_back(new_move);
        }
        if (row == 6 && chessBoard->pos[5][col] == nullptr && chessBoard->pos[4][col] == nullptr) {
            std::string new_move;
            new_move.push_back(col + 97);
            new_move.push_back(58 - row);
            moves->push_back(new_move);
        }
    } else {
        if (row < 7 && col > 0 && ((chessBoard->pos[row + 1][col - 1] && chessBoard->pos[row + 1][col - 1]->getColor() == 'w') || (chessBoard->enPassantSquare[0] == (char)col + 96 && chessBoard->enPassantSquare[1] == 55 - (char)row))) {
            std::string new_move;
            new_move.push_back(col + 96);
            new_move.push_back(55 - row);
            moves->push_back(new_move);
        }
        if (row < 7 && col < 7 && ((chessBoard->pos[row + 1][col + 1] && chessBoard->pos[row + 1][col + 1]->getColor() == 'w') || (chessBoard->enPassantSquare[0] == (char)col + 98 && chessBoard->enPassantSquare[1] == 55 - (char)row))) {
            std::string new_move;
            new_move.push_back(col + 98);
            new_move.push_back(55 - row);
            moves->push_back(new_move);
        }
        if (row < 7 && chessBoard->pos[row + 1][col] == nullptr) {
            std::string new_move;
            new_move.push_back(col + 97);
            new_move.push_back(55 - row);
            moves->push_back(new_move);
        }
        if (row == 1 && chessBoard->pos[2][col] == nullptr && chessBoard->pos[3][col] == nullptr) {
            std::string new_move;
            new_move.push_back(col + 97);
            new_move.push_back(54 - row);
            moves->push_back(new_move);
        }
    }
    
    for (int i = 0; i < moves->size(); i++) {
        std::string move = moves->at(i);
        if (move == chessBoard->enPassantSquare) {
            Piece* temp = chessBoard->pos[row][move[0] - 97];
            chessBoard->pos[56 - move[1]][move[0] - 97] = this;
            chessBoard->pos[row][col] = nullptr;
            chessBoard->pos[row][move[0] - 97] = nullptr;
            if (chessBoard->isInCheck()) {
                moves->erase(moves->begin() + i);
                i--;
            }
            chessBoard->pos[row][move[0] - 97] = temp;
            chessBoard->pos[row][col] = this;
            chessBoard->pos[56 - move[1]][move[0] - 97] = nullptr;
        } else {
            Piece* temp = chessBoard->pos[56 - move[1]][move[0] - 97];
            chessBoard->pos[56 - move[1]][move[0] - 97] = this;
            chessBoard->pos[row][col] = nullptr;
            if (chessBoard->isInCheck()) {
                moves->erase(moves->begin() + i);
                i--;
            }
            chessBoard->pos[row][col] = this;
            chessBoard->pos[56 - move[1]][move[0] - 97] = temp;
        }
    }
    
    std::string start;
    start.push_back(col + 97);
    start.push_back(56 - row);
    for (int i = 0; i < moves->size(); i++) {
        std::string move = moves->at(i);
        moves->at(i) = start + move;
        if ((color == 'w' && move.back() == '8') || color == 'b' && move.back() == '1') {
            moves->erase(moves->begin() + i);
            i--;
            moves->push_back(move + "n");
            moves->push_back(move + "b");
            moves->push_back(move + "r");
            moves->push_back(move + "q");
        }
    }
    return moves;
}

Knight::Knight(Board* b, char c, const std::string& l) : Piece(b, c, l) {}

std::vector<std::string>* Knight::getLegalMoves() {
    std::vector<std::string>* moves = new std::vector<std::string>();
    int row = -1;
    int col = -1;
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (chessBoard->pos[r][c] == this) {
                row = r;
                col = c;
                break;
            }
        }
        if (row != -1) {
            break;
        }
    }

    for (int rowDiff = -2; rowDiff < 3; rowDiff++) {
        for (int colDiff = -2; colDiff < 3; colDiff++) {
            if (rowDiff == 0 || colDiff == 0 || abs(colDiff) == abs(rowDiff)) {
                continue;
            }
            if (row + rowDiff >= 0 && row + rowDiff <= 7 && col + colDiff >= 0 && col + colDiff <= 7) {
                if (chessBoard->pos[row + rowDiff][col + colDiff] && chessBoard->pos[row + rowDiff][col + colDiff]->getColor() == color) {
                    continue;
                }
                std::string new_move;
                new_move.push_back(col + colDiff + 97);
                new_move.push_back(56 - (row + rowDiff));
                moves->push_back(new_move);
            }
        }
    }

    for (int i = 0; i < moves->size(); i++) {
        std::string move = moves->at(i);
        Piece* temp = chessBoard->pos[56 - move[1]][move[0] - 97];
        chessBoard->pos[56 - move[1]][move[0] - 97] = this;
        chessBoard->pos[row][col] = nullptr;
        if (chessBoard->isInCheck()) {
            moves->erase(moves->begin() + i);
            i--;
        }
        chessBoard->pos[row][col] = this;
        chessBoard->pos[56 - move[1]][move[0] - 97] = temp;
    }

    std::string start;
    start.push_back(col + 97);
    start.push_back(56 - row);
    for (int i = 0; i < moves->size(); i++) {
        moves->at(i) = start + moves->at(i);
    }

    return moves;
}

Bishop::Bishop(Board* b, char c, const std::string& l) : Piece(b, c, l) {}

std::vector<std::string>* Bishop::getLegalMoves() { 
    std::vector<std::string>* moves = new std::vector<std::string>();
    int row = -1;
    int col = -1;
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (chessBoard->pos[r][c] == this) {
                row = r;
                col = c;
                break;
            }
        }
        if (row != -1) {
            break;
        }
    }

    for (int i = 0; i < 4; i++) {
        int rowDiff = 1 + ((-i / 2) * 2);
        int colDiff = 1 + ((i % 2) * -2);
        int r = row + rowDiff;
        int c = col + colDiff;
        while (r >= 0 && r <= 7 && c >= 0 && c <= 7) {
            if (chessBoard->pos[r][c] && chessBoard->pos[r][c]->getColor() == color) {
                break;
            } else if (chessBoard->pos[r][c]) {
                std::string new_move;
                new_move.push_back(c + 97);
                new_move.push_back(56 - r);
                moves->push_back(new_move);
                break;
            }
            std::string new_move;
            new_move.push_back(c + 97);
            new_move.push_back(56 - r);
            moves->push_back(new_move);
            r += rowDiff;
            c += colDiff;
        }
    }

    for (int i = 0; i < moves->size(); i++) {
        std::string move = moves->at(i);
        Piece* temp = chessBoard->pos[56 - move[1]][move[0] - 97];
        chessBoard->pos[56 - move[1]][move[0] - 97] = this;
        chessBoard->pos[row][col] = nullptr;
        if (chessBoard->isInCheck()) {
            moves->erase(moves->begin() + i);
            i--;
        }
        chessBoard->pos[row][col] = this;
        chessBoard->pos[56 - move[1]][move[0] - 97] = temp;
    }

    std::string start;
    start.push_back(col + 97);
    start.push_back(56 - row);
    for (int i = 0; i < moves->size(); i++) {
        moves->at(i) = start + moves->at(i);
    }

    return moves;
}

Rook::Rook(Board* b, char c, const std::string& l) : Piece(b, c, l) {}

std::vector<std::string>* Rook::getLegalMoves() {
    std::vector<std::string>* moves = new std::vector<std::string>();
    int row = -1;
    int col = -1;
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (chessBoard->pos[r][c] == this) {
                row = r;
                col = c;
                break;
            }
        }
        if (row != -1) {
            break;
        }
    }

    for (int i = 0; i < 4; i++) {
        int rowDiff = (1 - 2 * (i == 3)) * (i > 1);
        int colDiff = (1 - 2 * (i == 0)) * (i < 2);
        int r = row + rowDiff;
        int c = col + colDiff;
        while (r >= 0 && r <= 7 && c >= 0 && c <= 7) {
            if (chessBoard->pos[r][c] && chessBoard->pos[r][c]->getColor() == color) {
                break;
            } else if (chessBoard->pos[r][c]) {
                std::string new_move;
                new_move.push_back(c + 97);
                new_move.push_back(56 - r);
                moves->push_back(new_move);
                break;
            }
            std::string new_move;
            new_move.push_back(c + 97);
            new_move.push_back(56 - r);
            moves->push_back(new_move);
            r += rowDiff;
            c += colDiff;
        }
    }

    for (int i = 0; i < moves->size(); i++) {
        std::string move = moves->at(i);
        Piece* temp = chessBoard->pos[56 - move[1]][move[0] - 97];
        chessBoard->pos[56 - move[1]][move[0] - 97] = this;
        chessBoard->pos[row][col] = nullptr;
        if (chessBoard->isInCheck()) {
            moves->erase(moves->begin() + i);
            i--;
        }
        chessBoard->pos[row][col] = this;
        chessBoard->pos[56 - move[1]][move[0] - 97] = temp;
    }

    std::string start;
    start.push_back(col + 97);
    start.push_back(56 - row);
    for (int i = 0; i < moves->size(); i++) {
        moves->at(i) = start + moves->at(i);
    }

    return moves;
}

Queen::Queen(Board* b, char c, const std::string& l) : Piece(b, c, l) {}

std::vector<std::string>* Queen::getLegalMoves() {
    int row = -1;
    int col = -1;
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (chessBoard->pos[r][c] == this) {
                row = r;
                col = c;
                break;
            }
        }
        if (row != -1) {
            break;
        }
    }
    
    Piece* queen = chessBoard->pos[row][col];
    Piece* bishop = new Bishop(chessBoard, color, color == 'w' ? "B" : "b");
    Piece* rook = new Rook(chessBoard, color, color == 'w' ? "R" : "r");
    chessBoard->pos[row][col] = bishop;
    std::vector<std::string>* moves = bishop->getLegalMoves();
    delete bishop;
    chessBoard->pos[row][col] = rook;
    std::vector<std::string>* rook_moves = rook->getLegalMoves();
    delete rook;
    for (int i = 0; i < rook_moves->size(); i++) {
        moves->push_back(rook_moves->at(i));
    }
    delete rook_moves;
    chessBoard->pos[row][col] = queen;

    return moves;
}

King::King(Board* b, char c, const std::string& l) : Piece(b, c, l) {}

std::vector<std::string>* King::getLegalMoves() {
    return new std::vector<std::string>();
}
