/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:30:17 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/17 17:59:16 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	texture_background_parsing(t_data *data, int fd, char *ln, int *c);
static int	config_number(char *ln, int *bit);
static int	texture_background_parsing2(t_data *data, char *ln, int config_num);

void	map_parsing(char *path, t_data *data)
{
	int		fd;
	char	*line;
	int		config_bit;

	config_bit = 0b00000000000;
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
		return (free(ln));
	if (ln[ft_strlen(ln) - 1] == '\n')
		ln[ft_strlen(ln) - 1] = '\0';
	config_num = config_number(ln, bit);
	if (config_num == -1)
		parsing_error_exit("Error\nMap file have wrong line\n", fd, ln, data);
	*bit += (1 << config_num);
	if (texture_background_parsing2(data, ln, config_num) == FAILURE)
		parsing_error_exit("Error\nMap file have wrong line\n", fd, ln, data);
	free(ln);
}

static int	config_number(char *ln, int *bit)
{
	if ((*bit & NBIT) == 0 && ln[0] == 'N' && ln[1] == 'O' && ln[2] == ' ')
		return (NORTH);
	else if ((*bit & SBIT) == 0 && ln[0] == 'S' && ln[1] == 'O' && ln[2] == ' ')
		return (SOUTH);
	else if ((*bit & WBIT) == 0 && ln[0] == 'W' && ln[1] == 'E' && ln[2] == ' ')
		return (WEST);
	else if ((*bit & EBIT) == 0 && ln[0] == 'E' && ln[1] == 'A' && ln[2] == ' ')
		return (EAST);
	else if ((*bit & DBIT) == 0 && ln[0] == 'D' && ln[1] == 'O' && ln[2] == ' ')
		return (DOOR);
	else if ((*bit & S1BT) == 0 && ln[0] == 'S' && ln[1] == '1' && ln[2] == ' ')
		return (SP1);
	else if ((*bit & S2BT) == 0 && ln[0] == 'S' && ln[1] == '2' && ln[2] == ' ')
		return (SP2);
	else if ((*bit & S3BT) == 0 && ln[0] == 'S' && ln[1] == '3' && ln[2] == ' ')
		return (SP3);
	else if ((*bit & S4BT) == 0 && ln[0] == 'S' && ln[1] == '4' && ln[2] == ' ')
		return (SP4);
	else if ((*bit & FLOOR_BIT) == 0 && ln[0] == 'F' && ln[1] == ' ')
		return (FLOOR);
	else if ((*bit & CEILING_BIT) == 0 && ln[0] == 'C' && ln[1] == ' ')
		return (CEILING);
	else
		return (-1);
}

static int	texture_background_parsing2(t_data *data, char *ln, int config_num)
{
	t_img	*t;
	int		temp;

	ln += 2;
	while (*ln == ' ')
		ln++;
	if (config_num <= SP4)
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
