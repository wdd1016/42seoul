/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadroutine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:18:15 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/01 22:25:53 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_eating(t_philo *pinfo, t_data *tdata);
static int	ft_eating_process(t_philo *pinfo, t_data *tdata);
static int	ft_sleeping(t_philo *pinfo, t_data *tdata);
static int	ft_timecheck(t_philo *pinfo, t_data *tdata);

void	*ft_thread_routine(void *arg)
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
			printf("%lld %d is sleeping", tdata.temptime, tdata.pnum);
		pthread_mutex_unlock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
		tdata.left_time = pinfo->sleeptime;
		if (ft_sleeping(pinfo, &tdata) == TERMINATE)
			break ;
		if (pinfo->inter->exit_flag || ft_timecheck(pinfo, &tdata))
			break ;
		pthread_mutex_lock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
		if (!pinfo->inter->exit_flag)
			printf("%lld %d is thinking", tdata.temptime, tdata.pnum);
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
	pthread_mutex_lock(&(pinfo->inter->forkmutex)[tdata->sec_fork]);
	if (pinfo->inter->exit_flag || ft_timecheck(pinfo, tdata))
		return (TERMINATE);
	pthread_mutex_lock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
	if (!pinfo->inter->exit_flag)
		printf("%lld %d is eating", tdata->temptime, tdata->pnum);
	pthread_mutex_unlock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
	tdata->left_time = pinfo->mealtime;
	if (ft_eating_process(pinfo, tdata) == TERMINATE)
		return (TERMINATE);
	gettimeofday(&(tdata->reftime), NULL);
	if (++(tdata->eat_count) == pinfo->max_meal)
	{
		pthread_mutex_lock(&(pinfo->inter->sysmutex)[MEAL_FIN_COUNT]);
		(pinfo->inter->fin_count)++;
		pthread_mutex_unlock(&(pinfo->inter->sysmutex)[MEAL_FIN_COUNT]);
		return (TERMINATE);
	}
	return (CONTINUE);
}

static int	ft_eating_process(t_philo *pinfo, t_data *tdata)
{
	while (tdata->left_time > 0)
	{
		if (!pinfo->inter->exit_flag && !ft_timecheck(pinfo, tdata))
		{
			tdata->left_time -= 5;
			if (tdata->left_time < 0)
				usleep((5 + tdata->left_time) * 1000);
			else
				usleep(5000);
		}
		else
		{
			pthread_mutex_unlock(&(pinfo->inter->forkmutex)[tdata->sec_fork]);
			pthread_mutex_unlock(&(pinfo->inter->forkmutex)[tdata->fir_fork]);
			return (TERMINATE);
		}
	}
	pthread_mutex_unlock(&(pinfo->inter->forkmutex)[tdata->sec_fork]);
	pthread_mutex_unlock(&(pinfo->inter->forkmutex)[tdata->fir_fork]);
	return (CONTINUE);
}

static int	ft_sleeping(t_philo *pinfo, t_data *tdata)
{
	while (tdata->left_time > 0)
	{
		if (!pinfo->inter->exit_flag && !ft_timecheck(pinfo, tdata))
		{
			tdata->left_time -= 5;
			if (tdata->left_time < 0)
				usleep((5 + tdata->left_time) * 1000);
			else
				usleep(5000);
		}
		else
			return (TERMINATE);
	}
	return (CONTINUE);
}

static int	ft_timecheck(t_philo *pinfo, t_data *tdata)
{
	struct timeval	now;
	long			aftereat;
	long			lifediff;

	gettimeofday(&now, NULL);
	lifediff = (now.tv_sec - pinfo->starttime.tv_sec) * 1000 + \
	(now.tv_usec - pinfo->starttime.tv_usec) / 1000;
	aftereat = (now.tv_sec - tdata->reftime.tv_sec) * 1000 + \
	(now.tv_usec - tdata->reftime.tv_usec) / 1000;
	tdata->temptime = now.tv_sec * 1000 + now.tv_usec / 1000;
	if (lifediff > pinfo->lifetime || aftereat > pinfo->lifetime)
	{
		pthread_mutex_lock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
		(pinfo->inter->exit_flag)++;
		if (pinfo->inter->exit_flag == TERMINATE)
			printf("%lld %d died", tdata->temptime, tdata->pnum);
		pthread_mutex_unlock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
		return (TERMINATE);
	}
	return (CONTINUE);
}
