#ifndef _UPDATEBOARDTEST_H_
#define _UPDATEBOARDTEST_H_

#include "gtest/gtest.h"
#include "../Board.h"

TEST(pawnTest, pawnMove){
    std::string ans =  "   =====================================\n8  |   r   n   b   q   k   b   n   r   |\n   |                                   |\n7  |   p   p   p   p   p   p   p   p   |\n   |                                   |\n6  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n5  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n4  |   P   0   0   0   0   0   0   0   |\n   |                                   |\n3  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n2  |   0   P   P   P   P   P   P   P   |\n   |                                   |\n1  |   R   N   B   Q   K   B   N   R   |\n   |                                   |\n   =====================================\n       A   B   C   D   E   F   G   H\n";
    Board board;
    board.setColor('w');
    board.updateBoard("a2", "a4");
    EXPECT_EQ(board.printBoard(), ans);
}

TEST(knightTest, knightMove){
    std::string ans =  "   =====================================\n8  |   r   n   b   q   k   b   n   r   |\n   |                                   |\n7  |   p   p   p   p   p   p   p   p   |\n   |                                   |\n6  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n5  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n4  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n3  |   N   0   0   0   0   0   0   0   |\n   |                                   |\n2  |   P   P   P   P   P   P   P   P   |\n   |                                   |\n1  |   R   0   B   Q   K   B   N   R   |\n   |                                   |\n   =====================================\n       A   B   C   D   E   F   G   H\n";
    Board board;
    board.setColor('w');
    board.updateBoard("b1", "a3");
    EXPECT_EQ(board.printBoard(), ans);
}

TEST(rookTest, rookMoveEatsPawn){
    std::string ans =  "   =====================================\n8  |   r   n   b   q   k   b   n   r   |\n   |                                   |\n7  |   R   p   p   p   p   p   p   p   |\n   |                                   |\n6  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n5  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n4  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n3  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n2  |   0   P   P   P   P   P   P   P   |\n   |                                   |\n1  |   0   N   B   Q   K   B   N   R   |\n   |                                   |\n   =====================================\n       A   B   C   D   E   F   G   H\n";
    std::vector<std::vector<char>> sp = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    Board board;
    board.setPosition(sp);
    board.setColor('w');
    board.updateBoard("a1", "a7");
    EXPECT_EQ(board.printBoard(), ans);
}

TEST(bishopTest, bishopMove){
    std::string ans =  "   =====================================\n8  |   r   n   b   q   k   b   n   r   |\n   |                                   |\n7  |   p   p   p   p   p   p   p   p   |\n   |                                   |\n6  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n5  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n4  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n3  |   B   0   0   0   0   0   0   0   |\n   |                                   |\n2  |   P   0   P   P   P   P   P   P   |\n   |                                   |\n1  |   R   N   0   Q   K   B   N   R   |\n   |                                   |\n   =====================================\n       A   B   C   D   E   F   G   H\n";
    std::vector<std::vector<char>> sp = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', '0', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    Board board;
    board.setPosition(sp);
    board.setColor('w');
    board.updateBoard("c1", "a3");
    EXPECT_EQ(board.printBoard(), ans);
}

TEST(queenTest, queenMove){
    std::string ans =  "   =====================================\n8  |   r   n   b   q   k   b   n   r   |\n   |                                   |\n7  |   p   p   p   p   p   p   p   p   |\n   |                                   |\n6  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n5  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n4  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n3  |   0   Q   0   0   0   0   0   0   |\n   |                                   |\n2  |   P   P   0   P   P   P   P   P   |\n   |                                   |\n1  |   R   N   B   0   K   B   N   R   |\n   |                                   |\n   =====================================\n       A   B   C   D   E   F   G   H\n";
    std::vector<std::vector<char>> sp = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', '0', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    Board board;
    board.setPosition(sp);
    board.setColor('w');
    board.updateBoard("d1", "b3");
    EXPECT_EQ(board.printBoard(), ans);
}

TEST(kingTest, kingMove){
    std::string ans = "   =====================================\n8  |   r   n   b   q   k   b   n   r   |\n   |                                   |\n7  |   p   p   p   p   p   p   p   p   |\n   |                                   |\n6  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n5  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n4  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n3  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n2  |   P   P   P   P   P   P   P   P   |\n   |                                   |\n1  |   R   N   B   K   0   B   N   R   |\n   |                                   |\n   =====================================\n       A   B   C   D   E   F   G   H\n";
    std::vector<std::vector<char>> sp = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', '0', 'K', 'B', 'N', 'R' }
    };
    Board board;
    board.setPosition(sp);
    board.setColor('w');
    board.updateBoard("e1", "d1");
    EXPECT_EQ(board.printBoard(), ans);
}

TEST(pawnTest,pawnEatpawn){
    std::string ans =  "   =====================================\n8  |   r   n   b   q   k   b   n   r   |\n   |                                   |\n7  |   p   0   p   p   p   p   p   p   |\n   |                                   |\n6  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n5  |   0   P   0   0   0   0   0   0   |\n   |                                   |\n4  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n3  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n2  |   0   P   P   P   P   P   P   P   |\n   |                                   |\n1  |   R   N   B   Q   K   B   N   R   |\n   |                                   |\n   =====================================\n       A   B   C   D   E   F   G   H\n";
    std::vector<std::vector<char>> sp = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', '0', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', 'p', '0', '0', '0', '0', '0', '0' },
        { 'P', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    Board board;
    board.setPosition(sp);
    board.setColor('w');
    board.updateBoard("a4", "b5");
    EXPECT_EQ(board.printBoard(), ans);
}

