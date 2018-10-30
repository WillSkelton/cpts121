#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct player {
	char board[10][10];
	char *name;
}Player;

int gameLoop(void);

void resetGameBoard(char board[][10]);

void resetGameBoardAlt(char board[][10]);

void printBoard(char board[][10]);

void randomlyPlaceShips(int *lengths, char *symbols, char board[][10]);

void manuallyMoveShips(char board[][10]);

void printBoardWithShip(int startRow, int startCol, int shipLength, int direction, char shipSymbol, char board[][10]);

int isOccupied(int startRow, int startCol, int length, int direction, char board[][10]);

int inputCheck(int lowerBound, int upperBound, void(*printMenu)());

void printPreGameSetup(void);