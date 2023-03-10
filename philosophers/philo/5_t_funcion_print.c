/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_t_funcion_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:15:55 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/10 15:53:06 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print(t_philo *pinfo, t_data *tdata, int flag)
{
	if (flag == FORK)
		ft_print_fork(pinfo, tdata);
	else if (flag == EAT)
		ft_print_eat(pinfo, tdata);
	else if (flag == SLEEP)
		ft_print_sleep(pinfo, tdata);
	else if (flag == THINK)
		ft_print_think(pinfo, tdata);
}

void	ft_print_fork(t_philo *pinfo, t_data *tdata)
{
	pthread_mutex_lock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
	pthread_mutex_lock(&(pinfo->inter->sysmutex)[GETTIME]);
	gettimeofday(&(tdata->ntm), NULL);
	pthread_mutex_unlock(&(pinfo->inter->sysmutex)[GETTIME]);
	if (pinfo->inter->exit_flag == CONTINUE && \
	(tdata->ntm.tv_sec - tdata->rtm.tv_sec) * 1000 + \
	(tdata->ntm.tv_usec - tdata->rtm.tv_usec) / 1000 <= pinfo->lifetime)
		printf("%ld %d has taken a fork\n", \
		(tdata->ntm.tv_sec - pinfo->stm.tv_sec) * 1000 + \
		(tdata->ntm.tv_usec - pinfo->stm.tv_usec) / 1000, tdata->pnum);
	pthread_mutex_unlock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
}

void	ft_print_eat(t_philo *pinfo, t_data *tdata)
{
	pthread_mutex_lock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
	pthread_mutex_lock(&(pinfo->inter->sysmutex)[GETTIME]);
	gettimeofday(&(tdata->ntm), NULL);
	pthread_mutex_unlock(&(pinfo->inter->sysmutex)[GETTIME]);
	if (pinfo->inter->exit_flag == CONTINUE && \
	(tdata->ntm.tv_sec - tdata->rtm.tv_sec) * 1000 + \
	(tdata->ntm.tv_usec - tdata->rtm.tv_usec) / 1000 <= pinfo->lifetime)
		printf("%ld %d has taken a fork\n%ld %d is eating\n", \
		(tdata->ntm.tv_sec - pinfo->stm.tv_sec) * 1000 + \
		(tdata->ntm.tv_usec - pinfo->stm.tv_usec) / 1000, tdata->pnum, \
		(tdata->ntm.tv_sec - pinfo->stm.tv_sec) * 1000 + \
		(tdata->ntm.tv_usec - pinfo->stm.tv_usec) / 1000, tdata->pnum);
	pthread_mutex_unlock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
}

void	ft_print_sleep(t_philo *pinfo, t_data *tdata)
{
	pthread_mutex_lock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
	pthread_mutex_lock(&(pinfo->inter->sysmutex)[GETTIME]);
	gettimeofday(&(tdata->ntm), NULL);
	pthread_mutex_unlock(&(pinfo->inter->sysmutex)[GETTIME]);
	if (pinfo->inter->exit_flag == CONTINUE && \
	(tdata->ntm.tv_sec - tdata->rtm.tv_sec) * 1000 + \
	(tdata->ntm.tv_usec - tdata->rtm.tv_usec) / 1000 <= pinfo->lifetime)
		printf("%ld %d is sleeping\n", \
		(tdata->ntm.tv_sec - pinfo->stm.tv_sec) * 1000 + \
		(tdata->ntm.tv_usec - pinfo->stm.tv_usec) / 1000, tdata->pnum);
	pthread_mutex_unlock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
}

void	ft_print_think(t_philo *pinfo, t_data *tdata)
{
	pthread_mutex_lock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
	pthread_mutex_lock(&(pinfo->inter->sysmutex)[GETTIME]);
	gettimeofday(&(tdata->ntm), NULL);
	pthread_mutex_unlock(&(pinfo->inter->sysmutex)[GETTIME]);
	if (pinfo->inter->exit_flag == CONTINUE && \
	(tdata->ntm.tv_sec - tdata->rtm.tv_sec) * 1000 + \
	(tdata->ntm.tv_usec - tdata->rtm.tv_usec) / 1000 <= pinfo->lifetime)
		printf("%ld %d is thinking\n", \
		(tdata->ntm.tv_sec - pinfo->stm.tv_sec) * 1000 + \
		(tdata->ntm.tv_usec - pinfo->stm.tv_usec) / 1000, tdata->pnum);
	pthread_mutex_unlock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
}
