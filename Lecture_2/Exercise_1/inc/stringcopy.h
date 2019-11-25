#ifndef STRCOPY_H
#define STRCOPY_H

/**
 * Function copies all digits from one string to other string of size.
 * If output string size is too small, function return value indicates error.
 * @param input C string from where digits are read
 * @param output C string to where digits are copied
 * @param out_size int number which indicates output C string
 * @return int number which indicates error code -1 if output size is too
 *         small to store all characters from input string, 0 indicates success.
 */
int str_copy(char* input, char* output, int out_size);


#endif
