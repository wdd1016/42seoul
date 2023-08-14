/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:37:43 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/14 22:42:24 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_type = copy.getType();
	return (*this);
}

void Animal::setType(const std::string &type)
{
	this->_type = type;
}

const std::string &Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "An animal make a sound" << std::endl;
}

void Animal::setIdea(int index, const std::string &idea) const
{
	(void)index;
	(void)idea;
	std::cout << "Animal doesn't have a brain" << std::endl;
}

const std::string &Animal::getIdea(int index) const
{
	(void)index;
	std::cout << "Animal doesn't have a brain" << std::endl;
	return (_type);
}
