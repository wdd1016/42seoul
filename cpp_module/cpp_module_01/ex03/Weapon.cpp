/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:54:53 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/10 16:41:49 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const char *newWeapon) {
  this->_type = newWeapon;
}

const std::string& Weapon::getType() {
  return (this->_type);
}

void  Weapon::setType(const char *newWeapon) {
  this->_type = newWeapon;
}