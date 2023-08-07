/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:51:11 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/07 21:23:50 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _isGateKeeper(false) {
  this->_hitPoint = 100;
  this->_energyPoint = 50;
  this->_attackDamege = 20;
  std::cout << "Defalut ScavTrap constructor called!" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name), _isGateKeeper(false) {
  this->_hitPoint = 100;
  this->_energyPoint = 50;
  this->_attackDamege = 20;
  std::cout << "ScavTrap " << _name << " constructor called!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destructor called!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {

  if (this == &copy)
    return (*this);

  this->_name = copy._name;
  this->_hitPoint = copy._hitPoint;
  this->_energyPoint = copy._energyPoint;
  this->_attackDamege = copy._attackDamege;
  this->_isGateKeeper = copy._isGateKeeper;

	std::cout << "ScavTrap " << this->_name << " assignment operator called!" << std::endl;

  return (*this);
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
  *this = copy;
  std::cout << "ScavTrap " << this->_name << " copy constructor called!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_energyPoint == 0) {
		std::cout << _name << " can't attack because it doesn't have an energyPoint." << std::endl;
		return;
	} else if (_hitPoint == 0) {
		std::cout << _name << " can't attack because it's already broken." << std::endl;
		return;
	}

	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamege << " points of damage." << std::endl;
	_energyPoint--;
	if (_energyPoint == 0) {
		std::cout << _name << "'s energy points are now zero." << std::endl;
	}
}

void ScavTrap::guardGate() {
	if (_energyPoint == 0) {
		std::cout << _name << " can't guard because it doesn't have an energyPoint." << std::endl;
		return;
	} else if (_hitPoint == 0) {
		std::cout << _name << " can't guard because it's already broken." << std::endl;
		return;
	}
  if (_isGateKeeper == true)
    std::cout << _name << " is already in Gate keeper mode." << std::endl;
  else {
    _isGateKeeper = true;
    std::cout << _name << " starts Gatekeeper mode." << std::endl;
  }
}
