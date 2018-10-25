#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

/*
* Author: Will Skelton
* Args: N/a
* Desc: Main REPL for the game. It's responsible for the main menu and will only exit once the user asks to or the game ends.
* Returns: 0
*/
int gameLoop(void);

/*
* Author: Will Skelton
* Args: n/a
* Desc: prints the main menu
* Returns: n/a 
*/
void printMenu(void);

/*
* Author: Will Skelton
* Args: n/a
* Desc: prints the rules
* Returns: n/a
*/
void printRules(void);

/*
* Author: Will Skelton
* Args: 2 pointers to integer arrays of length 13 that represent two players scorecards
* Desc: Player one rolls dice and selects a combination. Then, player2 does the same thing
* Returns: 0
*/
int playGame(int *playerOne, int *playerTwo);

/*
* Author: Will Skelton
* Args: one pointer to an integer array that represents a scorecard
* Desc: Prints the rolled dice, checks to see of the player wants to reroll or stay, rerolls if
* necessary, parses the dice based on which combination the player wants to use, and calculates the
* the score accordingly.
* Returns: n/a
*/
void playerRoll(int *scorecard);

/*
* Author: Will Skelton
* Args: 
*   - int pointer for which combination the user wants
*	- int pointer for the number of times the user rerolled their dice
*	- pointer to int array of dice
*	- pointer to an empty int array thet will be the new list of rerolled dice
* Desc: asks player if they want to re roll which dice and which ones they want to reroll. Then it rerolls them.
* Returns: n/a
*/
void reRollLoop(int *choice, int *numberOfReRolls, int *dice, int *reRoll);

/*
* Author: Will Skelton
* Args: a pointer to an int array of the player's dice
* Desc: randomizes all the dice in the array
* Returns: 0
*/
int rollDice(int *dice);

/*
* Author: Will Skelton
* Args: 2 pointers to int arrays of dice and which dice to reroll
* Desc: iterates through array of dice and if the same element of reroll is 1, that die is rerolled
* Returns: 0
*/
int reRollDice(int *dice, int *reRoll);

/*
* Author: Will Skelton
* Args: n/a
* Desc: prints the options to either to reroll the dice or to keep them
* Returns: n/a
*/
void printRollOptions(void);

/*
* Author: Will Skelton
* Args: 2 pointers to int arrays: A scorecard and a set of 5 dice
* Desc: goes through and counts how many of each die are in the dice array and stores them in a new array
* where the number on the dice corresponds to the index of the new array. then is calls verify results with
* the dice array, number of each dice array, and the the scorecard
* Returns:  n/a
*/
void parseRoll(int *scorecard, int *dice);

/*
* Author: Will Skelton
* Args: 3 pointers to int arrays: player's dice, number of each dice, and their scorecard
* Desc: asks the user which combo they want to use. If they have that combo, they get the 
* points. Otherwise, they get a 0. In either case, that combinatuon is 'used' and can't 
* be used again.
* Returns: n/a
*/
void verifyResults(int *dice, int *results, int *scorecard);

/*
* Author: Will Skelton
* Args: 1 pointer to an int array and 2 integers: length of array and a search value.
* Desc: iterates through an array and returns 1 if it contains the provided value
* or 0 otherwise
* Returns: 1 or 0 depending on if the provided value is found
*/
int arrayContains(int search, int *array, int arrLen);

/*
* Author: Will Skelton
* Args: n/a
* Desc: prints possible combinations
* Returns: n/a
*/
void printCombinationOptions(void);

/*
* Author: Will Skelton
* Args: pointer to int array that represents a scorecard and a total score of that player
* Desc: iterates through and prints the player's scorecard and their score total
* Returns:n/a
*/
void printScores(int *player, int total);

/*
* Author: Will Skelton
* Args: 2 ints that represent the lower and upper bounds of the input validation and a 
* a pointer to a function that prints the menu
* Desc: calls the provided printfunction and then asks the user to enter a number within the 
* valid range
* Returns: the user's choice
*/
int inputCheck(int lowerBound, int upperBound, void(*printMenu)());

/*
* Author: Will Skelton
* Args: a pointer to an int array and length of that array
* Desc: loops through the array and finds the sum of all elements
* Returns: sum of all numbers in array
*/
int arraySum(int *array, int len);

/*
* Author: Will Skelton
* Args: pointer to a scorecard array
* Desc: sets all values in the scorecard to -1
* Returns: n/a
*/
void resetScorecard(int *scorecard);
