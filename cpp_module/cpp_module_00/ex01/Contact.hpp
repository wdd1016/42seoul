/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 23:50:10 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/08 14:14:04 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <cerrno>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

class Contact {
 private:
  std::string firstName;
  std::string lastName;
  std::string nickName;
  std::string phoneNumber;
  std::string darkestSecret;

  // return cutted string (max 10 char)
  std::string cutString(std::string &str);

 public:
  // add data from stdin
  void addContact();
  // show cutted data on stdout
  void showCuttedContact(int i);
  // show all data on stdout
  void showContactDetail();
};

#endif