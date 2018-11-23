#include "functions.h"


void printBorder(int size, int length) {

	switch (size) {
	case 1:
		for (int i = 0; i < length; ++i) {
			printf("-");
		}
		printf("\n");
		break;
	case 2:
		for (int i = 0; i < length; ++i) {
			printf("=");
		}
		printf("\n");
		break;
	}

}

int inputCheckCallback(int lowerBound, int upperBound, void(*printMenu)()) {
	int choice = 0;
	do {
		choice = 0;

		printMenu();
		scanf("%d", &choice);

		if (choice < lowerBound || choice > upperBound) {
			system("cls");
			printMessage("That's not a valid option. Try again.");
		}
		else {
			break;
		}

	} while (choice != upperBound);

	return choice;
}

int inputCheck(int lowerBound, int upperBound) {
	int choice = 0;
	do {
		choice = 0;
		printf(">>> ");
		scanf("%d", &choice);

		if (choice < lowerBound || choice > upperBound) {
			system("cls");
			printMessage("That's not a valid option. Try again.");
		}
		else {
			break;
		}

	} while (choice != upperBound);

	return choice;
}

void printMessage(char *message) {

	int length = strlen(message) + 6;

	printBorder(2, length);
	printf("|| %s ||\n", message);
	printBorder(2, length);
}

// New Player
void newPlayer(Player *p) {
	for (int i = 0; i < NUMCARDS; ++i) {
		p->hand[i].face = 0;
		p->hand[i].suit = 0;
	}

	for (int i = 0; i < NUMHANDS; ++i) {
		p->options[i] = 0;
		p->precedence[i] = 1;
	}

	for (int i = 0; i < NUMFACES; ++i) p->numFaces[i] = 0;

	for (int i = 0; i < NUMSUITS; ++i) p->numSuits[i] = 0;

	for (int i = 0; i < 3; ++i) p->switcherooni[i] = -1;

	p->score = 0;
	p->chosenHand = 0;
}

