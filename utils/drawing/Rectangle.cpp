/*
 * Rectangle.cpp
 *
 *  Created on: Dec 19, 2021
 *      Author: ubuntu
 */

#include "Rectangle.h"

const Rectangle Rectangle::ZERO(0, 0, 0, 0);
const Rectangle Rectangle::UNDEFINED(10000, 10000, 0, 0);

Rectangle::Rectangle(int32_t inputX, int32_t inputY, int32_t width, int32_t height): x(inputX), y(inputY), w(width), h(height) {
}

bool Rectangle::operator==(const Rectangle& other) const {
	return x == other.x && y == other.y && w == other.w && h == other.h;
}

bool Rectangle::operator!=(const Rectangle& other) const {
	return !(*this == other);
}

bool Rectangle::in(const Point& point) const {
	return point.x >= x && point.x <= x + w && point.y >= y && point.y <= y + h;
}
