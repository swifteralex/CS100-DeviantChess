#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "ChessObject.h"
#include "Piece.h"

class Board : public ChessObject {
private:
	// 8x8 array of chars that represent the pieces on the board from white's perspective.
	// 0 = empty square, 'N' = white knight, 'p' = black pawn, etc.
	std::vector<std::vector<Piece*>> pos = {
//        	{ new Rook(this, 'r', 'b'), new Knight(this, 'n', 'b'), new Bishop(this, 'b', 'b'), new Queen(this,'q', 'b'), new King(this, 'k', 'b'), new Bishop(this, 'b', 'b'), new Knight(this, 'n', 'b'), new Rook(this, 'r', 'b')  },
//        	{ new Pawn(this, 'p', 'b'), new Pawn(this, 'p', 'b'), new Pawn(this, 'p', 'b'), new Pawn(this, 'p', 'b'), new Pawn(this, 'p', 'b'), new Pawn(this, 'p', 'b'), new Pawn(this, 'p', 'b'), new Pawn(this, 'p', 'b') },
        	{  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  },
        	{  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  },
        	{  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  },
        	{  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  },
		{  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  },
                {  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  },
                {  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  },
                {  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  }
//        	{ new Pawn(this, 'P', 'w'), new Pawn(this, 'P', 'w'), new Pawn(this, 'P', 'w'), new Pawn(this, 'P', 'w'), new Pawn(this, 'P', 'w'), new Pawn(this, 'P', 'w'), new Pawn(this, 'P', 'w'), new Pawn(this, 'P', 'w') },
//        	{ new Rook(this, 'R', 'w'), new Knight(this, 'N', 'w'), new Bishop(this, 'B', 'w'), new Queen(this,'Q', 'w'), new King(this, 'K', 'w'), new Bishop(this, 'B', 'w'), new Knight(this, 'N', 'w'), new Rook(this, 'R', 'w') }
    	};

	char title = 'C';

	// AIStrategy* strategy;
	
	// Holds data about where each player can castle.
	// KQkq = both players can castle king and queenside.
	// Kkq = white can only castle kingside, and black can castle both sides.
	// "-" = no players can castle.
	std::string castlingPrivileges = "KQkq";

	// If the last move was a pawn moving up two squares, this will be set
	// to the square where that pawn can be captured en-passant.
	// Any other move will set this to "-".
	std::string enPassantSquare = "-";

    	std::vector<int> findVPos(const std::string &pos) const;

public:
	Board();
                
	void setPosition(const std::vector<std::vector<Piece*>>&);

	// Returns true if the current player is in check
	bool isInCheck() const;

    	// void setStrategy(AIStrategy*)

	// Used by Stockfish to get the current position.
	std::string generateFEN() const;
		
	Piece* getPieceAt(const std::string &position) const;

   	void printBoard() const;
};

#endif
