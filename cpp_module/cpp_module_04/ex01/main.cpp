/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:00:37 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/15 22:46:54 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
  const Animal* i = new Cat();
  const Animal* j = new Dog();
  Animal* k = new Cat(static_cast<const Cat &>(*i));

  std::cout << std::endl << i->getType() << std::endl;
  i->makeSound();
  i->setIdea(0, "Idea zero");
  std::cout << i->getIdea(0) << std::endl;
  std::cout << std::endl;

  std::cout << j->getType() << std::endl;
  j->makeSound();
  j->setIdea(0, "Idea zero");
  std::cout << j->getIdea(0) << std::endl;
  std::cout << std::endl;

  std::cout << k->getType() << std::endl;
  k->makeSound();
  std::cout << k->getIdea(0) << std::endl;
  k->setIdea(0, "Idea zero");
  std::cout << k->getIdea(0) << std::endl;
  std::cout << std::endl;

  delete i;
  delete j;
  delete k;

  const Animal* animal[20];
  
  for (int l = 0; l < 20; l++) {
    if (l % 2 == 0)
      animal[l] = new Dog();
    else
      animal[l] = new Cat();
  }

  for (int m = 0; m < 20; m++) {
    std::cout << std::endl << animal[m]->getType() << std::endl;
    animal[m]->makeSound();
    animal[m]->setIdea(0, "Idea array");
    std::cout << animal[m]->getIdea(0) << std::endl;   
  }

  std::cout << std::endl;

  for (int m = 0; m < 20; m++) {
    delete animal[m];
  }

  return 0;
}