# COMP2113/ENGG1340 Course project brief introduction

Group No.: 134

Group Members: Tse Tsz Chun, Lam Chun Yin Angus

# Game Introduction

Tentative name of the game: 'Try your luck'

Concept: mixing 'guessing random number' and 'bingo' games

The grid of the 'bingo' board will be a 3x3 grid.

A player will need to press 'N' to start the main game. (If the player has already had a game playing beforehand, press 'L' then the saved game will be reloaded.) If the player enters other integers, the player will be asked to re-enter the input to choose the grid size again, while if the player entered Q, the game will end by outputting "Bye Bye, see you next time!". 

Vector to_be_guessed = {'random number between 1-9 for position [0]' , 'random number between 1-9 for position [1]', ... , 'random number between 1-9 for position [8]'} will be initiated. 

Vector out_put = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'} will be initiated.

int Number_of_attempts_allowed per node = a random number of chance will be given (any tries between 2-6);

int Number_of_attempts_left = Number_of_attempts_allowed (will -1 for each attempts tried);

int user_input_for_node;

Flow of the game:

1. After triggering the game, the player could choose either 'L', 'N' or 'Q', which 'L': Load the previous saved game from Savefile.txt; 'N': Start a new game; 'Q': Quit the game;

2. After entering the command, if 'L' is chosen, then will trigger function 'load' to load the saved datum into out_put vector, while of 'N' is chosen, new vector of out_put = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'} will be initiated. Meanwhile a set of 'corrrect answer' are randomly generated and stored in the vector 'to_be_guessed";

3. Then the current status will be print while the char 'A-I' are used for locating and 'X' or 'O' are for determincating whether the player is able to guess the correct answer in the particular node within randomly generated max guessing tries (int i in run.cpp);

4. Assuming 'A' is chosen, the player will be guided to input the interger between 1-9, and a clearly listed amount of trials are stated, a while-loop is then trigger to intake player's input, and return either 'true' or false' for the specific node;

5. Then the result is returned to the 'run_guessing_random_number_game' funtion in main.cpp, where there's another while-loop for looping through all the nodes. After all, the result of whether there is bingo will be outputed to the player;

6. The game is named "Test your luck" because it involves 2 level of luck tester, one is the right or wrong per node, second one is whether bingo is achieved.

# Code Requirements
How it satisfies the code requirements

Code requirement 1: Generation of random game sets or events

When the player entered the game, they have to guess the correct number. In total there are 2 random events happening, the first one is the generation of random number stored in the vector 'to_be_guessed', where random number between 1-9 is generated as the correct answer for each node. Second random event is the amount of trial a player could have in guesseing the correct number for a specific node, which lay between 2-6 trials.

Code requirement 2: Data structures for storing game status

We will ultilise vector for storing the number to be guessed for each box in the grid boxes, which will be refreshed every main game. Meanwhile we will set up another vector for storing the output (bingo board) for sotring the "O" and "X". 2 vectors are ultilise here, one for storing the out out in the form of a bingo board (printed ultilising for-loop in for-loop), while the other serve as a constant in each main game, which stored teh correct answer. Also we use loop to intake player's input and wash away while looping happens, including 'user_input_for_node' in run.cpp and 'node_input' in main.cpp.

Code requirement 3: Dynamic memory management

For checking whether the user input is the same with the corresponding to_be_guessed[corresponding node location ('A' = 0; 'B' = 1; ... ; 'I' = 8], the input will be stored as 'user_input_for_node' and run loop until they have the right guess, if they have the right guess, int 1 will returned and convert into char "O"; or after running the loop, they still haven't have the right guess, int 0 will returned and convert into char "X". then out_put will be refreshed and print and for deciding whether bingo is trggered or achieved eventually.

Code requirement 4: File input/output (e.g. for loading/saving game status)

After the player has successfully or unsucessfully guessed a number, the number will be changed to a "O" or "X" on the bingo board. If the player has already had a game playing beforehand, press 'L' then the saved game will be reloaded from 'Savefile.txt' (only support .txt)

Code requirement 5: Program codes in multiple files

Basically there are 2 .cpp files, one is the main.cpp while the other is run.cpp. In the main.cpp there are multiples function including 'run_guessing_random_number_game', 'save' and 'load', which will perform their task in the main function, which run.cpp is for deciding whether the specific node has the correct guess and will return eiter int 1 or int 0, it consist of a 'run' funtion which is affiliated under the 'run_guessing_random_number_game'. A header file is also created for triggering.

(The project was originally created in my partner's Github repository. Link of the original project: https://github.com/angus6291/COMP2113-Project/blob/main/README.md)
