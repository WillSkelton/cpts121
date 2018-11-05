#include "functions.h"

int gameLoop(void) {


	char shipSymbols[5] = { 'C', 'B', 'S', 'R', 'D' };
	int shipLengths[5] = { 5, 4, 3, 3, 2 };
	int count = 0, dir = 0;
	int choice = 0;

	Player player;
	initializePlayer(&player);

	Player computer;
	initializePlayer(&computer);

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
	
	//initializePlayer(&player);
	//randomlyPlaceShips(shipLengths, shipSymbols, player.board);
	//printBoard(&player);
	//
	//initializePlayer(&player);
	//randomlyPlaceShips(shipLengths, shipSymbols, player.board);
	//printBoard(&player);

	//initializePlayer(&player);
	//randomlyPlaceShips(shipLengths, shipSymbols, player.board);
	//printBoard(&player);

	playGame(&player, &computer);

	return 0;
}

void resetGameBoard(char board[NUMROWS][NUMCOLS]) {
	for (int r = 0; r < NUMROWS; ++r) {
		for (int c = 0; c < NUMCOLS; ++c) {
			board[r][c] = WATERSYMBOL;
		}
	}
}

void resetGameBoardAlt(char board[NUMROWS][NUMCOLS]) {
	for (int r = 0; r < NUMROWS; ++r) {
		for (int c = 0; c < NUMCOLS; ++c) {
			board[r][c] = WATERSYMBOL;
		}
	}
}

void printBoard(Player *p) {

	char rowLetters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

	printf("     1  2  3  4  5  6  7  8  9  10  \n");
	for (int r = 0; r < NUMROWS; ++r) {
		if (r == 9) {
			printf(" %d ", r + 1);
		}
		else {
			printf("  %d ", r + 1);

		}

		for (int c = 0; c < NUMCOLS; ++c) {
			printf(" %c ", p->board[r][c]);
		}

		printf("\n");
	}

}

void manuallyMoveShips(int *lengths, char *symbols, char board[NUMROWS][NUMCOLS]) {
	system("cls");

	Error err;
	err.log = printMessage;

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
			printf(">>> ");
			scanf(" %c", &choice);

			switch (choice) {

			case 'w':
				if (row > 0) {
					--row;
					system("cls");
				}
				else {
					system("cls");
					err.log("You can't go that way.");
				}
				break;

			case 'd':
				if (direction == 1) {
					if (col < (NUMCOLS - lengths[ship])) {
						++col;
						system("cls");
					}
					else {
						system("cls");
						err.log("You can't go that way.");
					}
				}
				else if (direction == 0) {
					if (col < NUMCOLS - 1) {
						++col;
						system("cls");
					}
					else {
						system("cls");
						err.log("You can't go that way.");

					}
				}
				else {
					err.log("IDK how you got here.");
				}
				break;

			case 's':
				if (direction == 0) {
					if (row < (NUMROWS - lengths[ship])) {
						++row;
						system("cls");
					}
					else {
						system("cls");
						err.log("You can't go that way.");
					}
				}
				else if (direction == 1) {
					if (row < NUMROWS - 1) {
						++row;
						system("cls");
					}
					else {
						system("cls");
						err.log("You can't go that way.");

					}
				}
				else {
					err.log("IDK how you got here.");
				}
				break;

			case 'a':
				if (col > 0) {
					--col;
					system("cls");
				}
				else {
					system("cls");
					err.log("You can't go that way.");
				}
				break;

			case 'r':
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
					err.log("You can't place that ship there.");
				}
			}
		} while (choice != 'x');
	}
}

