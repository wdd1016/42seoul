/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:04:50 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/19 19:12:37 by juyojeon         ###   ########.fr       */
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
  Fixed&  operator=(const Fixed& copy);
  ~Fixed();
  int getRawBits(void) const;
  void setRawBits(int const raw);
};




#endif