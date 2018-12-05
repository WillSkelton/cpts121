#include "functions.h"

int main(void) {
	char dest[20] = "Guy";

	char src[14] = "On a Buffalo!";

	char *arrayPtr = *myStringNCat(dest, src, 14);


	return 0;
}