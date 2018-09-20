#include "read.h"

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