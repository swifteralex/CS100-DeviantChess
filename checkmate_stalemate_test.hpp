  
#ifndef CHECKMATE_STALEMATE_TEST_H
#define CHECKMATE_STALEMATE_TEST_H

#include "gtest/gtest.h"
#include "../Board.h"

TEST(CheckmateTest, FirstPosition) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'R', '0', '0', '0', '0', '0', 'k', '0' },
        { '0', '0', '0', '0', '0', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'K', '0', '0', '0', '0' }
    };
    board.setPosition(pos);
    board.setColor('b');
    castlingPrivileges = "-";
    EXPECT_EQ(board.isCheckmated(), true);
}


TEST(CheckmateTest, SecondPosition) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', '0', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', '0', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'p', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', 'P', 'q' },
        { '0', '0', '0', '0', '0', 'P', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', '0', '0', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    castlingPrivileges = "-";
    EXPECT_EQ(board.isCheckmated(), true);
}


TEST(CheckmateTest, ThirdPosition) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'R', '0', '0', '0', '0', '0', '0', 'k' },
        { '0', 'R', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', 'K', '0', '0', '0', '0', '0' }
    };
    board.setPosition(pos);
    board.setColor('b');
    castlingPrivileges = "-";
    EXPECT_EQ(board.isCheckmated(), true);
}


TEST(CheckmateTest, FourthPosition) {
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
    castlingPrivileges = "-";
    EXPECT_EQ(board.isCheckmated(), false);
}


TEST(CheckmateTest, FifthPosition) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'k', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', 'Q', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'K', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' }
    };
    board.setPosition(pos);
    board.setColor('w');
    castlingPrivileges = "-";
    EXPECT_EQ(board.isCheckmated(), false);
}

TEST(StalemateTest, FirstPosition) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'k', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', 'Q', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'K', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' }
    };
    board.setPosition(pos);
    board.setColor('b');
    castlingPrivileges = "-";
    EXPECT_EQ(board.isStalemated(), true);
}


TEST(StalemateTest, SecondPosition) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { '0', '0', '0', '0', '0', '0', '0', 'k' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', 'K', 'P' },
        { '0', '0', '0', 'B', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' }
    };
    board.setPosition(pos);
    board.setColor('b');
    castlingPrivileges = "-";
    EXPECT_EQ(board.isStalemated(), true);
}


TEST(StalemateTest, ThirdPosition) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', 'p', '0', 'p', 'p', '0', 'p', '0' },
        { 'p', 'P', 'p', 'r', 'r', 'p', 'P', 'p' },
        { 'K', '0', 'n', 'k', 'q', 'n', '0', 'Q' }
    };
    board.setPosition(pos);
    board.setColor('b');
    castlingPrivileges = "-";
    EXPECT_EQ(board.isStalemated(), true);
}


TEST(StalemateTest, FourthPosition) {
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
    castlingPrivileges = "-";
    EXPECT_EQ(board.isStalemated(), false);
}


TEST(StalemateTest, FifthPosition) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'R', '0', '0', '0', '0', '0', 'k', '0' },
        { '0', '0', '0', '0', '0', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'K', '0', '0', '0', '0' }
    };
    board.setPosition(pos);
    board.setColor('w');
    castlingPrivileges = "-";
    EXPECT_EQ(board.isStalemated(), false);
}

#endif
