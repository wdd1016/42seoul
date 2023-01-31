/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:08:06 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/01 03:41:34 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_changing_sigaction(void (*sigact)(int, siginfo_t *, void *));
static void	ft_handler_client(int signo, siginfo_t *info, void *content);
static void	ft_send_message(void);
static int	ft_valid_atoi(const char *str);

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(2, "Parameter Error\n", 16);
		exit(1);
	}
	g_data.opponent_pid = ft_valid_atoi(argv[1]);
	g_data.string = argv[2];
	if (*(g_data.string) == '\0')
	{
		write(2, "Empty String Error\n", 21);
		exit(1);
	}
	g_data.act.sa_flags = SA_SIGINFO;
	ft_changing_sigaction(ft_handler_client);
	if (kill(g_data.opponent_pid, SIGUSR1) == -1)
	{
		write(2, "Kill Error\n", 11);
		exit(1);
	}
	while (TRUE)
		pause();
}

static void	ft_changing_sigaction(void (*sigact)(int, siginfo_t *, void *))
{
	g_data.act.sa_sigaction = sigact;
	if (sigaction(SIGUSR1, &(g_data.act), NULL) == -1 || \
	sigaction(SIGUSR2, &(g_data.act), NULL) == -1)
	{
		write(2, "Sigaction Error\n", 16);
		exit(1);
	}
}

static void	ft_handler_client(int signo, siginfo_t *info, void *content)
{
	if (info->si_pid != g_data.opponent_pid)
	{
		write(2, "Receive Error\n", 14);
		signo = (int)content;
		exit(1);
	}
	else if (signo == SIGUSR2 && *(g_data.string) == '\0')
	{
		write(1, "Process Completed Successfully", 30);
		exit(0);
	}
	else if (signo == SIGUSR2)
	{
		write(2, "Sending Error", 30);
		exit(1);
	}
	else
		ft_send_message();
}

static void	ft_send_message(void)
{
	static char	buf;
	static int	count;
	int			v_signal;

	if (count == 0)
	{
		buf = *(g_data.string);
		if (*(g_data.string))
			(g_data.string)++;
	}
	count++;
	if (buf & 128)
		v_signal = SIGUSR2;
	else
		v_signal = SIGUSR1;
	buf = (buf << 1);
	if (count == 8)
		count = 0;
	usleep(50);
	if (kill(g_data.opponent_pid, v_signal) == -1)
	{
		write(2, "Kill Error\n", 11);
		exit(1);
	}
}

static int	ft_valid_atoi(const char *str)
{
	long long	sum;

	while (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	sum = 0;
	while (*str >= '0' && *str <= '9')
	{
		sum = (sum * 10) + (*str - '0');
		if (sum > 4194304)
		{
			write(2, "Unavailable PID Error\n", 22);
			exit(1);
		}
		str++;
	}
	while (*str == ' ')
		str++;
	if (*str != '\0')
	{
		write(2, "Unavailable PID Error\n", 22);
		exit(1);
	}
	return ((int)sum);
}
