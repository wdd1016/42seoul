/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:03:52 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/27 22:45:02 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
  // Create a ClapTrap object named "Robot1"
  ClapTrap robot1("Robot1");

  // Case 1: Attacking with zero energy points
  robot1.attack("Enemy1");   // Attack when energy points are still 10
  robot1.attack("Enemy2");   // Attack when energy points are 9
  robot1.attack("Enemy3");   // Attack when energy points are 8
  robot1.attack("Enemy4");   // Attack when energy points are 7
  robot1.attack("Enemy5");   // Attack when energy points are 6
  robot1.attack("Enemy6");   // Attack when energy points are 5
  robot1.attack("Enemy7");   // Attack when energy points are 4
  robot1.attack("Enemy8");   // Attack when energy points are 3
  robot1.attack("Enemy9");   // Attack when energy points are 2
  robot1.attack("Enemy10");  // Attack when energy points are 1
  robot1.attack(
      "Enemy11");  // Attack when energy points are 0 (Energy points become 0)
  robot1.attack("Enemy12");  // Attack when energy points are 0 (Energy points
                             // are still 0)

  // Create a ClapTrap object named "Robot2"
  ClapTrap robot2("Robot2");

  // Case 2: Taking damage until hit points become 0
  robot2.takeDamage(2);  // Hit points are now 8
  robot2.takeDamage(3);  // Hit points are now 5
  robot2.takeDamage(1);  // Hit points are now 4
  robot2.takeDamage(5);  // Hit points are now 0 (Robot2 is broken!)
  robot2.takeDamage(2);  // Hit points are still 0 (Robot2 is broken!)

  // Case 3: Being repaired until hit points become 100
  robot2.beRepaired(5);  // Hit points are still 0 (Robot2 is broken!)

  ClapTrap robot3("Robot3");
  robot3.beRepaired(3);    // Hit points are now 13
  robot3.beRepaired(12);   // Hit points are now 25
  robot3.beRepaired(100);  // Hit points are now 125
  robot3.beRepaired(100);  // Hit points are now 225
  robot3.beRepaired(100);  // Hit points are now 325
  robot3.beRepaired(100);  // Hit points are now 425
  robot3.beRepaired(100);  // Hit points are now 525
  robot3.beRepaired(100);  // Hit points are now 625
  robot3.beRepaired(100);  // Hit points are now 725
  robot3.beRepaired(100);  // Hit points are now 825
  robot3.beRepaired(100);  // Energy points are 0

  return 0;
}