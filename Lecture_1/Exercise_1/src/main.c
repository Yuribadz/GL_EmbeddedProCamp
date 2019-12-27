#include <stdio.h>
#include <stdint.h>
#include "swap.h"

void swap16(uint16_t *value)
{
	*value = (((*value) >> 8) & 0x00FF) |
		(((*value) << 8) & 0xFF00);
}

void swap32(uint32_t *value)
{
	*value = (((*value >> 24) & 0x000000ff) |
		((*value >>8) & 0x0000ff00) |
		((*value <<8) & 0x00ff0000) |
		((*value <<24) & 0xff000000));
}

void swap64(uint64_t *value)
{
	*value = (((*value) >> 56) & 0x00000000000000FF) |
		(((*value) >> 40) & 0x000000000000FF00) |
		(((*value) >> 24) & 0x0000000000FF0000) |
		(((*value) >>  8) & 0x00000000FF000000) |
		(((*value) <<  8) & 0x000000FF00000000) |
		(((*value) << 24) & 0x0000FF0000000000) |
		(((*value) << 40) & 0x00FF000000000000) |
		(((*value) << 56) & 0xFF00000000000000);
}

int main(void) {
	uint16_t endian16 = 0xaabb;
	uint32_t endian32 = 0xaabbccdd;
	uint64_t endian64 = 0xaabbccddeeffffff;
	swap16(&endian16);
	printf("\n Endian 16 bit swap = 0x%X\n", endian16);
	swap32(&endian32);
	printf("\n Endian 32 bit swap = 0x%X\n", endian32);
	swap64(&endian64);
	printf("\n Endian 64 bit swap = 0x%lX\n", endian64);
}
