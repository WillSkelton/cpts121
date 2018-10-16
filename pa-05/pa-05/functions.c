#include "functions.h"
#define MAXLENGTH 13
#define NUMDICE 5

int gameLoop(void) {

	int playerOne[MAXLENGTH] = { 0 };
	int playerTwo[MAXLENGTH] = { 0 };

	int choice = 0;

	do {
		choice = 0;
		printMenu();
		scanf("%d", &choice);

		switch (choice) {
		
		case 1:
			system("cls");
			printRules();
			break;

		case 2:
			system("cls");
			playGame(playerOne, playerTwo);
			break;

		case 3:
			system("cls");
			printf("============================== Score ==============================\n");
			printScores(playerOne, playerTwo);
			printBorder(2, 67);


			break;

		case 4:
			system("cls");
			break;

		case 5:
			printf("Goodbye!\n");
			break;

		default:
			system("cls");
			printBorder(2, 45);
			printf("%d? That's not a valid option. Try again.\n", choice);
			printBorder(2, 45);

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

void printRules(void) {
	printf("========================= Rules =========================\n");
	printf("1. \n");
	printf("");
	printBorder(2, 57);
}

int playGame(int *playerOne, int *playerTwo) {
	printf("=============== Time's up. Let's do this! ===============\n");

	

	playerRoll(playerOne);

	int round = 0;
	//do
	//{

	//	++round;
	//} while (round < 13);

	system("pause");
	return 0;
}

void playerRoll(int *scorecard) {
	int choice = 0;
	int numberOfReRolls = 0;
	int reRoll[NUMDICE] = { 0 };
	int dice[NUMDICE] = { 0 };

	rollDice(dice);

	do {
		choice = 0;

		printRoll(dice);
		printRollOptions();
		scanf("%d", &choice);

		reRollLoop(&choice, &numberOfReRolls, dice, reRoll);

	} while (choice != 1 && choice != 2);


}

void reRollLoop(int *choice, int *numberOfReRolls, int *dice, int *reRoll) {
	switch (*choice) {

	case 1:
		break;

	case 2:
		do {
			++*numberOfReRolls;
			printf("Select which dice re-roll by entering 1 for a re-roll or 0 to keep.\n");
			printf("(EG: 1 0 1 1 0 keeps dice 2 and 5 and rerolls 1, 3, and 4)\n>>> ");
			scanf("%d%d%d%d%d", &reRoll[0], &reRoll[1], &reRoll[2], &reRoll[3], &reRoll[4]);

			system("cls");
			reRollDice(dice, reRoll);
			printRoll(dice);
		} while (*numberOfReRolls < 3);

		break;

	default:
		system("cls");
		printBorder(2, 45);
		printf("%d? That's not a valid option. Try again.\n", *choice);
		printBorder(2, 45);
	}

}

int rollDice(int *dice) {

	for (int i = 0; i < NUMDICE; ++i) {
		dice[i] = rand() % 6 + 1;
	}
	return 0;
}

int reRollDice(int *dice, int *reRoll) {

	for (int i = 0; i < NUMDICE; ++i) {
		if (reRoll[i] == 1) {
			dice[i] = rand() % 6 + 1;
		}
		else {
			continue;
		}
	}
}

void printRollOptions(void) {
	printf("Press 1 to keep your dice:\n");
	printf("Press 2 to re-roll certain dice:\n");
	printf(">>> ");
}

void printScores(int *playerOne, int *playerTwo) {

	printf("Player 1:");
	for(int i = 0; i < MAXLENGTH; ++i) {
		printf(" | %d", playerOne[i]);
	}

	printf("\n");
	printf("Player 2:");
	for (int i = 0; i < MAXLENGTH; ++i) {
		printf(" | %d", playerTwo[i]);
	}
	printf("\n");

}

void parseRoll(int *scorecard, int *dice) {
	
}