/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:30:17 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/04 19:35:26 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	texture_background_parsing(t_data *data, int fd, char *ln, int *c);
static int	texture_background_parsing2(t_data *data, char *ln, int config_num);

void	ft_map_parsing(char *path, t_data *data)
{
	int		fd;
	char	*line;
	int		config_cnt;

	config_cnt = 0b000000;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit("Error : Map file open failed\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (close(fd) == -1)
				error_exit("Error : Map file close failed\n");
			ft_is_right_map(data);
			break ;
		}
		if (config_cnt & 0b111111 < 0b111111)
			texture_background_parsing(data, fd, line, &config_cnt);
		else
			coordinate_parsing(data, fd, line);
		free(line);
	}
}

static void	texture_background_parsing(t_data *data, int fd, char *ln, int *c)
{
	int		config_num;

	if (ln[0] == '\n')
		return ;
	if (*c & 0b000001 == 0 && ln[0] == 'N' && ln[1] == 'O' && ln[2] == ' ')
		config_num = NORTH;
	else if (*c & 0b000010 == 0 && ln[0] == 'S' && ln[1] == 'O' && ln[2] == ' ')
		config_num = SOUTH;
	else if (*c & 0b000100 == 0 && ln[0] == 'W' && ln[1] == 'E' && ln[2] == ' ')
		config_num = WEST;
	else if (*c & 0b001000 == 0 && ln[0] == 'E' && ln[1] == 'A' && ln[2] == ' ')
		config_num = EAST;
	else if (*c & 0b010000 == 0 && ln[0] == 'F' && ln[1] == ' ')
		config_num = FLOOR;
	else if (*c & 0b100000 == 0 && ln[0] == 'C' && ln[1] == ' ')
		config_num = CEILING;
	else
		parsing_error_exit("Error : Map file parsing failed\n", fd, ln);
	*c += 1 << config_num;
	if (texture_background_parsing2(data, ln, config_num) == FAILURE)
		parsing_error_exit("Error : Map file parsing failed\n", fd, ln);
}

static int	texture_background_parsing2(t_data *data, char *ln, int config_num)
{
	t_texture	*tmp;
	int			temp;

	if (config_num <= EAST)
	{
		tmp = &(data->texture[config_num - 1]);
		tmp->img = mlx_xpm_file_to_image(data->mlx, ln + 3, \
		&(tmp->width), &(tmp->height));
		if (!tmp->img)
			return (FAILURE);
		tmp->data = mlx_get_data_addr(tmp->img, \
		&(tmp->bpp), &(tmp->size_l), &(tmp->endian));
		if (!tmp->data)
			return (FAILURE);
		return (SUCCESS);
	}
	temp = ft_colortoi(ln + 2);
	if (temp == -1)
		return (FAILURE);
	if (config_num == FLOOR)
		data->floor_color = temp;
	else
		data->ceiling_color = temp;
	return (SUCCESS);
}

void	parsing_error_exit(char *msg, int fd, char *line)
{
	free(line);
	close(fd);
	error_exit(msg);
}
