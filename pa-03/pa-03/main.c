/*
Author: Will Skelton
Date: 9/20/18

Discription: Opens data.sat, parses it and then outputs calculations of the contents to results.dat and results.md
*/
#include "functions.h"

int main(void)
{
	// ===================== Variables =====================
	// files
	FILE *infile = NULL, *outfile = NULL, *markdown = NULL;

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
	infile = fopen("input.dat", "r");
	outfile = fopen("output.dat", "w");

	// Optional Markdown file (open in a markdown editor or see on github)
	markdown = fopen("output.md", "w");


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

	// Prints all data to results.md
	double scores[6] = {gpaMean, classStandingMean, ageMean, gpaStandardDev, gpaMin, gpaMax};
	printMD(markdown, scores);

	fclose(markdown);
	fclose(outfile);
	fclose(infile);

	return 0;

}