/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:46:21 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/04 23:46:44 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_is_right_map(t_data *data, int config_cnt)
{
	int	i;
	int	j;

	if (data->player.x == 0.0)
		error_exit("Error : No player\n");
	else if (config_cnt != 0b111111)
		error_exit("Error : Missing config\n");
	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
		{
			if (data->map[i][j] == '0')
				ft_is_right_position(data, i, j);
		}
	}
}

static void	ft_is_right_position(t_data *data, int i, int j)
{
	if (i == 0 || i == data->map_height - 1 || j == 0 || j == data->map_width - 1)
		error_exit("Error : Invalid map\n");
	else if (data->map[i - 1][j] == ' ' || data->map[i + 1][j] == ' ' || \
	data->map[i][j - 1] == ' ' || data->map[i][j + 1] == ' ')
		error_exit("Error : Invalid map\n");
	else if (data->map[i - 1][j - 1] == ' ' || data->map[i - 1][j + 1] == ' ' \
	|| data->map[i + 1][j - 1] == ' ' || data->map[i + 1][j + 1] == ' ')
		error_exit("Error : Invalid map\n");
}