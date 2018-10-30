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

	manuallyMoveShips(p1Board);

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

void manuallyMoveShips(char board[][10]) {
	system("cls");

	char choice = ' ';

	int row = 0, col = 0;

	int shipLengths[] = { 5 };

	do {
		//system("cls");
		printBoardWithShip(row, col, 5, 1, 'C', board);
		printf("Where do you want to move your ship? (Use N/E/S/W): ");
		scanf(" %c", &choice);

		//printf("%c\n", choice);

		switch (choice){ 

		case 'n':
			if (row > 0) {
				--row;
				system("cls");
			}

			else {
				system("cls");
				printf("Nope!\n");
			}

			break;

		case 'e':
			// printf("col: %d\n", col + 1);
			// printf("max col: %d\n", (NUMCOLS - shipLengths[0]));
			if (col < (NUMCOLS - shipLengths[0])) {
				++col;
				system("cls");
			}
			
			else {
				system("cls");
				printf("Nope!\n");
			}

			break;

		case 's':
			if (row < NUMROWS) {
				++row;
				system("cls");
			}

			else {
				system("cls");
				printf("Nope!\n");
			}
		
			break;
		
		case 'w':
			if (col > 0) {
				--col;
				system("cls");
			}

			else {
				system("cls");
				printf("Nope!\n");
			}
			break;
		}

	} while (1);
}

void printBoardWithShip(int startRow, int startCol, int shipLength, int direction, char shipSymbol, char board[][10]) {
	char rowLetters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
	int row = startRow;
	int col = startCol;

	printf("    1  2  3  4  5  6  7  8  9  10  \n");

	if (direction == 1) {
		// outer loop
		for (int r = 0; r < NUMROWS; ++r) {
			// print row letter
			printf(" %c ", rowLetters[r]);

			// inner loop
			for (int c = 0; c < NUMCOLS; ++c) {

				if (r == row && c == col) {

					for (c = col; c < col + shipLength; ++c) {
						printf(" %c ", shipSymbol);
					}
					printf(" ~ ");

				}
				else{
					printf(" %c ", board[r][c]);
				}
			}

			printf("\n");
		}
	}
}