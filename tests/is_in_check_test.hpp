#ifndef _IS_IN_CHECK_TEST_H_
#define _IS_IN_CHECK_TEST_H_

#include "gtest/gtest.h"
#include "../Board.h"

TEST(WhiteInCheckTest, KnightAttackingSmothered) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'n', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    EXPECT_EQ(board.isInCheck(), true);
}

TEST(WhiteInCheckTest, OwnKnightAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'N', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    EXPECT_EQ(board.isInCheck(), false);
}

TEST(WhiteInCheckTest, KnightAttackingCorner) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'n', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', '0', 'B', 'N', 'K' }
    };
    board.setPosition(pos);
    board.setColor('w');
    EXPECT_EQ(board.isInCheck(), true);
}

TEST(BlackInCheckTest, KnightAttackingSmothered) {
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
    EXPECT_EQ(board.isInCheck(), true);
}

TEST(BlackInCheckTest, OwnKnightAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', 'n', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    EXPECT_EQ(board.isInCheck(), false);
}

TEST(WhiteInCheckTest, PawnAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'p', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'K', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', '0', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    EXPECT_EQ(board.isInCheck(), true);
}

TEST(WhiteInCheckTest, OwnPawnAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'P', '0', 'P', '0', '0' },
        { '0', '0', '0', '0', 'K', '0', '0', '0' },
        { '0', '0', '0', 'P', '0', 'P', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', '0', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    EXPECT_EQ(board.isInCheck(), false);
}

TEST(BlackInCheckTest, PawnAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', '0', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'k', '0', '0', '0', '0' },
        { '0', '0', 'P', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    EXPECT_EQ(board.isInCheck(), true);
}

TEST(BlackInCheckTest, OwnPawnAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', '0', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', 'k', '0', '0', '0', '0', '0' },
        { '0', 'p', 'p', 'p', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    EXPECT_EQ(board.isInCheck(), false);
}

TEST(WhiteInCheckTest, PawnAttackingBoardEdge) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'p', '0' },
        { 'R', 'N', 'B', 'Q', '0', 'B', '0', 'K' }
    };
    board.setPosition(pos);
    board.setColor('w');
    EXPECT_EQ(board.isInCheck(), true);
}

TEST(WhiteInCheckTest, BishopAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', 'b', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'K', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', '0', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    EXPECT_EQ(board.isInCheck(), true);
}

TEST(WhiteInCheckTest, BlockedBishopAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', 'b', '0', '0', '0', '0', '0', '0' },
        { '0', '0', 'P', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'K', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', '0', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    EXPECT_EQ(board.isInCheck(), false);
}

TEST(WhiteInCheckTest, OwnBishopAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', 'B' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'K', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', '0', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    EXPECT_EQ(board.isInCheck(), false);
}

TEST(BlackInCheckTest, BishopAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', '0', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', 'B' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    EXPECT_EQ(board.isInCheck(), true);
}

TEST(BlackInCheckTest, BlockedBishopAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'B', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    EXPECT_EQ(board.isInCheck(), false);
}

TEST(BlackInCheckTest, OwnBishopAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'b', 'b', 'b', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    EXPECT_EQ(board.isInCheck(), false);
}

TEST(WhiteInCheckTest, RookAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'r', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', '0', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    EXPECT_EQ(board.isInCheck(), true);
}

TEST(WhiteInCheckTest, BlockedRookAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'r', '0', '0', '0', '0', '0', 'P', 'K' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', '0', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    EXPECT_EQ(board.isInCheck(), false);
}

TEST(WhiteInCheckTest, OwnRookAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'R', 'R', 'R', 'P', 'P' },
        { 'R', 'N', 'B', 'R', 'K', 'R', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    EXPECT_EQ(board.isInCheck(), false);
}

TEST(BlackInCheckTest, RookAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'R', '0', '0', '0', 'k', 'b', 'n', 'r' },
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
    EXPECT_EQ(board.isInCheck(), true);
}

TEST(BlackInCheckTest, BlockedRookAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', '0', 'R' },
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
    EXPECT_EQ(board.isInCheck(), false);
}

TEST(BlackInCheckTest, OwnRookAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'r', 'k', 'r', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'r', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    EXPECT_EQ(board.isInCheck(), false);
}

TEST(WhiteInCheckTest, QueenAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', 'K' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', 'q', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', '0', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    EXPECT_EQ(board.isInCheck(), true);
}

TEST(WhiteInCheckTest, BlockedQueenAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'q', 'q', 'q', 'q', 'k', 'q', 'q', 'q' },
        { 'q', 'q', 'q', 'q', 'q', 'q', 'q', 'q' },
        { 'q', 'q', 'q', '0', '0', '0', 'q', '0' },
        { 'q', 'q', 'q', '0', '0', 'q', '0', '0' },
        { 'q', 'q', 'q', '0', 'q', '0', '0', '0' },
        { 'q', 'q', 'q', 'q', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'K', 'B', 'Q', '0', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    EXPECT_EQ(board.isInCheck(), false);
}

TEST(WhiteInCheckTest, OwnQueenAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', 'Q', 'Q', 'Q', '0', '0' },
        { 'P', 'P', 'P', 'Q', 'Q', 'Q', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'Q', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('w');
    EXPECT_EQ(board.isInCheck(), false);
}

TEST(BlackInCheckTest, QueenAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'Q', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    EXPECT_EQ(board.isInCheck(), true);
}

TEST(BlackInCheckTest, BlockedQueenAttacking) {
    Board board;
    std::vector<std::vector<char>> pos = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', 'Q', '0', 'Q', '0', 'Q', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    board.setPosition(pos);
    board.setColor('b');
    EXPECT_EQ(board.isInCheck(), false);
}

TEST(BlackInCheckTest, OwnQueenAttacking) {
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
    EXPECT_EQ(board.isInCheck(), false);
}

#endif
