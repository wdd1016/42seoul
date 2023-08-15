/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:19:49 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/15 22:23:39 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default"), _invCount(0), _trashCount(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
  for (int i = 0; i < 256; i++)
    _trash[i] = NULL;
}

Character::Character(const std::string &name) : _name(name), _invCount(0), _trashCount(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
  for (int i = 0; i < 256; i++)
    _trash[i] = NULL;
}

Character::Character(const Character &copy)
{
	*this = copy;
}

Character::~Character()
{
	for (int i = 0; i < _invCount; i++)
		delete _inventory[i];
  for (int i = 0; i < _trashCount; i++)
    delete _trash[i];
}

Character &Character::operator=(const Character &subst)
{
  if (this == &subst)
    return (*this);

  _name = subst.getName();
  for (int i = 0; i < _invCount; i++)
    delete _inventory[i];

  _invCount = subst.getInvCount();
  for (int i = 0; i < _invCount; i++)
    _inventory[i] = subst._inventory[i]->clone();
  for (int i = _invCount; i < 4; i++)
    _inventory[i] = NULL;

  return (*this);
}

const std::string &Character::getName() const
{
	return (_name);
}

const int &Character::getInvCount() const
{
  return (_invCount);
}

void Character::equip(AMateria* m)
{
	if (_invCount == 4) {
    if (_trashCount == 256) {
      std::cerr << "Inventory is full and trash is full." << std::endl;
      return;
    }
    std::cout << "Inventory is full. Moving to trash." << std::endl;
    _trash[_trashCount++] = m;
    return;
  }
  else if (m == NULL)
		return;

	for (int i = 0; i < _invCount; i++)
		if (_inventory[i] == m) {
      std::cout << "Already equipped." << std::endl;
			return;
    }
	_inventory[_invCount++] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= _invCount) {
    std::cout << "Invalid index." << std::endl;
		return;
  }
  if (_trashCount == 256) {
    std::cerr << "It's full of trash, which can cause memory leaks." << std::endl;
  } else {
    _trash[_trashCount++] = _inventory[idx];
  }
	for (int i = idx; i < _invCount - 1; i++)
		_inventory[i] = _inventory[i + 1];
	_inventory[--_invCount] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= _invCount || _inventory[idx] == NULL) {
    std::cout << "Invalid index." << std::endl;
		return ;
  }
	_inventory[idx]->use(target);
}
