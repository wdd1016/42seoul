/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:44:17 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/03 14:35:46 by juyojeon         ###   ########.fr       */
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

int	ft_mutex_threadt_init(t_philo *info)
{
	int	i;

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

void	ft_find_pnum_init_data(t_philo *pinfo, t_data *tdata)
{
	int	temp;

	pthread_mutex_lock(&(pinfo->inter->sysmutex)[FIL_NUM]);
	temp = ++(pinfo->inter->pil_num);
	pthread_mutex_unlock(&(pinfo->inter->sysmutex)[FIL_NUM]);
	if (temp % 2 == 0)
		usleep(pinfo->mealtime * 500);
	tdata->pnum = temp;
	tdata->eat_count = 0;
	tdata->reftime.tv_sec = pinfo->starttime.tv_sec;
	tdata->reftime.tv_usec = pinfo->starttime.tv_usec;
	tdata->fir_fork = ((temp - 1) / 2) * 2;
	if (temp == 1)
		tdata->sec_fork = pinfo->num_people - 1;
	else if (temp % 2 == 1)
		tdata->sec_fork = tdata->fir_fork - 1;
	else if (temp % 2 == 0)
		tdata->sec_fork = tdata->fir_fork + 1;
}

int	ft_init_check_get_start_time(t_philo *info)
{
	if (gettimeofday(&(info->starttime), NULL) == -1)
	{
		ft_error(info, "Time parcing Error\n");
		return (TERMINATE);
	}
	else if (info->num_people == 1)
	{
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
