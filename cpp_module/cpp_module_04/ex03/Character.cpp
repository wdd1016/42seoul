/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:19:49 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/18 21:34:00 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default"), _invCount(0), _trashCount(0), _maxTrashCount(256)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
  _trash = new AMateria*[256];
  for (int i = 0; i < 256; i++)
    _trash[i] = NULL;
}

Character::Character(const std::string &name) : _name(name), _invCount(0), _trashCount(0), _maxTrashCount(256)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
  _trash = new AMateria*[256];
  for (int i = 0; i < 256; i++)
    _trash[i] = NULL;
}

Character::Character(const Character &copy)
{
	*this = copy;
}

Character::~Character()
{
  for (int i = 0; i < _trashCount; i++)
    delete _trash[i];
  delete[] _trash;
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
  if (_trashCount == _maxTrashCount) {
    AMateria **newTrash = new AMateria*[_maxTrashCount * 2];
    for (int i = 0; i < _maxTrashCount; i++)
      newTrash[i] = _trash[i];
    delete[] _trash;
    _trash = newTrash;
    _maxTrashCount *= 2;
  }
  if (m == NULL) {
    std::cerr << "Invalid materia." << std::endl;
    return;
  }
	for (int i = 0; i < _invCount; i++) {
		if (_inventory[i] == m) {
      std::cout << "Already equipped." << std::endl;
			return;
    }
  }
  if (_invCount == 4)
    std::cout << "Inventory is full. Moving to trash." << std::endl;
  else
    _inventory[_invCount++] = m;
  for (int i = 0; i < _trashCount; i++) {
    if (_trash[i] == m)
      return;
  }
  _trash[_trashCount++] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= _invCount) {
    std::cout << "Invalid index." << std::endl;
		return;
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
