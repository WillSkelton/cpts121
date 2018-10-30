#include "functions.h"
#define NUMROWS 10
#define NUMCOLS 10


int gameLoop(void) {
	
	char p1Board[10][10] = { { '~', '~' }, { '~' } };
	char shipSymbols[5] = { 'c', 'b', 's', 'r', 'd' };
	int shipLengths[5] = { 5, 4, 3, 3, 2 };
	int count = 0, dir = 0;

	resetGameBoard(p1Board);
	printBoard(p1Board);

	return 0;
}

void resetGameBoard(char board[][10]) {
	for (int r = 0; r < NUMROWS; ++r) {
		for (int c = 0; c < NUMCOLS; ++c) {
			board[r][c] = '~';
		}
	}
}

void printBoard(char board[][10]) {
	char rowLetters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	
	printf("    1  2  3  4  5  6  7  8  9  10  \n");
	for (int r = 0; r < NUMROWS; ++r) {
		printf(" %c ", rowLetters[r]);
		
		for (int c = 0; c < NUMCOLS; ++c) {
			printf(" %c ", board[r][c]);
		}
		
		printf("\n");
	}
}
