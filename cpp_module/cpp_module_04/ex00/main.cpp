/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:37:59 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/14 15:38:09 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal* meta = new Animal();
  const Animal* i = new Cat();
  const Animal* j = new Dog();
  const WrongAnimal* k = new WrongAnimal();
  const WrongAnimal* l = new WrongCat();

  std::cout << std::endl << meta->getType() << std::endl;
  std::cout << i->getType() << std::endl;
  std::cout << j->getType() << std::endl;
  std::cout << k->getType() << std::endl;
  std::cout << l->getType() << std::endl << std::endl;

  meta->makeSound();
  i->makeSound(); //will output the cat sound!
  j->makeSound();
  k->makeSound();
  l->makeSound();
  std::cout << std::endl;

  delete meta;
  delete i;
  delete j;
  delete k;
  delete l;
  return 0;
}