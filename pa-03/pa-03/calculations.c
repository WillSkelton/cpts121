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

	mean = sum / num;

	return mean;
}

double calculateDev(double num, double mean)
{
	return 0.0;
}

double calculateVariance(double numbers[])
{
	return 0.0;
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

