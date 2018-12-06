#include "functions.h"


char *myStringNCat(char *dest, char src[], int n, int len) {

	for (int i = 0; i < n; ++i) {
		dest[len + i] = src[i];
		
		if (src[i] == '\0') {
			break;
		}
		
	}

	return &dest;
}

int binSearch(int *list, int lower, int upper, int searchValue) {
	int indexOfSV = -1;
	
	while (lower <= upper) {
		int middleIndex = lower + (upper - lower) / 2;

		if (list[middleIndex] == searchValue) {
			indexOfSV = middleIndex;
		}

		if (list[middleIndex] < searchValue) {
			lower = middleIndex + 1;
		}

		else {
			upper = middleIndex - 1;
		}
	}

	return indexOfSV;
}

void bubbleSort(char *strings[], int length) {
	int u = length - 1;
	int c = 0;
	

	while (u > 0) {
		c = 1;
		while (c <= u) {
			if (strings[c] < strings[c - 1]) {
				char *temp = strings[c - 1];
				strings[c - 1] = strings[c];
				strings[c] = temp;
			}
			++c;
		}
		--u;
	}

}