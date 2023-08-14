#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &copy);
		virtual ~Cat();
		Cat &operator=(const Cat &copy);
		virtual void makeSound() const;
};

#endif