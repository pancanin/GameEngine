/*
 * Point.h
 *
 *  Created on: Dec 19, 2021
 *      Author: ubuntu
 */

#ifndef UTILS_DRAWING_POINT_H_
#define UTILS_DRAWING_POINT_H_

#include <cstdint>

struct Point {
	Point() = default;
	Point(int32_t x, int32_t y);

	int32_t x = 0;
	int32_t y = 0;
};

extern const Point ZERO;
extern const Point UNDEFINED;

#endif /* UTILS_DRAWING_POINT_H_ */
