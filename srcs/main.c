/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:53:21 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/06 19:35:44 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2 || ft_is_cubformat(argv[1], ".cub") == FAILURE)
		error_exit("Argument Error : [Usage] ./cub3D any.cub\n", &data);
	ft_data_mlx_init(&data);
	ft_map_parsing(argv[1], &data);
	ft_set_hooks(&data);
	ft_print_image(&data);
	mlx_loop_hook(data.mlx, ft_print_image, &data);
	mlx_loop(data.mlx);
	exit(EXIT_SUCCESS);
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
			free(temp->line);
			data->tempmap = data->tempmap->next;
			free(temp);
		}
	}
	exit(EXIT_FAILURE);
}
