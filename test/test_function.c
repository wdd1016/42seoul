/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:08:06 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/30 20:48:25 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	handler(int signo, siginfo_t *info, void *content)
{
	printf("\n%d\n", 111);
}

void	handler2(int signo)
{
	printf("\n%d\n", 222);
}

int	main(int argc, char *argv[])
{
	pid_t	mypid;
	struct sigaction act;

	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	mypid = getpid();
	printf("%d\n", mypid);
	sigaction(SIGINT, &act, NULL);
	pause();
	act.sa_handler = handler2;
	sigaction(SIGINT, &act, NULL);
	printf("%d\n", 999);
	// act.sa_flags = 0;
	while (TRUE)
	{
		pause();
		printf("%d\n", 888);
	}
}
