#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

#define NUMCARDS 5
#define NUMFACES 13
#define NUMSUITS 4
#define NUMHANDS 7
#define NUMGAMES 10

// Card Definition
typedef struct Card {
	// index of the corresponding face and suit
	int face;
	int suit;
} Card;

// Player Definition
typedef struct Player {
	Card hand[NUMCARDS];     // Cards
	char *name;              // Player name
	int options[NUMHANDS];   // 7 element array that shows which hands the player can play
	int numFaces[NUMFACES];  // 13 element array that represents the number of each face value the player has in their hand.
	int numSuits[NUMSUITS];  // 4 element array that represents the number of each suit the player has
	int switcheroo[3];     // 3 element array that contains the indecies in the hand array to redraw
	int score;               // the number of times the player won
	int chosenHand;          // the hand that the player decided to play. eg: pair, flush, strait, etc


} Player;

// Prints a string of - or = of a given length
void printBorder(int size, int length);

// Checks to make sure user enters a valid number within the upper and lower bounds.
// Also Accepts a function that prints a menu or listof options as an argument
int inputCheckCallback(int lowerBound, int upperBound, void(*printMenu)());

// Checks to make sure user enters a valid number within the upper and lower bounds. NO CALLBACK FUNCTION
int inputCheck(int lowerBound, int upperBound);

// Prints a message wrapped in a box  made with = and ||
void printMessage(char *message);

// Initializes Player
void newPlayer(Player *p, char *name);

// Shuffles cards in deck. NOTE: DESK MUST BE RESET TO 0 OR FRESHLY INITIALIZED TO BE SHUFFLED.
// Credit to: Deitel & Deitel - C How to Program
void shuffle(int wDeck[][13]);

// Deal 5 cards to the player and 5 to the computer
// Credit to: Deitel & Deitel - C How to Program
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Player *u, Player *c);

// Traverses the card array of a given player and updates that player's numFaces and numSuits arrays
// so their cards can be analyzed. 
int parseCards(Player *p);

// Traverses an array of a given length and returns the number of times a given number is found
int arrayContains(int *array, int length, int num);

// Calls all the checkFor** functions and assigns the outputs to a player's options array
void determineOptions(Player *p);

// Checks the numFaces and numSuits arrays and returns a 1 if there is a pair and 0 if not
int checkForPair(Player *p);

// Checks the numFaces and numSuits arrays and returns a 1 if there are 2 pairs and 0 if not
int checkForTwoPairs(Player *p);

// Checks the numFaces and numSuits arrays and returns a 1 if there is 3 of a kind and 0 if not
int checkFor3OAK(Player *p);

// Checks the numFaces and numSuits arrays and returns a 1 if there is 4 of a kind and 0 if not
int checkFor4OAK(Player *p);

// Checks the numFaces and numSuits arrays and returns a 1 if there is a flush and 0 if not
int checkForFlush(Player *p);

// Checks the numFaces and numSuits arrays and returns a 1 if there is a strait and 0 if not
int checkForStrait(Player *p);

// Test player that can have be forced to have a specific hand to make testing easier. NOT ACTIVE.
void newTestingBoi(Player *p);

// Prints the name of a player and their cards
void printCards(const int wDeck[][13], const char *wFace[], const char *wSuit[], Player *p);

// Asks the player if they want to switch up to 3 cards. The indices of those cards in the card array is stored in the player's
// switcheroo array
void askToSwitch(const int wDeck[][13], const char *wFace[], const char *wSuit[], Player *u);

// Traverses a given player's switcheroo array and replaces the cards at those indecies
void reDraw(const int wDeck[][13], const char *wFace[], const char *wSuit[], Player *u);

// Prints the possible hands that the user can play, then stores that value on the user's chosenHand property
void printOptions(const int wDeck[][13], const char *wFace[], const char *wSuit[], const char *handOptions[], Player *u);

// Calculates the best hand that the computer can play and then stores that value on the computer's chosenHand property
void computerTurn(Player *c);

// Compares the user's and computer's chosenHand properties, increments score property of the winner, and then
// returns 1 if the player won and 0 if not. NOTE: The computer always win in the event of a tie.
int compareHands(Player *u, Player *c);

// Plays one round of the game
void oneRound(const int wDeck[][13], const char *wFace[], const char *wSuit[], const char *handOptions[], Player *u, Player *c);

// Resets the deck array to all 0s
void resetDeck(int wDeck[][13]);

// Resets a given player's round specific properties but not things like score and name
void resetPlayer(Player *p);

// These are pretty simple
void printTitle(void);

void printRules(void);

void printMainMenu(void);