#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal
{
	private:
		Brain *_brain;

	public:
		Cat();
		Cat(const Cat &copy);
		virtual ~Cat();
		Cat &operator=(const Cat &copy);

		virtual void makeSound() const;
		const Brain *getBrain() const;
		virtual void setIdea(int index, const std::string &idea) const;
		virtual const std::string &getIdea(int index) const;

};

#endif