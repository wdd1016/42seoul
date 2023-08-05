/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:51:11 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/05 21:50:17 by juyojeon         ###   ########.fr       */
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

void ScavTrap::guardGate() {
  if (_isGateKeeper == true)
    std::cout << _name << " is already in Gate keeper mode." << std::endl;
  else {
    _isGateKeeper = true;
    std::cout << _name << " starts Gatekeeper mode." << std::endl;
  }
}