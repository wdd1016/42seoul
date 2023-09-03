/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_coor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:07:49 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/03 18:02:03 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_fill_player(t_data *data, int map_row, char *line, int idx);
static void	ft_is_right_position(t_data *data, int i, int j);

void	coordinate_parsing(t_data *data, int fd, char *line)
{
	static int	map_row = -1;
	int			i;

	if (map_row == -1 && line[0] == '\n')
		return ;
	if (++map_row >= MAP_MAX_ROWS)
		parsing_error_exit("Error : Too many map rows\n", fd, line);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	if (ft_strlen(line) > MAP_MAX_COLS)
		parsing_error_exit("Error : Too many map cols\n");
	i = -1;
	while (++i < ft_strlen(line))
	{
		if (data->player.x == 0.0 && \
		(line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E'))
			ft_fill_player(data, map_row, line, i);
		if (line[i] != '0' && line[i] != '1' && line[i] != ' ')
			parsing_error_exit("Error : Invalid map character\n", fd, line);
		data->map[map_row][i] = line[i];
	}
}

static void	ft_fill_player(t_data *data, int map_row, char *line, int idx)
{
	double	direction;

	data->player.x = idx + 0.5;
	data->player.y = map_row + 0.5;
	if (line[idx] == 'N')
		direction = 0.0;
	else if (line[idx] == 'S')
		direction = PI;
	else if (line[idx] == 'W')
		direction = PI / 2;
	else if (line[idx] == 'E')
		direction = PI * 3 / 2;
	data->player.direction = direction;
	line[idx] = '0';
}

void	ft_is_right_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MAP_MAX_ROWS)
	{
		j = -1;
		while (++j < MAP_MAX_COLS)
		{
			if (data->map[i][j] == '0')
				ft_is_right_position(data, i, j);
		}
	}
}

static void	ft_is_right_position(t_data *data, int i, int j)
{
	if (i == 0 || i == MAP_MAX_ROWS - 1 || j == 0 || j == MAP_MAX_COLS - 1)
		error_exit("Error : Invalid map\n");
	else if (data->map[i - 1][j] == ' ' || data->map[i + 1][j] == ' ' || \
	data->map[i][j - 1] == ' ' || data->map[i][j + 1] == ' ')
		error_exit("Error : Invalid map\n");
	else if (data->map[i - 1][j - 1] == ' ' || data->map[i - 1][j + 1] == ' ' || \
	data->map[i + 1][j - 1] == ' ' || data->map[i + 1][j + 1] == ' ')
		error_exit("Error : Invalid map\n");
}