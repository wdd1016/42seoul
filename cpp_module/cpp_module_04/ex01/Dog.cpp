/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:37:55 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/18 20:25:47 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain();
	*this = copy;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_type = copy.getType();
	*(this->_brain) = *(copy.getBrain());
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Woof woof" << std::endl;
}

const Brain *Dog::getBrain() const {
	return (this->_brain);
}

void Dog::setIdea(int index, const std::string &idea) const {
	_brain->setIdea(index, idea);
}

const std::string &Dog::getIdea(int index) const {
	return (_brain->getIdea(index));
}