/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:04:50 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/19 23:46:07 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	_value;
  static const int  _fractionBit = 8;

public:
  Fixed();
  Fixed(const Fixed& copy);
  Fixed(const int initValue);
  Fixed(const float initValue);
  ~Fixed();

  Fixed&  operator=(const Fixed& target);

  bool  operator>(const Fixed& target) const;
  bool  operator<(const Fixed& target) const;
  bool  operator>=(const Fixed& target) const;
  bool  operator<=(const Fixed& target) const;
  bool  operator==(const Fixed& target) const;
  bool  operator!=(const Fixed& target) const;

  Fixed   operator+(const Fixed& target) const;
  Fixed   operator-(const Fixed& target) const;
  Fixed   operator*(const Fixed& target) const;
  Fixed   operator/(const Fixed& target) const;

  Fixed&  operator++(); // prefix increment operator
  Fixed&  operator--(); // prefix decrement operator
  Fixed   operator++(int); // postfix increment operator
  Fixed   operator--(int); // postfix decrement operator

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
  
  static Fixed& min(Fixed& one, Fixed& two);
  static const Fixed& min(const Fixed& one, const Fixed& two);
  static Fixed& max(Fixed& one, Fixed& two);
  static const Fixed& max(const Fixed& one, const Fixed& two);
};

std::ostream& operator<<(std::ostream& os, const Fixed& addValue);

#endif