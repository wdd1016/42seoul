/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:07:20 by juyojeon          #+#    #+#             */
/*   Updated: 2023/08/18 20:26:04 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const &copy) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &copy) {
	std::cout << "Brain assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy.getIdea(i);
	return (*this);
}

void Brain::setIdea(int index, const std::string &idea) {
	_ideas[index] = idea;
}

const std::string &Brain::getIdea(int index) const {
	return (this->_ideas[index]);
}
