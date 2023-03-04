/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_t_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:18:15 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/04 19:18:58 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_timecheck(t_philo *pinfo, t_data *tdata, int flag);
static int	ft_eating(t_philo *info, t_data *dt);
static int	ft_eating_process(t_philo *pinfo, t_data *tdata);
static int	ft_sleeping_thinking(t_philo *pinfo, t_data *tdata, long times);

void	*ft_th_routine(void *arg)
{
	t_philo	*pinfo;
	t_data	tdata;

	pinfo = arg;
	ft_find_pnum_init_data(pinfo, &tdata);
	while (!pinfo->inter->exit_flag && !ft_timecheck(pinfo, &tdata, PASS))
	{
		if (ft_eating(pinfo, &tdata) == TERMINATE)
			break ;
		if (pinfo->inter->exit_flag || ft_timecheck(pinfo, &tdata, SLEEP))
			break ;
		if (ft_sleeping_thinking(pinfo, &tdata, pinfo->sleeptime) == TERMINATE)
			break ;
		if (pinfo->inter->exit_flag || ft_timecheck(pinfo, &tdata, THINK))
			break ;
		if (pinfo->thinkt > 0)
			if (ft_sleeping_thinking(pinfo, &tdata, pinfo->thinkt) == TERMINATE)
				break ;
	}
	return (NULL);
}

static int	ft_timecheck(t_philo *pinfo, t_data *tdata, int flag)
{
	if (flag == FORK)
		ft_print_fork(pinfo, tdata);
	else if (flag == EAT)
		ft_print_eat(pinfo, tdata);
	else if (flag == SLEEP)
		ft_print_sleep(pinfo, tdata);
	else if (flag == THINK)
		ft_print_think(pinfo, tdata);
	else
		gettimeofday(&(tdata->ntm), NULL);
	if ((tdata->ntm.tv_sec - tdata->rtm.tv_sec) * 1000 + (tdata->ntm.tv_usec \
	- tdata->rtm.tv_usec) / 1000 < pinfo->lifetime)
		return (CONTINUE);
	else
	{
		pthread_mutex_lock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
		(pinfo->inter->exit_flag)++;
		gettimeofday(&(tdata->ntm), NULL);
		if (pinfo->inter->exit_flag == TERMINATE)
			printf("%ld %d died\n", (tdata->ntm.tv_sec - \
			pinfo->stm.tv_sec) * 1000 + (tdata->ntm.tv_usec - \
			pinfo->stm.tv_usec) / 1000, tdata->pnum);
		pthread_mutex_unlock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
		return (TERMINATE);
	}
}

static int	ft_eating(t_philo *info, t_data *dt)
{
	pthread_mutex_lock(&(info->inter->forkmutex)[dt->fir_fork]);
	if (info->inter->exit_flag || ft_timecheck(info, dt, FORK))
	{
		pthread_mutex_unlock(&(info->inter->forkmutex)[dt->fir_fork]);
		return (TERMINATE);
	}
	pthread_mutex_lock(&(info->inter->forkmutex)[dt->sec_fork]);
	if (info->inter->exit_flag || ft_timecheck(info, dt, EAT))
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

	gettimeofday(&now, NULL);
	while ((now.tv_sec - tdata->rtm.tv_sec) * 1000 + \
	(now.tv_usec - tdata->rtm.tv_usec) / 1000 < pinfo->mealtime)
	{
		if (!pinfo->inter->exit_flag && !ft_timecheck(pinfo, tdata, PASS))
		{
			usleep(500);
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
	return (CONTINUE);
}

static int	ft_sleeping_thinking(t_philo *pinfo, t_data *tdata, long times)
{
	struct timeval	start;
	struct timeval	now;

	start = tdata->ntm;
	gettimeofday(&now, NULL);
	while ((now.tv_sec - start.tv_sec) * 1000 + (now.tv_usec - start.tv_usec) \
	/ 1000 < times)
	{
		if (!pinfo->inter->exit_flag && !ft_timecheck(pinfo, tdata, PASS))
		{
			usleep(500);
			gettimeofday(&now, NULL);
			continue ;
		}
		else
			return (TERMINATE);
	}
	return (CONTINUE);
}
