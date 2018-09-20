/*
	Author: Will Skelton
	Date: 9/1/18

	Discription: Given User input, program calculates the following values:
				* Newton’s Second Law of Motion
				* Volume of a cylinder
				* Character encoding
				* Distance between two points
				* Tangent
				* Equivalent parallel resistance
				* General equation
*/

#include <stdio.h>
#include <math.h>

// Asks user for mass and accelleration, then computes and prints Force to the console
double secondLaw(void)
{
	double force = 0.0,
		mass = 0.0,
		acceleration = 0.0;
	
	printf("Please enter mass: ");
	scanf(" %lf", &mass);

	printf("Please enter acceleration: ");
	scanf(" %lf", &acceleration);

	force = mass * acceleration;

	printf("If mass = %lf, and acceleration = %lf, then force = (mass * acceleration) = %lf.\n", mass, acceleration, force);

	return force;
}

// Asks user for radius and height and calculates the volume of a cylinder with those measurements
double cylinderVolume(void)
{
	double radius = 0.0,
		height = 0.0,
		pi = 3.14159,
		volume = 0.0;

	printf("Please enter radius: ");
	scanf(" %lf", &radius);

	printf("Please enter height: ");
	scanf(" %lf", &height);

	volume = pi * (radius * radius) * height;

	printf("If radius = %lf and height = %lf, then volume = %lf.\n", radius, height, volume);
	return volume;
}

// Asks for character and encodes that character
char encoder(void)
{
	char character = "";
	int shift = 0;
	
	printf("What character do you want to encode?: ");
	scanf(" %c", &character);

	printf("Please enter a shift value: ");
	scanf(" %d", &shift);

	printf("Your new character = %c.\n", (character - 'A') + 'a' - shift);

	return character;
}

// Asks user for 2 points and calculates the distance between the two
double distance(void)
{
	double x1 = 0.0,
		y1 = 0.0,
		x2 =0.0,
		y2 = 0.0,
		dist = 0.0;

	printf("Please enter x and y coordinates for 1st point separated by a space: ");
	scanf(" %lf %lf", &x1, &y1);
	
	printf("Please enter x and y coordinates for 2nd point separated by a space: ");
	scanf(" %lf %lf", &x2, &y2);

	printf("Point 1: (%lf, %lf)\n", x1, y1);
	printf("Point 2: (%lf, %lf)\n", x2, y2);

	dist = sqrt((pow((x1 - x2), 2)) + (pow((y1 - y2), 2)));

	printf("Distance: %lf\n", dist);

	return dist;
}

// Asks user for theta and computes the tangent
double calcTangent(void)
{
	double theta = 0.0,
		tangent = 0.0;

	printf("What is the value of theta? (in radians): ");
	scanf(" %lf", &theta);

	tangent = sin(theta) / cos(theta);

	printf("Tangent: %lf.\n", tangent);

	return tangent;
}

// Asks user for resistance for 3 resisters and calculates perallel resistance
double parallelResistance(void)
{
	int r1 = 0,
		r2 = 0,
		r3 = 0;
		
	double pr = 0.0;

	printf("Please enter Resistance for R1, R2, R3 spearated by a space: ");
	scanf(" %d%d%d", &r1, &r2, &r3);

	//pr = r1 + r2 + r3;
	pr = 1/ ((1 / (double)r1) + (1 / (double)r2) + (1 / (double)r3));

	printf("Parallel resistance: %lf.\n", pr);

	return pr;

}

// Asks user for x, y, z and a and calculates general equation
double genEquation(void)
{
	int a = 0;
	double x = 0.0,
		y = 0.0,
		z = 0.0,
		pi = 3.14159;

	printf("Please enter a, x, y, and z separated by spaces: ");
	scanf(" %d%lf%lf%lf", &a, &x, &y, &z);

	y = ((double)2 / (double)3) - y + z * x / (a % 2) + pi;

	printf("y = %lf\n", y);

	return y;
}

// main
int main(void)
{

	secondLaw();
	printf("==========================\n");

	cylinderVolume();
	printf("==========================\n");

	encoder();
	printf("==========================\n");

	distance();
	printf("==========================\n");

	calcTangent();
	printf("==========================\n");

	parallelResistance();
	printf("==========================\n");

	genEquation();
	printf("==========================\n");
	return 0;
}