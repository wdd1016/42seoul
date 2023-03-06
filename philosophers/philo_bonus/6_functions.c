/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:39:52 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/06 23:38:04 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atol(const char *str)
{
	long	sum;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	sum = 0;
	while (*str >= '0' && *str <= '9')
	{
		sum = (sum * 10) + (*str - '0');
		str++;
	}
	if (*str != '\0')
		return (0);
	return (sum);
}

size_t	ft_strlen(const char *s)
{
	const char	*copy;

	if (!s)
		return (0);
	copy = s;
	while (*s)
		s++;
	return ((size_t)s - (size_t)copy);
}

int	ft_error(t_philo *info, const char *str)
{
	write(2, str, strlen(str));
	if (info && info->pids)
		free(info->pids);
	if (info)
		free(info);
	return (-1);
}

int	ft_error_process(int idx, t_philo *info, const char *str)
{
	int		i;

	sem_wait((info->semaphore)[EXIT_FLAG]);
	(info->exit_flag)++;
	sem_post((info->semaphore)[EXIT_FLAG]);
	i = -1;
	while (++i < idx)
		kill((info->pids)[i], SIGTERM);
	i = -1;
	while (++i < 3)
		sem_close((info->semaphore)[i]);
	write(2, str, strlen(str));
	if (info && info->pids)
		free(info->pids);
	if (info)
		free(info);
	return (-1);
}
