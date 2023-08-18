/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:57:22 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/18 21:17:23 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &copy) : AMateria(copy) {}

Cure::~Cure() {}

Cure &Cure::operator=(const AMateria &subst) {
	this->_type = subst.getType();
	return (*this);
}

Cure &Cure::operator=(const Cure &subst) {
	this->_type = subst.getType();
	return (*this);
}

AMateria* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}