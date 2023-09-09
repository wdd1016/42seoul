/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:06:37 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/02 21:50:40 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &copy) : AMateria(copy) {}

Ice::~Ice() {}

Ice &Ice::operator=(const AMateria &subst) {
	std::cout << "Something wrong!, Ice always ice" << std::endl;
	return (*this);
}

Ice &Ice::operator=(const Ice &subst) {
	return (*this);
}

AMateria* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
	