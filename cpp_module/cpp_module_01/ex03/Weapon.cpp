/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:54:53 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/08 22:29:04 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const char *newWeapon) {
  this->_type = std::string(newWeapon);
}

const std::string& Weapon::getType() {
  return (this->_type);
}

void  Weapon::setType(const char *newWeapon) {
  this->_type = std::string(newWeapon);
}