#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &copy);
		virtual ~Dog();
		Dog &operator=(const Dog &copy);
		virtual void makeSound() const;
};

#endif