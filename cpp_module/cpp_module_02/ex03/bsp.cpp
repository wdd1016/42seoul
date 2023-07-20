/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:36:29 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/20 23:57:36 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

const Point vector(Point const A, Point const B) {
  return (Point(B.getX() - A.getX(), B.getY() - A.getY()));
}

Fixed crossProduct(Point const vectorA, Point const vectorB) {
	return ((vectorA.getX() * vectorB.getY()) - (vectorB.getX() * vectorA.getY()));
}

Fixed dotProduct(const Fixed crossProductA, const Fixed crossProductB) {
  return (crossProductA * crossProductB)
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed normalVector = crossProduct(vector(a, b), vector(a, c));

  if (dotProduct() >= 0
  && )
}
