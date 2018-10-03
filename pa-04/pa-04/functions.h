#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int gameLoop(void);

void showMenu(void);

void showRules(void);

int rollDice(void);

double playGame(double accountBalance);
// int sanitizeInput(int);

double setAccountBalance(void);

double getAccountBalance(double accountBalance);

double getWager(double accountBalance);

void printDice(int num);
