/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:42:16 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/14 22:29:16 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_updown_player(int key, t_player *p, char **map)
{
	if (key == KEY_W)
	{
		if (map[(int)(p->y + p->dir_y * p->walk_speed)][(int)p->x] == '0')
			p->y += p->dir_y * p->walk_speed;
		if (map[(int)p->y][(int)(p->x + p->dir_x * p->walk_speed)] == '0')
			p->x += p->dir_x * p->walk_speed;
	}
	else if (key == KEY_S)
	{
		if (map[(int)(p->y - p->dir_y * p->walk_speed)][(int)p->x] == '0')
			p->y -= p->dir_y * p->walk_speed;
		if (map[(int)p->y][(int)(p->x - p->dir_x * p->walk_speed)] == '0')
			p->x -= p->dir_x * p->walk_speed;
	}
}

void	move_side_player(int key, t_player *p, char **map)
{
	if (key == KEY_D)
	{
		if (map[(int)(p->y + p->dir_x * p->walk_speed)][(int)p->x] == '0')
			p->y += p->dir_x * p->walk_speed;
		if (map[(int)p->y][(int)(p->x - p->dir_y * p->walk_speed)] == '0')
			p->x -= p->dir_y * p->walk_speed;
	}
	else if (key == KEY_A)
	{
		if (map[(int)(p->y - p->dir_x * p->walk_speed)][(int)p->x] == '0')
			p->y -= p->dir_x * p->walk_speed;
		if (map[(int)p->y][(int)(p->x + p->dir_y * p->walk_speed)] == '0')
			p->x += p->dir_y * p->walk_speed;
	}
}
