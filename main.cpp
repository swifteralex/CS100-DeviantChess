#include "Board.h"
#include <iostream>

int main() {
    Board board;
    
    while (!board.isCheckmated() && !board.isStalemated()) {
        string userMove1 = "";
        string userMove2 = "";
        board.printBoard();
        std::cout << "Enter the location of the piece you want to move." << std::endl;
        cin >> userMove1;
        std::cout << "Enter the location of where you want to move." << std::endl;
        cin >> userMove2;
        board.updateBoard(userMove1, userMove2);
    }

    return 0;
}
