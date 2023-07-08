/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:55:35 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/08 20:56:51 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {

	Zombie zombie1 = Zombie("Zombie1");
	Zombie zombie2 = Zombie("");
	Zombie* zombie3 = newZombie("Zombie3");
	Zombie* zombie4 = new Zombie("Zombie4");
	

	zombie1.announce();
	zombie2.announce();
	zombie3->announce();
	zombie4->announce();

	delete zombie3;
	delete zombie4;

	randomChump("random1");
	randomChump("random2");
	randomChump("random3");

	return (0);
}