/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:26:33 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/11 22:33:28 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, const char* argv[])
{
	Harl harlFilter;

  if (argc != 2)
  {
    std::cout << "Argument Error" << std::endl;
    exit(EXIT_FAILURE);
  }
  harlFilter.complain(argv[1]);

	return (0);
}