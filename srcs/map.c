/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:30:17 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/14 20:09:22 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	texture_background_parsing(t_data *data, int fd, char *ln, int *c);
static int	texture_background_parsing2(t_data *data, char *ln, int config_num);

void	map_parsing(char *path, t_data *data)
{
	int		fd;
	char	*line;
	int		config_bit;

	config_bit = 0b000000;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit("Error : Map file open failed\n", data);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (close(fd) == -1)
				error_exit("Error : Map file close failed\n", data);
			if (data->map_height > 0)
				make_map(data);
			is_valid_map(data, config_bit);
			break ;
		}
		if ((config_bit & COMPLETE_BIT) != COMPLETE_BIT)
			texture_background_parsing(data, fd, line, &config_bit);
		else
			coordinate_parsing(data, fd, line);
	}
}

static void	texture_background_parsing(t_data *data, int fd, char *ln, int *bit)
{
	int		config_num;

	if (ln[0] == '\n')
		return ;
	config_num = -1;
	if ((*bit & NO_BIT) == 0 && ln[0] == 'N' && ln[1] == 'O' && ln[2] == ' ')
		config_num = NORTH;
	else if ((*bit & SO_BIT) == 0 && ln[0] == 'S' && ln[1] == 'O' && ln[2] == ' ')
		config_num = SOUTH;
	else if ((*bit & WE_BIT) == 0 && ln[0] == 'W' && ln[1] == 'E' && ln[2] == ' ')
		config_num = WEST;
	else if ((*bit & EA_BIT) == 0 && ln[0] == 'E' && ln[1] == 'A' && ln[2] == ' ')
		config_num = EAST;
	else if ((*bit & FLOOR_BIT) == 0 && ln[0] == 'F' && ln[1] == ' ')
		config_num = FLOOR;
	else if ((*bit & CEILING_BIT) == 0 && ln[0] == 'C' && ln[1] == ' ')
		config_num = CEILING;
	else
		parsing_error_exit("Error\nMap file have wrong line\n", fd, ln, data);
	*bit += (1 << config_num);
	if (texture_background_parsing2(data, ln, config_num) == FAILURE)
		parsing_error_exit("Error\nMap file have wrong line\n", fd, ln, data);
	free(ln);
}

static int	texture_background_parsing2(t_data *data, char *ln, int config_num)
{
	t_img	*t;
	int		temp;

	ln += 2;
	while (*ln == ' ')
		ln++;
	if (config_num <= EAST)
	{
		t = &(data->texture[config_num]);
		t->img = mlx_xpm_file_to_image(data->mlx, ln, &t->width, &t->height);
		if (!t->img)
			return (FAILURE);
		t->addr = mlx_get_data_addr(t->img, &t->bpp, &t->size_l, &t->endian);
		if (!t->addr)
			return (FAILURE);
		return (SUCCESS);
	}
	temp = color_to_i(ln);
	if (temp == -1)
		return (FAILURE);
	if (config_num == FLOOR)
		data->floor_color = temp;
	else
		data->ceiling_color = temp;
	return (SUCCESS);
}

void	parsing_error_exit(char *msg, int fd, char *line, t_data *data)
{
	free(line);
	close(fd);
	error_exit(msg, data);
}
