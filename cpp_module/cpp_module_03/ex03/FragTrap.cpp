/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 23:49:14 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/07 22:40:14 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
  this->_hitPoint = 100;
  this->_energyPoint = 100;
  this->_attackDamege = 30;
  this->ownHitpoint();
  this->ownAttackDamage();
  std::cout << "Defalut FragTrap constructor called!" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
  this->_hitPoint = 100;
  this->_energyPoint = 100;
  this->_attackDamege = 30;
  this->ownHitpoint();
  this->ownAttackDamage();
  std::cout << "FragTrap " << _name << " constructor called!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destructor called!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy) {

  if (this == &copy)
	return (*this);

  this->_name = copy._name;
  this->_hitPoint = copy._hitPoint;
  this->_energyPoint = copy._energyPoint;
  this->_attackDamege = copy._attackDamege;

	std::cout << "FragTrap " << this->_name << " assignment operator called!" << std::endl;

  return (*this);
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
  *this = copy;
  std::cout << "FragTrap " << this->_name << " copy constructor called!" << std::endl;
}

void FragTrap::highFivesGuys() {
	if (_energyPoint == 0) {
		std::cout << _name << " can't High Five because it doesn't have an energyPoint." << std::endl;
		return;
	} else if (_hitPoint == 0) {
		std::cout << _name << " can't High Five because it's already broken." << std::endl;
		return;
	}
  std::cout << _name << " requests a positive high fives." << std::endl;
}

unsigned int FragTrap::ownHitpoint(void) {
	static unsigned int hitPoint;
  static unsigned int checkPoint;

  if (checkPoint == 0) {
    hitPoint = _hitPoint;
    checkPoint = 1;
    return (hitPoint);
  }
  else
    return (hitPoint);
}

unsigned int FragTrap::ownAttackDamage(void) {
  static unsigned int attackDamage;
  static unsigned int checkPoint;

  if (checkPoint == 0) {
    attackDamage = _attackDamege;
    checkPoint = 1;
    return (attackDamage);
  }
  else
    return (attackDamage);
}