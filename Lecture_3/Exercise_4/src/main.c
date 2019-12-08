#include <stdio.h>
#include "functions.h"

int negative(int input)
{
    return input = input * -1;
}

int function(int (*func)(int), int arg)
{
	return func(5);
}

int main(void)
{
	func = &negative;
	printf("Call negative function on number 5 =  : %d\n",
		function(func,5));
        return 0;
}
