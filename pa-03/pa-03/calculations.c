#include "calculations.h"
#include "read.h"

double calculateSums(FILE *infile)
{

	// student variables
	double GPAs[5];
	double GPASum = 0.0, ageSum = 0.0, temp = 0.0;
	int SID = 0, classStandingSum = 0;

	for (int i = 0; i < 5; i += 1)
	{
		SID = readDouble(infile);

		temp = readDouble(infile);
		GPAs[i] = temp;
		GPASum += temp;

		classStandingSum += readDouble(infile);
		ageSum += readDouble(infile);
	}

	for (int i = 0; i < 5; i += 1)
	{
		printf("%.2f\n", GPAs[i]);
	}


}

double calculateMean(double sum, int num)
{
	return 0.0;
}

double calculateDev(double num, double mean)
{
	return 0.0;
}

double calculateVariance(double dev1, double dev2, double dev3, double dev4, double dev5, int num)
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

