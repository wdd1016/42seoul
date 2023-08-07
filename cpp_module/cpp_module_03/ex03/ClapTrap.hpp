/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:04:06 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/07 23:12:45 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

protected:
	std::string _name;
  unsigned int _hitPoint;
  unsigned int _energyPoint;
  unsigned int _attackDamege;

  ClapTrap();

public:
	ClapTrap(const std::string name);
	virtual ~ClapTrap();
  ClapTrap(const ClapTrap& copy);
  ClapTrap& operator=(const ClapTrap& copy);

  void  attack(const std::string& target);
  void  takeDamage(unsigned int amount);
  void  beRepaired(unsigned int amount);
};

#endif