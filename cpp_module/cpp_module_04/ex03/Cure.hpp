/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:15:04 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/14 23:48:32 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	private:

	public:
		Cure();
    Cure(const Cure &copy);
    virtual ~Cure();
    Cure &operator=(const Cure &subst);

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif