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
		virtual Animal &operator=(const Animal &copy);

		void setType(const std::string &type);
		const std::string &getType() const;
		virtual void makeSound() const;
		virtual void setIdea(int index, const std::string &idea) const;
		virtual const std::string &getIdea(int index) const;
};

#endif