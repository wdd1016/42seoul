/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:02:53 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/05 23:57:28 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_data_mlx_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error_exit("Error : mlx_init failed\n", data);
}

static void	ft_init_img(t_img *img, t_data *data)
{
// 	img->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
// 	if (!img->img)
// 		error_exit("Error : mlx_new_image failed\n", data);
// 	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->size_l,
// 			&img->endian);
// 	if (!img->data)
// 		error_exit("Error : mlx_get_data_addr failed\n", data);
}
// data에 들어가있는 모든 항목 초기화, mlx_init