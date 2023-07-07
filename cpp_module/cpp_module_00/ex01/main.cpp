/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 22:50:12 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/07 18:01:54 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
  PhoneBook book;
  int		cmd_idx;

  while (1) {
	  cmd_idx = book.findCommand();
	  if (cmd_idx == EXIT) {
      std::cout << "The program quits and the contacts are lost forever!" << std::endl;
  		break; // quit program
  	}
	  else if (cmd_idx == ADD)
		  book.add();
	  else if (cmd_idx == SEARCH)
		  book.search();
    else
      std::cout << "Wrong command entered." << std::endl; // wrong command
  }
}