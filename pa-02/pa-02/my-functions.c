#include "my-functions.h"

// ========= Getters =========

int getMassAndAcceleration(void)
{
	double mass = 0.0,
		acceleration = 0.0;

	printf("Please enter mass: ");
	scanf(" %lf", &mass);

	printf("Please enter acceleration: ");
	scanf(" %lf", &acceleration);

	secondLaw(mass, acceleration);

	return 0;
}

int getRadAndHeight(void)
{
	double radius = 0.0,
		height = 0.0;

	printf("Please enter radius: ");
	scanf(" %lf", &radius);

	printf("Please enter height: ");
	scanf(" %lf", &height);

	cylinderVolume(radius, height);

	return 0;
}

int getChar(void)
{
	char character = "";
	int shift = 0;

	printf("What character do you want to encode?: ");
	scanf(" %c", &character);

	printf("Please enter a shift value: ");
	scanf(" %d", &shift);

	encoder(character, shift);


	return 0;
}

int getPoints(void) {
	double x1 = 0.0,
		y1 = 0.0,
		x2 = 0.0,
		y2 = 0.0;

	printf("Please enter x and y coordinates for 1st point separated by a space: ");
	scanf(" %lf %lf", &x1, &y1);

	printf("Please enter x and y coordinates for 2nd point separated by a space: ");
	scanf(" %lf %lf", &x2, &y2);

	printf("Point 1: (%.2lf, %.2lf)\n", x1, y1);
	printf("Point 2: (%.2lf, %.2lf)\n", x2, y2);

	distance(x1, y1, x2, y2);
	return 0;
}

int getTheta(void) {
	double theta = 0.0;

	printf("What is the value of theta? (in radians): ");
	scanf(" %lf", &theta);

	calcTangent(theta);

	return 0;
}

int getResistors(void)
{
	int r1 = 0,
		r2 = 0,
		r3 = 0;

	printf("Please enter Resistance for R1, R2, R3 spearated by a space: ");
	scanf(" %d%d%d", &r1, &r2, &r3);

	parallelResistance(r1, r2, r3);

	return 0;
}

int getTheLastStuff(void) {

	int a = 0;

	double x = 0.0,
		y = 0.0,
		z = 0.0;

	printf("Please enter a, x, y, and z separated by spaces: ");
	scanf(" %d%lf%lf%lf", &a, &x, &y, &z);

	genEquation(a, x, y, z);

	return 0;
}


// ========= Doers =========

double secondLaw(double mass, double acceleration)
{
	double force = 0.0;

	force = mass * acceleration;

	printf("If mass = %.2lf, and acceleration = %.2lf, then force = (mass * acceleration) = %.2lf.\n", mass, acceleration, force);

	return force;
}

double cylinderVolume(double radius, double height)
{
	double volume = 0.0,
		pi = 3.14159;

	volume = pi * (radius * radius) * height;

	printf("If radius = %.2lf and height = %.2lf, then volume = %.2lf.\n", radius, height, volume);
	return volume;
}

char encoder(char character, int shift)
{

	printf("Your new character = %c.\n", (character - 'A') + 'a' - shift);

	return character;
}

double distance(double x1, double y1, double x2, double y2)
{
	double dist = 0.0;

	dist = sqrt((pow((x1 - x2), 2)) + (pow((y1 - y2), 2)));

	printf("Distance: %.2lf\n", dist);

	return dist;
}

double calcTangent(double theta)
{
	double tangent = 0.0;

	tangent = sin(theta) / cos(theta);

	printf("Tangent: %.2lf.\n", tangent);

	return tangent;
}

double parallelResistance(int r1, int r2, int r3)
{

	double pr = 0.0;

	pr = 1 / ((1 / (double)r1) + (1 / (double)r2) + (1 / (double)r3));

	printf("Parallel resistance: %.2lf.\n", pr);

	return pr;

}

double genEquation(int a, double x, double y, double z)
{

	double pi = 3.14159;

	y = ((double)2 / (double)3) - y + z * x / (a % 2) + pi;

	printf("y = %.2lf\n", y);

	return y;
}
