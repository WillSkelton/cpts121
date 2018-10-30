#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct player {
	char board[10][10];
};

int gameLoop(void);

void resetGameBoard(char board[][10]);

void printBoard(char board[][10]);