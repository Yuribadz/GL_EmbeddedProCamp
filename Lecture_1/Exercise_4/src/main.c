#include <stdio.h>
#include "circle.h"

double perimeter(int radius)
{
	return radius * 2 * PI;
}

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
