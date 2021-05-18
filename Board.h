#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include<string>
#include <iostream>

#include <sstream>


Class Board: public ChessObject{
	private:
		// 8x8 array of chars that represent the pieces on the board from white's perspective.
		// 0 = empty square, 'N' = white knight, 'p' = black pawn, etc.
		std::vector<std::vector<ChessObject*>> pos = {
        { new Rook(instance, 'r', 'b'), new Knight(instance, 'n', 'b'), new Bishop(instance, 'b', 'b'), new Queen(instance,'q', 'b'), new King(instance, 'k', 'b'), new Bishop(instance, 'b', 'b'), new Knight(instance, 'n', 'b', new Rook(instance, 'r', 'b'  },
        { new Pawn(instance, 'p', 'b'), new Pawn(instance, 'p', 'b'), new Pawn(instance, 'p', 'b'), new Pawn(instance, 'p', 'b'), new Pawn(instance, 'p', 'b'), new Pawn(instance, 'p', 'b'), new Pawn(instance, 'p', 'b'), new Pawn(instance, 'p', 'b') },
        {  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  },
        {  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  },
        {  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  },
        {  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  },
        { new Pawn(instance, 'P', 'w'), new Pawn(instance, 'P', 'w'), new Pawn(instance, 'P', 'w'), new Pawn(instance, 'P', 'w'), new Pawn(instance, 'P', 'w'), new Pawn(instance, 'P', 'w'), new Pawn(instance, 'P', 'w'), new Pawn(instance, 'P', 'w') },
        { new Rook(instance, 'R', 'w'), new Knight(instance, 'N', 'w'), new Bishop(instance, 'B', 'w'), new Queen(instance,'Q', 'w'), new King(instance, 'K', 'w'), new Bishop(instance, 'B', 'w'), new Knight(instance, 'N', 'w', new Rook(instance, 'R', 'w' }
    	};
		// This MUST be set to nullptr outside of the class before any code is run; setting to
		// nullptr here is a compiler error.
		static Board* instance;

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

		// 'w' = next move will be played by white, 'b' = next move by black
		char currentTurn = 'w';
    		vector<int> findVPos(string &pos);
    		Board() {};
	public:
		void setPosition(const std::vector<std::vector<ChessObject*>>&);

		// Returns true if the current player is in check
		bool isInCheck() const;

    		// Returns a pointer to the only Board object.
    		static Board* getInstance();

    		// void setStrategy(AIStrategy*)

   	   	// Used by Stockfish to get the current position.
   	   	std::string generateFEN() const;
		
		Piece getPieceAt(string &position);
   		void printBoard() const;
};
