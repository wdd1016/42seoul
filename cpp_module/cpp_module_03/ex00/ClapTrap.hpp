/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:04:06 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/27 22:39:11 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string _name;
  unsigned int _hitPoint;
  unsigned int _energyPoint;
  unsigned int _attackDamege;

public:
	ClapTrap(const std::string name);
	~ClapTrap();
  ClapTrap(const ClapTrap& copy);
  ClapTrap& operator=(const ClapTrap& copy);

  void  attack(const std::string& target);
  void  takeDamage(unsigned int amount);
  void  beRepaired(unsigned int amount);
};

#endif