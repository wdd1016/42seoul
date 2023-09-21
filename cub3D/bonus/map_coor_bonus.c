/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_coor_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:07:49 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/17 16:55:42 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static t_map	*new_tempmap(t_data *data, char *line);
static void		fill_player(t_data *data, int rowidx, char *line, int idx);
static void		door_store(t_data *data, int row_idx, int col_idx, int fd);

void	coordinate_parsing(t_data *data, int fd, char *line)
{
	int		i;
	t_map	*use_line;

	if (!data->tempmap && line[0] == '\n')
		return (free(line));
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	use_line = new_tempmap(data, line);
	if (!use_line)
		parsing_error_exit("Error : Allocation failed\n", fd, line, data);
	data->map_height++;
	if (use_line->len > data->map_width)
		data->map_width = use_line->len;
	i = -1;
	while (++i < use_line->len)
	{
		if (data->player.x == 0.0 && \
		(line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E'))
			fill_player(data, data->map_height - 1, line, i);
		else if (line[i] == '2')
			door_store(data, data->map_height - 1, i, fd);
		if ((line[i] < '0' || line[i] > '3') && line[i] != ' ')
			parsing_error_exit("Error\nInvalid map char\n", fd, 0, data);
	}
}

static t_map	*new_tempmap(t_data *data, char *line)
{
	t_map	*new;
	t_map	*temp;

	new = (t_map *)malloc(sizeof(t_map));
	if (!new)
		return (0);
	new->line = 0;
	if (line)
		new->line = line;
	new->len = ft_strlen(line);
	new->next = 0;
	if (!data->tempmap)
		data->tempmap = new;
	else
	{
		temp = data->tempmap;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	return (new);
}

static void	fill_player(t_data *data, int row_idx, char *line, int col_idx)
{
	double	y_direction;
	double	x_direction;

	data->player.x = col_idx + 0.5;
	data->player.y = row_idx + 0.5;
	y_direction = 0.0;
	x_direction = 0.0;
	if (line[col_idx] == 'N')
		y_direction = -1.0;
	else if (line[col_idx] == 'S')
		y_direction = 1.0;
	else if (line[col_idx] == 'W')
		x_direction = -1.0;
	else if (line[col_idx] == 'E')
		x_direction = 1.0;
	data->player.dir_y = y_direction;
	data->player.dir_x = x_direction;
	data->player.plane_y = x_direction * 0.66;
	data->player.plane_x = y_direction * (-0.66);
	line[col_idx] = '0';
}

static void	door_store(t_data *data, int row_idx, int col_idx, int fd)
{
	if (data->num_doors >= DOOR_SIZE)
		parsing_error_exit("Error\nToo many doors\n", fd, 0, data);
	(data->door)[data->num_doors].x = col_idx;
	(data->door)[data->num_doors].y = row_idx;
	(data->num_doors)++;
}

void	make_map(t_data *data)
{
	int		i;
	int		j;
	t_map	*temp;

	data->map = (char **)malloc(sizeof(char *) * data->map_height);
	if (!(data->map))
		error_exit("Error : Allocation failed\n", data);
	i = -1;
	while (++i < data->map_height && data->tempmap)
	{
		(data->map)[i] = (char *)malloc(sizeof(char) * (data->map_width + 1));
		if (!(data->map)[i])
			error_exit("Error : Allocation failed\n", data);
		j = -1;
		while (++j < data->tempmap->len)
			(data->map)[i][j] = (data->tempmap->line)[j];
		while (j < data->map_width)
			(data->map)[i][j++] = ' ';
		(data->map)[i][j] = '\0';
		temp = data->tempmap;
		data->tempmap = data->tempmap->next;
		free(temp->line);
		free(temp);
	}
}
