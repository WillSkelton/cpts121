#include "functions.h"

int gameLoop(void) {

	srand((unsigned int)time(NULL));

	double accountBalance = 0.0;
	
	do {
		accountBalance = getAccountBalance();

		if (accountBalance <= 0.0) printf("Excuse me, you can't play if you don't have any money. Lets try again.\n");

	} while (accountBalance <= 0.0);

	int choice = 0;

	do {
		showMenu();
		printf(">>> ");
		scanf("%d", &choice);

		switch (choice) {

		case 1:
			showRules();
			break;

		case 2:
			accountBalance += playGame(accountBalance);
			break;

		case 3:
			printf("You have $%.2f left in your account.\n", accountBalance);
			break;

		case 4:
			printf("Goodbye!\n");
			break;

		default:
			printf("Invalid input, try again.\n");
			break;

		}
	}	while (choice != 4);
	
	return 0;
}

void showMenu(void) {
	printf("Press 1 to show the menu: \n");
	printf("Press 2 to start the game: \n");
	printf("Press 3 to show your account balance: \n");
	printf("Press 4 to cash out: \n");
}


void showRules(void) {
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

	printf("> You rolled a %d and a %d.\n", d1, d2);

	sum = d1 + d2;

	return sum;
}

double playGame(double accountBalance) {
	double winnings = 0.0, wager = 0.0;
	
	int diceSum = 0, mark = 0.0;

	int lost = 0, won = 0;

	printf("================================================ Time's up! Lets do this! ==============================================\n");

	wager = getWager(accountBalance);

	diceSum = rollDice();

	if (diceSum == 7 || diceSum == 11) {
		printf("> NICE! You win.\n");
		winnings += wager;
		printf("> You won $%.2lf.\n", winnings);

	}

	else if (diceSum == 2 || diceSum == 3 || diceSum == 12) {
		printf("> Sorry, you lose!\n");
		winnings -= wager;
		printf("> You lost $%.2lf.\n", winnings);
	}

	else {
		mark = diceSum;
		
		printf("> Alright, Your mark is %d.\n", mark);
		printf("> Now, you'll keep rolling until you roll a %d and you win or a 7 or 11 and you lose.\n", mark);

		do {
			diceSum = rollDice();

			if (diceSum == mark) {
				printf("> NICE! You win.\n");
				winnings += wager;
				printf("> You won $%.2lf.\n", winnings);
				break;
			} 
			else if (diceSum == 7 || diceSum == 11) {
				printf("> Sorry, you lose!\n");
				winnings -= wager;
				printf("> You lost $%.2lf.\n", winnings);
				break;

			}
			else {
				printf("> Rolling again...\n");
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