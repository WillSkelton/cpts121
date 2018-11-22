#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

#define NUMCARDS 5
#define NUMFACES 13
#define NUMSUITS 4
#define NUMHANDS 7

typedef struct Card {
	int face;
	int suit;
} Card;

typedef struct Player {
	Card hand[5];
	int options[NUMHANDS];
	int numFaces[13];
	int numSuits[4];
	int score;

} Player;

/* shuffle cards in deck */
void shuffle(int wDeck[][13]);

/* deal cards in deck */
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Player *p, Player *c);

//Initializes player
void newPlayer(Player *p);

// counts the number of each face and suit in a player's hand
int parseCards(Player *p);

// searches an array for a given value and returns the number of occurences of that number
int arrayContains(int *array, int length, int num);

void determineOptions(Player *p);

int checkForPair(Player *p);

int checkForTwoPairs(Player *p);

int checkFor3OAK(Player *p);

int checkFor4OAK(Player *p);

int checkForFlush(Player *p);

int checkForStrait(Player *p);

void newTestingBoi(Player *p);

void printCards(const int wDeck[][13], const char *wFace[], const char *wSuit[], Player *p);

void printOptions(Player *p, const int wDeck[][13], const char *wFace[], const char *wSuit[], const char *handOptions[]);

void printBorder(int size, int length);

int inputCheck(int lowerBound, int upperBound, void(*printMenu)());

void printMessage(char *message);