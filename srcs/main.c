/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:53:21 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/04 23:51:17 by juyojeon         ###   ########.fr       */
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
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}
