#include "my-things.h"


double bmi(double height, double thiccness)
{
	double BMI = 0.0;
	printf("my-things: bmi()\n\n");

	printf("height: %lf, thiccness: %lf", height, thiccness);

	BMI = (thiccness) / pow((height * 12), 2) * 703;
	return 0.0;
}