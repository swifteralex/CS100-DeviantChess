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
        { new Rook(instance, 'r', "black"), new Knight(instance, 'n', "black"), new Bishop(instance, 'b', "black"), new Queen(instance,'q', "queen"), new King(instance, 'k', "black"), new Bishop(instance, 'b', "black"), new Knight(instance, 'n', "black", new Rook(instance, 'r', "black"  },
        { new Pawn(instance, 'p', "black"), new Pawn(instance, 'p', "black"), new Pawn(instance, 'p', "black"), new Pawn(instance, 'p', "black"), new Pawn(instance, 'p', "black"), new Pawn(instance, 'p', "black"), new Pawn(instance, 'p', "black"), new Pawn(instance, 'p', "black") },
        {  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  },
        {  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  },
        {  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  },
        {  nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr,   nullptr  },
        { new Pawn(instance, 'P', "white"), new Pawn(instance, 'P', "white"), new Pawn(instance, 'P', "white"), new Pawn(instance, 'P', "white"), new Pawn(instance, 'P', "white"), new Pawn(instance, 'P', "white"), new Pawn(instance, 'P', "white"), new Pawn(instance, 'P', "white") },
        { new Rook(instance, 'R', "White"), new Knight(instance, 'N', "white"), new Bishop(instance, 'B', "white"), new Queen(instance,'Q', "white"), new King(instance, 'K', "white"), new Bishop(instance, 'B', "white"), new Knight(instance, 'N', "White", new Rook(instance, 'R', "White" }
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
