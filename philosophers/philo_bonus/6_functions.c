/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:39:52 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/10 16:23:18 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atol(const char *str)
{
	long long	sum;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	sum = 0;
	while (*str >= '0' && *str <= '9')
	{
		sum = (sum * 10) + (*str - '0');
		if (sum > 2147483647)
			return (0);
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

void	ft_died(t_philo *info, t_data *data)
{
	sem_wait((info->semaphore)[PRINT_SEM]);
	sem_wait((info->semaphore)[GTIME_SEM]);
	gettimeofday(&(data->ntm), NULL);
	sem_post((info->semaphore)[GTIME_SEM]);
	printf("%ld %d died\n", (data->ntm.tv_sec - info->stm.tv_sec) * 1000 \
	+ (data->ntm.tv_usec - info->stm.tv_usec) / 1000, data->pnum);
	sem_post((info->semaphore)[PRINT_SEM]);
	sem_close((info->semaphore)[PRINT_SEM]);
	sem_close((info->semaphore)[GTIME_SEM]);
	exit(DEAD);
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
	int	i;
	int	temp;

	i = -1;
	while (++i < idx)
		kill((info->pids)[i], SIGTERM);
	i = -1;
	while (++i < idx)
		waitpid((info->pids)[i], &temp, 0);
	sem_close((info->semaphore)[FK_SEM]);
	sem_close((info->semaphore)[PRINT_SEM]);
	sem_close((info->semaphore)[GTIME_SEM]);
	write(2, str, strlen(str));
	if (info && info->pids)
		free(info->pids);
	if (info)
		free(info);
	return (-1);
}
