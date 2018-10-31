#include "functions.h"

int main(void) {

	srand((unsigned int)time(NULL));

	// printTitle();
	
	Error err;
		
	err.print = errorMessage;

	err.print("Hey");

	// gameLoop();

	return 0;
}