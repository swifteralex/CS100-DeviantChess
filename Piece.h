#ifndef PIECE_H
#define PIECE_H

#include "Board.h"
#include "ChessObject.h"

class Piece : public ChessObject {
  
private:
  std::string pos;
  //Board* chessBoard;
  
public:
  virtual bool playMove(const std::string&) = 0;
  virtual std::vector<std::string>* getLegalMoves() = 0;
};

#endif
