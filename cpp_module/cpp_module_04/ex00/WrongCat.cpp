/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:38:07 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/14 15:38:08 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->type = copy.getType();
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << "Wrong meow meow" << std::endl;
}
