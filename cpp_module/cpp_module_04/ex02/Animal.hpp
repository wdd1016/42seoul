#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &copy);
		virtual ~Animal();
		Animal &operator=(const Animal &copy);

		void setType(const std::string &type);
		const std::string &getType() const;
		virtual void makeSound() const = 0;
		virtual void setIdea(int index, const std::string &idea) const = 0;
		virtual const std::string &getIdea(int index) const = 0;
};

#endif