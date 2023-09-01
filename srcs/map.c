/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:30:17 by juyojeon          #+#    #+#             */
/*   Updated: 2023/09/01 17:14:24 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_map_parsing(char *path, t_data *data)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit("Map file open failed");
	texture_background_parsing(fd);
	coordinate_parsing(fd);
}

void	tetexture_background_parsing(int fd)
{}
