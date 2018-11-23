// Authors: Deitel & Deitel - C How to Program

#include "functions.h";

//void shuffle(int wDeck[][13]);
//void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[]);

int main(void)
{

	Player player;
	newPlayer(&player);

	Player computer;
	newPlayer(&computer);


	/* initialize suit array */
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char *face[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initialize face array */
	const char *handOptions[NUMHANDS] = { "Fold", "Pair", "2 Pairs", "3 of a Kind", "4 of a Kind", "Flush", "Strait" };



	/* initalize deck array */
	int deck[4][13] = { 0 };

	srand((unsigned)time(NULL)); /* seed random-number generator */


	for (int i = 0; i < NUMGAMES; ++i) {
		
		gameLoop(deck, face, suit, handOptions, &player, &computer);

		resetDeck(deck);
	}

	printf("================= Score ==================\n");

	printf("Player: %d\n", player.score);
	printf("Computer: %d\n", computer.score);

	printBorder(2, 42);

	// ====================== TEST ======================
	//Player TestingBoi;
	//newTestingBoi(&TestingBoi);

	//askToSwitch(deck, face, suit, &TestingBoi);

	//parseCards(&TestingBoi);

	//printOptions(&TestingBoi, deck, face, suit, handOptions);
	//// ====================== END TEST ======================


	/*shuffle(deck);
	deal(deck, face, suit, &player, &computer);*/



	//askToSwitch(deck, face, suit, &player);

	//parseCards(&player);
	//parseCards(&computer);

	//printOptions(&player, deck, face, suit, handOptions);
	//
	//computerTurn(&computer);

	//winner = compareHands(&player, &computer) == 1 ? "Player" : "Computer";

	//printf("The winner is: %s.\n", winner);

	return 0;
}
