#include "AIStrategy.h"
#include <random>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <string.h>

AIStrategy::AIStrategy(Board* b) : board(b) {}

Stockfish::Stockfish(Board* b, int level) : AIStrategy(b) {
    this->level = level;
    if (this->level < 0) {
        this->level = 0;
    } else if (this->level > 20) {
        this->level = 20;
    }
}

std::string Stockfish::getBestMove() {
    FILE* in = NULL;
    FILE* out = NULL;
    char* line = NULL;
    size_t size = 0;
    int to_child[2] = { -1, -1 };
    int to_parent[2] = { -1, -1 };

    // set up pipes for communicating with Stockfish
    pipe(to_child);
    pipe(to_parent);
    if (fork() == 0) {
        dup2(to_child[0], STDIN_FILENO);
        dup2(to_parent[1], STDOUT_FILENO);
        execlp("./Stockfish/src/stockfish", "./Stockfish/src/stockfish", NULL);
    }
    in = fdopen(to_parent[0], "r");
    out = fdopen(to_child[1], "w");
    setvbuf(out, NULL, _IONBF, BUFSIZ);

    // input position into Stockfish, tell it to go, and retrieve the best move
    getline(&line, &size, in);
    char str[200];
    strcpy(str, "setoption name Skill Level value ");
    strcat(str, (std::to_string(level)).c_str());
    strcat(str, " \n");
    fprintf(out, str);
    strcpy(str, "position fen ");
    strcat(str, (board->generateFEN()).c_str());
    strcat(str, " \n");
    fprintf(out, str);
    fprintf(out, "go\n");
    while (line[0] != 'b') {
        getline(&line, &size, in);
    }
    std::string ret(line);
    ret = ret.substr(9, 4);

    fprintf(out, "quit\n");
    free(line);
    fclose(in);
    fclose(out);

    return ret;
}

Random::Random(Board* b) : AIStrategy(b) {}

std::string Random::getBestMove() {
    std::vector<std::string> moves;
    for (char r = '1'; r < '9'; r++) {
        for (char c = 'a'; c < 'i'; c++) {
            std::string square;
            square.push_back(c);
            square.push_back(r);
            Piece* piece = board->getPieceAt(square);
            if (piece && piece->getColor() == board->getColor()) {
                std::vector<std::string>* ret = piece->getLegalMoves();
                for (int i = 0; i < ret->size(); i++) {
                    moves.push_back(ret->at(i));
                }
                delete ret;
            }
        }
    }
    srand(time(0));
    int random_move = rand() % moves.size();
    return moves[random_move];
}
