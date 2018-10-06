#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

/**************************************
* return type: void
* parameters: n/a
* last modified: 10/5/18
* desctiption: loop that runs the game
**************************************/
int gameLoop(void);

/**************************************
* return type: void
* parameters: n/a
* last modified: 10/5/18
* desctiption: prints menu
**************************************/
void showMenu(void);

/**************************************
* return type: void
* parameters: n/a
* last modified: 10/5/18
* desctiption: prints rules
**************************************/
void showRules(void);

/*****************************************
* return type: integer sum of 2 dice
* parameters: n/a
* last modified: 10/5/18
* desctiption: randomly generates 2 dice
*****************************************/
int rollDice(void);

/*******************************************************
* return type: double value of winnings from that round
* parameters: account balance
* last modified: 10/5/18
* desctiption: rolls 2 dice and adds or subtracts 
*   wager depending on success
*******************************************************/
double playGame(double accountBalance);

/*****************************************************************
* return type: double value of winnings from that round
* parameters: wager amount and sum of dice
* last modified: 10/5/18
* desctiption: continues rolling dice until player wins or loses
******************************************************************/
double successiveRoll(int diceSum, double wager);

/**********************************************************
* return type: double value account balance
* parameters: n/a
* last modified: 10/5/18
* desctiption: asks user for account balance and saves it
**********************************************************/
double setAccountBalance(void);

/**********************************************************
* return type: double value account balance
* parameters: account balance
* last modified: 10/5/18
* desctiption: gets and prints account balance 
**********************************************************/
double getAccountBalance(double accountBalance);

/**********************************************************
* return type: double value wager
* parameters: account balance
* last modified: 10/5/18
* desctiption: asks user for wager and saves it
**********************************************************/
double getWager(double accountBalance);

/**********************************************************
* return type: n/a
* parameters: face number
* last modified: 10/5/18
* desctiption: prints an ascii die based on face number
**********************************************************/
void printDice(int num);

/*********************************************************************************
* return type: n/a
* parameters: int from 0-2 rating success with - being losing and 2 being winning
* last modified: 10/5/18
* desctiption: prints game chatter
*********************************************************************************/
void gameChatter(int num);