/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:03:52 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/06 17:40:46 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    // Create a ClapTrap object named "Robot1"
    ScavTrap robot1("Robot1");

    robot1.takeDamage(20); 
    robot1.takeDamage(30); 
    robot1.takeDamage(10);

    robot1.attack("Bot");

    robot1.guardGate();
    robot1.guardGate();

    ScavTrap robot2(robot1);

    robot2.guardGate();
    robot2.attack("Cot");


	ScavTrap robot3("Robot3");

    robot3.beRepaired(5);
    robot3.beRepaired(3);
    robot3.beRepaired(12);
    robot3.beRepaired(100);

    robot3.guardGate();
    
    return 0;
}