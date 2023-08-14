/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:37:49 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/14 22:36:03 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat constructor called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_type = copy.getType();
	this->_brain = new Brain(*copy.getBrain());
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Cats don’t bark" << std::endl;
}

const Brain *Cat::getBrain() const {
	return (this->_brain);
}

void Cat::setIdea(int index, const std::string &idea) const {
	_brain->setIdea(index, idea);
}

const std::string &Cat::getIdea(int index) const {
	return (_brain->getIdea(index));
}