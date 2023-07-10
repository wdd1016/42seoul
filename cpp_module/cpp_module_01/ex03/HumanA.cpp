/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:54:49 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/10 21:06:32 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
  if (name.length() == 0) {
    char buf[5];
    std::sprintf(buf, "%d", std::rand() % 10000);
    std::string temp("Noname");
    temp.append(buf);
    this->_name = temp;
  }
  else
    this->_name = name;
}

void	HumanA::attack() const
{
  std::cout << this->_name
  << " attacks with their "
  << this->_weapon.getType() << std::endl;
}