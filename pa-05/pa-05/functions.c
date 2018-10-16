#include "functions.h"


int gameLoop(void) {

	int choice = 0;

	do {
		choice = 0;
		printMenu();
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			system("cls");
			printf("Rules:\n");
			break;

		case 2:
			system("cls");
			printf("Play game\n");
			break;

		case 3:
			system("cls");
			printf("score\n");

			break;

		case 4:
			system("cls");
			break;

		case 5:
			printf("Goodbye!\n");
			break;

		default:
			system("cls");
			printBorder(2, 50);
			printf("%d? That's not a valid option. Try again.\n", choice);
			printBorder(2, 50);

		}

	} while (choice != 5);

	return 0;
}

void printMenu(void) {
	printf("Press 1 to show the rules: \n");
	printf("Press 2 to play the game: \n");
	printf("Press 3 to see score: \n");
	printf("Press 4 to clear the screen: \n");
	printf("Press 5 to exit: \n");
	printf(">>> ");
}

int sanitizeInput(void) {
	int choice = 0;

	do {
		choice = 0;
		system("cls");
		printMenu();
		scanf("%d", &choice);
		
		if (choice < 1 || choice > 5) {
			system("cls");
			printf("%d?, That's not a valid option. Try again.\n", choice);
			system("pause");
		}
		else {
			break;
		}

	} while (choice >= 1 && choice <= 5);


	return choice;
}