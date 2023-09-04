/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_coor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:07:49 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/05 00:00:02 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_map	*ft_new_tempmap(t_data *data, char *line);
static void		ft_fill_player(t_data *data, int rowidx, char *line, int idx);

void	coordinate_parsing(t_data *data, int fd, char *line)
{
	int		i;
	t_map	*use_line;

	if (!(data->tempmap) && line[0] == '\n')
		return (free(line));
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	use_line = ft_new_tempmap(data, line);
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
			ft_fill_player(data, data->map_height - 1, line, i);
		if (line[i] != '0' && line[i] != '1' && line[i] != ' ')
			parsing_error_exit("Error : Invalid map char\n", fd, line, data);
	}
}

static t_map	*ft_new_tempmap(t_data *data, char *line)
{
	t_map	*new;
	t_map	*temp;

	new = (t_map *)malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->line = line;
	new->len = ft_strlen(line);
	new->next = NULL;
	if (!(data->tempmap))
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

static void	ft_fill_player(t_data *data, int rowidx, char *line, int idx)
{
	double	direction;

	data->player.x = idx + 0.5;
	data->player.y = rowidx + 0.5;
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

void	ft_make_map(t_data *data)
{
	int		i;
	int		j;
	t_map	*temp;

	data->map = (char **)malloc(sizeof(char *) * data->map_height);
	if (!(data->map))
		error_exit("Error : Allocation failed\n", data);
	temp = data->tempmap;
	i = -1;
	while (++i < data->map_height)
	{
		map[i] = (char *)malloc(sizeof(char) * data->map_width);
		if (!map[i])
			error_exit("Error : Allocation failed\n", data);
		j = -1;
		while (++j < temp->len)
			map[i][j] = temp->line[j];
		while (++j < data->map_width)
			map[i][j] = ' ';
		temp = temp->next;
	}
	while (data->tempmap)
	{
		temp = data->tempmap;
		data->tempmap = data->tempmap->next;
		free(temp->line);
		free(temp);
	}
}
