/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 01:43:26 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/01 03:41:25 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_print_pid(int n)
{
	int	x;

	x = n % 10 + '0';
	if (n >= 10)
	{
		if (ft_print_pid(n / 10) < 0)
			return (-1);
	}
	if (write(1, &x, 1) < 0)
		return (-1);
	return (1);
}

void	ft_cut_in_error(int *count)
{
	write(1, "\nClient PID changed in the middle\n", 34);
	(*count) = 0;
	ft_change_sigaction(ft_check_client);
}
