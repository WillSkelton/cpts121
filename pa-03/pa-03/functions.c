#include "functions.h"

double calculateSums(double nums[])
{
	double sum = 0.0;
	
	for (int i = 0; i < 5; i += 1)
	{
		sum += nums[i];
	}

	return sum;

}

double calculateMean(double sum, int num)
{
	double mean = 0.0;

	if (num == 0) {
		mean = -1.0;
	}
	else {
		mean = sum / num;
	}

	return mean;
}

double calculateDev(double num, double mean)
{
	double deviation = 0.0;

	deviation = num - mean;

	return deviation;
}

double calculateVariance(double deviations[], int num)
{
	double variance = 0.0;

	for (int i = 0; i < 5; i += 1) {
		variance += pow(deviations[i], 2);
	}

	variance /= num;

	return variance;
}

double calculateStandardDev(double variance)
{
	return sqrt(variance);
}

double findMax(double nums[])
{
	double max = 0.0;
	for (int i = 0; i < 5; i += 1) {
		if (max < nums[i]) {
			max = nums[i];
		}
	}
	return max;
}

double findMin(double nums[])
{
	double min = nums[0];
	for (int i = 0; i < 5; i += 1) {
		if (min > nums[i]) {
			min = nums[i];
		}
	}
	return min;
}

double readDouble(FILE *infile)
{
	double number = 0.0;
	fscanf(infile, " %lf", &number);

	return number;
}

int readInteger(FILE *infile)
{
	int number = 0;
	fscanf(infile, " %d", &number);

	return number;

}

void printDouble(FILE *outfile, double num)
{
	printf("Printed %.2f\n", num);
	fprintf(outfile, "%.2f\n", num);
}

void printMD(FILE *markdown, double nums[])
{
	fprintf(markdown, "# Results:\n");

	for (int i = 0; i < 6; i += 1) {
		fprintf(markdown, "  - %.2f\n", nums[i]);
	}
}