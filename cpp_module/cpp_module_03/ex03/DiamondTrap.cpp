/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:02:28 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/07 23:13:42 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap(), _name()
{
  ClapTrap::_name = "_clap_name";
  _hitPoint = FragTrap::ownHitpoint();
  _attackDamege = FragTrap::ownAttackDamage();
  std::cout << "Defalut DiamondTrap constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name), _name(name)
{
  ClapTrap::_name = name.append("_clap_name");
  _hitPoint = FragTrap::ownHitpoint();
  _attackDamege = FragTrap::ownAttackDamage();
  std::cout << "DiamondTrap " << this->_name << " is born!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : FragTrap(copy), ScavTrap(copy)
{
  *this = copy;
	std::cout << "DiamondTrap " << this->_name << " copy constructor called!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " is dead!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	if (this == &copy)
		return (*this);
	
  this->_name = copy._name;
  this->_hitPoint = copy._hitPoint;
  this->_energyPoint = copy._energyPoint;
  this->_attackDamege = copy._attackDamege;
  ClapTrap::_name = this->_name + "_clap_name";

  std::cout << "DiamondTrap " << this->_name << " assignment operator called!" << std::endl;

	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	if (_energyPoint == 0) {
		std::cout << _name << " can't speak because it doesn't have an energyPoint." << std::endl;
		return;
	} else if (_hitPoint == 0) {
		std::cout << _name << " can't speak because it's already broken." << std::endl;
		return;
	}
	std::cout << "My name is " << this->_name << std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
}