TEST(pawnTest, pawnPromo){
    std::string ans ="   =====================================\n8  |   Q   n   b   q   k   b   n   r   |\n   |                                   |\n7  |   0   p   p   p   p   p   p   p   |\n   |                                   |\n6  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n5  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n4  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n3  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n2  |   0   P   P   P   P   P   P   P   |\n   |                                   |\n1  |   R   N   B   0   K   B   N   R   |\n   |                                   |\n   =====================================\n       A   B   C   D   E   F   G   H\n";
    std::vector<std::vector<char>> sp = {
        { '0', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'P', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', '0', 'K', 'B', 'N', 'R' }
    };
    Board board;
    board.setPosition(sp);
    board.setColor('w');
    board.updateBoard("a7", "a8q");
    EXPECT_EQ(board.printBoard(), ans);
}

TEST(castlingTest, castlingQueenSide){
    std::string ans ="   =====================================\n8  |   0   0   k   r   0   b   n   r   |\n   |                                   |\n7  |   p   p   p   p   p   p   p   p   |\n   |                                   |\n6  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n5  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n4  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n3  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n2  |   P   P   P   P   P   P   P   P   |\n   |                                   |\n1  |   R   N   B   Q   K   B   N   R   |\n   |                                   |\n   =====================================\n       A   B   C   D   E   F   G   H\n";
    std::vector<std::vector<char>> sp = {
        { 'r', '0', '0', '0', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    Board board;
    board.setPosition(sp);
    board.setColor('b');
    board.updateBoard("e8", "c8");
    EXPECT_EQ(board.printBoard(), ans);
}

TEST(castlingTest, castlingKingSide){
    std::string ans ="   =====================================\n8  |   r   n   b   q   0   r   k   0   |\n   |                                   |\n7  |   p   p   p   p   p   p   p   p   |\n   |                                   |\n6  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n5  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n4  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n3  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n2  |   P   P   P   P   P   P   P   P   |\n   |                                   |\n1  |   R   N   B   Q   K   B   N   R   |\n   |                                   |\n   =====================================\n       A   B   C   D   E   F   G   H\n";
    std::vector<std::vector<char>> sp = {
        { 'r', 'n', 'b', 'q', 'k', '0', '0', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    Board board;
    board.setPosition(sp);
    board.setColor('b');
    board.updateBoard("e8", "g8");
    EXPECT_EQ(board.printBoard(), ans);
}

TEST(rookTest, rookHorizontal){
    std::string ans ="   =====================================\n8  |   r   n   b   q   k   b   n   r   |\n   |                                   |\n7  |   p   p   p   p   p   p   p   p   |\n   |                                   |\n6  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n5  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n4  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n3  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n2  |   P   P   P   P   K   P   P   P   |\n   |                                   |\n1  |   0   0   0   0   0   0   R   R   |\n   |                                   |\n   =====================================\n       A   B   C   D   E   F   G   H\n";
    std::vector<std::vector<char>> sp = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'K', 'P', 'P', 'P' },
        { 'R', '0', '0', '0', '0', '0', '0', 'R' }
    };
    Board board;
    board.setPosition(sp);
    board.setColor('w');
    board.updateBoard("a1", "g1");
    EXPECT_EQ(board.printBoard(), ans);
}

TEST(queenTest, QueenHorizontalVertical){
    std::string ans ="   =====================================\n8  |   r   n   Q   q   k   b   n   r   |\n   |                                   |\n7  |   p   p   0   p   p   p   p   p   |\n   |                                   |\n6  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n5  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n4  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n3  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n2  |   P   P   0   P   K   P   P   P   |\n   |                                   |\n1  |   0   0   0   0   0   0   0   R   |\n   |                                   |\n   =====================================\n       A   B   C   D   E   F   G   H\n";
    std::vector<std::vector<char>> sp = {
        { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
        { 'p', 'p', '0', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', '0', 'P', 'K', 'P', 'P', 'P' },
        { 'Q', '0', '0', '0', '0', '0', '0', 'R' }
    };
    Board board;
    board.setPosition(sp);
    board.setColor('w');
    board.updateBoard("a1", "c1");
    board.updateBoard("c1", "c8");
    EXPECT_EQ(board.printBoard(), ans);
}

TEST(errorTest,invalidMove){
    Board board;
    board.setColor('w');
    EXPECT_EQ(board.updateBoard("a1","a5") == false, true);
}

TEST(errorTest, wrongColor){
    Board board;
    board.setColor('b');
    EXPECT_EQ(board.updateBoard("a2", "a4") == false, true);
}

TEST(pawnTest, pawnOffSpawn){
    Board board;
    board.setColor('w');
    board.updateBoard("a2", "a4");
    EXPECT_EQ(board.updateBoard("a4","a6"), false);
}
TEST(castlingTest, noCastling){
    std::vector<std::vector<char>> sp = {
        { 'r', 'n', 'b', 'q', 'k', '0', '0', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    Board board;
    board.setCastling("-");
    board.setPosition(sp);
    board.setColor('b');
    // board.updateBoard("e8", "g8");
    EXPECT_EQ(board.updateBoard("e8", "g8"), false);
}

TEST(kingTest, kingNextking){
    Board board;
    std::vector<std::vector<char>> sp = {
        { 'r', 'n', 'b', 'q', '0', '0', '0', 'r' },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', 'k', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', 'K', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', '0', 'B', 'N', 'R' }
    };
    board.setPosition(sp);
    board.setColor('w');
    EXPECT_EQ(board.updateBoard("e4", "e5"), false);
}

TEST(pawnTest, pawnPromotestoInvalidepiece){
    std::vector<std::vector<char>> sp = {
        { '0', 'n', 'b', 'q', 'k', '0', '0', 'r' },
        { 'P', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
        { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
    };
    Board board;
    board.setPosition(sp);
    board.setColor('w');
    EXPECT_EQ(board.updateBoard("a7","a8b"),true);
}
#endif