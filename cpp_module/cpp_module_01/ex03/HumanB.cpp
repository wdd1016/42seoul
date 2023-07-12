/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:54:41 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/12 19:20:58 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
  if (name.length() == 0)
    this->_name = "Noname";
  else
    this->_name = name;
	this->_weapon = NULL;
}

void  HumanB::setWeapon(Weapon &weapon)
{
  this->_weapon = &weapon;
}

void	HumanB::attack() const
{
	if (this->_weapon)
  {
		std::cout << this->_name
		<< " attacks with their "
		<< this->_weapon->getType() << std::endl;
	}
	else
  {
		std::cout << this->_name
    << " doesn't have a weapon and can't attack" << std::endl;
	}
}