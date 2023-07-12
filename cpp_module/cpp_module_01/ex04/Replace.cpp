/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:18:25 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/12 19:08:55 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

// source file open & destnation file make
Replace::Replace(std::string path)
{
	this->inputFile.open(path);
  if (this->inputFile.is_open()) {
    this->inputFlag = true;
    this->outputFile.open(path.append(".replace").c_str());
    if (this->outputFile.is_open())
      this->outputFlag = true;
    else {
      this->outputFlag = false;
      std::cout << "File Making Error" << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  else {
    std::cout << "File Opening Error" << std::endl;
    exit(EXIT_FAILURE);
  }
}

// source file close & destnation file close
Replace::~Replace()
{
  if (inputFlag)
    this->inputFile.close();
  if (outputFlag)
    this->outputFile.close();
}

void  Replace::convert(std::string s1, std::string s2)
{
  std::string temp;

  if (s1.length() == 0)
  {
    std::cout << "Argument Error" << std::endl;
    exit(EXIT_FAILURE);
  }
  else
  {
    while (1)
    {
      size_t idx = 0;
      std::getline(this->inputFile, temp);
      if (this->inputFile.fail() || this->inputFile.bad())
        break;
      else if (this->inputFile.eof() == 0)
        temp.append("\n");
      while (1)
      {
        idx = temp.find(s1, idx);
        if (idx == std::string::npos)
          break;
        temp.erase(idx, s1.length());
        temp.insert(idx, s2);
        idx += s2.length();
      }
      this->outputFile.write(temp.c_str(), temp.length());
      if (this->inputFile.eof() == 1)
        break;
    }
  }
}
