#include "functions.h"
#define MAXLENGTH 13
#define NUMDICE 5

int gameLoop(void) {

	int playerOne[MAXLENGTH] = { 0 };
	int playerTwo[MAXLENGTH] = { 0 };
	
	resetScorecard(playerOne);
	resetScorecard(playerTwo);

	int playerOneTotal = 0, playerTwoTotal = 0;
	

	int choice = 0;

	do {
		choice = inputCheck(1, 5, printMenu);

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
			playerOneTotal = getScoreTotal(playerOne);
			playerTwoTotal = getScoreTotal(playerTwo);
			printScores(playerOne, playerOneTotal, playerTwo, playerTwoTotal);
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

	
	for (int i = 0; i < 1; ++i) {

		playerRoll(playerOne);
		playerRoll(playerTwo);
	}
	int round = 0;

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
		printRoll(dice);
		choice = inputCheck(1, 2, printRollOptions);

		reRollLoop(&choice, &numberOfReRolls, dice, reRoll);

	} while (choice != 1 && choice != 2);

	parseRoll(scorecard, dice);

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

void parseRoll(int *scorecard, int *dice) {
	int j = 0;

	/*for (int i = 0; i < 5; ++i) {
		printf(">>> ");
		scanf("%d", &j);
		dice[i] = j;
	}*/

	int results[NUMDICE + 2] = { 0 };

	for (int i = 0; i < NUMDICE; ++i) {
		++results[dice[i]];
	}

	verifyResults(dice, results, scorecard);
}

void verifyResults(int *dice, int *results, int *scorecard) {
	system("cls");
	printRoll(dice);
	int faceSum = arraySum(dice, NUMDICE);

	int choice = inputCheck(1, 13, printCombinationOptions);
	
	//("%d", scorecard[12])

	while (scorecard[choice-1] != -1) {
		system("cls");
		printBorder(2, 57);
		printf("Please pick a different option.\n");
		printBorder(2, 57);
		choice = inputCheck(1, 13, printCombinationOptions);
		continue;
		
	}
	
	switch (choice) {
	case 1: // Sum of 1s
		scorecard[choice - 1] = (1 * results[choice]);
		break;

	case 2: // Sum of 2s
		scorecard[choice - 1] = (2 * results[choice]);
		break;

	case 3: // Sum of 3s
		scorecard[choice - 1] = (3 * results[choice]);
		break;

	case 4: // Sum of 4s
		scorecard[choice - 1] = (4 * results[choice]);
		break;

	case 5: // Sum of 5
		scorecard[choice - 1] = (5 * results[choice]);
		break;

	case 6: // Sum of 6s
		scorecard[choice - 1] = (6 * results[choice]);
		break;

	case 7: // 3 of a kind
		if (arrayContains(3, results, NUMDICE + 2) == 1) {
			scorecard[choice - 1] = faceSum;
		}
		else {
			scorecard[choice - 1] = 0;
		}
		break;

	case 8: // 4 of a kind
		if (arrayContains(4, results, NUMDICE + 2) == 1) {
			scorecard[choice - 1] = faceSum;
		}
		else {
			scorecard[choice - 1] = 0;
		}
		break;

	case 9: // Full House
		if (arrayContains(2, results, NUMDICE + 2) == 1 && arrayContains(3, results, NUMDICE + 2) == 1) {
			scorecard[choice - 1] = 25;
		}
		else {
			scorecard[choice - 1] = 0;
		}
		break;

	case 10: // small straight
		if (results[1] == 0 && results[2] == 0) {
			scorecard[choice - 1] = 30;
		}
		else if (results[6] == 0 && results[6] == 0) {
			scorecard[choice - 1] = 30;
		}
		else if (results[1] == 0 && results[6] == 0) {
			scorecard[choice - 1] = 30;
		}
		else {
			scorecard[choice - 1] = 0;
		}
		break;

	case 11: // large straight
		if (results[1] == 0) {
			scorecard[choice - 1] = 40;
		}
		else if (results[6] == 0) {
			scorecard[choice - 1] = 40;
		}
		else {
			scorecard[choice - 1] = 0;
		}
		break;

	case 12: // Yahtzee

		if (arrayContains(5, results, NUMDICE + 2) == 1) {
			scorecard[choice - 1] = 50;
		}
		else {
			scorecard[choice - 1] = 0;
		}
		break;

	case 13: // Chance
		scorecard[choice - 1] = faceSum;
		break;
	}

	

}

int arrayContains(int search, int *array, int arrLen) {
	int flag = 0;

	for (int i = 0; i < arrLen; ++i) {
		if (array[i] == search) {
			flag = 1;
			break;
		}
	}

	return flag;
}

void printCombinationOptions(void) {
	printf("Press 1 for sum of 1s: \n");
	printf("Press 2 for sum of 2s: \n");
	printf("Press 3 for sum of 3s: \n");
	printf("Press 4 for sum of 4s: \n");
	printf("Press 5 for sum of 5s: \n");
	printf("Press 6 for sum of 6s: \n");
	printf("Press 7 for 3 of a kind: \n");
	printf("Press 8 for 4 of a kind: \n");
	printf("Press 9 for a full house: \n");
	printf("Press 10 for a small straight: \n");
	printf("Press 11 for a large straight: \n");
	printf("Press 12 for Yahtzee: \n");
	printf("Press 13 for Chance: \n");
	printf(">>> ");
}

void printScores(int *playerOne, int p1Total, int *playerTwo, int p2Total) {

	printf("Player 1:");
	for (int i = 0; i < MAXLENGTH; ++i) {
		printf(" | %d", playerOne[i]);
	}
	printf(" | Total: %d |", p1Total);
	printf("\n");

	printf("Player 2:");
	for (int i = 0; i < MAXLENGTH; ++i) {
		printf(" | %d", playerTwo[i]);
	}
	printf(" | Total: %d |", p2Total);

	printf("\n");

}

int inputCheck(int lowerBound, int upperBound, void(*printMenu)()) {
	int choice = 0;
	do {
		choice = 0;

		// TODO: system("cls");
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

int arraySum(int *array, int len) {

	int sum = 0;
	for (int i = 0; i < len; ++i) {
		sum += array[i];
	}

	return sum;
}

void resetScorecard(int *scorecard) {
	for (int i = 0; i < 13; ++i) {
		scorecard[i] = -1;
	}
}

int getScoreTotal(int *scorecard) {
	int sum = 0;
	for (int i = 0; i < 13; ++i) {
		if (scorecard[i] == -1) {
			scorecard[i] = 0;
		}
		sum += scorecard[i];
	}

	return sum;
}