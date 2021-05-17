#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

class Board :public ChessObject{
private: 
    // 8x8 array of chars that represent the pieces on the board from white's perspective.
    // 0 = empty square, 'N' = white knight, 'p' = black pawn, etc.
    std::vector<std::vector<ChessObject*>> pos = {
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

    Board() {};

public:
    void setPosition(const std::vector<std::vector<char>>&);

    // Returns a pointer to a list of legal moves for the current player.
    std::vector<std::string>* getLegalMoves() const;

    // Returns true if the current player is in check.
    bool isInCheck() const;

    // Returns a pointer to the only Board object.
    static Board* getInstance();

    // void setStrategy(AIStrategy*)

    // Used by Stockfish to get the current position.
    std::string generateFEN() const;

    // Attempts to play the provided move, returns false if it's not legal.
    // For example, "e2e4" will attempt to move a piece on square e2 to e4.
    // "e1g1" will attempt to castle kingside for white.
    // "a7a8q" will attempt to promote a pawn on a7 to a queen.
    // Assumes that the argument is in the correct format.
    bool playMove(const std::string&);

    void printBoard() const;
    
    char getColor() const;
    
    void setColor(char);
    
};

#endif
