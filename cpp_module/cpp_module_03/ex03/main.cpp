/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:03:52 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/29 23:04:09 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{

	DiamondTrap a("a");
	DiamondTrap b("b");
	DiamondTrap c("c");


	a.attack("b");
	b.takeDamage(a.attack_damage);
	b.beRepaired(10);
	b.guardGate();
	b.highFivesGuys();
	b.whoAmI();
	c = a;
	c.whoAmI();
    
    return 0;
}