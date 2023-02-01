/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 01:43:26 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/01 11:46:52 by juyojeon         ###   ########.fr       */
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

void	ft_cut_in_middle(int *count, pid_t pid)
{
	write(1, "\nClient PID changed in the middle\n", 34);
	(*count) = 0;
	g_data.opponent_pid = pid;
	if (kill(g_data.opponent_pid, SIGUSR1) == -1)
	{
		write(2, "Kill Error\n", 11);
		exit(1);
	}
}
