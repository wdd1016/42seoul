/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:42:16 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/27 15:37:46 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	find_door_pos(double dir_x, double dir_y, int *ans_x, int *ans_y);

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

void	door_change(t_data *data, t_player *player)
{
	int		ans_x;
	int		ans_y;
	int		i;

	if (data->num_doors == 0)
		return ;
	ans_x = (int)(player->x);
	ans_y = (int)(player->y);
	if (find_door_pos(player->dir_x, player->dir_y, &ans_x, &ans_y))
		return ;
	i = 0;
	while (i < data->num_doors)
	{
		if ((data->door)[i].x == ans_x && (data->door)[i].y == ans_y)
		{
			if ((data->map)[ans_y][ans_x] == '2')
				(data->map)[ans_y][ans_x] = '0';
			else
				(data->map)[ans_y][ans_x] = '2';
			break ;
		}
		i++;
	}
}

static int	find_door_pos(double dir_x, double dir_y, int *ans_x, int *ans_y)
{
	if (dir_x > 0 && dir_y >= -0.7071 && dir_y <= 0.7071)
		*ans_x += 1;
	else if (dir_x < 0 && dir_y >= -0.7071 && dir_y <= 0.7071)
		*ans_x -= 1;
	else if (dir_y > 0 && dir_x >= -0.7071 && dir_x <= 0.7071)
		*ans_y += 1;
	else if (dir_y < 0 && dir_x >= -0.7071 && dir_x <= 0.7071)
		*ans_y -= 1;
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
