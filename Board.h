#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include<string>
#include <iostream>
#include "Piece.h"
#include "ChessObject.h"
#include <sstream>


class Board: public ChessObject{
	protected:
		// 8x8 array of chars that represent the pieces on the board from white's perspective.
		// 0 = empty square, 'N' = white knight, 'p' = black pawn, etc.
		std::vector<std::vector<Piece*>> pos;
		// This MUST be set to nullptr outside of the class before any code is run; setting to
		// nullptr here is a compiler error.
		//static Board* instance;
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
		void swap(std::vector<int> pos1, std::vector<int> pos2);
		// 'w' = next move will be played by white, 'b' = next move by black
		char currentTurn = 'w';
    		std::vector<int> findVPos(std::string &pos);
    		//Board() {};
	public:
		Board();
		~Board();

		// void setPosition(const std::vector<std::vector<ChessObject*>>&);
		void setPosition(const std::vector<std::vector<char>>&);

		// Returns true if the current player is in check
		bool isInCheck() const;

    		// Returns a pointer to the only Board object.
    		// static Board* getInstance();

    		// void setStrategy(AIStrategy*)

   	   	// Used by Stockfish to get the current position.
   	   	std::string generateFEN() const;
		bool isCheckMated();
		bool isStaleMated();
		Piece* getPieceAt(std::string &position);
		bool updateBoard(std::string& pos1, std::string& pos2c);
   		void printBoard() const;
		char getLabel();
		void setLabel(char l);
};

#endif