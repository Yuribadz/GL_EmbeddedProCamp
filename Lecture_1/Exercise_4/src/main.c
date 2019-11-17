#include <stdio.h>

#define RADIUS 6
#define PI 3.141592653589793238463;

/**
 * The function calculates circle perimeter in meters.
 * @param radius int number represents radius of the cirle in meters
 * @return The perimeter of the circle
 */
double perimeter(double radius)
{
	return radius * 2 * PI;
}

/**
 * The function calculates circle perimeter in meters.
 * @param radius int number represents radius of the circle in meters
 * @return The area of the circle in meters
 */
double area(int radius)
{
	return radius * radius * PI;
}

int main(int argc, char *argv[])
{
	printf("Circle radius size is 6 meters.\n");
	printf("Area : %lf\t", area(RADIUS));
	printf("Perimeter : %lf\n", perimeter(RADIUS));
	return 0;
}
