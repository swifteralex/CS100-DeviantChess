#ifndef _UPDATEBOARDTEST_H_
#define _UPDATEBOARDTEST_H_

#include "gtest/gtest.h"
#include "../Board.h"

TEST(updateBoardTest, pawnMove){
    std::string ans =  "   =====================================\n8  |   r   n   b   q   k   b   n   r   |\n   |                                   |\n7  |   p   p   p   p   p   p   p   p   |\n   |                                   |\n6  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n5  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n4  |   P   0   0   0   0   0   0   0   |\n   |                                   |\n3  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n2  |   0   P   P   P   P   P   P   P   |\n   |                                   |\n1  |   R   N   B   Q   K   B   N   R   |\n   |                                   |\n   =====================================\n       A   B   C   D   E   F   G   H\n";
    Board board;
    board.setColor('w');
    board.updateBoard("a2", "a4");
    EXPECT_EQ(board.printBoard(), ans);
}

TEST(updateBoardTest, knightMove){
    std::string ans =  "   =====================================\n8  |   r   n   b   q   k   b   n   r   |\n   |                                   |\n7  |   p   p   p   p   p   p   p   p   |\n   |                                   |\n6  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n5  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n4  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n3  |   N   0   0   0   0   0   0   0   |\n   |                                   |\n2  |   P   P   P   P   P   P   P   P   |\n   |                                   |\n1  |   R   0   B   Q   K   B   N   R   |\n   |                                   |\n   =====================================\n       A   B   C   D   E   F   G   H\n";
    Board board;
    board.setColor('w');
    board.updateBoard("b1", "a3");
    EXPECT_EQ(board.printBoard(), ans);
}

TEST(updateBoardTest, rookMoveEatsPawn){
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

TEST(updateBoardTest, bishopMove){
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

TEST(updateBoardTest, queenMove){
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

TEST(updateBoardTest, kingMove){
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

TEST(updateBoardTest,pawnEatpawn){
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

TEST(updateBoardTest, pawnPromo){
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

TEST(updateBoardTest, castlingQueenSide){
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

TEST(updateBoardTest, castlingKingSide){
    std::string ans ="   =====================================\n8  |   r   n   b   q   0   r   k   0   |\n   |                                   |\n7  |   p   p   p   p   p   p   p   p   |\n   |                                   |\n6  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n5  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n4  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n3  |   0   0   0   0   0   0   0   0   |\n   |                                   |\n2  |   P   P   P   P   P   P   P   P   |\n   |                                   |\n1  |   R   N   B   Q   K   B   N   R   |\n   |                                   |\n   =====================================\n       A   B   C   D   E   F   G   H\n";
    std::vector<std::vector<char>> sp = {
        { 'r', 'n', 'b', 'q', 'k', '0', '0', 'r' },
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
    board.setColor('b');
    board.updateBoard("e8", "g8");
    EXPECT_EQ(board.printBoard(), ans);
}
// TEST(updateBoardTest,invalidMove){
//     Board board;
//     board.setColor('w');
//     EXPECT_EQ(board.updateBoard("a1","a5") == false, true);
// }

// TEST(updateBoardTest, wrongColor){
//     Board board;
//     board.setColor('b');
//     EXPECT_EQ(board.updateBoard("a2", "a4") == false, true);
// }

#endif