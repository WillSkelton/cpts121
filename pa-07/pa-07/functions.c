#include "functions.h"

// New Player
void newPlayer(Player *p) {
	for (int i = 0; i < 5; ++i) {
		p->hand[i].face = 0;
		p->hand[i].suit = 0;
	}

	for (int i = 0; i < 6; ++i) {
		p->options[i] = 0;
	}

	for (int i = 0; i < 13; ++i) {
		p->numFaces[i] = 0;
	}

	for (int i = 0; i < 4; ++i) {
		p->numSuits[i] = 0;
	}

	p->score = 0;
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
					printf("%5s of %-8s%c", wFace[p->hand[card].face], wSuit[p->hand[card].suit], (card + 1) % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}

	printf("\n");
	// Deal Computer's hand
	for(card = 0; card < 5; card++)
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
					c->hand[card].face = column;
					c->hand[card].suit = row;
					//printf("%5s of %-8s%c", wFace[c->hand[card].face], wSuit[c->hand[card].suit], (card + 1) % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
	printf("done!");
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

	p->options[0] = checkForPair(p);
	p->options[1] = checkForTwoPairs(p);
	p->options[2] = checkFor3OAK(p);
	p->options[3] = checkFor4OAK(p);
	p->options[4] = checkForFlush(p);
	p->options[5] = checkForStrait(p);

}

int checkForPair(Player *p) {
	int pair = 0;

	int occurrences = arrayContains(p->numFaces, NUMFACES, 2);
	occurrences = occurrences || arrayContains(p->numFaces, NUMFACES, 3);
	occurrences = occurrences || arrayContains(p->numFaces, NUMFACES, 4);

	pair = (occurrences ? 1 : 0);

	return pair;
}

int checkForTwoPairs(Player *p){
	
	int twoPairs = 0;

	twoPairs = arrayContains(p->numFaces, NUMFACES, 3) == 1 && arrayContains(p->numFaces, NUMFACES, 2) == 1;

	twoPairs = twoPairs || arrayContains(p->numFaces, NUMFACES, 2) == 2;
	
	twoPairs = twoPairs || arrayContains(p->numFaces, NUMFACES, 4);

	twoPairs = (twoPairs) ? 1 : 0;
	
	return twoPairs;
}

int checkFor3OAK(Player *p) {}

int checkFor4OAK(Player *p) {}

int checkForFlush(Player *p) {}

int checkForStrait(Player *p) {}

void newTestingBoi(Player *p) {

	newPlayer(p);

	int testFaces[] = { 9, 9, 9, 9, 3 };
	int testSuits[] = { 0, 1, 2, 3, 3 };

	for (int i = 0; i < 5; ++i) {
		p->hand[i].face = testFaces[i];
		p->hand[i].suit = testSuits[i];
	}

}

void printCards(const int wDeck[][13], const char *wFace[], const char *wSuit[], Player *p) {

	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */


					// Deal Player's Hand
	for (card = 0; card < 5; card++) {
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++) {
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++) {
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card + 1) {
					printf("%5s of %-8s%c", wFace[p->hand[card].face], wSuit[p->hand[card].suit], (card + 1) % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}