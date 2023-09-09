/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:57:22 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/02 21:50:49 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &copy) : AMateria(copy) {}

Cure::~Cure() {}

Cure &Cure::operator=(const AMateria &subst) {
	std::cout << "Something wrong!, Cure always cure" << std::endl;
	return (*this);
}

Cure &Cure::operator=(const Cure &subst) {
	return (*this);
}

AMateria* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}