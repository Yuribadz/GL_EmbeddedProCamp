#include <stdio.h>
#include "max.h"

int max(int *array, int size)
{
	int max = array[0];
	for(int i = 0; i < size; ++i)
	{
		if(array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
}

int main(void) {

	int testArray[TEST_SIZE] = {1,5,5,6,7};
	printf("Max element of array : %d\n", max(testArray, 5));
	return 0;
}
