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
    std::vector<std::string>* moves = p->getLegalMoves();
    std::vector<std::string> expected = { "e2e3", "e2e4" };
    EXPECT_EQ((*moves) == expected, true);
    delete moves;
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
    std::vector<std::string>* moves = p->getLegalMoves();
    std::vector<std::string> expected = { "e7e6", "e7e5" };
    EXPECT_EQ((*moves) == expected, true);
    delete moves;
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
    std::vector<std::string>* moves = p->getLegalMoves();
    std::vector<std::string> expected = { "d4e5", "d4d5" };
    EXPECT_EQ((*moves) == expected, true);
    delete moves;
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
    std::vector<std::string>* moves = p->getLegalMoves();
    std::vector<std::string> expected = { "e5d4", "e5f4", "e5e4" };
    EXPECT_EQ((*moves) == expected, true);
    delete moves;
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
    std::vector<std::string>* moves = p->getLegalMoves();
    std::vector<std::string> expected = { "a6b7" };
    EXPECT_EQ((*moves) == expected, true);
    delete moves;
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
    std::vector<std::string>* moves = p->getLegalMoves();
    std::vector<std::string> expected = { "a7b6", "a7a6", "a7a5" };
    EXPECT_EQ((*moves) == expected, true);
    delete moves;
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
    std::vector<std::string>* moves = p->getLegalMoves();
    std::vector<std::string> expected = { "b7a8n", "b7a8b", "b7a8r", "b7a8q", "b7c8n", "b7c8b", "b7c8r", "b7c8q", "b7b8n", "b7b8b", "b7b8r", "b7b8q" };
    EXPECT_EQ((*moves) == expected, true);
    delete moves;
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
    std::vector<std::string>* moves = p->getLegalMoves();
    std::vector<std::string> expected = { "h2g1n", "h2g1b", "h2g1r", "h2g1q", "h2h1n", "h2h1b", "h2h1r", "h2h1q" };
    EXPECT_EQ((*moves) == expected, true);
    delete moves;
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
    std::vector<std::string>* moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ((*moves) == expected, true);
    delete moves;
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
    std::vector<std::string>* moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ((*moves) == expected, true);
    delete moves;
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
    std::vector<std::string>* moves = p->getLegalMoves();
    std::vector<std::string> expected = { "f4e5" };
    EXPECT_EQ((*moves) == expected, true);
    delete moves;
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
    std::vector<std::string>* moves = p->getLegalMoves();
    std::vector<std::string> expected = { "c7c5" };
    EXPECT_EQ((*moves) == expected, true);
    delete moves;
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
    std::vector<std::string>* moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ((*moves) == expected, true);
    delete moves;
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
    std::vector<std::string>* moves = p->getLegalMoves();
    std::vector<std::string> expected = { };
    EXPECT_EQ((*moves) == expected, true);
    delete moves;
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
    std::vector<std::string>* moves = p->getLegalMoves();
    std::vector<std::string> expected = { "d5e6", "d5d6" };
    EXPECT_EQ((*moves) == expected, true);
    delete moves;
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
    std::vector<std::string>* moves = p->getLegalMoves();
    std::vector<std::string> expected = { "b4a3", "b4c3", "b4b3" };
    EXPECT_EQ((*moves) == expected, true);
    delete moves;
}

#endif
