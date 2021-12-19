/*
 * Rectangle.h
 *
 *  Created on: Dec 19, 2021
 *      Author: ubuntu
 */

#ifndef UTILS_DRAWING_RECTANGLE_H_
#define UTILS_DRAWING_RECTANGLE_H_

#include <cstdint>

struct Rectangle {
	Rectangle(int32_t x, int32_t y, int32_t width, int32_t height);

	int32_t x = 0;
	int32_t y = 0;
	int32_t w = 0;
	int32_t h = 0;
};

//extern const Rectangle ZERO;
//extern const Rectangle UNDEFINED;

#endif /* UTILS_DRAWING_RECTANGLE_H_ */
