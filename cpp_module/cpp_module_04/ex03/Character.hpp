/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:22:32 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/18 21:17:27 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
  private:
	std::string _name;
	AMateria *_inventory[4];
	int	_invCount;
	AMateria **_trash;
	int	_trashCount;
	int _maxTrashCount;

  public:
  	Character();
	Character(std::string const & name);
	Character(const Character &copy);
	virtual ~Character();
	Character &operator=(const Character &subst);

	std::string const & getName() const;
	const int &getInvCount() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif