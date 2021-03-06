#ifndef PIECE_H
#define PIECE_H

#include "Board.h"
#include "ChessObject.h"

class Board;

class Piece : public ChessObject {
protected:
    bool moved = false;
    std::string pos;
    Board* chessBoard;
  
public:
    Piece(Board*, char, const std::string&);
    bool getMoved(){
        return moved;
    }
    void setMoved(bool m){
        moved = m;
    }
    virtual std::vector<std::string> getLegalMoves() = 0;
};

class Pawn : public Piece {
public:
    Pawn(Board*, char, const std::string&);
    std::vector<std::string> getLegalMoves();
};

class Knight : public Piece {
public:
    Knight(Board*, char, const std::string&);
    std::vector<std::string> getLegalMoves();
};

class Bishop : public Piece {
public:
    Bishop(Board*, char, const std::string&);
    std::vector<std::string> getLegalMoves();
};

class Rook : public Piece {
public:
    Rook(Board*, char, const std::string&);
    std::vector<std::string> getLegalMoves();
};

class Queen : public Piece {
public:
    Queen(Board*, char, const std::string&);
    std::vector<std::string> getLegalMoves();
};

class King : public Piece {
public:
    King(Board*, char, const std::string&);
    std::vector<std::string> getLegalMoves();
};

#endif
