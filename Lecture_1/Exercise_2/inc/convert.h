#ifndef CONVERT_H
#define CONVERT_H

/**
 * @brief Bitmask constant for red color bits in RGB888 pixel.
 */
#define RED_MASK 0xf80000

/**
 * @brief Bit constant to shift red bits in RGB888->RGB565 conversion.
 */
#define RED_SHIFT 8

/**
 * @brief Bitmask constant for green color bits in in RGB888 pixel.
 */
#define GREEN_MASK 0xfc00

/**
 * @brief Bit constant to shift green bits in RGB888->RGB565 conversion.
 */
#define GREEN_SHIFT 5

/**
 * @brief Bitmask constant for blue color bits in in RGB888 pixel.
 */
#define BLUE_MASK 0xf8

/**
 * @brief Constant used to shift blue bits in RGB888->RGB565 conversion.
 */
#define BLUE_SHIFT 3
/**
 * The function converts pixel colors from RGB888 to RGB565 format.
 * @param pixel uint32_t number which represents red RGB888 pixel color
 * @return uint16_t number which represents RGB565 pixel color
 */
uint16_t convert(uint32_t pixel);

#endif
