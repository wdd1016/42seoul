/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 23:27:22 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/09 19:54:07 by juyojeon         ###   ########.fr       */
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

void	error_exit(const char *str, t_data *data);

int		is_valid_format(const char *path, const char *format);

void	data_mlx_init(t_data *data);

void	map_parsing(char *path, t_data *data);
void	parsing_error_exit(char *msg, int fd, char *line, t_data *data);
void	coordinate_parsing(t_data *data, int fd, char *line);
void	make_map(t_data *data);
void	is_valid_map(t_data *data, int config_cnt);

void	set_hooks(t_data *data);
int		print_image(t_data *data);

#endif