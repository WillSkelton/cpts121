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
	double SIDs[5], GPAs[5], classStandings[5], ages[5], deviations[5];

	// forloop variable
	double temp = 0.0;
	
	// sums
	double gpaSum = 0.0, classStandingSum = 0.0, ageSum = 0.0;

	// means
	double gpaMean = 0.0, classStandingMean = 0.0, ageMean = 0.0;

	// Other
	double variance = 0.0, gpaStandardDev = 0.0, gpaMax = 0.0, gpaMin = 0.0;


	// ===================== Start Program =====================

	// Get Files
	infile = fopen("data.txt", "r");
	outfile = fopen("results.dat", "w");

	// Traverse the data file and get records
	for (int i = 0; i < 5; i += 1) {
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

	// Outputs Means to results.dat
	printDouble(outfile, gpaMean);
	printDouble(outfile, classStandingMean);
	printDouble(outfile, ageMean);
	
	// Deviations
	for (int i = 0; i < 5; i += 1) {
		deviations[i] = calculateDev(GPAs[i], gpaMean);
	}

	// Variance
	variance = calculateVariance(deviations, 5);

	// Standard Deviation
	gpaStandardDev = calculateStandardDev(variance);
	

	// max gpa
	gpaMax = findMax(GPAs);

	// min gpa
	gpaMin = findMin(GPAs);

	// Prints last 3 results
	printDouble(outfile, gpaStandardDev);
	printDouble(outfile, gpaMin);
	printDouble(outfile, gpaMax);

	fclose(outfile);
	fclose(infile);

	return 0;

}