/* shuffle cards in deck */
void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Player *p, Player *c)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					
	// Deal Player's Hand
	for (card = 0; card < 5; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card + 1)
				{
					p->hand[card].face = column;
					p->hand[card].suit = row;
					//printf("%s of %-8s%c", wFace[p->hand[card].face], wSuit[p->hand[card].suit], (card + 1) % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}

	//printf("\n");

	// Deal Computer's hand
	for(card = 5; card < 10; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card + 1)
				{
					/* Card - 5 is so we can assign cards 5-10 to indexes 0-4 in the computer's hand array*/
					c->hand[card - 5].face = column;
					c->hand[card - 5].suit = row;
					// printf("%s of %-8s%c", wFace[c->hand[card - 5].face], wSuit[c->hand[card - 5].suit], (card) % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}

int parseCards(Player *p) {

	for(int i = 0; i < NUMCARDS; ++i) {
		p->numFaces[p->hand[i].face]++;
		p->numSuits[p->hand[i].suit]++;
	}

	determineOptions(p);
}

int arrayContains(int *array, int length, int num) {

	int occurrences = 0;
	
	for (int i = 0; i < length; ++i) {
		if (array[i] == num) {
			++occurrences;
		}
	}

	return occurrences;
}

void determineOptions(Player *p) {

	p->options[0] = 1;
	p->options[1] = checkForPair(p);
	p->options[2] = checkForTwoPairs(p);
	p->options[3] = checkFor3OAK(p);
	p->options[4] = checkFor4OAK(p);
	p->options[5] = checkForFlush(p);
	p->options[6] = checkForStrait(p);

}

int checkForPair(Player *p) {
	int pair = 0;

	int occurrences = 0;

	// Checks if just one pair. Eg, 2x Js and 3 other cards
	occurrences = arrayContains(p->numFaces, NUMFACES, 2);
	
	// Checks for 3 of a kind
	occurrences = occurrences || arrayContains(p->numFaces, NUMFACES, 3);
	
	// Checks for 4 of a kind
	occurrences = occurrences || arrayContains(p->numFaces, NUMFACES, 4);

	pair = (occurrences ? 1 : 0);

	return pair;
}

int checkForTwoPairs(Player *p){
	
	int twoPairs = 0;

	// Checks if three of one kind and 2 of another. Eg, 3x Js and 2x 9s
	twoPairs = arrayContains(p->numFaces, NUMFACES, 3) == 1 && arrayContains(p->numFaces, NUMFACES, 2) == 1;

	// Checks if 2 of one, 2 of an other, and 1 of another. Eg, 2x Js, 2x 9s, and an ace
	twoPairs = twoPairs || arrayContains(p->numFaces, NUMFACES, 2) == 2;
	
	// Checks if 4 of a kind and one of an other one. Eg, 4x Js and a 9
	twoPairs = twoPairs || arrayContains(p->numFaces, NUMFACES, 4);

	twoPairs = (twoPairs) ? 1 : 0;
	
	return twoPairs;
}

int checkFor3OAK(Player *p) {
	
	int threeOAK = 0;

	// Checks for 3 of a kind
	threeOAK = arrayContains(p->numFaces, NUMFACES, 3);

	// Checks for 4 of a kind
	threeOAK = threeOAK || arrayContains(p->numFaces, NUMFACES, 4);

	threeOAK = (threeOAK) ? 1 : 0;

	return threeOAK;
}

int checkFor4OAK(Player *p) {

	int fourOAK = 0;

	fourOAK = arrayContains(p->numFaces, NUMFACES, 4);

	fourOAK = (fourOAK) ? 1 : 0;

	return fourOAK;

}

int checkForFlush(Player *p) {

	int flush = 0;

	flush = arrayContains(p->numSuits, NUMSUITS, 5);

	flush = flush ? 1 : 0;

	return flush;

}

int checkForStrait(Player *p) {

	int strait = 0;

	for (int i = 0; i < NUMFACES - 4; ++i) {
		if (p->numFaces[i] == 1) {
			for (int j = 1; j < 5; ++j) {
				if (p->numFaces[i + j] == 1) {
					strait = 1;
					continue;
				}
				else {
					strait = 0;
					break;
				}
			}
		}
		if (strait == 1) break;
	}

	strait = strait ? 1 : 0;

	return strait;

}

void newTestingBoi(Player *p) {

	newPlayer(p);

	int testFaces[] = { 3, 5, 6, 7, 12 };
	int testSuits[] = { 2, 0, 3, 3, 1 };

	for (int i = 0; i < NUMCARDS; ++i) {
		p->hand[i].face = testFaces[i];
		p->hand[i].suit = testSuits[i];
	
	}

	for (int i = 0; i < NUMHANDS; ++i) p->precedence[i] = 1;

}

void printCards(const int wDeck[][13], const char *wFace[], const char *wSuit[], Player *p) {

	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	printf("=============== Your Cards ===============\n");
	for (card = 0; card < 5; card++) {
		printf("%5s of %-8s%c", wFace[p->hand[card].face], wSuit[p->hand[card].suit], (card + 1) % 2 == 0 ? '\n' : '\t');

	}
	printf("\n");
	printBorder(2, 42);


}

void askToSwitch(const int wDeck[][13], const char *wFace[], const char *wSuit[], Player *p) {
	
	printCards(wDeck, wFace, wSuit, p);

	int  indexSwitch = 0;

	do {

		printf("Do you want to switch any of your cards?\n");
		printf("Press 0 to skip: \nPress 1 to replace certain cards:\n");

		if (inputCheck(0, 1) == 0) break;

		printf("Alright, now you get to switch up to 3 of your cards out for random cards.\n");

		for (int i = 0, k = 0; i < 5; ++i) {
			
			printf("Card #%d: Press 0 to keep or 1 to replace.\n", i + 1);
			
			indexSwitch = inputCheck(0, 1);

			if (indexSwitch == 1) {
				p->switcherooni[k] = i;
				++k;
			}
			
		}
		reDraw(wDeck, wFace, wSuit, p);



	} while (0 == 1);

}

void reDraw(const int wDeck[][13], const char *wFace[], const char *wSuit[], Player *p) {
	for (int card = 10, k = 0; card < 13; card++)
	{
		/* loop through rows of wDeck */
		for (int row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (int column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card + 1)
				{
					if (p->switcherooni[k] != -1) {

						p->hand[(p->switcherooni[k])].face = column;
						p->hand[(p->switcherooni[k])].suit = row;

					}
	
					++k;
					//printf("%s of %-8s%c", wFace[p->hand[card].face], wSuit[p->hand[card].suit], (card + 1) % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}

void printOptions(Player *p, const int wDeck[][13], const char *wFace[], const char *wSuit[], const char *handOptions[]) {

	system("cls");

	int choice = 0;

	printCards(wDeck, wFace, wSuit, p);	
	do {
				
		printf("\nHere are your options:\n");

		for (int i = 0; i < NUMHANDS; ++i) {
			printf("Press %d for%s", i + 1, ": ");
			printf("%s\n", (p->options[i] ? handOptions[i] : "XXXXXX"));
		}
		printf(">>> ");
		scanf("%d", &choice);

		if (choice > 7 || choice < 1 || p->options[choice - 1] != 1) {
			system("cls");
			printMessage("That is not a valid option");
			printCards(wDeck, wFace, wSuit, p);
		}

	} while (choice > 7 || choice < 1 || p->options[choice - 1] != 1);

	p->chosenHand = choice - 1;

}

void computerTurn(Player *c) {
	
	for (int i = 0; i < NUMHANDS; ++i) {
		if (c->options[NUMHANDS - 1 - i] == 1) {
			c->chosenHand = NUMHANDS - 1 - i;
			break;
		}
	}


}

int compareHands(Player *p, Player *c) {
	
	int playerWon = p->chosenHand > c->chosenHand ? 1 : 0;

	p->score += playerWon == 1 ? 1 : 0;
	c->score += playerWon == 1 ? 0 : 1;

	return playerWon;
}

void gameLoop(const int wDeck[][13], const char *wFace[], const char *wSuit[], const char *handOptions[], Player *p, Player *c) {
	char *winnerName;

	int winner;
	
	system("cls");

	shuffle(wDeck);
	deal(wDeck, wFace, wSuit, p, c);

	askToSwitch(wDeck, wFace, wSuit, p);

	parseCards(p);
	parseCards(c);

	printOptions(p, wDeck, wFace, wSuit, handOptions);

	computerTurn(c);

	winnerName = compareHands(p, c) == 1 ? "Player" : "Computer";

	printf("The winner is: %s.\n", winnerName);



	printf("================= Score ==================\n");

	printf("Player: %d\n", p->score);
	printf("Computer: %d\n", c->score);
}

void resetDeck(int wDeck[][13]) {
	for (int r = 0; r <= 3; ++r) {
		for (int c = 0; c <= 12; ++c) {
			wDeck[r][c] = 0;
		}
	}

}