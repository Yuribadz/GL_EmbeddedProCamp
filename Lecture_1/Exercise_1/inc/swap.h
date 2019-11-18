#ifndef SWAP_H
#define SWAP_H

/**
 * Function exchanges contents of two uint16_t between little->big or 
 * big->little endian. 
 * @param first The pointer of number for exchange
 */
void swap16(uint16_t *value);

/**
 * Function exchanges contents of two uint32_t between little->big or 
 * big->little endian. 
 * @param first The pointer of number for exchange
 */
void swap32(uint32_t *value);

/**
 * Function exchanges contents of two uint64_t between little->big or 
 * big->little endian. 
 * @param first The pointer of number for exchange
 */
void swap64(uint64_t *value);

#endif
