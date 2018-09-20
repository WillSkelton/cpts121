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
	// ===================== Variables =====================
	// files
	FILE *infile = NULL, *outfile = NULL;

	// student record arrays
	double SIDs[5], GPAs[5], classStandings[5], ages[5];

	// forloop variable
	double temp = 0.0;
	
	// sums
	double gpaSum = 0.0, classStandingSum = 0.0, ageSum = 0.0;

	// means
	double gpaMean = 0.0, classStandingMean = 0.0, ageMean = 0.0;

	// Other
	double gpaStandardDev = 0.0, gpaMax = 0.0, gpaMin = 0.0;


	// ===================== Start Program =====================

	// Get Files
	infile = fopen("data.txt", "r");
	outfile = fopen("results.txt", "w");

	// Traverse the data file and get records
	for (int i = 0; i < 5; i += 1)
	{
		SIDs[i] = readDouble(infile);

		GPAs[i] = readDouble(infile);

		classStandings[i] = readDouble(infile);

		ages[i] = readDouble(infile);
	}

	// Send Arrays to get summed
	gpaSum = calculateSums(GPAs);
	classStandingSum = calculateSums(classStandings);
	ageSum = calculateSums(ages);
	
	// Send Sums to get averaged
	gpaMean = calculateMean(gpaSum, 5);
	classStandingMean = calculateMean(classStandingSum, 5);
	ageMean = calculateMean(ageSum, 5);

	printf("gpaSum: %lf \nclassStandingSum: %lf\nageSum: %lf\ngpaMean: %lf\nclassStandingMean: %lf\nageMean: %lf\n", gpaSum, classStandingSum, ageSum, gpaMean, classStandingMean, ageMean);
	
	

	fclose(outfile);
	fclose(infile);

	return 0;

}