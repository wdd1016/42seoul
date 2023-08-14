#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Brain *_brain;
	
	public:
		Dog();
		Dog(const Dog &copy);
		virtual ~Dog();
		Dog &operator=(const Dog &copy);

		virtual void makeSound() const;
		const Brain *getBrain() const;
		virtual void setIdea(int index, const std::string &idea) const;
		virtual const std::string &getIdea(int index) const;

};

#endif