/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:15:00 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/08 18:11:48 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <ctime>

class Zombie {
	private:
    std::string _name;
  
  public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void setName(std::string name);
    void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif