#include "Board.h"

int main() {
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
    // board.updateBoard("a4", "b5");
    // EXPECT_EQ(board.printBoard(), ans);
    if(board.updateBoard("a4", "b5")){
        std::cout << board.printBoard();
    }
    else{
	std::cout << "fail"<< std::endl;
    }
    
    return 0;
}
