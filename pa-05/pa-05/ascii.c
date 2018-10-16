#include "functions.h"
#include "ascii.h"

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

void printRoll(int *dice) {

	//printf("%d", dice[0]);

	int die = 0;

	for (int i = 0; i < 5; ++i) {
		die = dice[i];
		printf("Die number %d\n", i + 1);
		printDice(die);
	}
}

void printBorder(int size, int length) {

	switch (size) {
	case 1:
		for (int i = 0; i < length; ++i) {
			printf("-");
			printf("\n");
		}
		break;
	case 2:
		for (int i = 0; i < length; ++i) {
			printf("=");
		}
		printf("\n");
		break;
	}
	
}