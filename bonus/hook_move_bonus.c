/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:42:16 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/16 23:24:57 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	move_updown_player(int key, t_player *p, char **map)
{
	if (key == KEY_W)
	{
		if (map[(int)(p->y + p->dir_y * p->walk_speed * 1.2)][(int)p->x] == '0')
			p->y += p->dir_y * p->walk_speed;
		if (map[(int)p->y][(int)(p->x + p->dir_x * p->walk_speed * 1.2)] == '0')
			p->x += p->dir_x * p->walk_speed;
	}
	else if (key == KEY_S)
	{
		if (map[(int)(p->y - p->dir_y * p->walk_speed * 1.2)][(int)p->x] == '0')
			p->y -= p->dir_y * p->walk_speed;
		if (map[(int)p->y][(int)(p->x - p->dir_x * p->walk_speed * 1.2)] == '0')
			p->x -= p->dir_x * p->walk_speed;
	}
}

void	move_side_player(int key, t_player *p, char **map)
{
	if (key == KEY_D)
	{
		if (map[(int)(p->y + p->dir_x * p->walk_speed * 1.2)][(int)p->x] == '0')
			p->y += p->dir_x * p->walk_speed;
		if (map[(int)p->y][(int)(p->x - p->dir_y * p->walk_speed * 1.2)] == '0')
			p->x -= p->dir_y * p->walk_speed;
	}
	else if (key == KEY_A)
	{
		if (map[(int)(p->y - p->dir_x * p->walk_speed * 1.2)][(int)p->x] == '0')
			p->y -= p->dir_x * p->walk_speed;
		if (map[(int)p->y][(int)(p->x + p->dir_y * p->walk_speed * 1.2)] == '0')
			p->x += p->dir_y * p->walk_speed;
	}
}

void	door_change(t_data *data, t_player *p)
{
	t_door	*t;

	t = data->door;
	while (t->next)
	{
		if (valid_door(p, t))
			continue ;
		// if (data->map[t->y][t->x] == '1')
		// 	data->map[t->y][t->x] = '0';
		// else if (data->map[t->y][t->x] == '0')
		// 	data->map[t->y][t->x] = '1';
		// t = t->next;
	}
}

static int	valid_door(t_player *p, t_door *d)
{
		// if (t->x == (int)(p->x) && t->y == (int)(p->y))
		// 	continue ;
		// if (p->dir_x > 0 && ((int)(p->x) - t->x < 0 || (int)(p->x) - t->x > 1))
		// 	continue ;
		// if (p->dir_x == 0 && ((int)(p->x) - t->x != 0))
		// 	continue ;
		// if (p->dir_x < 0 && (t->x - (int)(p->x) < 0 || t->x - (int)(p->x) > 1))
		// 	continue ;
		// if (p->dir_y > 0 && ((int)(p->y) - t->y < 0 || (int)(p->y) - t->y > 1))
		// 	continue ;
		// if (p->dir_y == 0 && ((int)(p->y) - t->y != 0))
		// 	continue ;
		// if (p->dir_y < 0 && (t->y - (int)(p->y) < 0 || t->y - (int)(p->y) > 1))
		// 	continue ;
}