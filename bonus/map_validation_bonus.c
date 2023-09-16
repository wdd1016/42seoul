/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:46:21 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/16 20:00:03 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	is_valid_position(t_data *data, int i, int j);

void	is_valid_map(t_data *data, int config_bit)
{
	int	i;
	int	j;

	if (data->player.x == 0.0)
		error_exit("Error\nNo player\n", data);
	else if (config_bit != COMPLETE_BIT)
		error_exit("Error\nMissing config\n", data);
	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
		{
			if (data->map[i][j] == '0')
				is_valid_position(data, i, j);
		}
	}
}

static void	is_valid_position(t_data *data, int i, int j)
{
	if (i == 0 || i == data->map_height - 1 || \
	j == 0 || j == data->map_width - 1)
		error_exit("Error\nInvalid map\n", data);
	else if (data->map[i - 1][j] == ' ' || data->map[i + 1][j] == ' ' || \
	data->map[i][j - 1] == ' ' || data->map[i][j + 1] == ' ')
		error_exit("Error\nInvalid map\n", data);
	else if (data->map[i - 1][j - 1] == ' ' || data->map[i - 1][j + 1] == ' ' \
	|| data->map[i + 1][j - 1] == ' ' || data->map[i + 1][j + 1] == ' ')
		error_exit("Error\nInvalid map\n", data);
}
