/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 22:50:16 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/07 19:42:48 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::addContact() {
  std::cout << "Please enter contact details." << std::endl;
  std::cout << "First Name : ";
  std::cin >> this->firstName;
  if (std::cin.eof()) exit(1);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "Last Name : ";
  std::cin >> this->lastName;
  if (std::cin.eof()) exit(1);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "Nickname : ";
  std::cin >> this->nickName;
  if (std::cin.eof()) exit(1);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  while (true) {
    long longNum;
    char *stop = NULL;
    std::cout << "Phone Number only number (e.g. 01012345678) : ";
    std::cin >> this->phoneNumber;
    if (std::cin.eof()) exit(1);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    errno = 0;
    longNum = std::strtol(this->phoneNumber.c_str(), &stop, 10);
    if (errno == ERANGE || *stop != '\0' || longNum < 110000000 ||
        longNum > 1999999999)
      continue;
    else
      break;
  }
  std::cout << "Darkest Secret : ";
  std::cin >> this->darkestSecret;
  if (std::cin.eof()) exit(1);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Contact::showCuttedContact(int i) {
  std::cout << std::setw(10) << i + 1 << "|" << std::setw(10)
            << cutString(this->firstName) << "|" << std::setw(10)
            << cutString(this->lastName) << "|" << std::setw(10)
            << cutString(this->nickName) << "|" << std::endl;
}

std::string Contact::cutString(std::string &str) {
  const int maxsize = 10;

  if (str.length() <= maxsize)
    return (str);
  else {
    std::string cuttedstr = str.substr(0, 9) + ".";
    return (cuttedstr);
  }
}

void Contact::showContactDetail() {
  std::cout << "First name : " << this->firstName << std::endl;
  std::cout << "Last Name : " << this->lastName << std::endl;
  std::cout << "Nick Name : " << this->nickName << std::endl;
  std::cout << "Phone Number : " << this->phoneNumber << std::endl;
  std::cout << "Darkest Secret : " << this->darkestSecret << std::endl;
}