void printBoardWithShip(int startRow, int startCol, int shipLength, int direction, char shipSymbol, char board[NUMROWS][NUMCOLS]) {
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

				if (r == row && c == col && col < (startCol + shipLength)) {
					printf(" %c ", shipSymbol);
					col++;
				}
				else {
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

void randomlyPlaceShips(int *lengths, char *symbols, Player *p) {
	int row = 0, col = 0, direction = 0, done = 0;

	for (int ship = 0; ship < NUMSHIPS; ++ship) {
		direction = rand() % 2;

		if (direction == 1) {
			do {
				row = rand() % NUMROWS - 1;
				col = rand() % (NUMCOLS - lengths[ship] + 1);
				if (isOccupied(row, col, lengths[ship], direction, p->board) == 0) {
					for (int i = 0; i < lengths[ship]; ++i) {
						p->board[row][col + i] = symbols[ship];
						//printBoard(p);
						//system("cls");
					}
					done = 1;
				}
				else {
					--ship;
				}

			} while (!done);
		}
		else {
			do {
				row = rand() % (NUMROWS - lengths[ship] + 1);
				col = rand() % NUMCOLS - 1;
				if (isOccupied(row, col, lengths[ship], direction, p->board) == 0) {
					for (int i = 0; i < lengths[ship]; ++i) {
						p->board[row + i][col] = symbols[ship];
						/*printBoard(p);
						system("cls");*/
					}
					done = 1;
				}
				else {
					--ship;
				}

			} while (!done);


		}
	}
}

int isOccupied(int startRow, int startCol, int length, int direction, char board[NUMROWS][NUMCOLS]) {
	int occupied = 0;

	if (direction == 1) {
		for (int i = 0; i < length; ++i) {
			if ((board[startRow][startCol + i] != WATERSYMBOL)) {
				occupied = 1;
				break;
			}
		}
	}
	else if (direction == 0) {
		for (int i = 0; i < length; ++i) {
			if ((board[startRow + i][startCol] != WATERSYMBOL)) {
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

void placeShip(int startRow, int startCol, int length, int direction, char symbol, char board[NUMROWS][NUMCOLS]) {
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

void printMessage(char *message) {

	int length = strlen(message) + 6;

	printBorder(2, length);
	printf("|| %s ||\n", message);
	printBorder(2, length);
}

void youSankMyShip(char *whoSankIt, char *shipName) {

	int length = strlen(shipName) + strlen(whoSankIt) + 6;

	printBorder(2, length);
	printf("|| %s %s ||\n", whoSankIt, shipName);
	printBorder(2, length);

}

int newError(Error *err) {

	err->log = printMessage;
}

void initializePlayer(Player *p) {

	resetGameBoard(p->board);
	resetGameBoard(p->map);

	p->name;
	p->kills = 0;
	p->deadShips = 0;
	p->scorePoints = 0;
	p->kdr = 1;
	p->hits = 0;
	p->misses = 0;
	p->CHealth = 5;
	p->BHealth = 4;
	p->SHealth = 3;
	p->RHealth = 3;
	p->DHealth = 2;

	p->calculateKDR = calculateKDR;
}

int calculateKDR(int k, int d) {
	int kills = k;
	int deaths = d;

	if (d <= 0) {
		deaths = 1;
	}

	return kills / deaths;

}

void playGame(Player *player, Player *computer) {

	player->whoSankIt = "You sunk their";
	computer->whoSankIt = "They sunk your";


	Error err;
	err.log = printMessage;

	while ((player->deadShips != NUMSHIPS) && (computer->deadShips != NUMSHIPS)) {
		playerTurn(player, computer, &err);
		computerTurn(player, computer, &err);
	}
	
}

void playerTurn(Player *player, Player *computer, Error *err) {

	int row = 0, col = 0, hitOrMiss = 0;

	char target = ' ', result = ' ';

	do {
		hitOrMiss = 0;

		system("cls");
		
		printMessage("Your Turn");

		printf("Score Points : %d | Ships Alive : %d\n", player->scorePoints, NUMSHIPS - player->deadShips);
		
		printf("Map:\n");
		printBoard(player->map);
		
		printBorder(2, 34);

		printf("Your Ships:\n");
		printBoard(player->board);

		printf("Enter a row number for your shot: ");
		scanf("%d", &row);
		printf("Enter a column number for your shot: ");
		scanf("%d", &col);

		row -= 1;
		col -= 1;

		target = computer->board[row][col];
		result = shotResult(target, player, computer, err, &hitOrMiss);

		//printf("Target: '%c'\n", target);

		computer->board[row][col] = result;
		player->map[row][col] = result;

		Sleep(1000);

		system("cls");

	} while (hitOrMiss != 0 && hitOrMiss != 1);

}

void computerTurn(Player *player, Player *computer, Error *err) {

	
	int row = 0, col = 0, hitOrMiss = 0;;
	char target = ' ', result = ' ';

	row = rand() % NUMROWS - 1;
	col = rand() % NUMCOLS - 1;


	printMessage("Computer's turn");
	target = player->board[row][col];
	result = shotResult(target, computer, player, err, &hitOrMiss);

	player->board[row][col] = result;
	computer->map[row][col] = result;

	printf("Score Points : %d | Ships Alive : %d\n", player->scorePoints, NUMSHIPS - player->deadShips);

	printf("Map:\n");
	printBoard(player->map);

	printBorder(2, 34);

	printf("Your Ships:\n");
	printBoard(player->board);
	Sleep(1000);

	system("cls");

}

char shotResult(char c, Player *attack, Player *defense, Error *err, int *hitOrMiss) {

	char result = ' ';

	if (c == 'x' || c == 'o') {
		result = c;
		err->log("You already shot there.");
	}
	else if (c != WATERSYMBOL) {

		*hitOrMiss = 1;
		result = 'x';
		updateShipHealth(attack, defense, c);
	}
	else if (c == WATERSYMBOL) {
		*hitOrMiss = 0;

		printMessage("MISS!");
		result = 'o';
	}

	return result;
}

void updateShipHealth(Player *attack, Player *defence, char shipSymbol) {

	switch (shipSymbol) {
	case 'C':
		attack->hits++;
		defence->CHealth--;
		//system("cls");
		printMessage("HIT!");

		if (defence->CHealth == 0) {
			youSankMyShip(attack->whoSankIt, "Carrier!");
			attack->kills++;
			attack->scorePoints++;
			defence->deadShips++;	
		}

		Sleep(1000);
		break;

	case 'B':
		attack->hits++;
		defence->BHealth--;
		printMessage("HIT!");

		if (defence->BHealth == 0) {
			youSankMyShip(attack->whoSankIt, "Battleship!");
			attack->kills++;
			attack->scorePoints++;
			defence->deadShips++;
		}
		Sleep(1000);
		break;

	case 'S':
		attack->hits++;
		defence->SHealth--;
		printMessage("HIT!");

		if (defence->SHealth == 0) {
			youSankMyShip(attack->whoSankIt, "Submarine!");
			attack->kills++;
			attack->scorePoints++;
			defence->deadShips++;
		}
		Sleep(1000);
		break;

	case 'R':
		attack->hits++;
		defence->RHealth--;
		printMessage("HIT!");

		if (defence->RHealth == 0) {
			youSankMyShip(attack->whoSankIt, "Cruiser!");
			attack->kills++;
			attack->scorePoints++;
			defence->deadShips++;
		}
		Sleep(1000);
		break;

	case 'D':
		attack->hits++;
		defence->DHealth--;
		printMessage("HIT!");

		if (defence->DHealth == 0) {
			youSankMyShip(attack->whoSankIt, "Destroyer!");
			attack->kills++;
			attack->scorePoints++;
			defence->deadShips++;
		}
		Sleep(1000);
		break;
	}
}

