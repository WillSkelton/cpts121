#include "functions.h"


char *myStringNCat(char dest[], char src[], int n) {

	int length = (sizeof(dest) / sizeof(dest[0])) - 1;

	for (int i = 0; i < n; ++i) {
		dest[length + i] = src[i];
		
		if (src[i] == '\0') {
			break;
		}
		
	}

	return &dest;
}