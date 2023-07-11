/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:26:27 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/11 22:33:45 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug()
{
	std::cout << "[ DEBUG ]\n" 
  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
  << "I really do!\n" << std::endl;
}

void	Harl::info()
{
  std::cout << "[ INFO ]\n" 
  << "I cannot believe adding extra bacon costs more money.\n"
  << "You didn’t put enough bacon in my burger!\n"
  << "If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning()
{
  std::cout << "[ WARNING ]\n" 
  << "I think I deserve to have some extra bacon for free.\n" 
  << "I’ve been coming for years whereas you started working here since last month.\n"
  << std::endl;
}

void	Harl::error()
{
  std::cout << "[ ERROR ]\n" 
  << "This is unacceptable, I want to speak to the manager now.\n"
  << std::endl;
}

void  Harl::complain(std::string level)
{
  void  (Harl::*memFun[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
  const std::string memCommand[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
  bool  significanceFlag = false;

  for (int i = 0; i < 4; i++) {
     if (level == memCommand[i])
     {
      significanceFlag = true;
      for (; i < 4; i++) {
        (this->*memFun[i])();
      }
     }
  }
  if (significanceFlag == false)
  {
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
  }
}
