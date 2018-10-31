#include "functions.h"
#define NUMROWS 10
#define NUMCOLS 10
#define NUMSHIPS 5


int gameLoop(void) {

	int shipLengths[5] = { 5, 4, 3, 3, 2 };
	char shipSymbols[5] = { 'C', 'B', 'S', 'R', 'D' };

	//Player player;
	//initializePlayer(player, shipLengths);

	//Player computer;
	//initializePlayer(computer, shipLengths);

	Player player;
	player.board[10][10];
	player.map[10][10];
	
	resetGameBoardAlt(player.board);
	resetGameBoardAlt(player.map);

	
	Player computer;
	computer.board[10][10];
	computer.map[10][10];
	
	resetGameBoardAlt(computer.board);
	resetGameBoardAlt(computer.map);

	int count = 0, dir = 0;
	int choice = 0;


	resetGameBoardAlt(computer.board);

	choice = inputCheck(1, 2, printPreGameSetup);

	switch (choice) {
	case 1:
		randomlyPlaceShips(shipLengths, shipSymbols, player.board);
		randomlyPlaceShips(shipLengths, shipSymbols, computer.board);
		break;

	case 2:
		manuallyMoveShips(shipLengths, shipSymbols, player.board);
		randomlyPlaceShips(shipLengths, shipSymbols, computer.board);
		break;
	}

	printf("Player Board:\n");
	printBoard(player.board);

	printf("\n");

	printf("Computer Board:\n");
	printBoard(computer.board);

	return 0;
}

void resetGameBoard(char board[][10]) {
	for (int r = 0; r < NUMROWS; ++r) {
		for (int c = 0; c < NUMCOLS; ++c) {
			board[r][c] = '~';
		}
	}
}

void resetGameBoardAlt(char board[][10]) {
	for (int r = 0; r < NUMROWS; ++r) {
		for (int c = 0; c < NUMCOLS; ++c) {
			board[r][c] = ' ';
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

void manuallyMoveShips(int *lengths, char *symbols, char board[][10]) {
	system("cls");

	Error err;
	err.print = errorMessage;


	char choice = ' ';

	int row = 0, col = 0, direction = 1;


	for (int ship = 0; ship < NUMSHIPS; ++ship) {
		row = 0;
		col = 0;
		direction = 1;
		int temp = 0;

		do {

			printBoardWithShip(row, col, lengths[ship], direction, symbols[ship], board);
			printf("Where do you want to move your ship? (Use w/d/s/a for north/eeast/south/west:\n");
			printf("You can also rotate with r and confirm with x. \n");
			printf(">>>");
			scanf(" %c", &choice);

			switch (choice) {

			case 'w':
				if (row > 0) {
					--row;
					system("cls");
				}

				else {
					system("cls");
					err.print("You can't go that way.");
				}

				break;

			case 'd':
				if (col < (NUMCOLS - lengths[ship])) {
					++col;
					system("cls");
				}

				else {
					system("cls");
					err.print("You can't go that way.");
				}

				break;

			case 's':
				if (row < NUMROWS - 1) {
					++row;
					system("cls");
				}

				else {
					system("cls");
					err.print("You can't go that way.");
				}

				break;

			case 'a':
				if (col > 0) {
					--col;
					system("cls");
				}

				else {
					system("cls");
					err.print("You can't go that way.");
				}
				break;

			case 'r':
				/*temp = row;
				row = col;
				col = temp;
				temp = 0;*/
				direction = !direction;
				system("cls");
				break;

			case 'x':
				if (isOccupied(row, col, lengths[ship], direction, board) == 0) {
					placeShip(row, col, lengths[ship], direction, symbols[ship], board);
					system("cls");
				}
				else {
					system("cls");
					--ship;
					err.print("You can't place that ship there.");
				}
			}

		} while (choice != 'x');


	}

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
					--c;
					// printf(" ~ ");

				}
				else{
					printf(" %c ", board[r][c]);
				}
			}

			printf("\n");
		}
	}
	if (direction == 0) {

		// outer loop
		for (int r = 0; r < NUMROWS; ++r) {
			// print row letter
			printf(" %c ", rowLetters[r]);

			// inner loop
			for (int c = 0; c < NUMCOLS; ++c) {

				if (r == row && c == col && row < (startRow + shipLength)) {
					printf(" %c ", shipSymbol);
					row++;
				}
				else {
					printf(" %c ", board[r][c]);
				}
			}

			printf("\n");
		}
	}
}

