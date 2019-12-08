#ifndef STRCOPY_H
#define STRCOPY_H

/**
 * @brief Buffer size for test data
 */
#define BUF_SIZE 10

/**
 * Function one string into other. Function does not have any boundary check.
 * Use with care.
 * @param input C string to copy.
 * @param output C string copy destination.
 */
void str_copy(char* input, char* output);


#endif
