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
	FILE *infile = NULL, *outfile = NULL;
	double SID = 0.0;

	infile = fopen("data.txt", "r");
	outfile = fopen("results.txt", "w");
	
	SID = readDouble(infile);

	printDouble(outfile, SID);

	fclose(outfile);
	fclose(infile);

	return 0;

}