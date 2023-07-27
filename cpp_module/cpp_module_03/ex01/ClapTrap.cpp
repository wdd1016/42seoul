/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:00:52 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/27 22:43:59 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// 생성자
ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamege(0)
{
	std::cout << "ClapTrap " << _name << " is generated." << std::endl;
}


// 소멸자
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " is destroyed." << std::endl;
}

// 복사 생성자
ClapTrap::ClapTrap(const ClapTrap& copy)
	: _name(copy._name), _hitPoint(copy._hitPoint), _energyPoint(copy._energyPoint), _attackDamege(copy._attackDamege)
{
	std::cout << "ClapTrap " << _name << " has been copied." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	if (this == &copy)
		return *this;

	_name = copy._name;
	_hitPoint = copy._hitPoint;
	_attackDamege = copy._attackDamege;
	_energyPoint = copy._energyPoint;

	std::cout << "ClapTrap " << this->_name << " has been assigned!" << std::endl;

	return *this;
}

// 공격 함수
void ClapTrap::attack(const std::string& target)
{
	if (_energyPoint == 0) {
		std::cout << "ClapTrap " << _name << " doesn't have an energy point." << std::endl;
		return;
	}

	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamege << " points of damage." << std::endl;
	_energyPoint--;
	if (_energyPoint == 0) {
		std::cout << "ClapTrap " << _name << "'s energy points are now zero." << std::endl;
	}
}

// 피해 입는 함수
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoint == 0) {
		std::cout << "ClapTrap " << _name << " is already broken!" << std::endl;
		return;
	}

	_hitPoint = (_hitPoint > amount) ? _hitPoint - amount : 0;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Current hit points: " << _hitPoint << std::endl;

	if (_hitPoint == 0)
		std::cout << "ClapTrap " << _name << " is broken!" << std::endl;
}

// 회복 함수
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoint == 0) {
		std::cout << "ClapTrap " << _name << " doesn't have an energy point." << std::endl;
		return;
	}

	_hitPoint = _hitPoint + amount;
	std::cout << "ClapTrap " << _name << " is repaired for " << amount << " hit points! Current hit points: " << _hitPoint << std::endl;
	_energyPoint--;
	if (_energyPoint == 0) {
		std::cout << "ClapTrap " << _name << "'s energy points are now zero." << std::endl;
	}
}
