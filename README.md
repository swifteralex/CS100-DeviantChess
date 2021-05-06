  
# Deviant Chess
 
 Authors: [Nathan Kong](https://github/NateGaNe),
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
    * Singleton Design Pattern
        * We will be using Singleton as the main design pattern for this project. Since we are creating a chess game, we will only create a single instance of a chess board and have other components such as chess pieces using that single instance. 
	      This way, our single instance makes sure no other instances of the chess board arises especially when we do not need it and configuration of the single instance is more clear.
    * Strategy Pattern 
        * We will be using the Strategy pattern for our chess AI's. We will be developing several different types of AI's (various Stockfish levels to go against and a bot that only makes random moves) and to organize these different engines we will make an interface ChessAI that captures common functionality between the engines.
          This design pattern solves the problem of updating a class whenever a new engine is designed or updated or removed. We believe this design pattern will lead to a good solution since the Strategy pattern very nicely groups all the chess engines into a single ChessAI interface that other classes can use.
 
  ## Phase II
  In addition to completing the "Class Diagram" section below, you will need to 
  * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
    * Backlog, TODO, In progress, In testing, Done
    * You can change these or add more if you'd like, but we should be able to identify at least these.
  * There is no requirement for automation in the project board but feel free to explore those options.
  * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
  * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
    * Create smaller development tasks as issues and assign them to team members. Place these in the `TODO` column.
    * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
    * 
  ## Class Diagram
  ![diagram](https://i.imgur.com/I4ay8aV.png)
  This diagram shows both of our design patterns. Within the Board class, we have used the Singleton pattern to make sure only one instance of a Board() object gets allocated at a time. This is accomplished by using a private constructor that is only called when variable instance is nullptr. Our other design pattern is the Strategy pattern; we have created an abstract class AIStrategy that other classes can inherit from. These inherited classes have to implement the getBestMove() function. The Board class contains a reference to an AIStrategy object so that it can generate a computer move independent of the engine being used.
  
  The Board class contains data for the position of the board -- a 8x8 2d array of chars representing the pieces ('n' = knight, 'p' = pawn, etc.), 2 chars representing castling rights for each player (0 = no castling, 1 = O-O only, 2 = O-O-O only, 3 = both), and an en-passant square if the last move was a pawn going two squares (0 if not). The class also contains a generateFEN() function that will be used by the engines. The function playMove() will take in a string representing a move (ex. "a1 c2" would move a knight from square a1 to c2 if possible), returning false if the move isn't legal. The Board constructor should set up the pieces in their starting positions among other actions.
  
  The engines would be instantiated by the setStrategy(AIStrategy*) method of the Board class. We'll use the convention that a nullptr strategy will mean that the game is between two human players and not a player and an engine.
 
  ## Phase III
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
  * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
  Screenshots of the input/output after running your application
 ## Installation/Usage
  Instructions on installing and running your application
 ## Testing
  How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
