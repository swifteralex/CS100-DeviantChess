 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# \<Deviant Chess\>
 > Your author list below should include links to all members GitHub (remove existing author).
 
 > Authors: \<[Nathan Kond](https://github/NateGaNe)\>
	\<[Joseph Chang](https://github.com/DevoTrix)\>
	\<[Alexander Coats](https://github.com/swifteralex)\>


## Project Description
 >	* Language:
 >       * C++
 >           * Chosen because all three of us are familiar with C++
 >   * Chess
 >   * Focus on the base game then deviate with different rules and/or gameplay(create variants such as no castling, etc.)
 >   * This project is interesting to us as we have never done a project like this before.
 >   * As children one of the board games that we have been playing for a long time is chess, which is why it is important for us to recreate chess.
 >   * Input/Output:
 >       * input is mouse/keyboard
 >       * output is screen in the console (GUI if we have time.)
 >   * Composite Design Pattern
 >       * Uses composite design pattern that starts with a base class that is being inheritted. We will have a base class
 >       Piece that all other pieces will inherit from. This will allow us to refer to each piece with a base class pointer,
 >       which will reduce spaghetti code. This way, a user could specify a piece they'd like to move and we could simply call
 >       Piece.move(some location), problems may arise when a piece (such as 2 knights) can move to the same square
 >   * Strategy Pattern 
 >       * Have a separated area where we it would be separated. Uses an algorithm to make a simple chess computer. A Chess game isn't playable without an opponent. Due to the lack of
 >       knowledge on implementing a wide multiplayer game. A computer controlled opponent would be suitable. Problems may arise when designing the chess engine itself Strategy Pattern
 >       would prove to be a good solution rather than random moves by the computer as it would prove to be a bit more challenging to the player.
 
 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
