/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:55:22 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/15 20:16:31 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	*this = copy;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _invCount; i++)
		delete _inventory[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &subst)
{
	if (this == &subst)
		return (*this);

	for (int i = 0; i < getInvCount(); i++)
		delete _inventory[i];

	_invCount = subst.getInvCount();
	for (int i = 0; i < _invCount; i++)
		_inventory[i] = subst._inventory[i]->clone();
	for (int i = _invCount; i < 4; i++)
		_inventory[i] = NULL;

	return (*this);
}

const int &MateriaSource::getInvCount() const
{
	return (_invCount);
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (_invCount == 4 || m == NULL)
		return ;
	_inventory[_invCount] = m;
	_invCount++;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < _invCount; i++)
	{
		if (_inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	return (NULL);
}
