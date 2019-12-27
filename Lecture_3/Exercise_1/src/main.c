#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "copy.h"

void str_copy(char* input, char* output)
{
	for (int i = 0; i < strlen(input); ++i)
	{
		output[i] = input[i];
	}
}

int main(void)
{
	char input[BUF_SIZE] = "Test str";
	char output[BUF_SIZE] = "\0";
	str_copy(input, output);
	printf("Copied string is\n %s\n", output);
        return 0;
}

