/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:17:08 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 21:34:55 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	atouc_exit(char *str);

void	execute_exit(t_treenode *node, int pipe_flag)
{
	if (pipe_flag == OFF)
		write(STDOUT_FILENO, "exit\n", 5);
	if ((node->cmd)[1])
	{
		g_exit_status = atouc_exit((node->cmd)[1]);
		if (g_exit_status == -1)
		{
			write(STDERR_FILENO, "minishell: exit: ", 17);
			write(STDERR_FILENO, (node->cmd)[1], ft_strlen((node->cmd)[1]));
			write(STDERR_FILENO, ": numeric argument required\n", 28);
			g_exit_status = 255;
		}
		else if ((node->cmd)[2] != NULLPOINTER)
		{
			write(STDERR_FILENO, "minishell: exit: too many arguments\n", 36);
			g_exit_status = 1;
		}
	}
	exit(g_exit_status);
}
/* 20 line -> printf("exit\n") : bash shell in interactive mode print 
              "exit" when exit command is executed */
/* we don't implement about interactive & script mode, 
   so we choose another option(pipe_flag) */

static int	atouc_exit(char *str)
{
	long long	number;
	long long	sign;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (number > 922337203685477580 || (number == 922337203685477580 && \
		((sign == 1 && *str > '7') || (sign == -1 && *str > '8'))))
			return (-1);
		number = (number * 10) + (*str - '0');
		str++;
	}	
	return ((unsigned char)(sign * number));
}
