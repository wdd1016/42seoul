#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &copy);
		virtual ~WrongCat();
		WrongCat &operator=(const WrongCat &copy);
		void makeSound() const;
};

#endif
