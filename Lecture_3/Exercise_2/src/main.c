#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

int push(int data)
{
	stack_t* pos = stack;

	while (pos->next != NULL)
	{
		pos = pos->next;
	}

	pos->next = malloc(sizeof(stack_t));
	if (pos->next == NULL)
	{
		return -1;
	}

	pos->next->data = data;
	pos->next->next = NULL;
	return 1;
}

int pop()
{
	stack_t *pos = stack;
	int res = 0;
	if (pos->next != NULL)
	{
		while (pos->next->next != NULL)
		{
			pos = pos->next;
		}
		res = pos->next->data;
		free(pos->next->next);
		pos->next = NULL;
	}
	else
	{
	        return INT_MAX;
	}
	return res;
}

int read()
{
	stack_t* pos = stack;
	while ( pos->next != NULL)
	{
		pos = pos->next;
	}
	return pos->data;
}

int main(void)
{
	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
	{
		printf("Error, could not alloc memory. Exiting...\n");
		return -1;
	}
	stack->data = 0;
	stack->next = NULL;
	push(1);
	printf("Number in stack : %d\n", read());
	printf("Pop from stack : %d\n", pop());
        printf("Pop from stack : %d\n", pop());
	printf("Verify empty stack %d\n" , read());
        return 0;
}
