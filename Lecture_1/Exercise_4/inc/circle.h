#ifndef CIRCLE_H
#define CIRCLE_H

/*
 * @brief Constant number which represents radius to be used for calculation.
 */
#define RADIUS 6

/*
 * @brief Decimal constant representation of PI number.
 */
#define PI 3.141592653589793238463;


/**
 * The function calculates circle perimeter in meters.
 * @param radius int number represents radius of the cirle in meters
 * @return The perimeter of the circle
 */
double perimeter(int radius);

/**
 * The function calculates circle perimeter in meters.
 * @param radius int number represents radius of the circle in meters
 * @return The area of the circle in meters
 */
double area(int radius);


#endif
