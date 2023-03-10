/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_t_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:18:15 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/10 16:03:44 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_flag_timecheck(t_philo *pinfo, t_data *tdata, int flag, int f2);
static int	ft_eating(t_philo *info, t_data *dt);
static int	ft_eating_process(t_philo *pinfo, t_data *tdata);
static int	ft_sleeping_thinking(t_philo *pinfo, t_data *tdata, long times);

void	*ft_th_routine(void *arg)
{
	t_philo	*pinfo;
	t_data	tdata;

	pinfo = arg;
	ft_find_pnum_init_data(pinfo, &tdata);
	while (ft_flag_timecheck(pinfo, &tdata, PASS, CONTINUE) == CONTINUE)
	{
		if (ft_eating(pinfo, &tdata) == TERMINATE)
			break ;
		if (ft_flag_timecheck(pinfo, &tdata, SLEEP, CONTINUE) == TERMINATE)
			break ;
		if (ft_sleeping_thinking(pinfo, &tdata, pinfo->sleeptime) == TERMINATE)
			break ;
		if (ft_flag_timecheck(pinfo, &tdata, THINK, CONTINUE) == TERMINATE)
			break ;
		if (pinfo->thinkt > 0)
			if (ft_sleeping_thinking(pinfo, &tdata, pinfo->thinkt) == TERMINATE)
				break ;
	}
	return (NULL);
}

static int	ft_flag_timecheck(t_philo *pinfo, t_data *tdata, int flag, int f2)
{
	pthread_mutex_lock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
	if (pinfo->inter->exit_flag != 0)
		f2 = TERMINATE;
	pthread_mutex_unlock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
	if (f2 == TERMINATE)
		return (TERMINATE);
	if (flag != PASS)
		ft_print(pinfo, tdata, flag);
	else
	{
		pthread_mutex_lock(&(pinfo->inter->sysmutex)[GETTIME]);
		gettimeofday(&(tdata->ntm), NULL);
		pthread_mutex_unlock(&(pinfo->inter->sysmutex)[GETTIME]);
	}
	if ((tdata->ntm.tv_sec - tdata->rtm.tv_sec) * 1000 + (tdata->ntm.tv_usec \
	- tdata->rtm.tv_usec) / 1000 <= pinfo->lifetime)
		return (CONTINUE);
	else
	{
		ft_die(pinfo, tdata);
		return (TERMINATE);
	}
}

static int	ft_eating(t_philo *info, t_data *dt)
{
	pthread_mutex_lock(&(info->inter->forkmutex)[dt->fir_fork]);
	if (ft_flag_timecheck(info, dt, FORK, CONTINUE) == TERMINATE)
	{
		pthread_mutex_unlock(&(info->inter->forkmutex)[dt->fir_fork]);
		return (TERMINATE);
	}
	pthread_mutex_lock(&(info->inter->forkmutex)[dt->sec_fork]);
	if (ft_flag_timecheck(info, dt, EAT, CONTINUE) == TERMINATE)
	{
		pthread_mutex_unlock(&(info->inter->forkmutex)[dt->sec_fork]);
		pthread_mutex_unlock(&(info->inter->forkmutex)[dt->fir_fork]);
		return (TERMINATE);
	}
	dt->rtm = dt->ntm;
	if (ft_eating_process(info, dt) == TERMINATE)
		return (TERMINATE);
	return (CONTINUE);
}

static int	ft_eating_process(t_philo *pinfo, t_data *tdata)
{
	struct timeval	now;

	pthread_mutex_lock(&(pinfo->inter->sysmutex)[GETTIME]);
	gettimeofday(&now, NULL);
	pthread_mutex_unlock(&(pinfo->inter->sysmutex)[GETTIME]);
	while ((now.tv_sec - tdata->rtm.tv_sec) * 1000000LL + \
	(now.tv_usec - tdata->rtm.tv_usec) <= pinfo->mealtime * 1000LL)
	{
		if (ft_flag_timecheck(pinfo, tdata, PASS, CONTINUE) == CONTINUE)
		{
			usleep(200);
			pthread_mutex_lock(&(pinfo->inter->sysmutex)[GETTIME]);
			gettimeofday(&now, NULL);
			pthread_mutex_unlock(&(pinfo->inter->sysmutex)[GETTIME]);
			continue ;
		}
		pthread_mutex_unlock(&(pinfo->inter->forkmutex)[tdata->sec_fork]);
		pthread_mutex_unlock(&(pinfo->inter->forkmutex)[tdata->fir_fork]);
		return (TERMINATE);
	}
	pthread_mutex_unlock(&(pinfo->inter->forkmutex)[tdata->sec_fork]);
	pthread_mutex_unlock(&(pinfo->inter->forkmutex)[tdata->fir_fork]);
	return (ft_is_max_meal(pinfo, tdata));
}

static int	ft_sleeping_thinking(t_philo *pinfo, t_data *tdata, long times)
{
	struct timeval	start;
	struct timeval	now;

	start = tdata->ntm;
	pthread_mutex_lock(&(pinfo->inter->sysmutex)[GETTIME]);
	gettimeofday(&now, NULL);
	pthread_mutex_unlock(&(pinfo->inter->sysmutex)[GETTIME]);
	while ((now.tv_sec - start.tv_sec) * (long long)1000000 + \
	(now.tv_usec - start.tv_usec) <= times * (long long)1000)
	{
		if (ft_flag_timecheck(pinfo, tdata, PASS, CONTINUE) == CONTINUE)
		{
			usleep(200);
			pthread_mutex_lock(&(pinfo->inter->sysmutex)[GETTIME]);
			gettimeofday(&now, NULL);
			pthread_mutex_unlock(&(pinfo->inter->sysmutex)[GETTIME]);
			continue ;
		}
		else
			return (TERMINATE);
	}
	return (CONTINUE);
}
