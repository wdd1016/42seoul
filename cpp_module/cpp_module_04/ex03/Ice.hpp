/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:15:18 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/18 21:15:44 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	private:

	public:
		Ice();
		Ice(const Ice &copy);
		virtual ~Ice();
		virtual Ice &operator=(const AMateria &subst);
		Ice &operator=(const Ice &subst);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif