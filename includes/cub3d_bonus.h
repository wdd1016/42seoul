/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 23:27:22 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/21 22:45:01 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3d_macro_bonus.h"
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

void	error_exit(const char *str, t_data *data);
int		is_valid_format(const char *path, const char *format);
int		color_to_i(const char *str);
void	data_mlx_init(t_data *data);

void	map_parsing(char *path, t_data *data);
void	parsing_error_exit(char *msg, int fd, char *line, t_data *data);
void	coordinate_parsing(t_data *data, int fd, char *line);
void	make_map(t_data *data);
void	is_valid_map(t_data *data, int config_cnt);

void	set_hooks(t_data *data);
void	rotate_player(t_player *p, double t_speed);
void	move_updown_player(int key, t_player *p, char **map);
void	move_side_player(int key, t_player *p, char **map);
void	door_change(t_data *data, t_player *p);

void	rendering_image(t_data *data);
void	input_vertical_line(t_data *data, t_img *img, t_ray *ray, int i);

void	sort_sprites(t_data *data);
void	input_sprite(t_data *data, t_img *s_img, t_sprite *spr);

void	input_minimap(t_data *data);

#endif