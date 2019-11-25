#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringcopy.h"

int str_copy(char* input, char* output, int out_size)
{
	int out_pos = 0;
	for (int in_pos = 0; input[in_pos] != '\0'; ++in_pos)
	{
		if ((input[in_pos] >= '0') && (input[in_pos] <= '9'))
		{
			if(out_pos > out_size)
			{
				return -1;
			}
			output[out_pos] = input[in_pos];
			++out_pos;
		}
	}

	return 0;
}

int main(void)
{
	char input[50];
	char output[50];
	memset(output,0,strlen(output));
	printf("Enter string : \n");
	scanf("%s", input);
	printf("You have entered : %s\n",input);
	if(str_copy(input, output, 100) == -1)
	{
		printf("Error, your output buffer to small to store all numbers."
			" Exiting...\n");
		return -1;
	}
	printf("Copied input numbers to outpout numbers are : %s\n", output);
        return 0;
}
