#include <stdio.h>
#include <stdint.h>

#define RED_MASK 0xf80000
#define RED_SHIFT 8
#define GREEN_MASK 0xfc00
#define GREEN_SHIFT 5
#define BLUE_MASK 0xf8
#define BLUE_SHIFT 3

/**
 * The function converts pixel colors from RGB888 to RGB565 format.
 * @param pixel uint32_t number which represents red RGB888 pixel color
 * @return uint16_t number which represents RGB565 pixel color
 */
uint16_t convert(uint32_t pixel)
{
	return (((pixel & RED_MASK) >> RED_SHIFT) +
			((pixel & GREEN_MASK) >> GREEN_SHIFT) +
			((pixel & BLUE_MASK) >> BLUE_SHIFT));
}

int main(int argc, char *argv[])
{
	uint32_t pixel = 0xffffff;
	printf("%#04x = \n", convert(pixel));
	return 0;
}
