#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int gameLoop(void);

void printMenu(void);

void printRules(void);

int playGame(int *playerOne, int *playerTwo);

void playerRoll(int *scorecard);

void reRollLoop(int *choice, int *numberOfReRolls, int *dice, int *reRoll);

int rollDice(int *dice);

int reRollDice(int *dice, int *reRoll);

void printRollOptions(void);

void parseRoll(int *scorecard, int *dice);

void verifyResults(int *dice, int *results, int *scorecard);

int arrayContains(int search, int *array, int arrLen);

void printCombinationOptions(void);

void printScores(int *playerOne, int *playerTwo);

int inputCheck(int lowerBound, int upperBound, void(*printMenu)());

int arraySum(int *array, int len);

