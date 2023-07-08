/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:09:58 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/08 21:41:57 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
  this->setName(name);
  std::cout << "Zombie \'" << this->_name << "\' generated." << std::endl;
}

void Zombie::setName(std::string name) {
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

Zombie::~Zombie() {
  std::cout << "Zombie \'" << this->_name << "\' deleted." << std::endl;
}

void Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}