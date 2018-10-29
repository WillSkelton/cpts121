#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void printBattleship(void);

void printTitle(void);

void printGameBoard(char board[10][10]);

void resetGameBoard(char board[10][10]);

void printBoardWithShip(int len, int row, int col, char orientation, char shipType);