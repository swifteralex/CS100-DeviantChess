#include "Board.h"
#include "AIStrategy.h"
#include <iostream>
#include <cctype>
using namespace std;
int main() {
   	Board board;
	char userInput;
	char secondInput;
	bool playAgain = true;
	while (playAgain) {
		cout << "Enter 1 to play against a player, 2 to play against Stockfish (Chess Engine), or 3 to play against a bot with random moves." << endl;
		cin >> userInput;
		while (userInput != '1' && userInput != '2' && userInput != '3' || !isdigit(userInput)) {
			cout << "Invalid input, try again." << endl;
			cin >> userInput;
		}
		
		if (userInput == '1') {
   			 while (!board.isCheckmated() && !board.isStalemated()) {
        			string userMove1 = "";
        			string userMove2 = "";
        			board.printBoard();
        			cout << "Enter the location of the piece you want to move." << endl;
        			cin >> userMove1;
        			cout << "Enter the location of where you want to move." << endl;
        			cin >> userMove2;
				board.setColor('w');
        			while(!(board.updateBoard(userMove1, userMove2))) {
					cout << "Invalid move, input move again." << endl;
		                        userMove1 = "";
                		        userMove2 = "";
                               		board.printBoard();
                  			cout << "Enter the location of the piece you want to move." << endl;
                   			cin >> userMove1;
                                	cout << "Enter the location of where you want to move." << endl;
                                	cin >> userMove2;
	
				}
                                userMove1 = "";
                                userMove2 = "";
                                board.printBoard();

				if (board.isCheckmated() || board.isStalemated()) {
					break;
				}

                                cout << "Enter the location of the piece you want to move." << endl;
                                cin >> userMove1;
                                cout << "Enter the location of where you want to move." << endl;
                                cin >> userMove2;
				board.setColor('b');
				while (!(board.updateBoard(userMove1, userMove2))) {
					cout << "Invalid move, input move again." << endl;
					userMove1 = "";
					userMove2 = "";
					board.printBoard();
					cout << "Enter the location of the piece you want to move." << endl;
					cin >> userMove1;
					cout << "Enter the location of where you want to move." << endl;
					cin >> userMove2;
				}
    			}
		}

		else if (userInput == '2') {
			int stockfishLevel;
			cout << "Which stockfish level would you like to play? (0 - 20)" << endl;
			cin >> stockfishLevel;
			string a = to_string(stockfishLevel);
			while(!isdigit(a[0])){
				cout << "Invalid level input. Try again." << endl;
				cin >> stockfishLevel;
			}	
			AIStrategy* AI = new Stockfish(&board, stockfishLevel);
			board.setStrategy(AI);
			board.setColor('w');
			while (!board.isCheckmated() && board.isStalemated()){
				string userMove1 = "";
				string userMove2 = "";
				board.printBoard();
				cout << "Enter the location of the piece you want to move." << endl;
				cin >> userMove1;
				cout << "Enter the location of where you want to move." << endl;
				cin >> userMove2;
				while (!(board.updateBoard(userMove1,userMove2))) {
					userMove1 = "";
                                	userMove2 = "";
                                	board.printBoard();
                                	cout << "Enter the location of the piece you want to move." << endl;
                                	cin >> userMove1;
                                	cout << "Enter the location of where you want to move." << endl;
                                	cin >> userMove2;
				}
			board.setColor('b');
			board.playEngineMove();
			}
			delete AI;
		}
	    else if (userInput == '3') {
		AIStrategy* AI = new Random(&board);
		board.setStrategy(AI);
                board.setColor('w');
                while (!board.isCheckmated() && board.isStalemated()){
                	string userMove1 = "";
                       	string userMove2 = "";
                      	board.printBoard();
                        cout << "Enter the location of the piece you want to move." << endl;
                        cin >> userMove1;
                    	cout << "Enter the location of where you want to move." << endl;
                        cin >> userMove2;
                        while (!(board.updateBoard(userMove1,userMove2))) {
                        	userMove1 = "";
                        	userMove2 = "";
                              	board.printBoard();
                              	cout << "Enter the location of the piece you want to move." << endl;
                           	cin >> userMove1;
                           	cout << "Enter the location of where you want to move." << endl;
                           	cin >> userMove2;
			}
		board.setColor('b');
		string output = "";
		string firstOutput = "";
		string secondOutput = "";
		output = AI->getBestMove();
		firstOutput = output.substr(0,2);
		secondOutput = output.substr(2,2);
		if (!(board.updateBoard(firstOutput,secondOutput))){
			cout << "Error! Random bot output invalid move." << endl;
			return 1;
			}
		}	
	delete AI;
	}

		else {
			cout << "Error with userInput" << endl;
			return 1;
		}

		cout << "Good game! Do you want to play again? Enter 1 to play again or 2 to quit." << endl;   
		cin >> secondInput;
		while (secondInput != '1' && secondInput != '2' || !isdigit(secondInput)) {
			cout << "Invalid input, try again." << endl;
			cin >> secondInput;
       		}
		if (secondInput == '1'){
			playAgain = true;
		}
		else if (secondInput == '2') {
			playAgain = false;
			cout << "Goodbye!" << endl;
		}
		else {
			cout << "Error with secondInput" << endl;
			return 1;
		}
	}
    return 0;
}
