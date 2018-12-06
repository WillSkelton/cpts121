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

int binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r)
	{
		int m = l + (r - l) / 2;

		// Check if x is present at mid 
		if (arr[m] == x) {
			return m;
		}

		// If x greater, ignore left half 
		if (arr[m] < x) {
			l = m + 1;
		}

		// If x is smaller, ignore right half 
		else {
			r = m - 1;
		}
	}

	// if we reach here, then element was 
	// not present 
	return -1;
}

