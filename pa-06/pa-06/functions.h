#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

#define NUMROWS 10
#define NUMCOLS 10
#define NUMSHIPS 5

typedef int(*CalculateKDR)(int k, int d);

typedef struct player {
	char board[NUMROWS][NUMCOLS];
	char map[NUMCOLS][NUMCOLS];
	char name;
	int kills;
	int deadShips;
	int scorePoints;
	int kdr;
	int hits;
	int misses;

	CalculateKDR calculateKDR;

}Player;


typedef void(*PrintError)(char *message);

typedef struct error {

	PrintError log;

} Error;

int gameLoop(void);

void resetGameBoard(char board[NUMROWS][NUMCOLS]);

void resetGameBoardAlt(char board[NUMROWS][NUMCOLS]);

void printBoard(char board[10][10]);

void randomlyPlaceShips(int *lengths, char *symbols, char board[NUMROWS][NUMCOLS]);

void manuallyMoveShips(int *lengths, char *symbols, char board[NUMROWS][NUMCOLS]);

void printBoardWithShip(int startRow, int startCol, int shipLength, int direction, char shipSymbol, char board[NUMROWS][NUMCOLS]);

int isOccupied(int startRow, int startCol, int length, int direction, char board[NUMROWS][NUMCOLS]);

int inputCheck(int lowerBound, int upperBound, void(*printMenu)());

void printPreGameSetup(void);

void printMessage(char *message);

void placeShip(int startRow, int startCol, int length, int direction, char symbol, char board[NUMROWS][NUMCOLS]);

int newError(Error *err);

void initializePlayer(Player *p);

int calculateKDR(int k, int d);

void playGame(Player *player, Player *computer);

void playerTurn(Player *player, Player *computer, Error *err);

void ptrTest(Player *p);