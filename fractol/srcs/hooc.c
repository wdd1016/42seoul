/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:30:13 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/03 23:02:44 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_key_handler(int keycode, t_data *all);
static int	ft_mouse_handler(int button, int x, int y, t_data *all);
static void	ft_kill_process(t_data *all);

void	ft_hook_setup(t_data *all)
{
	mlx_key_hook(all->win, ft_key_handler, all);
	mlx_mouse_hook(all->win, ft_mouse_handler, all);
}

static int	ft_key_handler(int keycode, t_data *all)
{
	if (keycode == KEY_UP)
		ft_move_range(all, -1, 0);
	else if (keycode == KEY_DOWN)
		ft_move_range(all, 1, 0);
	else if (keycode == KEY_LEFT)
		ft_move_range(all, 0, -1);
	else if (keycode == KEY_RIGHT)
		ft_move_range(all, 0, 1);
	if (keycode == KEY_ESC)
		ft_kill_process(all);
	else if (keycode == KEY_RED)
		ft_change_palette(all, KEY_RED);
	else if (keycode == KEY_BLUE)
		ft_change_palette(all, KEY_BLUE);
	return (0);
}

static int	ft_mouse_handler(int button, int x, int y, t_data *all)
{
	if (button == BUTTON_UP)
		ft_expand_fractal(all, x, y);
	else if (button == BUTTON_DOWN)
		ft_reduct_fractal(all, x, y);
}

static void	ft_kill_process(t_data *all)
{
	if (all->win)
		mlx_clear_window(all->mlx, all->win);
	if (all->img)
		mlx_destroy_image(all->mlx, all->img);
	if (all->win)
		mlx_destroy_window(all->mlx, all->win);
	free(all->mlx);
	write(1, "Enter the ESC key\n", 18);
	exit(0);
}
