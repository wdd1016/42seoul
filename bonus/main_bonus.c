/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:53:21 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/16 19:59:42 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	print_image(t_data *data);
static void	free_allocated_data(t_data *data);

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2 || is_valid_format(argv[1], ".cub") == FAILURE)
		error_exit("Argument Error : [Usage] ./cub3D any.cub\n", &data);
	data_mlx_init(&data);
	map_parsing(argv[1], &data);
	set_hooks(&data);
	rendering_image(&data);
	print_image(&data);
	mlx_loop_hook(data.mlx, print_image, &data);
	mlx_loop(data.mlx);
	free_allocated_data(&data);
	exit(EXIT_SUCCESS);
}

static int	print_image(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

void	error_exit(const char *str, t_data *data)
{
	t_map	*temp;
	int		i;

	write(2, str, ft_strlen(str));
	if (data->map)
	{
		i = -1;
		while (++i < data->map_height)
			free(data->map[i]);
		free(data->map);
	}
	if (data->tempmap)
	{
		while (data->tempmap)
		{
			temp = data->tempmap;
			if (temp->line)
				free(temp->line);
			data->tempmap = data->tempmap->next;
			free(temp);
		}
	}
	exit(EXIT_FAILURE);
}

static void	free_allocated_data(t_data *data)
{
	t_map	*temp;
	int		i;

	if (data->map)
	{
		i = -1;
		while (++i < data->map_height)
			free(data->map[i]);
		free(data->map);
	}
	if (data->tempmap)
	{
		while (data->tempmap)
		{
			temp = data->tempmap;
			if (temp->line)
				free(temp->line);
			data->tempmap = data->tempmap->next;
			free(temp);
		}
	}
}
