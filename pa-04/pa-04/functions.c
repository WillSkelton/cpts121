#include "functions.h"

int gameLoop(void) {

	srand((unsigned int)time(NULL));

	double accountBalance = 0.0;

	int choice = 0;
	do {
		
		printf("Press 1 to show the menu: \n");
		printf("Press 2 to start the game: \n");
		printf("Press 3 to quit: \n");
		printf(">>> ");
		scanf("%d", &choice);

		switch (choice) {

		case 1:
			showRules();
			break;

		case 2:
			accountBalance = getAccountBalance();
			playGame(accountBalance);
			break;

		case 3:
			printf("Goodbye!\n");
			break;

		default:
			printf("Invalid input, try again.\n");
			break;

		}
	}	while (choice != 3);

}

void showRules(void) {
	printf("========================================================= Rules ========================================================");
	printf("1.) Pick a number\n");
	printf("2.) Roll Dice\n");
	printf("  i.) If the sum of the dice is 7 or 11, then you win.\n");
	printf("  ii.) If the sum is 2, 3, or 12, you lose.\n");
	printf("  iii.) If the sum is 4, 5, 6,8, 9, or 10, add that sum to your score until you hit your mark. Skip to step 3.\n");
	printf("    * Note: if you roll a 7 or 11 after the first roll, you lose\n");
	printf("3.) If you made it this far, keep rolling until you either hit your mark and you win or you roll a 7 or 11 and you lose.");
	printf("========================================================================================================================\n");

}

int rollDice(void) {
	int value = 0;

	value = rand() % 6 + 1;

	return value;
}

int playGame(double accountBalance) {

	printf("Alright! Lets do this!\n");

	printf("So as far as we can tell, you have $%.2lf in your bank account.\n", accountBalance);

	printf("die 1: %d\n", rollDice());
	printf("die 2: %d\n", rollDice());
}

double getAccountBalance(void) {
	double accountBalance = 0.0;
	printf("We need to know how much you have in your bank account: ");

	scanf(" %lf", &accountBalance);

	return accountBalance;
}