/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:44:17 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/08 18:34:50 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_philo_struct(t_philo *info)
{
	info->num_people = 0;
	info->lifetime = 0;
	info->mealtime = 0;
	info->sleeptime = 0;
	info->max_meal = 0;
	info->threads = 0;
	info->inter = 0;
	info->inter = (t_interact *)malloc(sizeof(t_interact));
	if (!info->inter)
		return (TERMINATE);
	info->inter->fin_count = 0;
	info->inter->pil_num = 0;
	info->inter->exit_flag = 0;
	info->inter->forkmutex = 0;
	return (CONTINUE);
}

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
		printf("%ld %d has taken a fork\n", 0, 1);
		usleep(info->lifetime * 1000);
		printf("%ld %d died\n", info->lifetime, 1);
		if (info && info->inter && info->inter->forkmutex)
			free(info->inter->forkmutex);
		if (info && info->inter)
			free(info->inter);
		if (info->threads)
			free(info->threads);
		if (info)
			free(info);
		return (TERMINATE);
	}
	return (CONTINUE);
}

int	ft_think_mutex_threadt_init(t_philo *info)
{
	int	i;

	if (info->num_people % 2 == 0)
		info->thinkt = 0;
	else
		info->thinkt = (info->lifetime - info->mealtime - info->sleeptime) / 2;
	if (info->thinkt < 0)
		info->thinkt = 0;
	info->inter->forkmutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* (info->num_people));
	if (info->inter->forkmutex == 0)
		return (TERMINATE);
	info->threads = (pthread_t *)malloc(sizeof(pthread_t) * info->num_people);
	if (info->threads == 0)
		return (TERMINATE);
	i = -1;
	while (++i < info->num_people)
		pthread_mutex_init(&(info->inter->forkmutex)[i], NULL);
	i = -1;
	while (++i < 3)
		pthread_mutex_init(&(info->inter->sysmutex)[i], NULL);
	return (CONTINUE);
}
