/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:43:17 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/18 20:26:05 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
  private:
    std::string _ideas[100];

  public:
    Brain();
    Brain(const Brain &copy);
    ~Brain();
    Brain &operator=(const Brain &copy);
    void setIdea(int index, const std::string &idea);
    const std::string &getIdea(int index) const;
};

#endif
