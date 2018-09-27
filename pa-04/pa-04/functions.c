#include "functions.h"

int gameLoop(void) {

	int choice = 0;

	while (choice >= 0) {
		printf("Press 1 to show the menu: \n");
		printf(">>> ");
		scanf("%d", &choice);

		if (choice == 1) {
			showRules();
		}
		else if (choice < 0) {
			printf("Goodbye!\n");
		}

	}

}

void showRules(void) {
	printf("========================================================= Rules ========================================================\n");
	printf("1.) Pick a number\n");
	printf("2.) Roll Dice\n");
	printf("  i.) If the sum of the dice is 7 or 11, then you win.\n");
	printf("  ii.) If the sum is 2, 3, or 12, you lose.\n");
	printf("  iii.) If the sum is 4, 5, 6,8, 9, or 10, add that sum to your score until you hit your mark. Skip to step 3.\n");
	printf("    * Note: if you roll a 7 or 11 after the first roll, you lose\n");
	printf("3.) If you made it this far, keep rolling until you either hit your mark and you win or you roll a 7 or 11 and you lose.");
	printf("========================================================================================================================\n");

}

