#include "functions.h"
#include "ascii.h"

int main(void) {
	srand((unsigned int)time(NULL));
	
	gameLoop();

	//int scorecard[13] = { 0 };
	//int dice[5] = { 5, 4, 3, 2, 1};
	// parseRoll(scorecard, dice);

	return 0;
}