#include "Board.h"

int main() {
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
    std::vector<std::string> ans = { "a7a8r", "a7a8n", "a7a8b", "a7a8q"};
    // EXPECT_EQ(moves == ans, true);
    for(int i = 0; i < moves.size(); i++){
        std::cout << moves[i] << std::endl;
    }
    return 0;
}
