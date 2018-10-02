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
		
		printf("Press 1 to show the menu: \n");
		printf("Press 2 to start the game: \n");
		printf("Press 3 to show your account balance: \n");
		printf("Press 4 to cash out: \n");
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
	int value = 0;

	value = rand() % 12 + 1;

	return value;
}

double playGame(double accountBalance) {
	double winnings = 0.0;
	
	int diceSum = 0;

	int lost = 0, won = 0;

	printf("================================================ Time's up! Lets do this! ==============================================\n");

	getWager(accountBalance);

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

		if (wager >= accountBalance) {
			printf("You don't have enough money to wager that much. Try again. \n");
		}

	} while (wager >= accountBalance);


}