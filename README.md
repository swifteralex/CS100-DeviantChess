  
# Deviant Chess
 
 Authors: [Nathan Kong](https://github.com/NateGaNe),
	[Joseph Chang](https://github.com/DevoTrix),
	[Alexander Coats](https://github.com/swifteralex)


## Project Description
 	* Language:
        * C++
            * Chosen because all three of us are familiar with C++
    * Chess
    * Focus on the base game then deviate with different rules and/or gameplay(create variants such as no castling, etc.)
    * This project is interesting to us as we have never done a project like this before.
    * As children one of the board games that we have been playing for a long time is chess, which is why it is important for us to recreate chess.
    * Technologies
        * We will be using Stockfish, an open source chess engine
    * Input/Output:
        * input is mouse/keyboard
        * output is screen in the console (GUI if we have time.)
    * Composite Design Pattern
        * We will be using the Composite pattern for this project. We intend to use it to create a base class for every object in our chess game, from the board to the pieces, and use a Board class as the composite class in the pattern. This way, we can reference every object in the game with a single ChessObject type. This base class will have a playMove() and a getColor() method, which can be applied to both the game board and the pieces. This pattern will solve the issue of redudant code and will help organize all of the different classes being used.
    * Strategy Pattern 
        * We will be using the Strategy pattern for our chess AI's. We will be developing several different types of AI's (various Stockfish levels to go against and a bot that only makes random moves) and to organize these different engines we will make an interface ChessAI that captures common functionality between the engines. This design pattern solves the problem of updating a class whenever a new engine is designed or updated or removed. We believe this design pattern will lead to a good solution since the Strategy pattern very nicely groups all the chess engines into a single ChessAI interface that other classes can use.
 
 <!-- ## Phase II
  In addition to completing the "Class Diagram" section below, you will need to 
  * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
    * Backlog, TODO, In progress, In testing, Done
    * You can change these or add more if you'd like, but we should be able to identify at least these.
  * There is no requirement for automation in the project board but feel free to explore those options.
  * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
  * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
    * Create smaller development tasks as issues and assign them to team members. Place these in the `TODO` column.
    * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA -->
  ## Class Diagram
  ![diagram](https://i.imgur.com/oCrqYZO.png)
  This diagram shows both of our design patterns. We have used the composite pattern -- the ChessObject class is the component, the Knight, Pawn, Bishop, etc. classes (all derived from a Piece class) are leafs, and the Board class is the composite class. We also used the strategy pattern for our chess ai's, enabling us to reference each ai with one AIStrategy type. Each ChessObject has a color; the Board class' color represents the current turn and the Piece class' color represents the color of the piece.
  
  The Board class contains data for the position of the board -- a 8x8 2d array of Piece*, 1 string representing castling rights for each player ("-" = no castling, "KkQq" = both sides can castle queen and kingside, etc.), and an en-passant square if the last move was a pawn going two squares ("-" if not). The class also contains a generateFEN() function that will be used by the engines. The function playMove(), aided by the isInCheck() and getLegalMoves() functions, will take in a string representing a move (ex. "a1 c2" would move a knight from square a1 to c2 if possible), returning false if the move isn't legal. The Board constructor should set up the pieces in their starting positions among other actions.
 
  <!--## Phase III
  You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
  * Before the meeting you should perform a sprint plan like you did in Phase II
  * In the meeting with your TA you will discuss: 
    - How effective your last sprint was (each member should talk about what they did)
    - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
    - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
    - What tasks you are planning for this next sprint.

  ## Final deliverable
  All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
  Before the demo, you should do the following:
  * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
  * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. -->
 
 ## Screenshots
  <!--Screenshots of the input/output after running your application-->
  ![](https://i.imgur.com/6UWmq09.png)
  ![](https://i.imgur.com/lo0eDcO.png)
  ![](https://i.imgur.com/oPqLcIQ.png)
  ![](https://i.imgur.com/gnRRKx1.png)
  ![](https://i.imgur.com/QA9WUTT.png)
  ![](https://i.imgur.com/82jHgG3.png)
  ![](https://i.imgur.com/bzNksZY.png)
 ## Installation/Usage
  <!--Instructions on installing and running your application --->
To install onto your repository use "git clone --recursive <repoLink>"
To compile the application, after clonging the repository, use the command "cmake3 . && make && (cd Stockfish/src && make build ARCH=x86-64)".  After that, two executables will generate named main and test. The test executable runs all the unit tests together. The main executable runs the application. When running the application, it first prompts you to choose which opponent you want to play against (player, computer, or random bot). If you pick the computer or random bot, you will then be prompted to choose which color you want to play from (white or black). To play moves, you input the location of the piece you want to move, then the location of where you want to move it. The chessboard updates every move so you can see the current position as well as the move the computer has just played if the opponent is a computer. When a stalemate or checkmate is reached, the application asks whether you want to play again, selecting no exits the application while selecting yes restarts the entire process.
 ## Testing
  <!--How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README. --->
We tested our project using google test and unit tests. These files are checkmate_and_stalemate_test.hpp, generate_FEN_test.hpp, get_legal_moves_test.hpp, is_in_check_test.hpp, updateBoardTest.h, and unit_tests.cpp. The checkmate_and_stalemate_test.hpp tests the isCheckmated() and isStalemated() functions, generate_FEN_test.hpp tests the generateFEN() function, get_legal_moves_test.hpp tests all of the piece's getLegalMoves() functions, is_in_check_test.hpp tests the isInCheck() function, and the updateBoardTest.h tests the updateBoard(string,string) function. All of our unit tests pass.
 
