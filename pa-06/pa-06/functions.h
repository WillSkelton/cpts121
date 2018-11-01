#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

typedef struct player {
	char *board[10][10];
	char *map[10][10];
	char *name;
	int kills;
	int deadShips;
	int scorePoints;

}Player;


typedef void(*PrintError)(char *message);

typedef struct error {

	//int  result; // to sotre the resut
	PrintError  log; // funtion pointer 

	int test;

} Error;

int gameLoop(void);

void resetGameBoard(char board[][10]);

void resetGameBoardAlt(char board[][10]);

void printBoard(char board[][10]);

void randomlyPlaceShips(int *lengths, char *symbols, char board[][10]);

void manuallyMoveShips(int *lengths, char *symbols, char board[][10]);

void printBoardWithShip(int startRow, int startCol, int shipLength, int direction, char shipSymbol, char board[][10]);

int isOccupied(int startRow, int startCol, int length, int direction, char board[][10]);

int inputCheck(int lowerBound, int upperBound, void(*printMenu)());

void printPreGameSetup(void);

void errorMessage(char *message);

void placeShip(int startRow, int startCol, int length, int direction, char symbol, char board[][10]);

int newError(Error *err);

void initializePlayer(Player *p);
