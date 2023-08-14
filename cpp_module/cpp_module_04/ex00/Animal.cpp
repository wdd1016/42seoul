/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:37:43 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/14 15:38:11 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : type(type)
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
	this->type = copy.type;
	return (*this);
}

void Animal::setType(const std::string &type)
{
	this->type = type;
}

const std::string &Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "An animal make a sound" << std::endl;
}
