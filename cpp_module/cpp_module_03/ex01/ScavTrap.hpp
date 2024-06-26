/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:51:24 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/07 19:24:59 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

protected:
  bool _isGateKeeper;
  ScavTrap();
  
public:
  ScavTrap(const std::string name);
  ~ScavTrap();
  ScavTrap(const ScavTrap& copy);
  ScavTrap& operator=(const ScavTrap& copy);

  void  attack(const std::string& target);
  void  guardGate();
};

#endif