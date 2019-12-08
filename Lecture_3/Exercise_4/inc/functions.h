#ifndef FUNCTION_H
#define FUNCTION_H

/**
 * Pointer to an int returning function
 */
int (*func)(int);
/**
 * Function to apply negative sign on number.
 */
int negative(int input);

/**
 * Function to call other function by a pointer.
 * @param f pointer to int returning function and int argrument.
 * @param arg Argument to a passed function pointer.
 * @return int number returned by a called int function.
 **/
int function(int (*f)(int), int arg);

#endif
