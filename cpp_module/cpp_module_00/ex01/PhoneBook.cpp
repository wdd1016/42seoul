/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 22:50:23 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/07 19:40:40 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::findCommand() {
  std::string temp;

  std::cout << "Please enter command [ADD, SEARCH, EXIT] : ";
  std::cin >> temp;
  if (std::cin.eof())
    exit(0); // EOF haddling
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  if (temp.compare("ADD") == 0)
    return (ADD);
  else if (temp.compare("SEARCH") == 0)
    return (SEARCH);
  else if (temp.compare("EXIT") == 0)
    return (EXIT);
  else
    return (WRONG);
}

void	PhoneBook::add() {
  int index;

  index = this->count % 8;
  this->count++;
  if (this->count > 0x70000000)
    this->count -= 0x60000000; // overflow handling
  this->contacts[index].addContact();
}

void  PhoneBook::search() {
  if (this->count == 0) {
    std::cout << "Please add an contact" << std::endl;
    return;
  }
  std::cout << std::setw(10) << "index" << "|"
  << std::setw(10) << "first name" << "|"
  << std::setw(10) << "last name" << "|"
  << std::setw(10) << "nickname" << "|" << std::endl;
  for (int i = 0; i < 8; i++)
    this->contacts[i].showCuttedContact(i);
  std::string temp;
  while (1)
  {
    std::cout << "Please enter index for searched contact : ";
    std::cin >> temp;
    if (std::cin.eof())
      exit(1);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (temp.length() != 1 || temp.at(0) < '1' || temp.at(0) > '9')
      continue;
    int preindex = temp.at(0) - '0';
    if (preindex > this->count)
      continue;
    int index = preindex - 1;
    this->contacts[index].showContactDetail();
    break;
  }
}
