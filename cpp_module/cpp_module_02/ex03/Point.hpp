/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:04:50 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/20 23:57:41 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
private:
  const Fixed _x;
  const Fixed _y;

public:
  Point();
  ~Point();
  Point(const float x, const float y);
  Point(const Fixed x, const Fixed y);
  Point(const Point& copy);

  const Point& operator=(const Point& target);
  const Fixed getX() const;
  const Fixed getY() const;
};

#endif