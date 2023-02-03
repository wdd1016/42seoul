/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:41:12 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/03 23:33:04 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../minilibx/mlx.h"
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

# define KEY_ESC		53
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_RED		15
# define KEY_BLUE		11
# define BUTTON_UP		4
# define BUTTON_DOWN	5
# define WIDTH			1200
# define HEIGHT			800
# define MANDEL			0
# define JULIA			1
# define NEWTON			2

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	double	rnum;
	double	inum;
	int		type;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	ft_error_handler(int errnum);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_hook_setup(t_data *data);

#endif