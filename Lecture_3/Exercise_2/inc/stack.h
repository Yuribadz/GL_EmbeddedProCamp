#ifndef STACK_H
#define STACK_H

typedef struct stack
{
	int data;
	struct stack* next;

} stack_t;

/**
 * @brief Global variable used to store stack structure
 **/
stack_t* stack = NULL;


/**
 * Function stores given int number into global pointer to stack_t type variable
 * @param data  data to be stored in stack.
 * @return int -1 on memory alloc failure
 *         1 indicates success.
 */
int push(int data);

/**
 * Function removes last element from the global stack variable.
 * @return int last number stored in stack_t variable. INT_MAX if stack has no elements.
 */
int pop();

/**
 * Function returns but does not remove last element from the global stack variable.
 * @return int last number stored in stack_t variable. NULL if empty.
 */
int read();

#endif
