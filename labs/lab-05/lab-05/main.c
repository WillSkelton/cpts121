#include <stdio.h>

int main(void) {
	FILE *infile = NULL;
	FILE *outfile = NULL;

	double sum = 0.0;
	double n = 0.0;
	double num = 0.0;
	double mean = 0.0;

	infile = fopen("data.txt", "r");
	outfile = fopen("output.txt", "w");

	while (!feof(infile)) {
		fscanf(infile, "%lf", &num);
		
		sum += num;

		n += 1;
	}

	mean = sum / n;

	fprintf(outfile, "%.3lf\n", mean);
}