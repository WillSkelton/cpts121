#include "functions.h"
#define MAXLENGTH 13
#define NUMDICE 5
#define NUMROUNDS 13

int gameLoop(void) {

	int playerOne[MAXLENGTH] = { 0 };
	int playerTwo[MAXLENGTH] = { 0 };
	
	resetScorecard(playerOne);
	resetScorecard(playerTwo);

	int playerOneTotal = 0, playerTwoTotal = 0;
	

	int choice = 0, round = 0;

	do {
		choice = inputCheck(1, 5, printMenu);

		switch (choice) {
		
		case 1:
			system("cls");
			printRules();
			break;

		case 2:
			system("cls");
			printf("=============== Time's up. Let's do this! ===============\n");

			++round;

			playGame(playerOne, playerTwo);

			break;

		case 3:
			system("cls");
			printf("================================================= Score =================================================\n");

			playerOneTotal = getScoreTotal(playerOne);
			playerTwoTotal = getScoreTotal(playerTwo);
			printf("Player    | 1s | 2s | 3s | 4s | 5s | 6s | 3x | 4x | FH | SS | LS | YZ | CH | Total:\n");
			printf("Player 1:");
			printScores(playerOne, playerOneTotal);
			
			printf("Player 2:");
			printScores(playerTwo, playerTwoTotal);

			printBorder(2, 105);

			break;

		case 4:
			system("cls");
			break;

		case 5:
			break;

		default:
			system("cls");
			printBorder(2, 45);
			printf("%d? That's not a valid option. Try again.\n", choice);
			printBorder(2, 45);

		}

	} while (choice != 5 && round < NUMROUNDS);

	playerOneTotal = getScoreTotal(playerOne);
	playerTwoTotal = getScoreTotal(playerTwo);

	printf("Player 1:");
	printScores(playerOne, playerOneTotal);

	printf("Player 2:");
	printScores(playerTwo, playerTwoTotal);

	printBorder(2, 105);

	printf("Goodbye!\n");


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
	printf("Here's how this works. You and your friend will take turns rolling dice. The Oldest will be player one\n");
	printf("and the youngest will be player two. You will each roll 13 times. Each roll, you may choose to reroll\n");
	printf("any of the dice up to three times. Once you're happy with your dice or you've rolled 3 times, you will\n");
	printf("pick one of the combinations in the table below. If you have the dice, you get the number of points listed.\n");
	printf("Otherwise, you will get a zero. Either way, you won't be able to use that combination any more, so choose wisely\n");
	printf("At the end of the 13th round, the totals will be calculated and if you're score is above 64, you get an additional 35 points/\n");
	printf("==================================================\n");
	printf("|    Name    |   Combination   |      Score      |\n");
	printf("| ---------- | --------------- | --------------- |\n");
	printf("|   1s       | At least one 1  | Sum of all 1s   |\n");
	printf("| ---------- | --------------- | --------------- |\n");
	printf("|   2s       | At least one 2  | Sum of all 2s   |\n");
	printf("| ---------- | --------------- | --------------- |\n");
	printf("|   3s       | At least one 3  | Sum of all 3s   |\n");
	printf("| ---------- | --------------- | --------------- |\n");
	printf("|   4s       | At least one 4  | Sum of all 4s   |\n");
	printf("| ---------- | --------------- | --------------- |\n");
	printf("|   5s       | At least one 5  | Sum of all 5s   |\n");
	printf("| ---------- | --------------- | --------------- |\n");
	printf("|   6s       | At least one 6  | Sum of all 6s   |\n");
	printf("| ---------- | --------------- | --------------- |\n");
	printf("|  Three of  | 3 dice of the   | Sum of all dice |\n");
	printf("|  a kind    | same face       |                 |\n");
	printf("| ---------- | --------------- | --------------- |\n");
	printf("|  Four of   | 4 dice of the   | Sum of all dice |\n");
	printf("|  a kind    | same face       |                 |\n");
	printf("| ---------- | --------------- | --------------- |\n");
	printf("| Full House | One pair and 3  |       25        |\n");
	printf("|            | of a kind       |                 |\n");
	printf("| ---------- | --------------- | --------------- |\n");
	printf("|   Small    | A consecutive   |       30        |\n");
	printf("|  Straight  | set of 4 dice   | EG: 1, 2, 3, 4  |\n");
	printf("| ---------- | --------------- | --------------- |\n");
	printf("|   Large    | A set of 5 dice |       40        |\n");
	printf("|  Straight  |                 |                 |\n");
	printf("| ---------- | --------------- | --------------- |\n");
	printf("|  Yahtzee   | 5 of a kind     |       50        |\n");
	printf("| ---------- | --------------- | --------------- |\n");
	printf("|  Chance    | Whatever. Dude, | Sum of all dice |\n");
	printf("|            | I don't care    |                 |\n");
	printf("| ---------- | --------------- | --------------- |\n");
	printBorder(2, 50); 
}

int playGame(int *playerOne, int *playerTwo) {

	printf("============================== Player 1 ==============================\n");
	playerRoll(playerOne);
	printBorder(2, 70);

	system("pause");
	system("cls");

	printf("============================== Player 2 ==============================\n");
	playerRoll(playerTwo);
	printBorder(2, 70);

	system("pause");
	system("cls");

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
		int stopReRolling = 0;

	case 1:
		break;

	case 2:
		
		do {
			++*numberOfReRolls;

			printf("Select which dice re-roll by entering 1 for a re-roll or 0 to keep.\n");
			
			for (int i = 0; i < 5; ++i) {
				printf("die #%d: ", i + 1);
				scanf("%d", &reRoll[i]);
			}

			system("cls");
			reRollDice(dice, reRoll);
			printRoll(dice);

			if (*numberOfReRolls < 3) {
				stopReRolling = inputCheck(1, 2, printRollOptions);

				if (stopReRolling == 1) break;
			}

		} while (*numberOfReRolls < 3);

		break;

	default:
		system("cls");
		printBorder(2, 45);
		printf("%d? That's not a valid option. Try again.\n", *choice);
		printBorder(2, 45);

		printRoll(dice);

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
		printRoll(dice);
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

void printScores(int *player, int total) {

	for (int i = 0; i < MAXLENGTH; ++i) {
		if (player[i] == -1) {
			printf(" | 00", player[i]);

		}
		else {
			printf(" | %d", player[i]);
		}
	}
	printf(" | Total: %d ", total);
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
			sum += 0;
		}
		else {
			sum += scorecard[i];
		}
	}

	if (sum > 63) {
		sum += 35;
	}

	return sum;
}