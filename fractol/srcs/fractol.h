/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:41:12 by juyojeon          #+#    #+#             */
/*   Updated: 2023/02/07 01:54:10 by juyojeon         ###   ########.fr       */
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
# define KEY_GREEN		5
# define KEY_BLUE		11
# define KEY_RED		15
# define BUTTON_UP		4
# define BUTTON_DOWN	5
# define WIDTH			1000
# define HEIGHT			1000
# define MANDEL			0
# define JULIA			1
# define NEWTON			2
# define GREEN			0
# define BLUE			1
# define RED			2
# define IMAGINARY		0
# define REAL			1
# define MAX_ITER		100

typedef struct s_coor
{
	double	rmin;
	double	rrange;
	double	imin;
	double	irange;	
}	t_coor;

typedef struct	s_unit
{
	int		x;
	int		y;
	double	runit;
	double	iunit;
}	t_unit;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	t_coor	*coor;
	int		colorset[10];
	double	rnum;
	double	inum;
	int		type;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	ft_colorsetting(t_data *all, int colortype);
void	ft_hook_setup(t_data *data);
void	ft_print_image(t_data *image);
void	ft_shift_axis(t_data *all, int axis, int change);
void	ft_expand_fractal(t_data *all, int x, int y);
void	ft_reduct_fractal(t_data *all, int x, int y);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_error(t_data *all, int errnum);
double	ft_atod(char *str);
double	ft_abs(double x);

#endif