#ifndef _GENERATE_FEN_TEST_H_
#define _GENERATE_FEN_TEST_H_

#include "gtest/gtest.h"
#include "../Board.h"

TEST(GenerateFENTest, StartingPosition) {
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
    EXPECT_EQ(board.generateFEN(), "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}

TEST(GenerateFENTest, NoPiece) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { '0', '0', '0', '0', 'k', '0', '0', '0' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { '0', '0', '0', '0', 'K', '0', '0', '0' }
    };
    board.setPosition(pos);
    board.setColor('w');
    EXPECT_EQ(board.generateFEN(), "4k3/pppppppp/8/8/8/8/PPPPPPPP/4K3 w KQkq - 0 1");
}

TEST(GenerateFENTest, OnlyKings) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', 'k', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'K', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' }
    };
    board.setPosition(pos);
    board.setColor('b');
    board.castlingPrivileges = "-";
    EXPECT_EQ(board.generateFEN(), "8/8/2k5/8/4K3/8/8/8 b - - 0 1");
}

TEST(GenerateFENTest, ComplicatedMiddleGame) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', '0', '0', '0', 'k', 'b', '0', 'r' },
        { '0', '0', 'q', 'b', '0', 'p', 'p', '0' },
        { 'p', '0', '0', 'p', 'p', 'n', '0', 'p' },
        { '0', '0', '0', '0', 'n', '0', '0', '0' },
        { '0', 'p', '0', 'N', 'P', '0', 'P', '0' },
        { 'P', '0', 'N', '0', 'B', 'P', '0', '0' },
        { '0', 'P', 'P', 'Q', '0', '0', '0', 'P' },
        { '0', '0', 'K', 'R', '0', 'B', 'R', '0' }
    };
    board.setPosition(pos);
    board.setColor('w');
    board.castlingPrivileges = "kq";
    EXPECT_EQ(board.generateFEN(), "r3kb1r/2qb1pp1/p2ppn1p/4n3/1p1NP1P1/P1N1BP2/1PPQ3P/2KR1BR1 w kq - 0 1");
}

#endif
