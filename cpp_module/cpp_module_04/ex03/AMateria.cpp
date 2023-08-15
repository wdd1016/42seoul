/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:45:56 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/15 20:34:48 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(const std::string &type) : _type(type) {}

AMateria::AMateria(const AMateria &copy) : _type(copy.getType()) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &subst) {
	_type = subst.getType();
	return (*this);
}

const std::string &AMateria::getType() const {
	return (_type);
}

void AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << "AMateria is not available on its own." << std::endl;
}
