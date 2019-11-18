#include <stdio.h>
#include "rectangle.h"


double rect_perimeter(double height, double width)
{
	return (2*(height +  width)) / INCH;
}

double rect_area(double height, double width)
{
	return (height * width) / INCH;
}

int main(int argc, char *argv[])
{
	double height, width;
	printf( "Rectangle height in meters :\n");
	if(scanf("%lf", &height) != 1)
	{
		printf("Not a number. Exiting on error\n");
		return -1;
	}
	printf( "Rectangle width in meters :\n");
	if(scanf("%lf", &width) != 1)
	{
		printf("Not a number. Exiting on error\n");
		return -1;
	}
	printf("Rectangle perimeter is %lf\n",
		   rect_perimeter(height,width));
	printf("Rectangle area is %lf\n",
		   rect_area(height,width));

	return 0;
}
