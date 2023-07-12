/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:55:35 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/12 16:36:06 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie *test1 = zombieHorde(5, "test1");
	for (int i = -0; i < 5; i++)
		test1[i].announce();
	delete[] test1;

	Zombie *test2 = zombieHorde(3, "test2");
	for (int i = 0; i < 3; i++)
		test2[i].announce();
	delete[] test2;

	Zombie test3;
	test3.announce();

	return (0);
}