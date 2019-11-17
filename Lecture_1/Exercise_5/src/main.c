#include <stdio.h>

#define NUMBER 10

/**
 * The function factorial of the given number.
 * @param number Number used to calculate its factorial
 * @return Number which represents factorial of a given number
 */
int factorial(int number)
{
	int factorial = 1;
	if(number == 0 || number == 1)
	{
		return 1;
	}
	for(int i = 1; i <= number; ++i)
	{
		factorial *= i;
	}
	return factorial;
}

int main(int argc, char *argv[])
{
	printf("Factorial  of  10 is : %d\n", factorial(NUMBER));
	return 0;
}
