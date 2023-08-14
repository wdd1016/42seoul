/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:01:55 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/14 23:08:55 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
  const Animal* i = new Cat();
  const Animal* j = new Dog();

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

  delete i;
  delete j;

  return 0;
}