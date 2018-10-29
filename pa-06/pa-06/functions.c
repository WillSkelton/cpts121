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
			case 'w':
				if (row != 0) {
					++row;
					printBoardWithShip(carrierLength, row, col, 'h', 'C');
				}
				break;
			
			case 's':
				if (row != 0) {
					--row;
					printBoardWithShip(carrierLength, row, col, 'h', 'C');
				}
				break;
		}


	} while (choice != 'x');
}