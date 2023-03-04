/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:44:17 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/05 02:52:19 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_record_arguments(t_philo *info, int argc, char *argv[])
{
	long	*times[5];
	int		i;

	times[1] = &(info->num_people);
	times[2] = &(info->lifetime);
	times[3] = &(info->mealtime);
	times[4] = &(info->sleeptime);
	if (argc <= 4 || argc >= 7)
		return (TERMINATE);
	i = 0;
	while (++i < 5)
	{
		*(times[i]) = ft_atol(argv[i]);
		if (*(times[i]) == 0)
			return (TERMINATE);
	}
	if (argc == 5)
		info->max_meal = 0;
	else
	{
		info->max_meal = ft_atol(argv[5]);
		if (info->max_meal == 0)
			return (TERMINATE);
	}
	return (CONTINUE);
}

int	ft_init_check_get_start_time(t_philo *info)
{
	if (gettimeofday(&(info->stm), NULL) == -1)
	{
		ft_error(info, "Time parcing Error\n");
		return (TERMINATE);
	}
	else if (info->num_people == 1)
	{
		usleep(info->lifetime * 1000);
		printf("%ld %d died\n", info->lifetime, 1);
		if (info)
			free(info);
		return (TERMINATE);
	}
	return (CONTINUE);
}

int	ft_think_sem_threadt_init(t_philo *info)
{
	int	i;

	if (info->num_people % 2 == 0)
		info->thinkt = 0;
	else
		info->thinkt = (info->lifetime - info->mealtime - info->sleeptime) / 2;
	if (info->thinkt < 0)
		info->thinkt = 0;
	info->pids = (size_t *)malloc(sizeof(size_t) * (info->num_people));
	if (info->pids == 0 || \
	memset(info->pids, 0, sizeof(size_t) * (info->num_people)))
		return (TERMINATE);
	(info->semaphore)[0] = \
	sem_open("forks", O_CREAT | O_EXCL, S_IRWXG, info->num_people);
	(info->semaphore)[1] = sem_open("flag", O_CREAT | O_EXCL, S_IRWXG, 1);
	(info->semaphore)[2] = sem_open("count", O_CREAT | O_EXCL, S_IRWXG, 1);
	if ((info->semaphore)[FK_SEM] == SEM_FAILED || (info->semaphore)[EXIT_FLAG] \
	== SEM_FAILED || (info->semaphore)[MEAL_FIN_COUNT] == SEM_FAILED)
		return (ft_sem_unlink_close(info));
	sem_unlink((info->semaphore)[0]);
	sem_unlink((info->semaphore)[1]);
	sem_unlink((info->semaphore)[2]);
	return (CONTINUE);
}

int	ft_sem_unlink_close(t_philo *info)
{
	if ((info->semaphore)[0])
	{
		sem_unlink((info->semaphore)[0]);
		sem_close((info->semaphore)[0]);
	}
	else if ((info->semaphore)[1])
	{
		sem_unlink((info->semaphore)[1]);
		sem_close((info->semaphore)[1]);
	}
	else if ((info->semaphore)[2])
	{
		sem_unlink((info->semaphore)[2]);
		sem_close((info->semaphore)[2]);
	}
	(info->semaphore)[0] = NULL;
	(info->semaphore)[1] = NULL;
	(info->semaphore)[2] = NULL;
	return (TERMINATE);
}
