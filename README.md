# Game Project 'TRY YOUR LUCK' Brief introduction

A Production of: Tse Tsz Chun & Lam Chun Yin Angus

# Game Introduction

Concept: mixing 'guessing random number' and 'bingo' games

The 'bingo' board will be a 3x3 grid.

A player will need to press 'N' to start the main game. (If the player has already had a game playing beforehand, press 'L' then the saved game will be reloaded.) If the player enters other integers, the player will be asked to re-enter the input to choose the grid size again, while if the player entered Q, the game will end by outputting "Bye Bye, see you next time!". 

Vector to_be_guessed = {'random number between 1-9 for position [0]' , 'random number between 1-9 for position [1]', ... , 'random number between 1-9 for position [8]'} will be initiated. 

Vector out_put = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'} will be initiated.

int Number_of_attempts_allowed per node = a random number of chance will be given (any tries between 2-6);

int Number_of_attempts_left = Number_of_attempts_allowed (will -1 for each attempts tried);

int user_input_for_node;

Game flow:

1. After triggering the game, the player could enter either 'L', 'N' or 'Q'.
'L': Load the previous saved game from Savefile.txt
'N': Start a new game
'Q': Quit the game

2. After entering the command, 
If 'L' is chosen, then function 'load' will be called to load the saved datum into out_put vector.
If 'N' is chosen, new vector of out_put = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'} will be initiated. Meanwhile a set of 'correct answer' is randomly generated and stored in the vector 'to_be_guessed'.

3. The current status of game will be displayed. The characters 'A'-'I' are used for locating each node in the grid, while 'X' and 'O' are used for determining whether the player is able to guess the correct answer at a certain node within the randomly generated maximum number of guesses allowed (i.e., int i in run.cpp).

4. Assume 'A' is chosen. The player will be guided to input an interger between 1-9. The amount of trials allowed is clearly stated. A while-loop is run to read the input and return either 'true' or 'false' for the specific node.

5. Then the result is returned to the 'run_guessing_random_number_game' funtion in main.cpp, where there's another while-loop for looping through all the nodes. After all, the result of whether there is bingo will be displayed.

6. The game is named "Try your luck" because it involves 2 levels of luck tester. The first level is the 'guessing random number' sub-game in each node of the bingo board. The second level is the 'bingo' main game.

# Code Requirements

How it satisfies the code requirements

Code requirement 1: Generation of random game sets or events

When the player entered the game, they have to guess the correct number. In total there are 2 random events happening. The first one is the generation of random number stored in the vector 'to_be_guessed', where random number between 1-9 is generated as the correct answer for each node. Another random event is the amount of trials allowed (between 2-6 trials) in guesseing the correct number for a specific node.

Code requirement 2: Data structures for storing game status

2 vectors are used in the code of this game project.
We use a vector to store the number to be guessed (the correct answer) for each node in the grid. The vector serves as a constant vector and is refreshed every main game. Meanwhile, we set up another vector for storing the content of the bingo board. The content is printed using a for-loop nested inside a bigger for-loop. Also, we use loops to read player's input and "wash it away" while looping happens, including 'user_input_for_node' in run.cpp and 'node_input' in main.cpp.

Code requirement 3: Dynamic memory management

To check whether the user input is the same with the corresponding to_be_guessed[corresponding node location ('A' = 0; 'B' = 1; ... ; 'I' = 8)], the input will be stored as 'user_input_for_node'. The loop will be run until the player has the right guess. If they have the right guess, integer '1' will be returned and converted into character "O". If after running the loop, they still haven't had the right guess, integer '0' will be returned and converted into character "X". Then, the 'out_put' vector will be refreshed and printed for deciding whether or not the bingo is achieved eventually.

Code requirement 4: File input/output (e.g. for loading/saving game status)

After the player has successfully or unsucessfully guessed a number, the character displaying the node location will be changed to a "O" or "X" on the bingo board. If the player has already had a game playing beforehand, press 'L', and the saved game will be reloaded from 'Savefile.txt' (only support .txt)

Code requirement 5: Program codes in multiple files

Basically there are 2 .cpp files, one is the 'main.cpp' while the other is 'run.cpp'. In 'main.cpp', there are multiple functions including 'run_guessing_random_number_game', 'save' and 'load'. These functions will perform their tasks in the main function. 'run.cpp' is for deciding whether or not the specific node has the correct guess, and the 'run.cpp' file will return either integer '1' or '0'. It consists of a 'run' funtion which is affiliated under the 'run_guessing_random_number_game'. A header file is also created for triggering the function.

# Remarks

This project is the group project of COMP2113/ENGG1340 course

Group No.: 134
