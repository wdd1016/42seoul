/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 03:27:25 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/31 04:11:51 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

typedef struct s_data
{
	struct sigaction	act;
	pid_t				cli_pid;
}	t_data;

static void	check_client(int signo, siginfo_t *info, void *content);
static void	process_str(int signo, siginfo_t *info, void *content);
static int	print_pid(int n);

t_data	g_data;

int	main(void)
{
	g_data.act.sa_sigaction = check_client;
	g_data.act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &(g_data.act), NULL) == -1 || \
	sigaction(SIGUSR2, &(g_data.act), NULL) == -1)
	{
		write(2, "Sigaction Error\n", 16);
		exit(1);
	}
	if (print_pid(getpid()) == -1 || write(1, "\n", 1) == -1)
	{
		write(2, "Print Error\n", 12);
		exit(1);
	}
	while (TRUE)
		pause();
}

static void	check_client(int signo, siginfo_t *info, void *content)
{
	if (signo != SIGUSR1)
		return ;
	g_data.cli_pid = info->si_pid;
	if (kill(g_data.cli_pid, SIGUSR1) == -1)
	{
		write(2, "Kill Error\n", 11);
		exit(1);		
	}
	g_data.act.sa_sigaction = process_str;
	if (sigaction(SIGUSR1, &(g_data.act), NULL) == -1 || \
	sigaction(SIGUSR2, &(g_data.act), NULL) == -1)
	{
		write(2, "Sigaction Error\n", 16);
		exit(1);
	}
}

static void	process_str(int signo, siginfo_t *info, void *content)
{
	static unsigned char	buf;
	static int				count;
	int						temp;						

	if (info->si_pid != g_data.cli_pid)
	{
		write(1, "\nClient PID changed in the middle\n", 34);
		g_data.act.sa_sigaction = check_client;
		count = 0;
		if (sigaction(SIGUSR1, &(g_data.act), NULL) == -1 || \
		sigaction(SIGUSR2, &(g_data.act), NULL) == -1)
		{
			write(2, "Sigaction Error\n", 16);
			exit(1);
		}	
	}
	else
	{
		count++;
		if (signo == SIGUSR1)
			temp = 0;
		else
			temp = 1;
		buf = (buf << 1) + temp;
		if (count == 8 && buf == 0)
		{
			write(1, "\n", 1);
			g_data.act.sa_sigaction = check_client;
			count = 0;
			if (sigaction(SIGUSR1, &(g_data.act), NULL) == -1 || \
			sigaction(SIGUSR2, &(g_data.act), NULL) == -1)
			{
				write(2, "Sigaction Error\n", 16);
				exit(1);
			}				
		}
		else if (count == 8)
		{
			write(1, &buf, 1);
			count = 0;
		}
	}
}

static int	print_pid(int n)
{
	int	x;

	x = n % 10 + '0';
	if (n >= 10)
	{
		if (print_pid(n / 10) < 0)
			return (-1);
	}
	if (write(1, &x, 1) < 0)
		return (-1);
	return (1);
}
