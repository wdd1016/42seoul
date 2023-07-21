/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 22:23:11 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/21 21:25:47 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
  // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
  // std::cout << "Copy constructor called" << std::endl;
  *this = copy;
}

Fixed::Fixed(const int initValue) : _value(initValue << _fractionBit) {
  // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float initValue) : _value(roundf(initValue * (1 << _fractionBit))) {
  // std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
// std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copy) {
  // std::cout << "Copy assignment operator called" << std::endl;
  if (this != &copy)
    this->_value = copy._value;
  return (*this);
}

bool  Fixed::operator>(const Fixed& target) const {
  return (this->_value > target._value ? true : false);
}

bool  Fixed::operator<(const Fixed& target) const {
  return (this->_value < target._value ? true : false);
}

bool  Fixed::operator>=(const Fixed& target) const {
  return (this->_value >= target._value ? true : false);
}

bool  Fixed::operator<=(const Fixed& target) const {
  return (this->_value <= target._value ? true : false);
}

bool  Fixed::operator==(const Fixed& target) const {
  return (this->_value == target._value ? true : false);
}

bool  Fixed::operator!=(const Fixed& target) const {
  return (this->_value != target._value ? true : false);
}

Fixed Fixed::operator+(const Fixed& target) const {
  Fixed temp;
  
  temp._value = this->getRawBits() + target.getRawBits();
  return (temp);
}

Fixed Fixed::operator-(const Fixed& target) const {
  Fixed temp;

  temp._value = this->getRawBits() - target.getRawBits();
  return (temp);
}

Fixed Fixed::operator*(const Fixed& target) const {
  Fixed temp;
  const int intangerBit = 32 - _fractionBit;

  /* target's intanger part multiplication + fraction part multiplication*/
  temp._value = (this->getRawBits() >> _fractionBit) * target.getRawBits()
                + (((this->getRawBits() << intangerBit) >> intangerBit) * target.getRawBits());

  return (temp);
}

Fixed Fixed::operator/(const Fixed& target) const {
  int mod = 1 << _fractionBit;
  return (Fixed((static_cast<float>(this->_value) / mod)  / (static_cast<float>(target._value) / mod)));
}

Fixed&  Fixed::operator++() {
  this->_value++;
  return (*this);
}

Fixed&  Fixed::operator--() {
  this->_value--;
  return (*this);
}

Fixed  Fixed::operator++(int) {
  Fixed temp(*this);
  this->_value++;
  return (temp);
}

Fixed  Fixed::operator--(int) {
  Fixed temp(*this);
  this->_value--;
  return (temp);
}

int Fixed::getRawBits() const {
  // std::cout << "getRawBits member function called" << std::endl;
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

Fixed& Fixed::min(Fixed& one, Fixed& two) {
  return (one.getRawBits() <= two.getRawBits() ? one : two);
}

const Fixed& Fixed::min(const Fixed& one, const Fixed& two) {
  return (one.getRawBits() <= two.getRawBits() ? one : two);
}

Fixed& Fixed::max(Fixed& one, Fixed& two) {
  return (one.getRawBits() >= two.getRawBits() ? one : two);
}

const Fixed& Fixed::max(const Fixed& one, const Fixed& two) {
  return (one.getRawBits() >= two.getRawBits() ? one : two);
}

std::ostream& operator<<(std::ostream& os, const Fixed& addValue) {
  os << addValue.toFloat();
  return (os);
}
