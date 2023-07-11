/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:26:33 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/11 22:27:30 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl01;

	harl01.complain("DEBUG");
	harl01.complain("INFO");
	harl01.complain("WARNING");
	harl01.complain("ERROR");
	harl01.complain("WRONG COMMAND");

	return (0);
}