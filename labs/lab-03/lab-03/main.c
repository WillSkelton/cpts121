#include "my-things.h"

int main(void)
{
	double height = 0.0,
		thiccness = 0.0;

	printf("How tall are you?: ");
	scanf(" %lf", &height);
	printf("Please enter your Thiccness in lbs: ");
	scanf(" %lf", &thiccness);

	bmi(height, thiccness);
}