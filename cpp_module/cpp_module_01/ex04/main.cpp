/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:25:44 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/11 16:26:18 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, const char* argv[])
{
  if (argc != 4)
  {
    std::cout << "Argument Error" << std::endl;
    exit(EXIT_FAILURE);
  }
  Replace filestream(argv[1]);
  filestream.convert(argv[2], argv[3]);
  return (0);
}