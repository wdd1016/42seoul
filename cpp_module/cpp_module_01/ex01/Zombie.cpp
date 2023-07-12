/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:09:58 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/12 16:35:25 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
  std::cout << "Zombie [default] constructor called." << std::endl;
}

Zombie::Zombie(std::string name) {
  this->setName(name);
  std::cout << "Zombie \'" << this->_name << "\' generated." << std::endl;
}

void Zombie::setName(std::string name) {
  if (name.length() == 0)
    this->_name = "Noname";
  else
    this->_name = name;
}

Zombie::~Zombie() {
  if (this->_name.length() == 0)
    std::cout << "Default Zombie deleted." << std::endl;
  else
    std::cout << "Zombie \'" << this->_name << "\' deleted." << std::endl;
}

void Zombie::announce(void) {
  if (this->_name.length() == 0)
    std::cout << "default: BraiiiiiiinnnzzzZ..." << std::endl;
  else
	  std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}