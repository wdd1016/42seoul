/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:45:56 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/15 22:54:31 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(const std::string &type) : _type(type) {}

AMateria::AMateria(const AMateria &copy) : _type(copy.getType()) {}

AMateria::~AMateria() {}

const std::string &AMateria::getType() const {
	return (_type);
}

void AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << "AMateria is not available on its own." << std::endl;
}
