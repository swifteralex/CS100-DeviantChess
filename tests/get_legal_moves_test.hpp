#ifndef _GET_LEGAL_MOVES_TEST_H_
#define _GET_LEGAL_MOVES_TEST_H_

#include "gtest/gtest.h"
#include "../Board.h"

TEST(WhitePawnLegalMovesTest, StartingPosition) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("e2");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "e2e3", "e2e4" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackPawnLegalMovesTest, StartingPosition) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("e7");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "e7e6", "e7e5" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhitePawnLegalMovesTest, CanTake) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', '0', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'p', '0', '0', '0' },
        { '0', '0', '0', 'P', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', '0', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("d4");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "d4e5", "d4d5" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackPawnLegalMovesTest, CanTake) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', '0', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'p', '0', '0', '0' },
        { '0', '0', '0', 'P', '0', 'P', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', '0', 'P', '0', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("e5");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "e5d4", "e5f4", "e5e4" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhitePawnLegalMovesTest, OnBoardEdge) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { 'P', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("a6");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "a6b7" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackPawnLegalMovesTest, OnBoardEdge) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', 'P', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', '0', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("a7");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "a7b6", "a7a6", "a7a5" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhitePawnLegalMovesTest, Promotion) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', '0', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'P', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("b7");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "b7a8n", "b7a8b", "b7a8r", "b7a8q", "b7c8n", "b7c8b", "b7c8r", "b7c8q", "b7b8n", "b7b8b", "b7b8r", "b7b8q" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackPawnLegalMovesTest, Promotion) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'p' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', '0' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("h2");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "h2g1n", "h2g1b", "h2g1r", "h2g1q", "h2h1n", "h2h1b", "h2h1r", "h2h1q" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhitePawnLegalMovesTest, OwnPieces) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', 'P', 'P' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("h2");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackPawnLegalMovesTest, OwnPieces) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', 'p', '0', '0', '0', '0', '0' },
        { '0', 'p', 'p', 'p', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("c4");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhitePawnLegalMovesTest, InCheckCanPrevent) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'r', '0', '0', '0' },
        { '0', '0', '0', '0', '0', 'P', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', '0', '0', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("f4");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "f4e5" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackPawnLegalMovesTest, InCheckCanPrevent) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', '0', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'k', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', 'Q', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("c7");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "c7c5" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhitePawnLegalMovesTest, InCheckNoMoves) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'r', '0', '0', '0' },
        { '0', '0', '0', '0', '0', 'P', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', '0', '0', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("a2");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackPawnLegalMovesTest, InCheckNoMoves) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', '0', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'k', 'p', 'p', 'p' },
        { 'P', '0', 'P', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', 'Q', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("b7");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhitePawnLegalMovesTest, EnPassant) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', '0', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'P', 'p', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', '0', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    board.enPassantSquare = "e6";
    Piece* p = board.getPieceAt("d5");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "d5e6", "d5d6" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackPawnLegalMovesTest, EnPassant) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'p', '0', '0', '0', '0', '0', '0' },
        { '0', '0', 'P', '0', '0', '0', '0', '0' },
        { '0', 'P', '0', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    board.enPassantSquare = "a3";
    Piece* p = board.getPieceAt("b4");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "b4a3", "b4c3", "b4b3" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteKnightLegalMovesTest, StartingPosition) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("b1");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "b1a3", "b1c3" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackKnightLegalMovesTest, StartingPosition) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("g8");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "g8f6", "g8h6" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteKnightLegalMovesTest, MiddleOfBoard) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', 'N', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("c6");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "c6b8", "c6d8", "c6a7", "c6e7", "c6a5", "c6e5", "c6b4", "c6d4" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackKnightLegalMovesTest, MiddleOfBoard) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'n', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("d4");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "d4c6", "d4e6", "d4b5", "d4f5", "d4b3", "d4f3", "d4c2", "d4e2" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteKnightLegalMovesTest, NoMoves) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', 'P', '0', 'P' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("g1");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackKnightLegalMovesTest, NoMoves) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { 'p', '0', '0', '0', 'p', '0', '0', '0' },
        { '0', '0', 'n', '0', '0', '0', '0', '0' },
        { 'p', '0', '0', '0', 'p', '0', '0', '0' },
        { '0', 'p', '0', 'p', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("c5");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteKnightLegalMovesTest, InCheckCanPrevent) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'N', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'n', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("d4");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "d4c2" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackKnightLegalMovesTest, InCheckCanPrevent) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', '0', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'Q', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("g8");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "g8e7" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteKnightLegalMovesTest, InCheckNoMoves) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'r', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', '0', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("b1");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackKnightLegalMovesTest, InCheckNoMoves) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', 'N', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("g8");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteBishopLegalMovesTest, EmptyPosition) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { '0', '0', '0', '0', 'k', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'B', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'K', '0', '0', '0' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("e4");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "e4f3", "e4g2", "e4h1", "e4d3", "e4c2", "e4b1", "e4f5", "e4g6", "e4h7", "e4d5", "e4c6", "e4b7", "e4a8" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackBishopLegalMovesTest, EmptyPosition) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { '0', '0', '0', '0', 'k', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', 'b', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'K', '0', '0', '0' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("b6");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "b6c5", "b6d4", "b6e3", "b6f2", "b6g1", "b6a5", "b6c7", "b6d8", "b6a7" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteBishopLegalMovesTest, PartiallyBlocked) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'p', '0', '0', '0' },
        { 'P', 'P', 'P', '0', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("c1");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "c1d2", "c1e3" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackBishopLegalMovesTest, PartiallyBlocked) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', 'p', '0', 'p', '0', '0' },
        { '0', '0', '0', '0', 'b', '0', '0', '0' },
        { '0', '0', '0', '0', '0', 'N', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("e5");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "e5f4", "e5d4", "e5c3", "e5b2" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteBishopLegalMovesTest, NoMoves) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("f1");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackBishopLegalMovesTest, NoMoves) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { 'p', 'p', '0', 'p', '0', '0', '0', '0' },
        { '0', '0', 'b', '0', '0', '0', '0', '0' },
        { 'p', 'p', '0', 'p', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("c5");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteBishopLegalMovesTest, InCheckCanPrevent) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { 'B', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'n', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("a6");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "a6d3" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackBishopLegalMovesTest, InCheckCanPrevent) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', '0', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', 'b', '0', '0' },
        { '0', '0', '0', '0', 'Q', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("f4");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "f4e3", "f4e5" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteBishopLegalMovesTest, InCheckNoMoves) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'r', '0', '0', '0' },
        { '0', '0', '0', '0', '0', 'p', '0', '0' },
        { '0', '0', '0', '0', '0', '0', 'B', '0' },
        { 'P', 'P', 'P', 'P', '0', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("g3");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackBishopLegalMovesTest, PinnedNoMoves) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', '0', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'b', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'R', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("e5");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteRookLegalMovesTest, EmptyPosition) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { '0', '0', '0', '0', 'k', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', 'R', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'K', '0', '0', '0' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("g5");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "g5f5", "g5e5", "g5d5", "g5c5", "g5b5", "g5a5", "g5h5", "g5g4", "g5g3", "g5g2", "g5g1", "g5g6", "g5g7", "g5g8" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackRookLegalMovesTest, EmptyPosition) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { '0', '0', '0', '0', 'k', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', 'r', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'K', '0', '0', '0' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("c4");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "c4b4", "c4a4", "c4d4", "c4e4", "c4f4", "c4g4", "c4h4", "c4c3", "c4c2", "c4c1", "c4c5", "c4c6", "c4c7", "c4c8" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteRookLegalMovesTest, PartiallyBlocked) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'p', 'R', '0', 'R', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("e5");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "e5d5", "e5f5", "e5e4", "e5e3", "e5e6", "e5e7" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackRookLegalMovesTest, PartiallyBlocked) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'r', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', 'P', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("c7");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "c7c6", "c7c5" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteRookLegalMovesTest, Pinned) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'r', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'R', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', '0', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("e3");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "e3e2", "e3e4", "e3e5", "e3e6", "e3e7" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackRookLegalMovesTest, Pinned) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', '0', 'k', 'b', 'n', 'r' },
        { 'p', 'p', '0', 'r', '0', '0', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'B', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("d7");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteRookLegalMovesTest, InCheckCanPrevent) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'R', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', 'P', 'P', 'P' },
        { '0', 'r', '0', '0', '0', '0', 'K', '0' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("d5");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "d5d1" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackRookLegalMovesTest, InCheckCanPrevent) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', '0', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', 'Q', 'r', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("c5");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "c5b5", "c5c6" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteQueenLegalMovesTest, EmptyPosition) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { '0', '0', '0', '0', 'k', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', 'Q', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'K', '0', '0', '0' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("c4");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "c4d3", "c4e2", "c4f1", "c4b3", "c4a2", "c4d5", "c4e6", "c4f7", "c4g8", "c4b5", "c4a6", "c4b4", "c4a4", "c4d4", "c4e4", "c4f4", "c4g4", "c4h4", "c4c3", "c4c2", "c4c1", "c4c5", "c4c6", "c4c7", "c4c8" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackQueenLegalMovesTest, EmptyPosition) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { '0', '0', '0', '0', 'k', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', 'q' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'K', '0', '0', '0' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("h7");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "h7g6", "h7f5", "h7e4", "h7d3", "h7c2", "h7b1", "h7g8", "h7g7", "h7f7", "h7e7", "h7d7", "h7c7", "h7b7", "h7a7", "h7h6", "h7h5", "h7h4", "h7h3", "h7h2", "h7h1", "h7h8" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteQueenLegalMovesTest, PartiallyBlocked) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', '0', 'p', 'p' },
        { '0', '0', '0', '0', '0', 'p', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'P', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', '0', '0', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("d1");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "d1e2", "d1f3", "d1g4", "d1h5", "d1d2", "d1d3", "d1d4", "d1d5", "d1d6", "d1d7" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackQueenLegalMovesTest, PartiallyBlocked) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'p', '0', '0', '0', '0' },
        { 'P', '0', '0', '0', '0', '0', '0', '0' },
        { '0', 'q', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("b3");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "b3c2", "b3a2", "b3c4", "b3a4", "b3a3", "b3c3", "b3d3", "b3e3", "b3f3", "b3g3", "b3h3", "b3b2", "b3b4", "b3b5", "b3b6" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteQueenLegalMovesTest, Pinned) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', '0', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'q', 'p', 'p', 'p' },
        { '0', '0', '0', '0', 'Q', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', '0', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("e6");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "e6e5", "e6e4", "e6e3", "e6e2", "e6e7" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackQueenLegalMovesTest, Pinned) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', '0', 'k', 'b', 'n', 'r' },
        { 'p', 'p', '0', 'q', '0', '0', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'B', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("d7");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "d7c6", "d7b5", "d7a4" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteQueenLegalMovesTest, InCheckCanPrevent) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'Q', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', 'P', 'P', 'P' },
        { '0', 'r', '0', '0', '0', '0', 'K', '0' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("d3");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "d3f1", "d3b1", "d3d1" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackQueenLegalMovesTest, InCheckCanPrevent) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', '0', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', 'Q', '0', 'q', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("d5");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "d5c6", "d5b5", "d5d7" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteKingLegalMovesTest, CanCastleBothSides) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', 'Q', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', '0', '0', '0', 'P', 'P' },
        { 'R', '0', '0', '0', 'K', '0', '0', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("e1");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "e1d2", "e1e2", "e1f2", "e1d1", "e1f1", "e1g1", "e1c1" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackKingLegalMovesTest, CanCastleBothSides) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', '0', '0', '0', 'k', '0', '0', 'r' },
        { 'p', 'p', 'p', '0', '0', '0', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("e8");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "e8d8", "e8f8", "e8d7", "e8e7", "e8f7", "e8g8", "e8c8" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteKingLegalMovesTest, InCheck) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', 'r', '0', '0', '0' },
        { '0', 'Q', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', '0', '0', '0', 'P', 'P' },
        { 'R', '0', '0', '0', 'K', '0', '0', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("e1");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "e1d2", "e1f2", "e1d1", "e1f1" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackKingLegalMovesTest, InCheck) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', '0', '0', '0', 'k', '0', '0', 'r' },
        { 'p', 'p', 'p', '0', '0', '0', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'Q', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("e8");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "e8d8", "e8f8", "e8d7", "e8f7" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteKingLegalMovesTest, CastlingBlockedByEnemy) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', 'Q', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'q', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', '0', '0', '0', 'P', 'P' },
        { 'R', '0', '0', '0', 'K', '0', '0', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("e1");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "e1e2", "e1f1" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackKingLegalMovesTest, CastlingBlockedByEnemy) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', '0', '0', '0', 'k', '0', '0', 'r' },
        { 'p', 'p', 'p', '0', '0', '0', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'R', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("e8");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "e8f8", "e8e7", "e8f7", "e8g8" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteKingLegalMovesTest, CastlingBlockedByPiece) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', '0', '0', '0', 'P', 'P' },
        { 'R', '0', '0', 'Q', 'K', '0', 'b', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("e1");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "e1d2", "e1e2", "e1f1" };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackKingLegalMovesTest, CastlingBlockedByPiece) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', '0', 'q', '0', 'k', 'N', '0', 'r' },
        { 'p', 'p', 'p', '0', '0', '0', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("e8");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { "e8d8", "e8f8", "e8e7", "e8f7" };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteKingLegalMovesTest, CantMoveIntoCheck) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', '0', 'p', 'p', 'p' },
        { '0', '0', '0', '0', 'p', '0', '0', '0' },
        { '0', '0', '0', '0', 'K', '0', '0', '0' },
        { '0', '0', '0', 'P', 'P', '0', '0', '0' },
        { '0', '0', '0', '0', '0', 'r', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', '0', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("e5");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackKingLegalMovesTest, CantMoveIntoCheck) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', '0', 'q', '0', 'k', '0', '0', 'r' },
        { 'p', 'p', 'p', '0', '0', '0', 'p', 'p' },
        { '0', '0', '0', 'Q', '0', 'K', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', '0', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("e8");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ(moves == expected, true);
}

TEST(WhiteKingLegalMovesTest, CheckMate) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', '0', '0', '0', 'K', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'k', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' }
    };
    board.setPosition(pos);
    board.setColor('w');
    Piece* p = board.getPieceAt("e8");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ(moves == expected, true);
}

TEST(BlackKingLegalMovesTest, CheckMate) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', '0', '0', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', 'p', 'Q' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'P', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', '0', 'P', 'P', 'P' },
        { 'R', 'N', 'B', '0', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    Piece* p = board.getPieceAt("e8");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ(moves == expected, true);
}

TEST(mytest, mtest){
    std::vector<std::vector<char>> pos = {
        { '0', '0', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'P', 'p', 'p', 'p', 'p', '0', '0', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', 'p', 'Q' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { '0', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    Board board;
    board.setPosition(pos);
    Piece* p = board.getPieceAt("a7");
    std::vector<std::string> moves = p->getLegalMoves();
    std::vector<std::string> ans = { "a7a8r"};
    EXPECT_EQ(moves == ans, true);
}

#endif