#include <stdio.h>
#include "divider.h"

/**
 * The function divides every number in range from 1 to 500 and prints it.
 * @param divider double number represends divider for numbers in range
 */
void divide_print(double divider)
{
	printf("Divided range :\n");
	for(double i = 1; i < 501; ++i)
	{
		printf("%lf ", (i / divider));
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	double divider = 0;
	printf( "Enter divider number for range from 1 to 500 :\n");
	if(scanf("%lf", &divider) != 1)
	{
		printf("Not a number. Exiting on error.\n");
		return -1;
	}
	else if(divider == 0)
	{
		printf("Divider cannot be zero. Exiting on error.\n");
		return -1;
	}
	else
	{
		divide_print(divider);
	}

	return 0;
}
