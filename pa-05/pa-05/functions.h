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


void printScores(int *playerOne, int *playerTwo);