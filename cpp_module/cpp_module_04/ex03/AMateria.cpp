/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:45:56 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/14 23:56:28 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {
}

AMateria::AMateria(const AMateria &copy) : type(copy.type) {
}

AMateria::~AMateria() {
}

AMateria &AMateria::operator=(const AMateria &subst) {
	this->type = subst.type;
	return (*this);
}

std::string const & AMateria::getType() const {
	return (this->type);
}

void AMateria::use(ICharacter& target) {
	std::cout << "* uses " << this->type << " on " << target.getName() << " *" << std::endl;
}
