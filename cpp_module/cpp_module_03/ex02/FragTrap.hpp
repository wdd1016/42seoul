/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 23:43:47 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/28 23:54:14 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

protected:

public:
  FragTrap();
  FragTrap(const std::string name);
  ~FragTrap();
  FragTrap(const FragTrap& copy);
  FragTrap& operator=(const FragTrap& copy);

  void highFivesGuys();
};

#endif