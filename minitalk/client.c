/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:08:06 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/30 22:41:47 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

struct sigaction act;

int	main(int argc, char *argv[])
{
	act.sa_sigaction = check_client;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	printf("%d\n", getpid());
	while (TRUE);
}

void	check_client(int signo, siginfo_t *info, void *content)
{
	info->
}

void	process_str(int signo, siginfo_t *info, void *content)
{
	static unsigned char	buf[];
	if ()
}


