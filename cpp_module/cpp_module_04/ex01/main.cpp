/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:00:37 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/14 22:52:02 by juyojeon         ###   ########.fr       */
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
  i->getIdea(0);
  std::cout << std::endl;

  std::cout << j->getType() << std::endl;
  j->makeSound();
  j->setIdea(0, "Idea zero");
  j->getIdea(0);
  std::cout << std::endl;

  delete i;
  delete j;

  return 0;
}