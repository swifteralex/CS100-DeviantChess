#ifndef PIECE_H
#define PIECE_H

class Piece: public ChessObject {
  
private:
  string pos;
  Board* chessBoard;
  
public:
  bool playMove(string);
  vector<string>* getLegalMoves();
  
  
};
#endif
