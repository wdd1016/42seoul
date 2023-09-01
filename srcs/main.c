 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:53:21 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/01 16:00:43 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2 || ft_is_cubformat(argv[1], ".cub") == FAILURE)
		error_exit("Argument Error : [Usage] ./cub3D any.cub\n");
	ft_mlx_init(&data);
	ft_map_parsing(argv[1], &data);
	ft_set_hooks(&data);
	ft_print_image(&data);
	mlx_loop_hook(data.mlx, ft_print_image, &data);
	mlx_loop(data.mlx);
	exit(EXIT_SUCCESS);
}

void	error_exit(const char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}
