/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:20:56 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/15 17:36:19 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	window_event(void);
static int	key_event(int key, t_data *data);
static void	rotate_player(int key, t_player *p);

void	set_hooks(t_data *data)
{
	mlx_hook(data->win, KEY_PRESS, 1L << 0, key_event, data);
	mlx_hook(data->win, KEY_EXIT, 0, window_event, data);
}

static int	window_event(void)
{
	write(1, "Click the ESC button\n", 21);
	exit(0);
}

static int	key_event(int key, t_data *data)
{	
	if (key == KEY_ESC)
	{
		write(1, "Enter the ESC key\n", 18);
		exit(0);
	}
	if (key == KEY_W || key == KEY_S)
		move_updown_player(key, &data->player, data->map);
	else if (key == KEY_A || key == KEY_D)
		move_side_player(key, &data->player, data->map);
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		rotate_player(key, &data->player);
	else
		return (0);
	rendering_image(data);
	return (0);
}

static void	rotate_player(int key, t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;
	double	speed;

	old_dir_x = p->dir_x;
	old_plane_x = p->plane_x;
	if (key == KEY_RIGHT)
		speed = p->turn_speed;
	else
		speed = -(p->turn_speed);
	p->dir_x = old_dir_x * cos(speed) - p->dir_y * sin(speed);
	p->dir_y = old_dir_x * sin(speed) + p->dir_y * cos(speed);
	p->plane_x = old_plane_x * cos(speed) - p->plane_y * sin(speed);
	p->plane_y = old_plane_x * sin(speed) + p->plane_y * cos(speed);
}
