#include "functions.h"

int gameLoop(void) {

	srand((unsigned int)time(NULL));

	double accountBalance = 0.0;
	
	do {
		accountBalance = getAccountBalance();

		if (accountBalance <= 0.0) printf("Excuse me, you can't play if you don't have any money. Lets try again.\n");

	} while (accountBalance <= 0.0);

	system("cls");

	int choice = 0;

	do {

		if (accountBalance <= 0.0) {
			system("cls");
			printf(">>> You've run out of money and must leave. Goodbye!\n");
			break;
		}

		showMenu();
		printf(">>> ");
		scanf("%d", &choice);

		switch (choice) {

		case 1:
			showRules();
			break;

		case 2:
			accountBalance += playGame(accountBalance);
			system("cls");
			break;

		case 3:
			system("cls");
			printf("----------------------------------------------\n");
			printf("You have $%.2f left in your account.\n", accountBalance);
			printf("----------------------------------------------\n");
			break;

		case 4:
			system("cls");
			break;

		case 5:
			system("cls");
			printf("Goodbye!\n");
			break;


		default:
			printf("Invalid input, try again.\n");
			break;

		}
	}	while (choice != 5);
	
	return 0;
}

void showMenu(void) {

	printf("Press 1 to show the rules: \n");
	printf("Press 2 to start the game: \n");
	printf("Press 3 to show your account balance: \n");
	printf("Press 4 to clear the screen: \n");
	printf("Press 5 to cash out: \n");
}

void showRules(void) {
	system("cls");
	printf("========================================================= Rules ========================================================\n");
	printf("1.) Roll Dice\n");
	printf("2.) If the sum of the dice is 7 or 11, then you win.\n");
	printf("3.) If the sum is 2, 3, or 12, you lose.\n");
	printf("4.) If the sum is 4, 5, 6,8, 9, or 10, that's your new goal. You have to keep rolling until you get that.\n");
	printf("  * Note: if you roll a 7 or 11 after the first roll, you lose\n");
	printf("========================================================================================================================\n");

}

int rollDice(void) {
	int d1 = 0, d2 = 0, sum = 0;

	d1 = rand() % 6 + 1;
	d2 = rand() % 6 + 1;

	sum = d1 + d2;

	printf("> Sum: %d\n\n", sum);
	printf("> Rolling...\n");

	printDice(d1);
	printDice(d2);

	printf("-------------------------------------------\n");
	printf("> You rolled a %d and a %d.\n", d1, d2);

	return sum;
}

double playGame(double accountBalance) {

	system("cls");

	double winnings = 0.0, wager = 0.0;
	
	int diceSum = 0, mark = 0, rollCount = 0;

	printf("================================================ Time's up! Lets do this! ==============================================\n");

	wager = getWager(accountBalance);

	system("cls");
	printf("> Roll Number: %d\n", ++rollCount);

	diceSum = rollDice();


	if (diceSum == 7 || diceSum == 11) {
		printf("> NICE! You win.\n");
		winnings += wager;
		printf("> You won $%.2lf.\n\n", winnings);
		system("pause");
	}

	else if (diceSum == 2 || diceSum == 3 || diceSum == 12) {
		printf("> Sorry, you lose!\n");
		winnings -= wager;
		printf("> You lost $%.2lf.\n\n", winnings);
		system("pause");
	}

	else {
		mark = diceSum;
		
		printf("------------------------------------------\n");
		printf("> Alright, Your mark is %d.\n", mark);
		printf("> Now, you'll keep rolling until you roll a %d and you win or a 7 or 11 and you lose.\n", mark);

		do {

			Sleep(2000);

			system("cls");
			printf("> Roll Number %d:\n", ++rollCount);
			printf("> Mark: %d\n", mark);

			diceSum = rollDice();


			if (diceSum == mark) {
				printf("> NICE! You win.\n");
				winnings += wager;
				printf("> You won $%.2lf.\n\n", winnings);
				system("pause");
				break;
			} 
			else if (diceSum == 7 || diceSum == 11) {
				printf("> Sorry, you lose!\n");
				winnings -= wager;
				printf("> You lost $%.2lf.\n\n", winnings);
				system("pause");
				break;

			}
			else {
				continue;
			}

		} while (diceSum != 7 || diceSum != 11 || diceSum != mark);
	}

	printf("========================================================================================================================\n");

	return winnings;
}

double getAccountBalance(void) {
	double accountBalance = 0.0;

	printf("Now, before we get started, we need to know how much you have in \nyour bank account. (It has to be greater than $0.00): ");

	scanf(" %lf", &accountBalance);

	if (accountBalance < 1000 && accountBalance > 0.0) printf("$%.2lf? You probably shouldn't be gambling but I'm not your mom.\n", accountBalance);

	return accountBalance;
}

double getWager(double accountBalance) {
	
	double wager = 0;
	
	printf("You have $%.2f left in your account.\n", accountBalance);

	do {

		printf("How much money do you want to wager?: ");
		scanf(" %lf", &wager);

		if (wager > accountBalance) {
			printf("You don't have enough money to wager that much. Try again. \n");
		}

	} while (wager > accountBalance);

	return wager;
}

void printDice(int num) {

	switch (num) {

	case 1:
		printf(" _________\n");
		printf("|         |\n");
		printf("|    O    |\n");
		printf("|         |\n");
		printf("|_________|\n");
		break;

	case 2:
		printf(" _________\n");
		printf("| O       |\n");
		printf("|         |\n");
		printf("|       O |\n");
		printf("|_________|\n");
		break;

	case 3:
		printf(" _________\n");
		printf("| O       |\n");
		printf("|    O    |\n");
		printf("|       O |\n");
		printf("|_________|\n");
		break;

	case 4:
		printf(" _________\n");
		printf("| O     O |\n");
		printf("|         |\n");
		printf("| O     O |\n");
		printf("|_________|\n");
		break;

	case 5:
		printf(" _________\n");
		printf("| O     O |\n");
		printf("|    O    |\n");
		printf("| O     O |\n");
		printf("|_________|\n");
		break;

	case 6:
		printf(" _________\n");
		printf("| O     O |\n");
		printf("| O     O |\n");
		printf("| O     O |\n");
		printf("|_________|\n");
		break;


	}
}