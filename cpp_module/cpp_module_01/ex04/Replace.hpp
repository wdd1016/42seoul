/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:03:54 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/11 22:23:44 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>

class Replace
{
  private:
    std::ifstream inputFile;
    std::ofstream outputFile;
    bool          inputFlag;
    bool          outputFlag;

  public:
    Replace(std::string path);
    ~Replace();
    void  convert(std::string s1, std::string s2);
};

#endif