void randomlyPlaceShips(int *lengths, char *symbols, char board[][10]) {
	int row = 0, col = 0, direction = 0, done = 0;

	for (int ship = 0; ship < NUMSHIPS; ++ship) {
		direction = rand() % 2;

		if (direction == 1) {
			do {
				row = rand() % NUMROWS;
				col = rand() % (NUMCOLS - lengths[ship] + 1);
				if (isOccupied(row, col, lengths[ship], direction, board) == 0) {
					for (int i = 0; i < lengths[ship]; ++i) {
						board[row][col + i] = symbols[ship];
					}
					done = 1;
				}

			} while (!done);
		}
		else {
			do {
				row = rand() % (NUMROWS - lengths[ship] + 1);
				col = rand() % NUMCOLS;
				if (isOccupied(row, col, lengths[ship], direction, board) == 0) {
					for (int i = 0; i < lengths[ship]; ++i) {
						board[row + i][col] = symbols[ship];
					}
					done = 1;
				}

			} while (!done);


		}
	}
}

int isOccupied(int startRow, int startCol, int length, int direction, char board[][10]) {
	int occupied = 0;
	
	if (direction == 1) {
		for (int i = 0; i < length; ++i) {
			if ((board[startRow][startCol + i] != ' ') && (board[startRow + i][startCol] != '~')) {
				occupied = 1;
				break;
			}
		}
	}
	else if (direction == 0) {
		for (int i = 0; i < length; ++i) {
			if ((board[startRow][startCol + i] != ' ') && (board[startRow + i][startCol] != '~')) {
				occupied = 1;
				break;
			}
		}
	}
	return occupied;
}

int inputCheck(int lowerBound, int upperBound, void(*printMenu)()) {
	int choice = 0;
	do {
		choice = 0;

		printMenu();
		scanf("%d", &choice);

		if (choice < lowerBound || choice > upperBound) {
			system("cls");
			printBorder(2, 45);
			printf("%d? That's not a valid option. Try again.\n", choice);
			printBorder(2, 45);
		}
		else {
			break;
		}

	} while (choice != upperBound);

	return choice;
}

void printPreGameSetup(void) {
	printf("Please choose an option:\n");
	printf("1: Randomize your ship locations\n");
	printf("2: Manually enter your ship locations\n");
}

void placeShip(int startRow, int startCol, int length, int direction, char symbol, char board[][10]) {
	int occupied = 0;

	if (direction == 1) {
		for (int i = 0; i < length; ++i) {
			board[startRow][startCol + i] = symbol;
		}
	}
	else if (direction == 0) {
		for (int i = 0; i < length; ++i) {
			for (int i = 0; i < length; ++i) {
				board[startRow + i][startCol] = symbol;
			}
		}
	}
	return occupied;
}

void errorMessage(char *message) {

	int length = strlen(message) + 6;

	printBorder(2, length);
	printf("|| %s ||\n", message);
	printBorder(2, length);
}

void initializePlayer(Player p, int *shipLengths) {
	p.board[10][10];
	p.map[10][10];

	resetGameBoardAlt(p.board);
	resetGameBoardAlt(p.map);


	char *name = "player";

	for (int i = 0; i < NUMSHIPS; ++i) {
		p.shipHealth[i] = shipLengths[i];
	}

	for (int i = 0; i < NUMSHIPS; ++i) {
		p.deadShips[i] = 0;
	}

	p.scorePoints = 0;

}
