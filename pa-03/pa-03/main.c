/*
Author: Will Skelton
Date: 9/13/18

Discription: Given User input, program calculates the following values:
* Newton's Second Law of Motion
* Volume of a cylinder
* Character encoding
* Distance between two points
* Tangent
* Equivalent parallel resistance
* General equation
*/
#include "read.h"
#include "calculations.h"

int main(void)
{
	// files
	FILE *infile = NULL, *outfile = NULL;

	//iterator variables
	int i = 0;

	// student variables
	// Student 1



	infile = fopen("data.txt", "r");
	outfile = fopen("results.txt", "w");
	
	calculateSums(infile);



	fclose(outfile);
	fclose(infile);

	return 0;

}