/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 23:27:22 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/01 17:14:30 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_macro.h"
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

void	error_exit(const char *str);

int		ft_is_cubformat(const char *path, const char *format);

void	ft_mlx_init(t_data *data);
void	ft_map_parsing(char *path, t_data *data);
void	ft_set_hooks(t_data *data);
int		ft_print_image(t_data *data);

#endif