/*
 * Point.cpp
 *
 *  Created on: Dec 19, 2021
 *      Author: ubuntu
 */

#include "Point.h"

const Point ZERO(0, 0);
const Point UNDEFINED(10000, 10000);

Point::Point(int32_t inputX, int32_t inputY): x(inputX), y(inputY) {
}
