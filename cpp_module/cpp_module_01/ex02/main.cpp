/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:27:26 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/08 21:51:02 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
	std::string str("HI THIS IS BRAIN");

	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "The memory address of the string variable : "
	<< &str << std::endl;
	std::cout << "The memory address held by stringPTR : "
	<< &stringPTR << std::endl;
	std::cout << "The memory address held by stringREF : "
	<< &stringREF << "\n" << std::endl;

	std::cout << "The value of the string variable : "
	<< str << std::endl;
	std::cout << "The value of stringPTR : "
	<< stringPTR << std::endl;
	std::cout << "The value of stringREF : "
	<< stringREF << "\n" << std::endl;

	std::cout << "string change -> str = \"NEW BRAIN\"" << std::endl;
	str = "NEW BRAIN";
	std::cout << "The value of the string variable : "
	<< str << std::endl;
	std::cout << "The value pointed to by stringPTR : "
	<< *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF : "
	<< stringREF << std::endl;
}