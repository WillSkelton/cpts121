#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>


int main(void) {

	srand((unsigned int)time(NULL));

	char *article[] = { "The", "a", "one", "some", "any"};
	char *noun[] = { "Boy", "Girl", "dog", "Town", "Car" };
	char *verb[] = { "drove", "jumped", "ran", "walked", "skipped" };
	char *preposition[] = { "to", "from", "over", "under", "on" };

	int x = rand() % 5;



	return 0;
}