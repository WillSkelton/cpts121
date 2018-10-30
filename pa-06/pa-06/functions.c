#include "functions.h"

int gameLoop(void) {
	placeShip();
}

void placeShip(void) {
	char choice = ' ';
	int row = 0, col = 0, carrierLength = 5;
	char carrier = 'C';
	do {
		printBoardWithShip(carrierLength, row, col, 'h', 'C');

		printf("Where do you want to move your carrier?: \n");
		scanf(" %c", &choice);

		switch (choice) {
		case 'n':
			if (row != 0) {
				--row;
				system("cls");

				//(carrierLength, row, col, 'h', 'C');
			}
			break;
			
		case 's':
			if (row != 10) {
				++row;
				system("cls");
				//(carrierLength, row, col, 'h', 'C');
			}
			break;

		case 'e':
			if (col != 10) {
				++col;
				system("cls");
				//(carrierLength, row, col, 'h', 'C');
			}
			break;

		case 'w':
			if (col != 0) {
				--col;
				system("cls");
				//(carrierLength, row, col, 'h', 'C');
			}
			break;
		}


	} while (choice != 'x');
}