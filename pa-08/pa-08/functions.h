
#include <stdio.h>

// Takes at most n characters out of source and appends them to dest, then returns the pointer to dest
char *myStringNCat(char *dest, char src[], int n, int len);

// Takes a list of SORTED integers and ises binary search to find targetValue
int binSearch(int *list, int lower, int upper, int searchValue);

void bubbleSort(char *strings[], int length);