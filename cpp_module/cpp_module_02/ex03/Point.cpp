/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:08:24 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/20 23:35:18 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor initializes the point with x and y set to 0.0
Point::Point() : _x(0.0f), _y(0.0f) {}

// Parameterized constructor initializes the point with given x and y coordinates
Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {}

// Copy constructor creates a new Point as a copy of the provided Point object
Point::Point(const Point& copy) : _x(copy._x), _y(copy._y) {}

// Destructor
Point::~Point() {}

// Assignment Operator Overloading
const Point& Point::operator=(const Point& target) {

    // Assignment operator overloading to copy the coordinates from the target Point
    if (this == &target)  // Check for self-assignment
        return *this;

    return target;
}

const Fixed Point::getX() const {
    return (this->_x);
}
const Fixed Point::getY() const {
    return (this->_y);
}
