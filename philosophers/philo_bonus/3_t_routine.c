/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_t_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:18:15 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/06 23:32:47 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_flag_timecheck(t_philo *info, t_data *data, int flag, int f2);
static int	ft_eating(t_philo *info, t_data *dt);
static int	ft_eating_process(t_philo *pinfo, t_data *tdata);
static int	ft_sleeping_thinking(t_philo *pinfo, t_data *tdata, long times);

int	ft_child_process_routine(t_philo *info, long pnum)
{
	t_data	data;

	ft_find_pnum_init_data(info, &data, pnum);
	while (ft_flag_timecheck(info, &data, PASS, CONTINUE) == CONTINUE)
	{
		if (ft_eating(info, &data) == TERMINATE)
			break ;
		if (ft_flag_timecheck(info, &data, SLEEP, CONTINUE) == TERMINATE)
			break ;
		if (ft_sleeping_thinking(info, &data, info->sleeptime) == TERMINATE)
			break ;
		if (ft_flag_timecheck(info, &data, THINK, CONTINUE) == TERMINATE)
			break ;
		if (info->thinkt > 0)
			if (ft_sleeping_thinking(info, &data, info->thinkt) == TERMINATE)
				break ;
	}
	sem_close((info->semaphore)[FK_SEM]);
	sem_close((info->semaphore)[EXIT_FLAG]);
	sem_close((info->semaphore)[MEAL_FIN_COUNT]);
	exit(0);
	return (0);
}

static int	ft_flag_timecheck(t_philo *info, t_data *data, int flag, int f2)
{
	sem_wait((info->semaphore)[EXIT_FLAG]);
	if (info->exit_flag != 0)
		f2 = TERMINATE;
	sem_post((info->semaphore)[EXIT_FLAG]);
	if (f2 == TERMINATE)
		return (TERMINATE);
	if (flag != PASS)
		ft_print(info, data, flag);
	else
		gettimeofday(&(data->ntm), NULL);
	if ((data->ntm.tv_sec - data->rtm.tv_sec) * 1000 + (data->ntm.tv_usec \
	- data->rtm.tv_usec) / 1000 < info->lifetime)
		return (CONTINUE);
	else
	{
		sem_wait((info->semaphore)[EXIT_FLAG]);
		(info->exit_flag)++;
		gettimeofday(&(data->ntm), NULL);
		if (info->exit_flag == TERMINATE)
			printf("%ld %d died\n", (data->ntm.tv_sec - info->stm.tv_sec) \
			* 1000 + (data->ntm.tv_usec - info->stm.tv_usec) / 1000, \
			data->pnum);
		sem_post((info->semaphore)[EXIT_FLAG]);
		return (TERMINATE);
	}
}

static int	ft_eating(t_philo *info, t_data *dt)
{
	sem_wait((info->semaphore)[FK_SEM]);
	if (ft_flag_timecheck(info, dt, FORK, CONTINUE) == TERMINATE)
	{
		sem_post((info->semaphore)[FK_SEM]);
		return (TERMINATE);
	}
	sem_wait((info->semaphore)[FK_SEM]);
	if (ft_flag_timecheck(info, dt, FORK, CONTINUE) == TERMINATE)
	{
		sem_post((info->semaphore)[FK_SEM]);
		sem_post((info->semaphore)[FK_SEM]);
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
		if (ft_flag_timecheck(pinfo, tdata, PASS, CONTINUE) == CONTINUE)
		{
			usleep(500);
			gettimeofday(&now, NULL);
			continue ;
		}
		sem_post((pinfo->semaphore)[FK_SEM]);
		sem_post((pinfo->semaphore)[FK_SEM]);
		return (TERMINATE);
	}
	sem_post((pinfo->semaphore)[FK_SEM]);
	sem_post((pinfo->semaphore)[FK_SEM]);
	if (++(tdata->eat_count) != pinfo->max_meal)
		return (CONTINUE);
	sem_wait((pinfo->semaphore)[MEAL_FIN_COUNT]);
	(pinfo->fin_count)++;
	sem_post((pinfo->semaphore)[MEAL_FIN_COUNT]);
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
		if (ft_flag_timecheck(pinfo, tdata, PASS, CONTINUE) == CONTINUE)
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
