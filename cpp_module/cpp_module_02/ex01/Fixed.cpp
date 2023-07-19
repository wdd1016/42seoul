/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 22:23:11 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/19 21:23:34 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
  std::cout << "Copy constructor called" << std::endl;
  *this = copy;
}

Fixed::Fixed(const int initValue) : _value(initValue << _fractionBit) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float initValue) : _value(roundf(initValue * (1 << _fractionBit))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copy) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &copy)
    this->_value = copy._value;
  return (*this);
}

Fixed::~Fixed() {
std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return (this->_value);
}

void Fixed::setRawBits(int const raw) {
  this->_value = raw;
}

float Fixed::toFloat(void) const {
  return (static_cast<float>(this->_value) / (1 << _fractionBit));
}

int Fixed::toInt() const {
  return (this->_value / (1 << _fractionBit));
}

std::ostream& operator<<(std::ostream& os, const Fixed& addValue) {
  os << addValue.toFloat();
  return os;
}
