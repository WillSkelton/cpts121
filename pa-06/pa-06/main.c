#include "functions.h"

int main(void) {

	char board[10][10];

	resetGameBoard(board);

	printGameBoard(board);

	printBattleship();

	return 0;
}