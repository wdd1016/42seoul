/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 03:27:25 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/01 03:41:29 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_process_str(int signo, siginfo_t *info, void *content);
static void	ft_print_buf(int *count, char buf);

int	main(void)
{
	g_data.act.sa_flags = SA_SIGINFO;
	ft_change_sigaction(ft_check_client);
	if (ft_print_pid(getpid()) == -1 || write(1, "\n", 1) == -1)
	{
		write(2, "Print Error\n", 12);
		exit(1);
	}
	while (TRUE)
		pause();
}

void	ft_change_sigaction(void (*sigact)(int, siginfo_t *, void *))
{
	g_data.act.sa_sigaction = sigact;
	if (sigaction(SIGUSR1, &(g_data.act), NULL) == -1 || \
	sigaction(SIGUSR2, &(g_data.act), NULL) == -1)
	{
		write(2, "Sigaction Error\n", 16);
		exit(1);
	}
}

void	ft_check_client(int signo, siginfo_t *info, void *content)
{
	if (signo != SIGUSR1)
		return ;
	g_data.opponent_pid = info->si_pid;
	ft_change_sigaction(ft_process_str);
	usleep(100);
	if (kill(g_data.opponent_pid, SIGUSR1) == -1)
	{
		write(2, "Kill Error\n", 11);
		signo = (int)content;
		exit(1);
	}
}

static void	ft_process_str(int signo, siginfo_t *info, void *content)
{
	static unsigned char	buf;
	static int				count;						

	if (info->si_pid != g_data.opponent_pid)
		ft_cut_in_error(&count);
	else
	{
		count++;
		if (signo == SIGUSR1)
			buf = (buf << 1) + 0;
		else
			buf = (buf << 1) + 1;
		usleep(50);
		if (count == 8)
			ft_print_buf(&count, buf);
		else
		{
			if (kill(g_data.opponent_pid, SIGUSR1) == -1)
			{
				write(2, "Kill Error\n", 11);
				signo = (int)content;
				exit(1);
			}
		}
	}
}

static void	ft_print_buf(int *count, char buf)
{
	(*count) = 0;
	if (buf == 0)
	{
		write(1, "\n", 1);
		if (kill(g_data.opponent_pid, SIGUSR2) == -1)
		{
			write(2, "Kill Error\n", 11);
			exit(1);
		}
		ft_change_sigaction(ft_check_client);
	}
	else
	{
		write(1, &buf, 1);
		if (kill(g_data.opponent_pid, SIGUSR1) == -1)
		{
			write(2, "Kill Error\n", 11);
			exit(1);
		}
	}
}
