#include "calculations.h"
#include "read.h"

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

double calculateStandarddev(double variance)
{
	return 0.0;
}

double findMax(double num1, double num2, double num3, double num4, double num5)
{
	return 0.0;
}

double findMin(double num1, double num2, double num3, double num4, double num5)
{
	return 0.0;
}

