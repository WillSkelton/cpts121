#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

#define NUMROWS 10
#define NUMCOLS 10
#define NUMSHIPS 5
#define WATERSYMBOL ' '

typedef int(*CalculateKDR)(int k, int d);

typedef struct player {
	char board[NUMROWS][NUMCOLS];
	char map[NUMCOLS][NUMCOLS];
	char name;
	char *whoSankIt;
	int CHealth;
	int BHealth;
	int SHealth;
	int RHealth;
	int DHealth;
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

void printBoard(char board[NUMROWS][NUMCOLS]);

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

void computerTurn(Player *player, Player *computer, Error *err);

char shotResult(char c, Player *attack, Player *defense, Error *err, int *hitOrMiss);

void updateShipHealth(Player *attack, Player *defence, char shipSymbol);