#include <stdio.h>
#include <stdint.h>
#include "convert.h"

uint16_t convert(uint32_t pixel)
{
	return (((pixel & RED_MASK) >> RED_SHIFT) +
		((pixel & GREEN_MASK) >> GREEN_SHIFT) +
		((pixel & BLUE_MASK) >> BLUE_SHIFT));
}

int main(int argc, char *argv[])
{
	uint32_t pixel = 0xffffff;
	printf("Converted RGB888 0xffffff to RGB565 %#04x\n", convert(pixel));
	return 0;
}
