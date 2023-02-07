/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:30:13 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/07 18:47:20 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	ft_key_handler(int keycode, t_data *all);
static int	ft_mouse_handler(int button, int x, int y, t_data *all);
static void	ft_kill_process(t_data *all);

void	ft_hook_setup_bonus(t_data *all)
{
	mlx_key_hook(all->win, ft_key_handler, all);
	mlx_mouse_hook(all->win, ft_mouse_handler, all);
}

static int	ft_key_handler(int keycode, t_data *all)
{
	if (keycode == KEY_UP)
		ft_shift_axis(all, IMAGINARY, -1);
	else if (keycode == KEY_DOWN)
		ft_shift_axis(all, IMAGINARY, 1);
	else if (keycode == KEY_LEFT)
		ft_shift_axis(all, REAL, -1);
	else if (keycode == KEY_RIGHT)
		ft_shift_axis(all, REAL, 1);
	else if (keycode == KEY_ESC)
		ft_kill_process(all);
	else if (keycode == KEY_GREEN)
		ft_colorsetting(all, GREEN);
	else if (keycode == KEY_BLUE)
		ft_colorsetting(all, BLUE);
	else if (keycode == KEY_RED)
		ft_colorsetting(all, RED);
	else
		return (0);
	ft_print_image(all);
	return (0);
}

static int	ft_mouse_handler(int button, int x, int y, t_data *all)
{
	if (button == BUTTON_DOWN)
		ft_expand_fractal(all, x, y);
	else if (button == BUTTON_UP)
		ft_reduct_fractal(all, x, y);
	else
		return (0);
	ft_print_image(all);
	return (0);
}

static void	ft_kill_process(t_data *all)
{
	if (all->win)
		mlx_clear_window(all->mlx, all->win);
	if (all->img)
		mlx_destroy_image(all->mlx, all->img);
	if (all->win)
		mlx_destroy_window(all->mlx, all->win);
	if (all->coor)
		free(all->coor);
	free(all->mlx);
	if (write(1, "Enter the ESC key\n", 18) < 0)
		exit(1);
	exit(0);
}
