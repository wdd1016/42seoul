/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadroutine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:18:15 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/03 14:39:23 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_eating(t_philo *pinfo, t_data *tdata);
static int	ft_eating_process(t_philo *pinfo, t_data *tdata);
static int	ft_sleeping(t_philo *pinfo, t_data *tdata);
static int	ft_timecheck(t_philo *pinfo, t_data *tdata);

void	*ft_th_routine(void *arg)
{
	t_philo	*pinfo;
	t_data	tdata;

	pinfo = arg;
	ft_find_pnum_init_data(pinfo, &tdata);
	while (!pinfo->inter->exit_flag && !ft_timecheck(pinfo, &tdata))
	{
		if (ft_eating(pinfo, &tdata) == TERMINATE)
			break ;
		if (pinfo->inter->exit_flag || ft_timecheck(pinfo, &tdata))
			break ;
		pthread_mutex_lock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
		if (!pinfo->inter->exit_flag)
			printf("%ld %d is sleeping\n", tdata.startdiff, tdata.pnum);
		pthread_mutex_unlock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
		if (ft_sleeping(pinfo, &tdata) == TERMINATE)
			break ;
		if (pinfo->inter->exit_flag || ft_timecheck(pinfo, &tdata))
			break ;
		pthread_mutex_lock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
		if (!pinfo->inter->exit_flag)
			printf("%ld %d is thinking\n", tdata.startdiff, tdata.pnum);
		pthread_mutex_unlock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
	}
	return (NULL);
}

static int	ft_eating(t_philo *pinfo, t_data *tdata)
{
	pthread_mutex_lock(&(pinfo->inter->forkmutex)[tdata->fir_fork]);
	if (pinfo->inter->exit_flag || ft_timecheck(pinfo, tdata))
	{
		pthread_mutex_unlock(&(pinfo->inter->forkmutex)[tdata->fir_fork]);
		return (TERMINATE);
	}
	if (!pinfo->inter->exit_flag)
		printf("%ld %d has taken a fork\n", tdata->startdiff, tdata->pnum);
	pthread_mutex_lock(&(pinfo->inter->forkmutex)[tdata->sec_fork]);
	if (pinfo->inter->exit_flag || ft_timecheck(pinfo, tdata))
	{
		pthread_mutex_unlock(&(pinfo->inter->forkmutex)[tdata->sec_fork]);
		pthread_mutex_unlock(&(pinfo->inter->forkmutex)[tdata->fir_fork]);
		return (TERMINATE);
	}
	gettimeofday(&(tdata->reftime), NULL);
	tdata->startdiff = (tdata->reftime.tv_sec - pinfo->starttime.tv_sec) \
	* 1000 + (tdata->reftime.tv_usec - pinfo->starttime.tv_usec) / 1000;
	pthread_mutex_lock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
	if (!pinfo->inter->exit_flag)
		printf("%ld %d is eating\n", tdata->startdiff, tdata->pnum);
	pthread_mutex_unlock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
	if (ft_eating_process(pinfo, tdata) == TERMINATE)
		return (TERMINATE);
	return (CONTINUE);
}

static int	ft_eating_process(t_philo *pinfo, t_data *tdata)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	while ((now.tv_sec - tdata->reftime.tv_sec) * 1000 + \
	(now.tv_usec - tdata->reftime.tv_usec) / 1000 < pinfo->mealtime)
	{
		if (!pinfo->inter->exit_flag && !ft_timecheck(pinfo, tdata))
		{
			usleep(2000);
			gettimeofday(&now, NULL);
			continue ;
		}
		pthread_mutex_unlock(&(pinfo->inter->forkmutex)[tdata->sec_fork]);
		pthread_mutex_unlock(&(pinfo->inter->forkmutex)[tdata->fir_fork]);
		return (TERMINATE);
	}
	pthread_mutex_unlock(&(pinfo->inter->forkmutex)[tdata->sec_fork]);
	pthread_mutex_unlock(&(pinfo->inter->forkmutex)[tdata->fir_fork]);
	if (++(tdata->eat_count) != pinfo->max_meal)
		return (CONTINUE);
	pthread_mutex_lock(&(pinfo->inter->sysmutex)[MEAL_FIN_COUNT]);
	(pinfo->inter->fin_count)++;
	pthread_mutex_unlock(&(pinfo->inter->sysmutex)[MEAL_FIN_COUNT]);
	return (TERMINATE);
}

static int	ft_sleeping(t_philo *pinfo, t_data *tdata)
{
	struct timeval	start;
	struct timeval	now;

	gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	while ((now.tv_sec - start.tv_sec) * 1000 + \
	(now.tv_usec - start.tv_usec) / 1000 < pinfo->sleeptime)
	{
		if (!pinfo->inter->exit_flag && !ft_timecheck(pinfo, tdata))
		{
			usleep(2000);
			gettimeofday(&now, NULL);
			continue ;
		}
		else
			return (TERMINATE);
	}
	return (CONTINUE);
}

static int	ft_timecheck(t_philo *pinfo, t_data *tdata)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	tdata->startdiff = (now.tv_sec - pinfo->starttime.tv_sec) * 1000 + \
	(now.tv_usec - pinfo->starttime.tv_usec) / 1000;
	tdata->refdiff = (now.tv_sec - tdata->reftime.tv_sec) * 1000 + \
	(now.tv_usec - tdata->reftime.tv_usec) / 1000;
	if (tdata->refdiff > pinfo->lifetime)
	{
		pthread_mutex_lock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
		(pinfo->inter->exit_flag)++;
		if (pinfo->inter->exit_flag == TERMINATE)
			printf("%ld %d died\n", tdata->startdiff, tdata->pnum);
		pthread_mutex_unlock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
		return (TERMINATE);
	}
	return (CONTINUE);
}
