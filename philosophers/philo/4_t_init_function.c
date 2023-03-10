/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_t_init_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:44:34 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/10 16:03:44 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_init_sleep(t_philo *info, t_data *data);

void	ft_find_pnum_init_data(t_philo *pinfo, t_data *tdata)
{
	int	temp;

	pthread_mutex_lock(&(pinfo->inter->sysmutex)[FIL_NUM]);
	temp = ++(pinfo->inter->pil_num);
	pthread_mutex_unlock(&(pinfo->inter->sysmutex)[FIL_NUM]);
	tdata->pnum = temp;
	tdata->eat_count = 0;
	tdata->rtm.tv_sec = pinfo->stm.tv_sec;
	tdata->rtm.tv_usec = pinfo->stm.tv_usec;
	tdata->startdiff = 0;
	tdata->fir_fork = ((temp - 1) / 2) * 2;
	if (temp == 1)
		tdata->sec_fork = pinfo->num_people - 1;
	else if (temp % 2 == 1)
		tdata->sec_fork = tdata->fir_fork - 1;
	else if (temp % 2 == 0)
		tdata->sec_fork = tdata->fir_fork + 1;
	ft_init_sleep(pinfo, tdata);
}

static void	ft_init_sleep(t_philo *info, t_data *data)
{
	if (info->num_people % 2 == 0 && data->pnum % 2 == 1)
		usleep(info->mealtime * 500);
	else if (info->num_people % 2 == 1)
	{
		if (data->pnum == info->num_people && info->num_people % 3 == 1)
			usleep(info->mealtime * 500);
		else if (data->pnum % 3 == 2)
			usleep(info->mealtime * 500);
		else if (data->pnum % 3 == 0)
			usleep(info->mealtime * 1500);
	}
}

void	ft_die(t_philo *pinfo, t_data *tdata)
{
	pthread_mutex_lock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
	(pinfo->inter->exit_flag)++;
	pthread_mutex_lock(&(pinfo->inter->sysmutex)[GETTIME]);
	gettimeofday(&(tdata->ntm), NULL);
	pthread_mutex_unlock(&(pinfo->inter->sysmutex)[GETTIME]);
	if (pinfo->inter->exit_flag == TERMINATE)
		printf("%ld %d died\n", (tdata->ntm.tv_sec - \
		pinfo->stm.tv_sec) * 1000 + (tdata->ntm.tv_usec - \
		pinfo->stm.tv_usec) / 1000, tdata->pnum);
	pthread_mutex_unlock(&(pinfo->inter->sysmutex)[EXIT_FLAG]);
}

int	ft_is_max_meal(t_philo *pinfo, t_data *tdata)
{
	if (++(tdata->eat_count) != pinfo->max_meal)
		return (CONTINUE);
	pthread_mutex_lock(&(pinfo->inter->sysmutex)[MEAL_FIN_COUNT]);
	(pinfo->inter->fin_count)++;
	pthread_mutex_unlock(&(pinfo->inter->sysmutex)[MEAL_FIN_COUNT]);
	return (TERMINATE);
}
