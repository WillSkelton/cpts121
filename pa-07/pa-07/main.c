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

	/* initalize deck array */
	int deck[4][13] = { 0 };

	srand((unsigned)time(NULL)); /* seed random-number generator */

	shuffle(deck);
	deal(deck, face, suit, &player, &computer);

	parseCards(&player);


	return 0;
}
