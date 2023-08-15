/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:13:52 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/15 20:35:15 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>
#include "Character.hpp"

class ICharacter;

class AMateria
{
  protected:
    std::string _type;

  public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria &copy);
    virtual ~AMateria();
    AMateria &operator=(const AMateria &subst);

    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
