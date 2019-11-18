#ifndef RECTANGLE_H
#define RECTANGLE_H

/**
 * @brief Represents meters in inch
 */
#define INCH 0.0254

/**
 * The function calculates rectangle perimeter in inches.
 * @param height double number represents height of rectangle
 * @param width double number represents width of rectangle
 * @return The perimeter of rectangle
 */
double rect_perimeter(double height, double width);

/**
 * The function calculates rectangle area in inches.
 * @param height double number represents height of rectangle
 * @param width double number represents width of rectangle
 * @return The area of rectangle
 */
double rect_area(double height, double width);

#endif
