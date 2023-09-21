/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:20:56 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/21 21:18:40 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	window_event(void);
static int	key_event(int key, t_data *data);
static void	mouse_mode(int key, t_data *data);

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
	else if (key == KEY_LEFT)
		rotate_player(&data->player, -(data->player.turn_speed));
	else if (key == KEY_RIGHT)
		rotate_player(&data->player, data->player.turn_speed);
	else if (key == KEY_SPACE)
		door_change(data, &data->player);
	else if (key == KEY_N || key == KEY_M)
		mouse_mode(key, data);
	return (0);
}

void	rotate_player(t_player *p, double t_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	old_plane_x = p->plane_x;
	p->dir_x = old_dir_x * cos(t_speed) - p->dir_y * sin(t_speed);
	p->dir_y = old_dir_x * sin(t_speed) + p->dir_y * cos(t_speed);
	p->plane_x = old_plane_x * cos(t_speed) - p->plane_y * sin(t_speed);
	p->plane_y = old_plane_x * sin(t_speed) + p->plane_y * cos(t_speed);
}

static void	mouse_mode(int key, t_data *data)
{
	if (key == KEY_M)
	{
		mlx_mouse_hide();
		mlx_mouse_move(data->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		data->mouse_mode_flag = TRUE;
	}
	else
	{
		mlx_mouse_show();
		data->mouse_mode_flag = FALSE;
	}
}
