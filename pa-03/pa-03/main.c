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
	double GPASum = 0.0, ageSum = 0.0;
	int SID = 0, classStandingSum = 0;

	infile = fopen("data.txt", "r");
	outfile = fopen("results.txt", "w");
	
	//SID = readDouble(infile);

	for (i = 0; i < 5; i += 1)
	{
		SID = readDouble(infile);
		GPASum += readDouble(infile);
		classStandingSum += readDouble(infile);
		ageSum += readDouble(infile);
	}

	printDouble(outfile, GPASum);
	printDouble(outfile, (int)classStandingSum);
	printDouble(outfile, (int)ageSum);

	fclose(outfile);
	fclose(infile);

	return 0;

}