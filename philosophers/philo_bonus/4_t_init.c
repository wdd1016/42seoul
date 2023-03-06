/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_t_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:44:34 by juyojeon          #+#    #+#             */
/*   Updated: 2023/03/06 23:37:53 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_find_pnum_init_data(t_philo *info, t_data *data, int p_num)
{
	data->pnum = p_num;
	data->eat_count = 0;
	data->startdiff = 0;
	data->rtm.tv_sec = info->stm.tv_sec;
	data->rtm.tv_usec = info->stm.tv_usec;
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
