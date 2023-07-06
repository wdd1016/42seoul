/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 23:50:14 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/06 23:53:17 by juyojeon         ###   ########.fr       */
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
    Contact contacts[8];
    int     count;

  public:
    PhoneBook() { count = 0; }
    int   findCommand();
    void  add();
    void  search();
};

#endif