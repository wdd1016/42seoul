/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 23:50:14 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/07 17:58:33 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

enum e_command {
  WRONG, ADD, SEARCH, EXIT
};

class PhoneBook {
  private:
    Contact contacts[8]; // use static array (Can't use dynamic allocation)
    int     count; // a number of stored contacts

  public:
    PhoneBook() { count = 0; }
    // get command from stdin
    int   findCommand();
    // add an contact
    void  add();
    // search contacts, view one cotact's detail
    void  search();
};

#endif