/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:36:29 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/23 16:22:03 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

const Point vector(Point const A, Point const B) {
  return (Point(B.getX() - A.getX(), B.getY() - A.getY()));
}

Fixed crossProduct(Point const vectorA, Point const vectorB) {
	return ((vectorA.getX() * vectorB.getY()) - (vectorB.getX() * vectorA.getY()));
}

Fixed absoluteValue(Fixed value) {
  if (value.getRawBits() > 0)
    return (value);
  else {
    value.setRawBits(-1 * (value.getRawBits()));
    return (value);
  }
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed areaAll(absoluteValue(crossProduct(vector(a, b), vector(a, c))));
  Fixed areaAP(absoluteValue(crossProduct(vector(a, b), vector(a, point))));
  Fixed areaBP(absoluteValue(crossProduct(vector(b, c), vector(b, point))));
  Fixed areaCP(absoluteValue(crossProduct(vector(c, a), vector(c, point))));



  if (areaAP != 0 && areaBP != 0 && areaCP != 0 && areaAll == areaAP + areaBP + areaCP)
    return true;
  else
    return false;
}
