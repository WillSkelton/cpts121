#include "functions.h"

int main(void) {

	// Question #1
	char dest[20] = "Guy on a";

	char src[14] = " Buffalo!";

	char *arrayPtr = *myStringNCat(dest, src, 10, 7);


	// Question #2
	
	int list[16] = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987 };
	
	int length = (sizeof(list) / sizeof(list[0])) - 1;

	// Test for case coverage
	printf("Test for case coverage:\n");
	for (int i = 0; i < length; ++i) {
		printf("%d: %s\n", list[i], (binSearch(&list, 0, length, list[i])) != -1 ? "True" : "False");
	}

	int testList[16] = {1000, 34, 40, 28, 35, 70, 5004, 47, 60, 658, 610, 89, 377, 8 , 57, 99};
	
	// Tests
	printf("\nTests:\n");
	for (int i = 0; i < length; ++i) {
		printf("%d: %s\n", testList[i], (binSearch(&list, 0, length, testList[i])) != -1 ? "True" : "False");
	}


	// Question #3

	return 0;
}