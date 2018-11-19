#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

#define NUMCARDS 5

typedef struct Card {
	int face;
	int suit;
} Card;

typedef struct Player {
	Card hand[5];
	int options[6];
	int numFaces[13];
	int numSuits[4];
	int score;

} Player;

/* shuffle cards in deck */
void shuffle(int wDeck[][13]);

/* deal cards in deck */
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Player *p, Player *c);

void newPlayer(Player *p);

int parseCards(Player *p);