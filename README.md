# COMP2113/ENGG1340 Course project brief introduction

Group No.: 134

Group Members: Tse Tsz Chun, Lam Chun Yin Angus

# Game Introduction

Tentative name of the game: 'Try your luck'

Concept: mixing 'guessing random numbers' and 'bingo' games

The grid size of the 'bingo' board will be 3x3 or 4x4 (if the grid size includes 5x5, we are afraid the game will take too long).

A player will need to choose the grid size first (by inputting character '3' or character '4'), and then play the game of 'guessing random numbers'. (If the player has already had a game playing beforehand, press 'L' then the saved game will be reloaded.) If the player enters other characters, the player will be asked "DO YOU WANT TO EXIT?". If the player presses character "Y", player will exit the game. If the player presses other characters, the player will need to choose the grid size again. When playing the game of 'guessing random number', the player will have 7 chances to guess the number. (WARNING: YOU CANNOT SAVE YOUR PROGRESS IN 'GUESSING RANDOM NUMBER' GAME.) 

If the player chooses 3x3 grid, a vector v = {1, 2, 3, 4, 5, 6, 7, 8, 9} will be initiated. If the player chooses 4x4 grid, vector v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16} will be initiated.

int Index_of_number_to_be_guessed_in_the_vector = srand(time(NULL)) % 10 (for 3x3), srand(time(NULL)) % 17 (for 4x4)

int Number_to_be_guessed = v[Index_of_number_to_be_guessed_in_the_vector]

int Number_of_attempts_allowed = 7 (for 3x3), 12 (for 4x4)

int Number_of_attempts_left = Number_of_attempts_allowed

int player's_input

When the player inputs a number (stored into variable 'player's_input'), the player's_input in the vector will be compared to Number_to_be_guessed. At the 1st/2nd/3rd/4th/5th/6th/7th (last) trial, if the two numbers match:

1. print out 'Yeah! this is the number we want!'

2. then the position of the number on the bingo board will become "O". The bingo board wll be shown, and the number will be removed from the vector v.

3. the player can press character "C" (or character "c") to continue, "S" (or character "s") to save, and "E" (or character "e") to exit. Only "C", "c", "S", "s", "E" and "e" will be sensed by the computer.

If the number is not guessed successfully:

1. print out 'Sorry, you still haven't guesses successfully the number we want.'

2. the position of the number on the bingo board will become "X". The bingo board wll be shown, and the number will be removed from the vector v.

If the player has not yet got a 'bingo', 'guessing random number' game will repeat, but the number the player has just guessed will be opted out. Similar procedure continues until the player gets a bingo, or until positions of all numbers are marked with a 'tick' or a 'cross'. If the player gets a bingo, he/she wins. If the player still doesn't get a bingo until all positions are marked with a 'check' or a 'cross', he/she loses. After the game is over, the player can press any key to leave (cout << " "). 

Disclaimer: The details are subject to change. We don't know whether the procedures to realize the idea are simple or not.

# Code Requirements
How it satisfies the code requirements

Code requirement 1: Generation of random game sets or events

When the player entered the game, they have to guess the correct number generated from srand(time(NULL)) % 10 (for 3x3), srand(time(NULL)) % 17 (for 4x4), which if you are playing 3x3 grid size, you will have to pick a random number from 0-9 to test whether it meets with the number in the vector which is generated randomly with in 7 trials, for 4x4, you do the same but the range increase to 0-16 and u are given 12 trials.

Code requirement 2: Data structures for storing game status

We will ultilise vector for storing the number to be guessed for each box in the grid boxes, which will be refreshed every play. Meanwhile we will set up another vector for storing the output (bingo board) for sotring the "0" and "X", which a further function would be used to evaluate after the completion of all boxes, whether there are 3 (for 3x3) or 4 (for 4x4) consecutive "0" vertically, horizontally or diagonally, if TRUE, then will output "YOU WIN!!!", else output "YOU LOSS, pls retry :("

Code requirement 3: Dynamic memory management

For checking whether the user input is the same with the corresponding "Number_to_be_guessed", the input will be sotred as "player's_input" and run loop until they have the right guess, if they have the right guess, "0" will added into the output bingo board vector, while the number in the corresponding guessing number vector with the same location will be removed. If player has the wrong guess, "X" will be added into the output bingo board vector, while the number will be removed from guessing number vector as well.

Meanwhile, if player press "E" or "e" to exit, we have to remove all the storage in the output bingo board and reset the number to be guessed vector to it's inital length.

Code requirement 4: File input/output (e.g. for loading/saving game status)

After the player has successfully or unsucessfully guessed a number, the number will be changed to a "O" or "X" on the bingo board. If the player presses "S" to save the status, the data of the current game progress will be saved in a file. 

If the player has already had a game playing beforehand, press 'L' then the saved game will be reloaded.

Code requirement 5: Program codes in multiple files

The main program will call functions of multiple files (in the form of header files), such as file(s) for the 'guessing the random number' game and file(s) for the 'bingo' game. Program files apart from the main program file, if needed, will call other header files in.
