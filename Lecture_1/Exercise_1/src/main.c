#include <stdio.h>
#include <stdint.h>

/**
 * Function exchanges contents of two uint16_t numbers.
 * @param first The pointer of first number for exchange
 * @param second The pointer of second number for exchange
 */
void swap16(uint16_t *first, uint16_t* second)
{
	uint16_t temporary = 0;
	temporary = *second;
	*second = *first;
	*first = temporary;
}

/**
 * Function exchanges contents of two uint32_t numbers.
 * @param first The pointer of first number for exchange
 * @param second The pointer of second number for exchange
 */
void swap32(uint32_t *first, uint32_t* second)
{
	uint32_t temporary = 0;
	temporary = *second;
	*second = *first;
	*first = temporary;
}

/**
 * Function exchanges contents of two uint64_t numbers.
 * @param first The pointer of first number for exchange
 * @param second The pointer of second number for exchange
 */
void swap64(uint64_t *first, uint64_t* second)
{
	uint64_t temporary = 0;
	temporary = *second;
	*second = *first;
	*first = temporary;
}

int main(int argc, char *argv[])
{
	uint16_t testOne16 = 5, testTwo16 = 6;
	uint32_t testOne32 = 10, testTwo32 = 11;
	uint64_t testOne64 = 15, testTwo64 = 16;

	printf("Swapping uint16_t numbers %u and %u\n",
		   testOne16, testTwo16);
	swap16(&testOne16, &testTwo16);
	printf("Swap result for uint32_t is %u and %u\n",
		   testOne16, testTwo16);

	printf("Swapping uint32_t numbers %u and %u\n",
		   testOne32, testTwo32);
	swap32(&testOne32, &testTwo32);
	printf("Swap result is %u and %u\n",
		   testOne32, testTwo32);

	printf("Swapping uint64_t numbers %lu and %lu\n",
		   testOne64, testTwo64);
	swap64(&testOne64, &testTwo64);
	printf("Swap result is %lu and %lu\n",
		   testOne64, testOne64);

	return 0;
}
